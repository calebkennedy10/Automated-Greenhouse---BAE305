/*
 * EE 305 Project Greenhouse Master Code
 * Automates aspects of the greenhouse
 * Authors: Caleb Kennedy, 
*/


//variable setup

int lightSensPin = A0;    // photresistor pin
int lightThreshold = 550;    // photoresister threshold to turn on lights

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define LED_PIN 2
#define NUMPIXELS 64

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500


/********************************************************************************/
void setup() 
{
 
  Serial.begin(9600);   // begin serial communication with the computer

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif

  pixels.begin();
  
}


void loop() 
{
  lightSensPin = analogRead(A0);    // measure photoresistor
  Serial.println(lightSensPin);
  if (lightSensPin < lightThreshold)
    {
      pixels.fill(pixels.Color(255, 255, 255), 0, 64);
      pixels.show(); 
    }
  else 
    {
      pixels.clear();
      pixels.show();
    }
}
