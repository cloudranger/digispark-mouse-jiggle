/*
 *  NAME: Digispark (ATTiny85) Mouse Jiggler
 *  DESC: Keep your computer awake and unlocked by jiggling the mouse
 *  VERSION: 1.0
 *  DATE: 2022-02-05 
 *  AUTHOR: cloudranger.ch
 */

#include <DigiMouse.h>

// Max delay that can be used in delay() is 16383 - 16 seconds

int sleep = 15000; // Sleep time between mouse jiggles
int led_lit = 100; // Keep the led lit for this many milliseconds

//int led = 0; // Model B
int led = 1; // Model A or Pro


void setup()
{
  pinMode(led, OUTPUT);
  DigiMouse.begin(); 
}

void loop()
{
  DigiMouse.delay(sleep);
  digitalWrite(led, HIGH);   // turn the LED on
  DigiMouse.moveX(1);
  DigiMouse.moveX(-1);
  DigiMouse.delay(led_lit);
  digitalWrite(led, LOW);   // turn the LED off
}
