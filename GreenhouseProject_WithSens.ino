
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
int irrigationTime = 1;
int irrigationInterval = 360;
int irrigationStatus = 0;
int hours = 0;
int minutes1 = 0;
int minutes2 = 0;
int timePast = 0;
int lightThreshold = 550;
int temperature = 70;
int humidity1 = 60;

int lowWaterPin = 2;
int highWaterPin = 4;
int refillValve = 5;
int heaterPin = 7;
int pumpPin = 8;
int fanPin = 12;
int irrigationPin = 13;
int ventOne = 9;

Servo servoOne;



void setup() {
  // put your setup code here, to run once:
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  pixels.begin();
  
  pinMode(lowWaterPin, INPUT_PULLUP);
  pinMode(highWaterPin, INPUT_PULLUP);
  
  pinMode(refillValve, OUTPUT);
  pinMode(heaterPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(irrigationPin, OUTPUT);

  digitalWrite(refillValve, HIGH);
  digitalWrite(heaterPin, LOW);
  digitalWrite(pumpPin, HIGH);
  digitalWrite(fanPin, HIGH);
  digitalWrite(irrigationPin, HIGH);
  
  servoOne.attach(ventOne);


  servoOne.write(120);

  Serial.begin(9600);

  while (!Serial)
   delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("SHTC3 test");
  if (! shtc3.begin()) {
    Serial.println("Couldn't find SHTC3");
    while (1) delay(1);
  }
  Serial.println("Found SHTC3 sensor");
  Serial.println(irrigationInterval);
}

void loop() {
  // put your main code here, to run repeatedly:

  sensors_event_t humidity, temp;
  shtc3.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  lightSensPin = analogRead(A2); 
  Serial.println(lightSensPin);

  
  if (lightSensPin < lightThreshold){
      pixels.fill(pixels.Color(255, 0, 255), 0, 64);
      pixels.show(); 
  }
  else {
      pixels.fill(pixels.Color(0, 0, 0), 0, 64);
      pixels.show();
  }

  if (lowWaterPin == HIGH) {
     digitalWrite(refillValve, LOW);
       while (highWaterPin== HIGH) {
         delay(1000);
       }
     digitalWrite(refillValve, HIGH);  
   }
temperature = temp.temperature;
humidity1 = humidity.relative_humidity;
Serial.println(temperature);
Serial.println(humidity1);
   
  if (temperature > 29) {
     servoOne.write(30);
     delay(2500);
     digitalWrite(fanPin, LOW);
     digitalWrite(pumpPin, LOW);
     digitalWrite(heaterPin, LOW);
   }
   else if (temperature> 24 & humidity1 < 50){
     servoOne.write(30);
     delay(2500);
     digitalWrite(fanPin, LOW);
     digitalWrite(pumpPin, LOW);
      digitalWrite(heaterPin, LOW);
   }
   else if (temperature> 24) {
     servoOne.write(30);
     delay(2500);
     digitalWrite(fanPin, LOW); 
     digitalWrite(heaterPin, LOW);
     digitalWrite(pumpPin, HIGH);
     
   }
   else if (temperature < 22) {
     servoOne.write(120);
     delay(2500);
     digitalWrite(heaterPin, HIGH);
     digitalWrite(pumpPin, HIGH);
     digitalWrite(fanPin, HIGH);
   }
   else{
     servoOne.write(75);
     delay(2500);
     digitalWrite(fanPin, HIGH);
     digitalWrite(heaterPin, LOW);
     digitalWrite(pumpPin, HIGH);
   }

  minutes1 = millis()/60/1000-minutes2;
Serial.println(minutes1);
  if(minutes1 >= irrigationInterval & irrigationStatus == 0) {
    minutes2 = minutes2+360;
    irrigationStatus =1;
    digitalWrite(irrigationPin, LOW);
  }
  else if(minutes1>=irrigationTime & irrigationStatus == 1) {
    minutes2 = minutes2+1;
    irrigationStatus=0;
    digitalWrite(irrigationPin, HIGH);
  }
 

    
}
