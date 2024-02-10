#include <FastLED.h>

#define NUM_LEDS 2
#define DATA_PIN 13


CRGB leds[NUM_LEDS];
void setup() { FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); }
void loop() {
  
  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB::Red; 
  }
  FastLED.show(); 
  delay(30);
  
  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB::Blue; 
  }
  
  FastLED.show(); 
  delay(30);
}
//// the setup function runs once when you press reset or power the board
//int light_sensor = A0; 
//void setup() {
//  // initialize digital pin LED_BUILTIN as an output.
//  pinMode(LED_BUILTIN, OUTPUT);
//  pinMode(A1, INPUT);
//  Serial.begin(9600); //begin Serial Communication
//}
//
//// the loop function runs over and over again forever
//void loop() {
////  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
////  delay(200);                      // wait for a second
////  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
////  delay(1000); 
//  int raw_light = analogRead(light_sensor); // read the raw value from light_sensor pin (A3)
//  int light = map(raw_light, 0, 1023, 0, 100); // map the value from 0, 1023 to 0, 100
// 
//  Serial.print("Light level: "); 
//  Serial.println(light); // print the light value in Serial Monitor
//  
//  if (light>60){
//    digitalWrite(LED_BUILTIN, HIGH);
//  }
//  else {
//    digitalWrite(LED_BUILTIN, LOW);
//  }
//  delay(500); // add a delay to only read and print every 1 second// wait for a second
//  
//}
//
//
// 
//
//  
//
