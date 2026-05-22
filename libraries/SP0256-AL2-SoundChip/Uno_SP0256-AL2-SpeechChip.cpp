#include "Arduino.h"
#include "Uno_SP0256-AL2-SpeechChip.h"

// Write 6-bit allophone address to Arduino UNO pins D2-D7.
// bit0 -> D2 -> SP0256 A1
// bit1 -> D3 -> SP0256 A2
// bit2 -> D4 -> SP0256 A3
// bit3 -> D5 -> SP0256 A4
// bit4 -> D6 -> SP0256 A5
// bit5 -> D7 -> SP0256 A6
// D0/D1 are preserved for RX/TX.
static inline void speechChipWriteAddress(uint8_t addr)
{
  PORTD = (PORTD & B00000011) | ((addr & B00111111) << 2);
}


SpeechChip::SpeechChip(int ALD)
{
  pinMode(ALD, OUTPUT);
  digitalWrite(ALD, HIGH);
  // Use D2-D7 for A1-A6, preserving D0/D1 for UART/USB/Bluetooth
  DDRD = (DDRD | B11111100);
  _ALD = ALD;
  _RESET = -1;
}

SpeechChip::SpeechChip(int ALD, int RESET)
{
  pinMode(ALD, OUTPUT);
  digitalWrite(ALD, HIGH);
  if (RESET >= 0) {
    digitalWrite(RESET, LOW);
    pinMode(RESET, INPUT);
  }
  // Use D2-D7 for A1-A6, preserving D0/D1 for UART/USB/Bluetooth
  DDRD = (DDRD | B11111100);
  _ALD = ALD;
  _RESET = RESET;
}

int SpeechChip::AddressLoad(int delayTime){
  digitalWrite(_ALD, LOW);
  delay(1);
  digitalWrite(_ALD, HIGH);
  delay(delayTime);
}

void SpeechChip::reset()
{
  if (_RESET < 0) {
    return;
  }

  // Open-drain style reset pulse: external 10k pull-ups keep SP0256 pins 2/25 high.
  digitalWrite(_RESET, LOW);
  pinMode(_RESET, OUTPUT);
  delay(100);
  pinMode(_RESET, INPUT);
  delay(100);
}

void SpeechChip::OR(){
  speechChipWriteAddress(B00111010);
  AddressLoad(330);
}

void SpeechChip::HH2(){
  speechChipWriteAddress(B00111001);
  AddressLoad(180);
}

void SpeechChip::HH1(){
  speechChipWriteAddress(B00011011);
  AddressLoad(130);
}

void SpeechChip::EH(){
  speechChipWriteAddress(B00000111);
  AddressLoad(70);
}

void SpeechChip::EL(){
  speechChipWriteAddress(B00111111);
  AddressLoad(190);
}

void SpeechChip::LL(){
  speechChipWriteAddress(B00101101);
  AddressLoad(110);
}

void SpeechChip::OW(){
  speechChipWriteAddress(B00110101);
  AddressLoad(240);
}

void SpeechChip::PA5(){
  speechChipWriteAddress(B00000100);
  AddressLoad(200);
}

void SpeechChip::BB1(){
  speechChipWriteAddress(B00011100);
  AddressLoad(80); 
}

void SpeechChip::AX(){
  speechChipWriteAddress(B00001111);
  AddressLoad(70);
}

void SpeechChip::IY(){
  speechChipWriteAddress(B00010011);
  AddressLoad(250);
}

void SpeechChip::NN2(){
  speechChipWriteAddress(B00111000);
  AddressLoad(190);
}

void SpeechChip::ER1(){
  speechChipWriteAddress(B00110011);
  AddressLoad(160);
}

void SpeechChip::AE(){
  speechChipWriteAddress(B00011010);
  AddressLoad(120);
}

void SpeechChip::AA(){
  speechChipWriteAddress(B00011000);
  AddressLoad(100);
}

void SpeechChip::AY(){
  speechChipWriteAddress(B00000110);
  AddressLoad(260);
}

void SpeechChip::KK1(){
  speechChipWriteAddress(B00101010);
  AddressLoad(160);
}

void SpeechChip::AO(){
  speechChipWriteAddress(B00010111);
  AddressLoad(100);
}

void SpeechChip::S(){
  speechChipWriteAddress(B00110111);
  AddressLoad(90);
}

void SpeechChip::EY(){
  speechChipWriteAddress(B00010100);
  AddressLoad(280);
}

void SpeechChip::PA4(){
  speechChipWriteAddress(B00000011);
  AddressLoad(100);
}

void SpeechChip::PA3(){
  speechChipWriteAddress(B00000010);
  AddressLoad(50);
}

