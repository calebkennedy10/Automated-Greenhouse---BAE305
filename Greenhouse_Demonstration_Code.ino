#include <Servo.h>

String temperature;
String RH;
String light;
String irrigation;


int temperatureInput;
int RHInput;
int lightInput;
int irrigationInput;


int lowWaterPin = 2;
int highWaterPin = 4;
int refillValve = 5;
int heaterPin = 7;
int pumpPin = 8;
int fanPin = 12;
int irrigationPin = 13;
int ventOne = 9;


Servo servoOne;

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

  digitalWrite(refillValve, HIGH);
  digitalWrite(heaterPin, LOW);
  digitalWrite(pumpPin, HIGH);
  digitalWrite(fanPin, HIGH);
  digitalWrite(irrigationPin, HIGH);
  
  servoOne.attach(ventOne);
 // servoTwo.attach(ventTwo);
 // servoThree.attach(ventThree);

  servoOne.write(120);
 // servoTwo.write(0);
 // servoThree.write(0);

  Serial.begin(9600);
  
  Serial.println("Enter demo parameters.");
  Serial.println("Seperate parameter values with commmas. Only input integers");
  Serial.println("Input order: Temperature, Relative Humidity, Light Status, Irrigation Status");
  Serial.println("Appropriate input values:");
  Serial.println("  Temperature: Anything in Degrees Fahrenheit");
  Serial.println("  Relative Humidity: 0-100");
  Serial.println("  Light Status: 1 = Turn on, 0 = Turn off");
  Serial.println("  Irrigation Status: 1 = Turn on, 0 = Turn off");
  Serial.println("Example Input: 80,60,1,1");
  
}

void loop() {
  // put your main code here, to run repeatedly
  if (Serial.available()>0) {
    
    temperature = Serial.readStringUntil(',');
    RH = Serial.readStringUntil(',');
    light = Serial.readStringUntil(',');
    irrigation = Serial.readStringUntil(',');
    

    temperatureInput = temperature.toInt();
    RHInput = RH.toInt();
    lightInput = light.toInt();
    irrigationInput = irrigation.toInt();
    

      if (lightInput == 1) {
        pixels.fill(pixels.Color(255, 0, 255), 0, 64);
        pixels.show();    
      }
      else {
        pixels.fill(pixels.Color(0, 0, 0), 0, 64);
        pixels.show();
      }

      if (irrigationInput == 1) {
        digitalWrite(irrigationPin, LOW);
      }
      else {
        digitalWrite(irrigationPin, HIGH);
      }


      if (lowWaterPin == HIGH) {
        digitalWrite(refillValve, LOW);
          while (highWaterPin==HIGH) {
            delay(1000);
          }
        digitalWrite(refillValve, HIGH);  
      }


      if (temperatureInput > 85) {
        servoOne.write(30);
        delay(2500);
        digitalWrite(fanPin, LOW);
        digitalWrite(pumpPin, LOW);
        digitalWrite(heaterPin, LOW);
      }
      else if (temperatureInput > 75 & RHInput< 50){
        servoOne.write(30);
        delay(2500);
        digitalWrite(fanPin, LOW);
        digitalWrite(pumpPin, LOW);
        digitalWrite(heaterPin, LOW);
      }
      else if (temperatureInput > 75) {
        servoOne.write(30);
        delay(2500);
        digitalWrite(fanPin, LOW);
        digitalWrite(heaterPin, LOW);
        digitalWrite(pumpPin, HIGH);
      }
      else if (temperatureInput < 55) {
        servoOne.write(120);
        delay(2500);
        digitalWrite(heaterPin, HIGH);
        digitalWrite(fanPin, HIGH);
        digitalWrite(pumpPin, HIGH);
      }
      else{
        servoOne.write(120);
        delay(2500);
        digitalWrite(fanPin, HIGH);
        digitalWrite(heaterPin, LOW);
        digitalWrite(pumpPin, HIGH);
      }
