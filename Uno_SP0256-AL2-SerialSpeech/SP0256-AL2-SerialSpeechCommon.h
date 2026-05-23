#ifndef SP0256_AL2_SERIAL_SPEECH_COMMON_H
#define SP0256_AL2_SERIAL_SPEECH_COMMON_H

#include <Arduino.h>
#include <string.h>

extern SpeechChip speech;

static char serialSpeechLine[96];
static uint8_t serialSpeechLen = 0;
static uint8_t serialSpeechUtfLead = 0;

static void speakPhone(const char *phone) {
  if (strcmp(phone, "PA1") == 0) speech.PA1();
  else if (strcmp(phone, "PA2") == 0) speech.PA2();
  else if (strcmp(phone, "PA3") == 0) speech.PA3();
  else if (strcmp(phone, "PA4") == 0) speech.PA4();
  else if (strcmp(phone, "PA5") == 0) speech.PA5();
  else if (strcmp(phone, "OY") == 0) speech.OY();
  else if (strcmp(phone, "AY") == 0) speech.AY();
  else if (strcmp(phone, "EH") == 0) speech.EH();
  else if (strcmp(phone, "KK3") == 0) speech.KK3();
  else if (strcmp(phone, "PP") == 0) speech.PP();
  else if (strcmp(phone, "JH") == 0) speech.JH();
  else if (strcmp(phone, "NN1") == 0) speech.NN1();
  else if (strcmp(phone, "IH") == 0) speech.IH();
  else if (strcmp(phone, "TT2") == 0) speech.TT2();
  else if (strcmp(phone, "RR1") == 0) speech.RR1();
  else if (strcmp(phone, "AX") == 0) speech.AX();
  else if (strcmp(phone, "MM") == 0) speech.MM();
  else if (strcmp(phone, "TT1") == 0) speech.TT1();
  else if (strcmp(phone, "DH1") == 0) speech.DH1();
  else if (strcmp(phone, "IY") == 0) speech.IY();
  else if (strcmp(phone, "EY") == 0) speech.EY();
  else if (strcmp(phone, "D1") == 0) speech.D1();
  else if (strcmp(phone, "UW1") == 0) speech.UW1();
  else if (strcmp(phone, "AO") == 0) speech.AO();
  else if (strcmp(phone, "AA") == 0) speech.AA();
  else if (strcmp(phone, "YY2") == 0) speech.YY2();
  else if (strcmp(phone, "AE") == 0) speech.AE();
  else if (strcmp(phone, "HH1") == 0) speech.HH1();
  else if (strcmp(phone, "BB1") == 0) speech.BB1();
  else if (strcmp(phone, "TH") == 0) speech.TH();
  else if (strcmp(phone, "UH") == 0) speech.UH();
  else if (strcmp(phone, "UW2") == 0) speech.UW2();
  else if (strcmp(phone, "AW") == 0) speech.AW();
  else if (strcmp(phone, "D2") == 0) speech.D2();
  else if (strcmp(phone, "GG3") == 0) speech.GG3();
  else if (strcmp(phone, "VV") == 0) speech.VV();
  else if (strcmp(phone, "GG1") == 0) speech.GG1();
  else if (strcmp(phone, "SH") == 0) speech.SH();
  else if (strcmp(phone, "ZH") == 0) speech.ZH();
  else if (strcmp(phone, "RR2") == 0) speech.RR2();
  else if (strcmp(phone, "FF") == 0) speech.FF();
  else if (strcmp(phone, "KK2") == 0) speech.KK2();
  else if (strcmp(phone, "KK1") == 0) speech.KK1();
  else if (strcmp(phone, "ZZ") == 0) speech.ZZ();
  else if (strcmp(phone, "NG") == 0) speech.NG();
  else if (strcmp(phone, "LL") == 0) speech.LL();
  else if (strcmp(phone, "WW") == 0) speech.WW();
  else if (strcmp(phone, "XR") == 0) speech.XR();
  else if (strcmp(phone, "WH") == 0) speech.WH();
  else if (strcmp(phone, "YY1") == 0) speech.YY1();
  else if (strcmp(phone, "CH") == 0) speech.CH();
  else if (strcmp(phone, "ER1") == 0) speech.ER1();
  else if (strcmp(phone, "ER2") == 0) speech.ER2();
  else if (strcmp(phone, "OW") == 0) speech.OW();
  else if (strcmp(phone, "DH2") == 0) speech.DH2();
  else if (strcmp(phone, "S") == 0) speech.S();
  else if (strcmp(phone, "NN2") == 0) speech.NN2();
  else if (strcmp(phone, "HH2") == 0) speech.HH2();
  else if (strcmp(phone, "OR") == 0) speech.OR();
  else if (strcmp(phone, "AR") == 0) speech.AR();
  else if (strcmp(phone, "YR") == 0) speech.YR();
  else if (strcmp(phone, "GG2") == 0) speech.GG2();
  else if (strcmp(phone, "EL") == 0) speech.EL();
  else if (strcmp(phone, "BB2") == 0) speech.BB2();
}

