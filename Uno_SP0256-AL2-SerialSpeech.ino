/*
 * SP0256-AL2 interactive serial speech example for Arduino Uno.
 *
 * Open Serial Monitor at 115200 baud, type text, press Enter. The sketch
 * flattens UTF-8 input to ASCII where possible, drops unsupported bytes, then
 * speaks a simple allophone approximation.
 */

#include "libraries/SP0256-AL2-SoundChip/Uno_SP0256-AL2-SpeechChip.h"
#include "libraries/SP0256-AL2-SoundChip/Uno_SP0256-AL2-SpeechChip.cpp"

SpeechChip speech(8, 10); // ALD on D8, reset pulse on D10

#include "SP0256-AL2-SerialSpeechCommon.h"

void setup() {
  setupSerialSpeechExample();
}

void loop() {
  loopSerialSpeechExample();
}
