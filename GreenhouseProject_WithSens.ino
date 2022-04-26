
// variable setup

#include <Servo.h>

#include "Adafruit_SHTC3.h"
Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define LED_PIN 3
#define NUMPIXELS 64
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

int tempSensPin = A0;
int RHSensPin = A1;
int lightSensPin = A2;
int irrigationTime = 30000;

int lowWaterPin = 2;
int highWaterPin = 4;
int refillValve = 5;
int heaterPin = 7;
int pumpPin = 8;
int fanPin = 12;
int irrigationPin = 13;
int ventOne = 9;
int ventTwo = 10;
int ventThree = 11;

Servo servoOne;
Servo servoTwo;
Servo servoThree;


void setup() {
  // put your setup code here, to run once:
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  pixels.begin();
  
  pinMode(lowWaterPin, INPUT_PULLUP);
  pinMode(highWaterPin, INPUT_PULLUP);
  
  pinMode(refillValve, OUTPUT);
  // pinMode(LEDPin, OUTPUT);
  pinMode(heaterPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(irrigationPin, OUTPUT);

  digitalWrite(refillValve, LOW);
  // digitalWrite(LEDPin, LOW);
  digitalWrite(heaterPin, LOW);
  digitalWrite(pumpPin, HIGH);
  digitalWrite(fanPin, LOW);
  digitalWrite(irrigationPin, LOW);
  
  servoOne.attach(ventOne);
  servoTwo.attach(ventTwo);
  servoThree.attach(ventThree);

  servoOne.write(0);
  servoTwo.write(0);
  servoThree.write(0);

  Serial.begin(9600);

  while (!Serial)
   delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("SHTC3 test");
  if (! shtc3.begin()) {
    Serial.println("Couldn't find SHTC3");
    while (1) delay(1);
  }
  Serial.println("Found SHTC3 sensor");
}

void loop() {
  // put your main code here, to run repeatedly:

  sensors_event_t humidity, temp;
  shtc3.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  lightSensPin = analogRead(A2); 

  if (lightSensPin < lightThreshold){
      pixels.fill(pixels.Color(255, 255, 255), 0, 64);
      pixels.show(); 
  }
  else {
      pixels.fill(pixels.Color(0, 0, 0), 0, 64);
      pixels.show();
  }

  if (lowWaterPin == HIGH) {
     digitalWrite(refillValve, HIGH);
       while (highWaterPin==LOW) {
         delay(1000);
       }
     digitalWrite(refillValve, LOW);  
   }

  if (temp > 29) {
     servoOne.write(90);
     delay(2500);
     servoTwo.write(90);
     delay(2500);
     servoThree.write(90);
     delay(2500);
     digitalWrite(fanPin, HIGH);
     digitalWrite(pumpPin, LOW);
   }
   else if (temp > 24 & humidity< 50){
     servoOne.write(90);
     delay(2500);
     servoTwo.write(90);
     delay(2500);
     servoThree.write(90);
     delay(2500);
     digitalWrite(fanPin, HIGH);
     digitalWrite(pumpPin, LOW);
   }
   else if (temp > 24) {
     servoOne.write(90);
     delay(2500);
     servoTwo.write(90);
     delay(2500);
     servoThree.write(90);
     delay(2500);
     digitalWrite(fanPin, HIGH);
   }
   else if (temp < 12) {
     servoOne.write(0);
     delay(2500);
     servoTwo.write(0);
     delay(2500);
     servoThree.write(0);
     delay(2500);
     digitalWrite(heaterPin, HIGH);
   }
   else{
     servoOne.write(90);
     delay(2500);
     servoTwo.write(90);
     delay(2500);
     servoThree.write(90);
     delay(2500);
     digitalWrite(fanPin, LOW);
     digitalWrite(heaterPin, LOW);
     digitalWrite(pumpPin, HIGH);
   }

int   runTime = millis() / 1000;
int   interval = runTime / 30;
    if (interval % 2 == 0) {
      digitalWrite(irrigationPin, HIGH);
    }
    else {
      digitalWrite(irrigationPin, LOW);
    }
}
