/*
   Tiny4kOLED - Drivers for SSD1306 controlled dot matrix OLED/PLED 128x32 displays

   Based on ssd1306xled, re-written and extended by Stephen Denne
   from 2017-04-25 at https://github.com/datacute/Tiny4kOLED

*/

// Choose your I2C implementation before including Tiny4kOLED.h
// The default is selected is Wire.h

// To use the Wire library:
//#include <Wire.h>

// To use the Adafruit's TinyWireM library:
#include <TinyWireM.h>

// To use the TinyI2C library from https://github.com/technoblogy/tiny-i2c
//#include <TinyI2CMaster.h>

// The blue OLED screen
#define TINY4KOLED_QUICK_BEGIN

#include <Tiny4kOLED.h>
#include "SolomonSystech.h"

// ============================================================================
bool strela = 0;
int x = 4;
int x8 = 4;
int y = 0;
int x2 = 0;
int xCLR = 0;
int xCLR2 = 0;
int xSHW = 0;
float zrychleni = 5;
void setup() {
  // put your setup code here, to run once:

  oled.begin(128, 64, sizeof(tiny4koled_init_128x64r), tiny4koled_init_128x64r);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(5, OUTPUT);

  oled.clear();

l


  oled.bitmap(0, 0, 128, 8, solomon_systech_logo_bitmap);
  oled.clear();
  oled.bitmap(0, 0, 8, 1, zbran);
  delay(2000);
  oled.setFont(FONT8X16);
  oled.clear();
  oled.setInverse(false);
  digitalWrite(5, HIGH);
}

void loop() {


  // The characters in the 8x16 font are 8 pixels wide and 16 pixels tall
  // 2 lines of 16 characters exactly fills 128x32


  // Position the cusror
  // usage: oled.setCursor(X IN PIXELS, Y IN ROWS OF 8 PIXELS STARTING WITH 0);

  oled.setCursor(40, 0);
oled.print(x8);
  // Write the text to oled RAM (which is not currently being displayed)
  // Wrap strings in F() to save RAM!

  int sensorVal = digitalRead(3);
  int sensorVal2 = digitalRead(4);
  int sensorVal3 = digitalRead(1);

  if (sensorVal == HIGH) {
  } else {
    x8++;


  }
  if (sensorVal == HIGH && sensorVal3 == HIGH) {
   
x8 = 7;
  } 

  if (sensorVal3 == HIGH) {

  } else {
    
    x8--;

  }
  if (sensorVal2 == HIGH) {
    strela = 0;

  } else {
    if (strela == 0) {
      x2 = x;
      y = 12;
      strela = 1;
    }
}
    if (x8 == 8) {
      x++;
      x8 = 0;
    }
    if (x8 == -8) {
      x--;
      x8 = 0;
    }


  
  if (xCLR2 != x) {
    oled.setCursor(0, x);
    oled.print("  ");
   
    xCLR2 = x;
  }
  if (xSHW != x) { 
    oled.setCursor(0, x - 2);
    oled.print("  ");
     oled.setCursor(0, x + 2);
    oled.print("  ");
    oled.setCursor(0, x);
    oled.print("{}");
  
    xSHW = x;
  } //else {xSHW++;}
  


  //oled.bitmap(0 ,x/8 ,8, 1, zbran);
  if (y < 112) {
    y = y + zrychleni;
    zrychleni = zrychleni * 0.972;
    oled.setCursor(y, x2);
    oled.print(" - ");
    strela = 1;

  } else {
    oled.setCursor(y, x2);
    oled.print("  ");
    zrychleni = 5;
  }
}
