# SP0256-AL2 Arduino Fixed Examples

Arduino Uno and Mega2560 examples for the General Instrument / Radio Shack
SP0256-AL2 speech synthesizer.

This repository is a fixed version of the common Arduino SP0256 example code
and wiring. The basic circuit can appear alive but start unreliably, produce
noise, or speak only sometimes if reset and unused inputs are left in unstable
states. The fixes here make startup deterministic:

- `SER IN` is pulled down instead of floating.
- `RESET` and `SBY RESET` use 10k pull-ups and a controlled Arduino reset pulse.
- Uno code preserves D0/D1 serial pins.
- Mega2560 code avoids AVR `PA1`-`PA5` macro conflicts.
- Power decoupling and audio filtering are documented explicitly.

Credit for the original build/reference idea:
https://www.instructables.com/Arduino-Vintage-Speech-Chip/

Allophone table:
[ALLOPHONES.md](ALLOPHONES.md)

Example word/allophone phrases:
[EXAMPLE_WORDS.md](EXAMPLE_WORDS.md)

Datasheet schematic notes:
[SCHEMATIC_NOTES.md](SCHEMATIC_NOTES.md)

## Repository Layout

```text
Uno_SP0256-AL2-HelloWorld.ino
Mega2560_SP0256-AL2-HelloWorld.ino
Uno_SP0256-AL2-SerialSpeech.ino
Mega2560_SP0256-AL2-SerialSpeech.ino
SP0256-AL2-SerialSpeechCommon.h
ALLOPHONES.md
EXAMPLE_WORDS.md
SCHEMATIC_NOTES.md
libraries/
  SP0256-AL2-SpeechChip/
    Uno_SP0256-AL2-SpeechChip.h
    Uno_SP0256-AL2-SpeechChip.cpp
    Mega2560_SP0256-AL2-SpeechChip.h
    Mega2560_SP0256-AL2-SpeechChip.cpp
```

The root `.ino` sketches include their matching `.h` and `.cpp` files directly
from `libraries/SP0256-AL2-SpeechChip/`. This keeps the repository flat and
avoids Arduino library auto-selection confusion between Uno and Mega variants.

## Examples

- `Uno_SP0256-AL2-HelloWorld.ino` and `Mega2560_SP0256-AL2-HelloWorld.ino`
  repeat a fixed "hello world" phrase.
- `Uno_SP0256-AL2-SerialSpeech.ino` and `Mega2560_SP0256-AL2-SerialSpeech.ino`
  read text from Serial Monitor at 115200 baud. Type text, press Enter, and the
  sketch sanitizes UTF-8 input to ASCII where possible before speaking a simple
  allophone approximation.
- In the serial examples, prefix input with `:` to send raw allophone symbols:
  `:HH1 EH LL OW PA5`.

The serial examples are small interactive demos, not full text-to-speech
engines. They include a small word list plus rough grapheme fallback. Serious
text cleanup and pronunciation should live on the host computer.

## Required SP0256 Wiring

These connections are common to Uno and Mega2560 unless a board-specific table
below says otherwise.

| SP0256 pin | Signal | Connection |
| --- | --- | --- |
| 1 | VSS | GND |
| 2 | `~RESET` | 10k pull-up to +5V, also tied to Arduino reset-control pin |
| 3 | ROM DISABLE | +5V |
| 4 | C1 | NC |
| 5 | C2 | NC |
| 6 | C3 | NC |
| 7 | VDD | +5V |
| 8 | SBY | Optional diagnostic output, do not load directly |
| 9 | `~LRQ` | Optional diagnostic/synchronization input, currently unused |
| 10 | A8 | GND |
| 11 | A7 | GND |
| 12 | SER OUT | NC |
| 13 | A6 | Arduino address bit 5 |
| 14 | A5 | Arduino address bit 4 |
| 15 | A4 | Arduino address bit 3 |
| 16 | A3 | Arduino address bit 2 |
| 17 | A2 | Arduino address bit 1 |
| 18 | A1 | Arduino address bit 0 |
| 19 | SE | +5V |
| 20 | `~ALD` | Arduino address-load strobe |
| 21 | SER IN | 10k pull-down to GND |
| 22 | TEST | GND |
| 23 | VD1 | +5V |
| 24 | DIGITAL OUT | RC audio filter, then speaker/amplifier input |
| 25 | `~SBY_RESET` | 10k pull-up to +5V, also tied to Arduino reset-control pin |
| 26 | ROM CLOCK | Output, around half the crystal frequency |
| 27 | OSC1 | 3.12 MHz datasheet crystal/resonator leg, about 22-27 pF to GND |
| 28 | OSC2 | 3.12 MHz datasheet crystal/resonator leg, about 22-27 pF to GND |