static void speakSeq(const char *const *phones, uint8_t count) {
  for (uint8_t i = 0; i < count; i++) {
    speakPhone(phones[i]);
  }
}

static bool speakKnownWord(const char *word) {
  static const char *hello[] = {"HH1", "EH", "LL", "OW"};
  static const char *world[] = {"WW", "ER1", "LL", "D1"};
  static const char *borg[] = {"BB1", "OR", "GG1"};
  static const char *borg9[] = {"BB1", "OR", "GG1", "PA2", "NN2", "AY", "NN1"};
  static const char *online[] = {"AO", "NN1", "LL", "AY", "NN1"};
  static const char *ready[] = {"RR1", "EH", "D1", "IY"};
  static const char *robot[] = {"RR1", "OW", "BB1", "AO", "TT1"};
  static const char *speech[] = {"S", "PP", "IY", "CH"};
  static const char *voice[] = {"VV", "OY", "S"};
  static const char *stop[] = {"S", "TT1", "AO", "PP"};
  static const char *reset[] = {"RR1", "IY", "S", "EH", "TT1"};
  static const char *test[] = {"TT1", "EH", "S", "TT1"};
  static const char *yes[] = {"YY1", "EH", "S"};
  static const char *no[] = {"NN2", "OW"};
  static const char *arduino[] = {"AR", "D2", "UW1", "IY", "NN2", "OW"};
  static const char *uno[] = {"YY1", "UW2", "NN2", "OW"};
  static const char *mega[] = {"MM", "EH", "GG1", "AX"};
  static const char *sp0256[] = {"S", "PP", "PA2", "OW", "PA1", "TT2", "UW2", "PA1", "FF", "AY", "VV", "PA1", "S", "IH", "KK1", "S"};

  if (strcmp(word, "hello") == 0) { speakSeq(hello, 4); return true; }
  if (strcmp(word, "world") == 0) { speakSeq(world, 4); return true; }
  if (strcmp(word, "borg") == 0) { speakSeq(borg, 3); return true; }
  if (strcmp(word, "borg9") == 0) { speakSeq(borg9, 7); return true; }
  if (strcmp(word, "online") == 0) { speakSeq(online, 5); return true; }
  if (strcmp(word, "ready") == 0) { speakSeq(ready, 4); return true; }
  if (strcmp(word, "robot") == 0) { speakSeq(robot, 5); return true; }
  if (strcmp(word, "speech") == 0) { speakSeq(speech, 4); return true; }
  if (strcmp(word, "voice") == 0) { speakSeq(voice, 3); return true; }
  if (strcmp(word, "stop") == 0) { speakSeq(stop, 4); return true; }
  if (strcmp(word, "reset") == 0) { speakSeq(reset, 5); return true; }
  if (strcmp(word, "test") == 0) { speakSeq(test, 4); return true; }
  if (strcmp(word, "yes") == 0) { speakSeq(yes, 3); return true; }
  if (strcmp(word, "no") == 0) { speakSeq(no, 2); return true; }
  if (strcmp(word, "arduino") == 0) { speakSeq(arduino, 6); return true; }
  if (strcmp(word, "uno") == 0) { speakSeq(uno, 4); return true; }
  if (strcmp(word, "mega") == 0) { speakSeq(mega, 4); return true; }
  if (strcmp(word, "sp0256") == 0) { speakSeq(sp0256, 16); return true; }
  return false;
}

