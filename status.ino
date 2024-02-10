#include <FastLED.h>

#define NUM_LEDS 2
#define DATA_PIN 13
#define LIGHT_SENSOR_PIN A0

CRGB leds[NUM_LEDS];

void setup() {
  // Setup LEDs
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  // Setup light sensor
  pinMode(LIGHT_SENSOR_PIN, INPUT);

  //Setup console
  Serial.begin(9600); //begin Serial Communication
}

// the loop function runs over and over again forever
void loop() {

  int raw_light = analogRead(LIGHT_SENSOR_PIN); // read the raw value from light_sensor pin (A3)
  int light = map(raw_light, 0, 1023, 0, 100); // map the value from 0, 1023 to 0, 100
 
  Serial.print("Light level: "); 
  Serial.println(light); // print the light value in Serial Monitor
  
  if (light>60){
    leds[0] = CRGB::Green;
    FastLED.show();
    delay(30);
  }
  else {
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(30);
  }
  
}
  
