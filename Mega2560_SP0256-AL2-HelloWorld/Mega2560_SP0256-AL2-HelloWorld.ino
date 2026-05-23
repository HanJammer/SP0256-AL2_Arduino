/*
 * SP0256-AL2 Hello World example for Arduino Mega2560.
 * The ALD pin is connected to pin 8. Mega pin 10 is connected
 * to SP0256 pins 2 and 25 for an active-low reset pulse.
 * Address pins use Mega D22-D27 / PORTA bits 0-5.
 * The allophones DD1, DD2, and SS have been renamed to D1,
 * D2, and S for conflict reasons.
 */

#include "src/SP0256-AL2-SpeechChip/Mega2560_SP0256-AL2-SpeechChip.h"

SpeechChip SpeechChip(8, 10); // ALD on D8, reset pulse on D10

void setup() {
  SpeechChip.reset();
}

void loop() {

  // Say "HELLO WORLD".
  SpeechChip.HH1();
  SpeechChip.EH();
  SpeechChip.LL();
  SpeechChip.OW();
  SpeechChip.PA5();

  SpeechChip.WW();
  SpeechChip.OR();
  SpeechChip.LL();
  SpeechChip.D1();
  SpeechChip.PA5();

  delay(1024);
}
