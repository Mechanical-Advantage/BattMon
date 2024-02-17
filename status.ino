#include <FastLED.h>

#define NUM_LEDS 3
#define NUM_SENSORS 3

#define DATA_PIN 10

#define LIGHT_SENSOR_PIN_0 A15
#define LIGHT_SENSOR_PIN_1 A14
#define LIGHT_SENSOR_PIN_2 A13


CRGB leds[NUM_LEDS];
uint8_t light_sensor_pins[NUM_SENSORS] = {A15, A14, A13};

void setup() {
  // Setup LEDs
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  for(int i = 0; i<NUM_SENSORS; i++) {
    // Setup light sensor
    pinMode(light_sensor_pins[i], INPUT);
  }

  //Setup console
  Serial.begin(9600); //begin Serial Communication
}

// the loop function runs over and over again forever
void loop() {
  for(int i=0; i<NUM_SENSORS; i++)
  {
    int raw_light = analogRead(light_sensor_pins[i]); // read the raw value from light_sensor pin (A3)
    int light = map(raw_light, 0, 1023, 0, 100); // map the value from 0, 1023 to 0, 100
    Serial.print(String(light_sensor_pins[i]));
    Serial.println("Sensor [" +  String(i) + "]" + String(light)); 
    
    if (light>45){
      leds[i] = CRGB::Purple;
      delay(30);
    }
    else {
      leds[i] = CRGB::Black;
      delay(30);
    }
  }
  FastLED.show();
}
  