static bool startsWithAt(const char *word, uint8_t pos, const char *prefix) {
  return strncmp(word + pos, prefix, strlen(prefix)) == 0;
}

static void speakCharFallback(char ch) {
  switch (ch) {
    case 'a': speech.AE(); break;
    case 'b': speech.BB1(); break;
    case 'c': speech.KK1(); break;
    case 'd': speech.D1(); break;
    case 'e': speech.EH(); break;
    case 'f': speech.FF(); break;
    case 'g': speech.GG1(); break;
    case 'h': speech.HH1(); break;
    case 'i': speech.IH(); break;
    case 'j': speech.JH(); break;
    case 'k': speech.KK1(); break;
    case 'l': speech.LL(); break;
    case 'm': speech.MM(); break;
    case 'n': speech.NN1(); break;
    case 'o': speech.AO(); break;
    case 'p': speech.PP(); break;
    case 'q': speech.KK1(); break;
    case 'r': speech.RR1(); break;
    case 's': speech.S(); break;
    case 't': speech.TT1(); break;
    case 'u': speech.UH(); break;
    case 'v': speech.VV(); break;
    case 'w': speech.WW(); break;
    case 'x': speech.KK1(); speech.S(); break;
    case 'y': speech.AY(); break;
    case 'z': speech.ZZ(); break;
    case '0': speech.ZZ(); speech.IY(); speech.RR1(); speech.OW(); break;
    case '1': speech.WW(); speech.AX(); speech.NN1(); break;
    case '2': speech.TT2(); speech.UW2(); break;
    case '3': speech.TH(); speech.RR1(); speech.IY(); break;
    case '4': speech.FF(); speech.OR(); break;
    case '5': speech.FF(); speech.AY(); speech.VV(); break;
    case '6': speech.S(); speech.IH(); speech.KK1(); speech.S(); break;
    case '7': speech.S(); speech.EH(); speech.VV(); speech.EH(); speech.NN1(); break;
    case '8': speech.EY(); speech.TT1(); break;
    case '9': speech.NN2(); speech.AY(); speech.NN1(); break;
  }
}

static void speakWord(const char *word) {
  if (word[0] == '\0') {
    return;
  }
  if (speakKnownWord(word)) {
    return;
  }

  for (uint8_t i = 0; word[i] != '\0';) {
    if (startsWithAt(word, i, "tion")) { speech.SH(); speech.AX(); speech.NN1(); i += 4; }
    else if (startsWithAt(word, i, "ch")) { speech.CH(); i += 2; }
    else if (startsWithAt(word, i, "sh")) { speech.SH(); i += 2; }
    else if (startsWithAt(word, i, "th")) { speech.TH(); i += 2; }
    else if (startsWithAt(word, i, "ph")) { speech.FF(); i += 2; }
    else if (startsWithAt(word, i, "ng")) { speech.NG(); i += 2; }
    else if (startsWithAt(word, i, "oo")) { speech.UW2(); i += 2; }
    else if (startsWithAt(word, i, "ee") || startsWithAt(word, i, "ea")) { speech.IY(); i += 2; }
    else if (startsWithAt(word, i, "ou") || startsWithAt(word, i, "ow")) { speech.AW(); i += 2; }
    else if (startsWithAt(word, i, "oy") || startsWithAt(word, i, "oi")) { speech.OY(); i += 2; }
    else if (startsWithAt(word, i, "ai") || startsWithAt(word, i, "ay")) { speech.EY(); i += 2; }
    else if (startsWithAt(word, i, "ar")) { speech.AR(); i += 2; }
    else if (startsWithAt(word, i, "or")) { speech.OR(); i += 2; }
    else if (startsWithAt(word, i, "er") || startsWithAt(word, i, "ir") || startsWithAt(word, i, "ur")) { speech.ER1(); i += 2; }
    else { speakCharFallback(word[i]); i++; }
  }
}

static bool speakRawAllophones(char *line) {
  char *token = strtok(line, " ,;|-_\t");
  bool spoken = false;
  while (token != NULL) {
    for (char *p = token; *p; p++) {
      if (*p >= 'a' && *p <= 'z') {
        *p = *p - 'a' + 'A';
      }
    }
    speakPhone(token);
    spoken = true;
    token = strtok(NULL, " ,;|-_\t");
  }
  return spoken;
}