The Radio Shack / SP0256-AL2 datasheet describes two address load modes. This
code uses `SE = HIGH`, then places the allophone address on `A1`-`A6` and sends
a negative pulse on `~ALD`.

## Uno Wiring

| Arduino Uno | SP0256-AL2 | Purpose |
| --- | --- | --- |
| D2 | pin 18 / A1 | Address bit 0 |
| D3 | pin 17 / A2 | Address bit 1 |
| D4 | pin 16 / A3 | Address bit 2 |
| D5 | pin 15 / A4 | Address bit 3 |
| D6 | pin 14 / A5 | Address bit 4 |
| D7 | pin 13 / A6 | Address bit 5 |
| D8 | pin 20 / `~ALD` | Address-load strobe |
| D10 | pins 2 and 25 | Shared active-low reset pulse |

Uno D0/D1 are left untouched for USB serial.

## Mega2560 Wiring

| Arduino Mega2560 | SP0256-AL2 | Purpose |
| --- | --- | --- |
| D22 / PA0 | pin 18 / A1 | Address bit 0 |
| D23 / PA1 | pin 17 / A2 | Address bit 1 |
| D24 / PA2 | pin 16 / A3 | Address bit 2 |
| D25 / PA3 | pin 15 / A4 | Address bit 3 |
| D26 / PA4 | pin 14 / A5 | Address bit 4 |
| D27 / PA5 | pin 13 / A6 | Address bit 5 |
| D8 | pin 20 / `~ALD` | Address-load strobe |
| D10 | pins 2 and 25 | Shared active-low reset pulse |

The Mega2560 code writes only the lower six bits of `PORTA`, so D28/D29
(`PA6`/`PA7`) remain available.

## DIP Orientation

Viewed from above with the notch at the top:

```text
                 SP0256-AL2 DIP-28
                       notch
                    ___     ___
             VSS  1|   \___/   |28 OSC2 ---- crystal ----+
 reset + 10k PU   2|           |27 OSC1 ---- crystal ----+-- 27pF each to GND
            +5V   3|           |26 ROM CLOCK  output only
             NC   4|           |25 ~SBY_RESET 10k PU + reset pin
             NC   5|           |24 DIGITAL OUT -> audio filter -> amp/speaker
             NC   6|           |23 VD1 +5V
            +5V   7|           |22 TEST GND
      SBY output  8|           |21 SER IN 10k PD to GND
     ~LRQ output  9|           |20 ~ALD Arduino strobe pin
            GND  10|           |19 SE +5V
            GND  11|           |18 A1 address bit 0
             NC  12|           |17 A2 address bit 1
       A6 bit 5  13|           |16 A3 address bit 2
       A5 bit 4  14|___________|15 A4 address bit 3

PU = pull-up to +5V. PD = pull-down to GND.
```

## Simplified Schematic

```text
Arduino address pins -------------- SP0256 pins 18..13 / A1..A6
Arduino ALD pin ------------------- SP0256 pin 20 / ~ALD

Arduino reset-control pin --------+ SP0256 pin 2  / ~RESET
                                  `- SP0256 pin 25 / ~SBY_RESET
                                     |          |
                                    10k        10k
                                     |          |
+5V --------------------------------+----------+---- SP0256 pins 7, 23, 3, 19
GND ------------------------------------------------ SP0256 pins 1, 10, 11, 22
GND --- 10k ---------------------------------------- SP0256 pin 21 / SER IN

3.12 MHz datasheet crystal/resonator between pins 27 and 28.
About 22-27 pF from pin 27 to GND and from pin 28 to GND.

SP0256 pin 24 DIGITAL OUT -- 33k --+-- 33k --+-- 1 uF -- amplifier input
                                   |         |
                                0.022 uF  0.022 uF
                                   |         |
                                  GND       GND