void SpeechChip::PA2(){
  speechChipWriteAddress(B00000001);
  AddressLoad(30);
}

void SpeechChip::PA1(){
  speechChipWriteAddress(00000000);
  AddressLoad(10);
}

void SpeechChip::PP(){
  speechChipWriteAddress(B00001001);
  AddressLoad(210);
}

void SpeechChip::D1(){
  speechChipWriteAddress(B00010101);
  AddressLoad(70);
}

void SpeechChip::D2(){
  speechChipWriteAddress(B00100001);
  AddressLoad(160);
}

void SpeechChip::TT2(){
  speechChipWriteAddress(B00001101);
  AddressLoad(140);
}

void SpeechChip::UW1(){
  speechChipWriteAddress(B00010110);
  AddressLoad(100);
}

void SpeechChip::MM(){
  speechChipWriteAddress(B00010000);
  AddressLoad(180);
}

void SpeechChip::YY2(){
  speechChipWriteAddress(B00011001);
  AddressLoad(180);
}

void SpeechChip::IH(){
  speechChipWriteAddress(B00001100);
  AddressLoad(70);
}

void SpeechChip::TT1(){
  speechChipWriteAddress(B00010001);
  AddressLoad(100);
}

void SpeechChip::ZZ(){
  speechChipWriteAddress(B00101011);
  AddressLoad(210);
}

void SpeechChip::NG(){
  speechChipWriteAddress(B00101100);
  AddressLoad(220);
}

void SpeechChip::GG1(){
  speechChipWriteAddress(B00100100);
  AddressLoad(80);
}

void SpeechChip::GG2(){
  speechChipWriteAddress(B00111101);
  AddressLoad(40);
}

void SpeechChip::GG3(){
  speechChipWriteAddress(B00100010);
  AddressLoad(140);
}

void SpeechChip::FF(){
  speechChipWriteAddress(B00101000);
  AddressLoad(150);
}

void SpeechChip::KK2(){
  speechChipWriteAddress(B00101001);
  AddressLoad(190);
}

void SpeechChip::KK3(){
  speechChipWriteAddress(B00001000);
  AddressLoad(120);
}

void SpeechChip::CH(){
  speechChipWriteAddress(B00110010); 
  AddressLoad(190);
}

void SpeechChip::TH(){
  speechChipWriteAddress(B00011101);
  AddressLoad(180);
}

void SpeechChip::ZH(){
  speechChipWriteAddress(B00100110);
  AddressLoad(190);
}

void SpeechChip::RR1(){
  speechChipWriteAddress(B00001110);
  AddressLoad(170);
}

void SpeechChip::RR2(){
  speechChipWriteAddress(B00100111);
  AddressLoad(120);
}

void SpeechChip::OY(){
  speechChipWriteAddress(B00000101);
  AddressLoad(420);
}

void SpeechChip::JH(){
  speechChipWriteAddress(B00001010);
  AddressLoad(140);
}

void SpeechChip::DH1(){
  speechChipWriteAddress(B00010010);
  AddressLoad(290);
}

void SpeechChip::DH2(){
  speechChipWriteAddress(B00110110);
  AddressLoad(240);
}

void SpeechChip::UW2(){
  speechChipWriteAddress(B00011111);
  AddressLoad(290);
}

void SpeechChip::YY1(){
  speechChipWriteAddress(B00110001);
  AddressLoad(130);
}

void SpeechChip::BB2(){
  speechChipWriteAddress(B00111111);
  AddressLoad(50);
}

void SpeechChip::UH(){
  speechChipWriteAddress(B00011110);
  AddressLoad(100);
}

void SpeechChip::AW(){
  speechChipWriteAddress(B00100000);
  AddressLoad(370);
}

void SpeechChip::VV(){
  speechChipWriteAddress(B00100011);
  AddressLoad(190);
}

void SpeechChip::SH(){
  speechChipWriteAddress(B00100101);
  AddressLoad(160);
}

void SpeechChip::WW(){
  speechChipWriteAddress(B00101110);
  AddressLoad(180);
}

void SpeechChip::XR(){
  speechChipWriteAddress(B00101111);
  AddressLoad(360);
}

void SpeechChip::WH(){
  speechChipWriteAddress(B00110000);
  AddressLoad(200);
}

void SpeechChip::ER2(){
  speechChipWriteAddress(B00110100);
  AddressLoad(300);
}

void SpeechChip::AR(){
  speechChipWriteAddress(B00111011);
  AddressLoad(290);
}

void SpeechChip::YR(){
  speechChipWriteAddress(B00111100);
  AddressLoad(350);
}

void SpeechChip::NN1(){
  speechChipWriteAddress(B00001011);
  AddressLoad(140);
}
