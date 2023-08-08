/*
  Programme fait maison pour commander en infrarouge à partir d'un ordre bluetoot
*/

#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>
#include <SoftwareSerial.h>
SoftwareSerial MyBlue(10, 11); // RX | TX
//int LED = 9;
String butid;
int a;
int x;

void setup()
{
  // Partie BT
  Serial.begin(9600);
  MyBlue.begin(9600);
 // pinMode(LED, OUTPUT);
  Serial.println("***AT commands mode***");
 // digitalWrite(LED, HIGH);
}


void Regvol(int x) {

  a=1;
  while (a<x*x+1) {
if (x<0) {
  IrSender.sendDenon(0x6, 0x32, 0);
  delay(100);
}
if (x>0) {
  IrSender.sendDenon(0x6, 0xB2, 0);
  delay(100);
}
  a++;
  }
}


void Emir(String w) {
//  digitalWrite(LED, LOW);
  Serial.println(F("Send NEC 16 bit address 0xFB0C and data 0x18 with (50 us) tick resolution timing (8 bit array format) "));
  Serial.flush();
  if (w == "Pwr")  IrSender.sendRC6(0x46, 0xC7, 0);
  if (w == "ht")  IrSender.sendRC6(0x46, 0x58, 0);
  if (w == "Ga")  IrSender.sendRC6(0x46, 0x5A, 0);
  if (w == "OK")  IrSender.sendRC6(0x46, 0x5C, 0);
  if (w == "Dte")  IrSender.sendRC6(0x46, 0x5B, 0);
  if (w == "Bas")  IrSender.sendRC6(0x46, 0x59, 0);
  if (w == "menu")  IrSender.sendRC6(0x46, 0x9C, 0);
  if (w == "Track_moins")  IrSender.sendRC6(0x46, 0x21, 0);
  if (w == "Play")  IrSender.sendRC6(0x46, 0x2C, 0);
  if (w == "Pause")  IrSender.sendRC6(0x46, 0x30, 0);
  if (w == "Track_plus")  IrSender.sendRC6(0x46, 0x20, 0);
  if (w == "Back")  IrSender.sendRC6(0x46, 0x83, 0);
  if (w == "Home")  IrSender.sendRC6(0x46, 0x92, 0);
  if (w == "Option")  IrSender.sendRC6(0x46, 0xC9, 0);
  if (w == "Disc_popup")  IrSender.sendRC6(0x9A, 0x20, 0);
  if (w == "Retrap")  IrSender.sendRC6(0x46, 0x29, 0);
  if (w == "Stop")  IrSender.sendRC6(0x46, 0x31, 0);
  if (w == "Av_rap")  IrSender.sendRC6(0x46, 0x28, 0);
  if (w == "ST")   IrSender.sendRC6(0x46, 0x4B, 0);
  if (w == "Audio")  IrSender.sendRC6(0x46, 0x4E, 0);
  if (w == "Power")  IrSender.sendDenon(0x6, 0xA, 0);
  if (w == "Video")  IrSender.sendDenon(0x6, 0xCA, 0);
  if (w == "Tape")  IrSender.sendDenon(0x6, 0x3A, 0);
  if (w == "Tuner")  IrSender.sendDenon(0x6, 0x9A, 0);
  if (w == "CD")  IrSender.sendDenon(0x6, 0x5A, 0);
  if (w == "Phono")  IrSender.sendDenon(0x6, 0x1A, 0);
  if (w == "Presetplus")  IrSender.sendDenon(0x6, 0x72, 0);
  if (w == "Presetm")  IrSender.sendDenon(0x6, 0xF2, 0);
  if (w == "volplus1")  Regvol(1);
  if (w == "Volmoins1")  Regvol(-1);
  if (w == "volplus2")  Regvol(2);
  if (w == "Volmoins2")  Regvol(-2);
  if (w == "volplus3")  Regvol(3);
  if (w == "Volmoins3")  Regvol(-3);
  delay(200); // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
 // digitalWrite(LED, HIGH);
}

void loop()
{
  if (MyBlue.available()) {
    String butid = MyBlue.readString();
    Emir (butid);
  }
}