static void speakSanitizedLine(char *line) {
  if (line[0] == ':') {
    Serial.println(F("RAW ALLOPHONES"));
    speakRawAllophones(line + 1);
    return;
  }

  char word[22];
  uint8_t wordLen = 0;
  bool spokeSomething = false;
  for (uint8_t i = 0;; i++) {
    char ch = line[i];
    bool end = ch == '\0';
    bool wordChar = (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
    if (wordChar && wordLen < sizeof(word) - 1) {
      word[wordLen++] = ch;
    } else {
      if (wordLen > 0) {
        word[wordLen] = '\0';
        if (spokeSomething) {
          speech.PA3();
        }
        speakWord(word);
        spokeSomething = true;
        wordLen = 0;
      }
      if (ch == '.' || ch == '!' || ch == '?') {
        speech.PA5();
      } else if (ch == ',' || ch == ':' || ch == ';') {
        speech.PA4();
      }
    }
    if (end) {
      break;
    }
  }
}

static char mapUtf8Polish(uint8_t lead, uint8_t b) {
  if (lead == 0xC3 && (b == 0x93 || b == 0xB3)) return 'o';
  if (lead == 0xC4) {
    if (b == 0x84 || b == 0x85) return 'a';
    if (b == 0x86 || b == 0x87) return 'c';
    if (b == 0x98 || b == 0x99) return 'e';
  }
  if (lead == 0xC5) {
    if (b == 0x81 || b == 0x82) return 'l';
    if (b == 0x83 || b == 0x84) return 'n';
    if (b == 0x9A || b == 0x9B) return 's';
    if (b == 0xB9 || b == 0xBA || b == 0xBB || b == 0xBC) return 'z';
  }
  return 0;
}

static char sanitizeInputByte(uint8_t b) {
  if (serialSpeechUtfLead != 0) {
    uint8_t lead = serialSpeechUtfLead;
    serialSpeechUtfLead = 0;
    return mapUtf8Polish(lead, b);
  }
  if (b >= 0xC2 && b <= 0xDF) {
    serialSpeechUtfLead = b;
    return 0;
  }
  if (b >= 0x80) {
    return 0;
  }
  if (b >= 'A' && b <= 'Z') {
    return b - 'A' + 'a';
  }
  if ((b >= 'a' && b <= 'z') || (b >= '0' && b <= '9')) {
    return b;
  }
  if (b == '.' || b == '!' || b == '?' || b == ',' || b == ':' || b == ';') {
    return b;
  }
  if (b == '\'' || b == '`' || b == '"') {
    return 0;
  }
  return ' ';
}

static void printSerialSpeechHelp() {
  Serial.println(F("SP0256-AL2 serial speech ready."));
  Serial.println(F("Type text and press Enter. UTF-8 is flattened to ASCII where possible."));
  Serial.println(F("Prefix ':' to send raw allophones, e.g. :HH1 EH LL OW PA5"));
  Serial.print(F("> "));
}

static void setupSerialSpeechExample() {
  Serial.begin(115200);
  speech.reset();
  printSerialSpeechHelp();
}

static void loopSerialSpeechExample() {
  while (Serial.available() > 0) {
    uint8_t raw = Serial.read();
    if (raw == '\r') {
      continue;
    }
    if (raw == '\b' || raw == 127) {
      if (serialSpeechLen > 0) {
        serialSpeechLen--;
      }
      continue;
    }
    if (raw == '\n') {
      serialSpeechLine[serialSpeechLen] = '\0';
      Serial.println();
      Serial.print(F("ASCII: "));
      Serial.println(serialSpeechLine);
      speakSanitizedLine(serialSpeechLine);
      serialSpeechLen = 0;
      serialSpeechUtfLead = 0;
      Serial.print(F("> "));
      return;
    }

    char ch = sanitizeInputByte(raw);
    if (ch == 0) {
      continue;
    }
    if (ch == ' ' && (serialSpeechLen == 0 || serialSpeechLine[serialSpeechLen - 1] == ' ')) {
      continue;
    }
    if (serialSpeechLen < sizeof(serialSpeechLine) - 1) {
      serialSpeechLine[serialSpeechLen++] = ch;
      Serial.write(ch);
    }
  }
}

#endif
