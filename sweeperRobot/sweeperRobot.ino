#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <Servo.h>

Adafruit_8x8matrix sweeperEyeLeft = Adafruit_8x8matrix();
Adafruit_8x8matrix sweeperEyeRight = Adafruit_8x8matrix();
#define bumperSwitch 7
#define servoLeftPin 5
#define servoRightPin 6
Servo sweeperLeftServo;
Servo sweeperRightServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sweeperEyeLeft.begin(0x70);
  sweeperEyeRight.begin(0x70);
  pinMode(bumperSwitch,INPUT);
  sweeperLeftServo.attach(5);
  sweeperRightServo.attach(6);

  //Counter clockwise
  sweeperLeftServo.writeMicroseconds(1550);
}

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  happy_bmp[] =
  { B00001110,
    B00011100,
    B00111000,
    B01110000,
    B01110000,
    B00111000,
    B00011100,
    B00001110 },
  angry_bmp[] =
  { B00011110,
    B00011110,
    B00111100,
    B00111100,
    B01111000,
    B01111000,
    B11110000,
    B11110000 };

void loop() {
  // put your main code here, to run repeatedly:
  sweeperEyeLeft.clear();
  if(digitalRead(bumperSwitch))
  {
    sweeperEyeLeft.drawBitmap(0,0,angry_bmp,8,8,LED_ON);
    sweeperEyeLeft.writeDisplay();
    sweeperEyeRight.drawBitmap(0,0,angry_bmp,8,8,LED_ON);
    sweeperEyeRight.writeDisplay();
    //delay(1000);
  }
  else if(!digitalRead(bumperSwitch))
  {
    sweeperEyeLeft.drawBitmap(0,0,happy_bmp,8,8,LED_ON);
    sweeperEyeLeft.writeDisplay();
    sweeperEyeRight.drawBitmap(0,0,happy_bmp,8,8,LED_ON);
    sweeperEyeRight.writeDisplay();

    
   
   // delay(1000);
  }
  else
  {
    sweeperEyeLeft.clear();
    sweeperEyeLeft.writeDisplay();
  }
}
