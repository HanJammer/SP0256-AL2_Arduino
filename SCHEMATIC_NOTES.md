# SP0256-AL2 Datasheet Schematic Notes

Notes from the "Typical Application Microcomputer Interface" schematic.

## Important Differences

- The datasheet schematic shows a `3.12 MHz` crystal/resonator on OSC1/OSC2,
  with 22 pF capacitors to ground. A `3.57954 MHz` colorburst crystal can make
  the chip run faster and higher-pitched. Prefer `3.12 MHz` when matching the
  datasheet voice/timing.
- The schematic expects both `RESET` and `SBY RESET` to share a power-on reset
  node. The shown reset network is a 100k pull-up to +5V, 0.1 uF to ground, and
  a diode around the pull-up for faster discharge/recovery behavior. Our Arduino
  reset-control pin can replace the passive-only reset behavior, but the reset
  pins must still be pulled up and must not be hard-tied directly to +5V.
- `LRQ` is wired back to the host as an input. It is the proper hardware pacing
  signal for loading the next allophone. Fixed delays work for demos, but `LRQ`
  is the better path for robust robot/runtime integration.
- `SBY` is also wired back to the host as an input in the datasheet example.
  It can be useful as a status/debug signal, but it is not required for the
  simple Arduino examples.
- The datasheet microcomputer interface drives the address pins and `ALD`.
  For the AL2 vocabulary only 64 addresses are needed, so using `A1`-`A6` and
  tying `A7`/`A8` to ground remains valid for this repository.

## Audio Path

The schematic does not drive a speaker directly from SP0256 pin 24. It uses a
filter/coupling network followed by an amplifier:

```text
SP0256 DIGITAL OUT
  -> 33k series
  -> 0.022 uF shunt to GND
  -> 33k series
  -> 0.022 uF shunt to GND
  -> 1 uF coupling capacitor
  -> 10k volume potentiometer
  -> LM386-style audio amplifier input
```

The amplifier section is the classic LM386-style arrangement:

- pin 6 to +5V with 0.1 uF supply bypass nearby,
- pin 4 to ground,
- pin 1 to pin 8 through 10 uF for higher gain,
- output from pin 5 through 100 uF to the speaker,
- output stability network from pin 5 through 10 ohm and 0.1 uF to ground.

Practical note: for a modern build, the SP0256 still wants filtering and AC
coupling before any amplifier module. A PAM8403/LM386 module can replace the
shown discrete amplifier stage, but not the need to avoid loading pin 24
directly.

## Current Repository Mapping

- `SE` is held HIGH.
- `TEST` is tied LOW.
- `ROM DISABLE` is held HIGH.
- `SER IN` is pulled LOW because serial allophone loading is not used.
- `A1`-`A6` are driven by Arduino GPIO.
- `A7`/`A8` are tied LOW for the 64-entry AL2 set.
- `ALD` is driven by Arduino.
- `RESET` and `SBY RESET` are tied together and pulled HIGH, with Arduino able
  to pulse the shared node LOW in an open-drain style.

## Recommended Hardware Follow-Up

- Prefer a `3.12 MHz` resonator/crystal if the goal is datasheet-correct speech
  speed and pitch.
- Expose `LRQ` to the Arduino/Mega2560. In FETank9000 wiring, the reserved D12
  line is a good fit.
- If using a raw amplifier rather than a module, copy the datasheet's two-stage
  `33k/0.022 uF` low-pass filter and LM386-style output network.
- Keep reset pull-ups and local decoupling close to the SP0256 board. Noise and
  floating control pins are credible causes of "sometimes speaks, sometimes
  only clicks" behavior.