```

Some hobby builds use a 3.57954 MHz colorburst crystal because it is easier to
find. It can oscillate, but it changes speech speed/pitch relative to the
datasheet timing.

Do not drive the SP0256 reset lines LOW if pins 2 or 25 are tied directly to
+5V. They must be pull-ups, not hard power rails.

## Reset Behavior

The software reset pulse is open-drain style:

1. Arduino reset-control pin is driven LOW for 100 ms.
2. The pin returns to input/high-Z.
3. External 10k pull-ups bring SP0256 pins 2 and 25 back HIGH.
4. The sketch waits another 100 ms before sending allophones.

This keeps the SP0256 held in reset while Arduino initializes its GPIO state,
then releases it into a known address/strobe configuration.

## Power Decoupling

Use a 10 uF electrolytic capacitor across the board supply:

- capacitor plus to +5V,
- capacitor minus to GND,
- placed close to the SP0256 power pins if possible.

Recommended follow-up: add 100 nF ceramic capacitors close to the chip power
pins. Ideally use one near VDD/VSS and one near VD1/VSS. The circuit can work
without them, but local ceramic decoupling is still the correct stable build.

Do not place any decoupling capacitor in series between Arduino +5V and the
rest of the board.

## Audio Output

SP0256 pin 24 is a digital/PWM speech output, not a speaker driver. Feed it
through a low-pass / coupling stage into a high-impedance input. The datasheet
typical application uses this two-stage filter:

```text
SP0256 pin 24 -- 33k --+-- 33k --+-- 1 uF -- amplifier/volume input
                       |         |
                    0.022 uF  0.022 uF
                       |         |
                      GND       GND
```

For a small speaker, use an amplifier module after the filter/coupling stage.
Practical choices:

- PAM8403-class 5V class-D amplifier for compact speaker output.
- LM386-class mono amplifier for simple low-power experiments.

Keep amplifier ground common with the SP0256/Arduino ground. If amplifier noise
gets into the speech chip, separate audio power routing from SP0256 logic power
as much as the bench board allows.

## Build

Because the repository keeps multiple root sketches, compile each sketch through a
temporary one-sketch folder.

Uno:

```sh
tmp="$(mktemp -d /tmp/sp0256-uno-compile.XXXXXX)"
sketch="$tmp/sp0256_uno"
mkdir "$sketch"
cp -a libraries "$sketch/"
cp Uno_SP0256-AL2-HelloWorld.ino "$sketch/sp0256_uno.ino"
arduino-cli compile -b arduino:avr:uno "$sketch"
rm -rf "$tmp"
```

For the serial example, copy `SP0256-AL2-SerialSpeechCommon.h` into the same
temporary sketch folder and replace the copied `.ino` file with
`Uno_SP0256-AL2-SerialSpeech.ino`.

Mega2560:

```sh
tmp="$(mktemp -d /tmp/sp0256-mega-compile.XXXXXX)"
sketch="$tmp/sp0256_mega"
mkdir "$sketch"
cp -a libraries "$sketch/"
cp Mega2560_SP0256-AL2-HelloWorld.ino "$sketch/sp0256_mega.ino"
arduino-cli compile -b arduino:avr:mega "$sketch"
rm -rf "$tmp"
```

For the serial example, copy `SP0256-AL2-SerialSpeechCommon.h` into the same
temporary sketch folder and replace the copied `.ino` file with
`Mega2560_SP0256-AL2-SerialSpeech.ino`.

Verified build sizes:

```text
Uno HelloWorld:          1348 bytes flash, 13 bytes RAM
Mega2560 HelloWorld:     1952 bytes flash, 13 bytes RAM
Uno SerialSpeech:        7102 bytes flash, 852 bytes RAM
Mega2560 SerialSpeech:   7954 bytes flash, 852 bytes RAM
```

The Mega2560 version is compile-tested. Verify wiring carefully before hardware
testing, especially D22-D27 address order and the reset pull-ups.

## Safety Checklist

- SP0256 pin 1 is GND.
- SP0256 pins 7 and 23 are +5V.
- SP0256 pin 19 / SE is +5V.
- SP0256 pin 22 / TEST is GND.
- SP0256 pin 21 / SER IN is pulled down to GND.
- SP0256 pins 2 and 25 are pulled up to +5V through 10k resistors.
- Arduino reset-control pin is tied to SP0256 pins 2 and 25.
- 10 uF capacitor is parallel from +5V to GND, not in series with +5V.
- Audio output on pin 24 is not shorted directly to power or ground.

If speech is silent, first verify +5V on pins 7 and 23, reset release on pins
2 and 25, oscillator activity on pins 27/28, ROM CLOCK on pin 26, and `~ALD`
pulses on pin 20.
