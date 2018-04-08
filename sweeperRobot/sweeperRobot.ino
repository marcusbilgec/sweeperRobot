#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <Servo.h>

Adafruit_8x8matrix sweeperEye1 = Adafruit_8x8matrix();
#define irSensorInputPin 7
#define servoLeftPin 9
#define servoRightPin 10
Servo sweeperLeftServo;
Servo sweeperRightServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sweeperEye1.begin(0x70);
  pinMode(irSensorInputPin,INPUT);
  sweeperLeftServo.attach(9);
  sweeperRightServo.attach(10);

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
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };

void loop() {
  // put your main code here, to run repeatedly:
  sweeperEye1.clear();
  if(digitalRead(irSensorInputPin))
  {
    sweeperEye1.drawBitmap(0,0,smile_bmp,8,8,LED_ON);
    sweeperEye1.writeDisplay();
    // delay(1000);
  }
  else if(!digitalRead(irSensorInputPin))
  {
    sweeperEye1.drawBitmap(0,0,frown_bmp,8,8,LED_ON);
    sweeperEye1.writeDisplay();
    // delay(1000);
  }
  else
  {
    sweeperEye1.clear();
    sweeperEye1.writeDisplay();
  }
}
