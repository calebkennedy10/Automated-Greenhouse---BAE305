
#include <Servo.h>

String temperature;
String RH;
String light;
String irrigation;
String duration;

int temperatureInput;
int RHInput;
int lightInput;
int irrigationInput;
int durationInput;

int lowWaterPin = 2;
int highWaterPin = 4;
int refillValve = 5;
// int LEDPin = 6;
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

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define LED_PIN 3
#define NUMPIXELS 64

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500


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
  
  Serial.println("Enter demo parameters.");
  Serial.println("Seperate parameter values with commmas. Only input integers");
  Serial.println("Input order: Temperature, Relative Humidity, Light Status, Irrigation Status, Demo Duration");
  Serial.println("Appropriate input values:");
  Serial.println("  Temperature: Anything in Degrees Fahrenheit");
  Serial.println("  Relative Humidity: 0-100");
  Serial.println("  Light Status: 1 = Turn on, 0 = Turn off");
  Serial.println("  Irrigation Status: 1 = Turn on, 0 = Turn off");
  Serial.println("  Demo Duration: Length of Demonstration in Seconds");
  Serial.println("Example Input: 80,60,1,1,45");
  
}

void loop() {
  // put your main code here, to run repeatedly
  if (Serial.available()>0) {
    
    temperature = Serial.readStringUntil(',');
    RH = Serial.readStringUntil(',');
    light = Serial.readStringUntil(',');
    irrigation = Serial.readStringUntil(',');
    duration = Serial.readStringUntil(',');

    temperatureInput = temperature.toInt();
    RHInput = RH.toInt();
    lightInput = light.toInt();
    irrigationInput = irrigation.toInt();
    durationInput = duration.toInt();

      if (lightInput == 1) {
        pixels.fill(pixels.Color(255, 0, 255), 0, 64);
        pixels.show();    
      }
      else {
        pixels.fill(pixels.Color(0, 0, 0), 0, 64);
        pixels.show();
      }

      if (irrigationInput == 1) {
        digitalWrite(irrigationPin, HIGH);
      }
      else {
        digitalWrite(irrigationPin, LOW);
      }

/*
      if (lowWaterPin == HIGH) {
        digitalWrite(refillValve, HIGH);
          while (highWaterPin==LOW) {
            delay(1000);
          }
        digitalWrite(refillValve, LOW);  
      }

*/

      if (temperatureInput > 85) {
        servoOne.write(90);
        delay(2500);
        servoTwo.write(90);
        delay(2500);
        servoThree.write(90);
        delay(2500);
        digitalWrite(fanPin, HIGH);
        digitalWrite(pumpPin, LOW);
      }
      else if (temperatureInput > 75 & RHInput< 50){
        servoOne.write(90);
        delay(2500);
        servoTwo.write(90);
        delay(2500);
        servoThree.write(90);
        delay(2500);
        digitalWrite(fanPin, HIGH);
        digitalWrite(pumpPin, LOW);
      }
      else if (temperatureInput > 75) {
        servoOne.write(90);
        delay(2500);
        servoTwo.write(90);
        delay(2500);
        servoThree.write(90);
        delay(2500);
        digitalWrite(fanPin, HIGH);
      }
      else if (temperatureInput < 55) {
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
delay(durationInput*1000);
}
}
