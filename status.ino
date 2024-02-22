#include <FastLED.h>

#define NUM_LEDS 15
#define NUM_SENSORS 15
#define DATA_PIN 10
#define DEFAULT_THRESH 8
#define LED_BRIGHTNESS 30

CRGB leds[NUM_LEDS];
uint8_t light_sensor_pins[NUM_SENSORS] = {A1, A2, A3, A6, A5, A4, A7, A8, A9, A12, A11, A10, A13, A14, A15};
int thresh[NUM_SENSORS];

void setup() {
  // Setup LEDs
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5,300);
  FastLED.setBrightness(LED_BRIGHTNESS);
  
  for(int i = 0; i<NUM_SENSORS; i++) {
    // Setup light sensor
    pinMode(light_sensor_pins[i], INPUT);
  }

  //Setting thresh values
  for(int i = 0; i<NUM_SENSORS; i++) {
    // Set light sensor threshold
    thresh[i] = DEFAULT_THRESH;
  }

//Set modified thresh values here
thresh[7, 8, 9] = 4;

  //Setup console
  Serial.begin(9600); //begin Serial Communication
}

// the loop function runs over and over again forever
void loop() {
  for(int i=0; i<NUM_SENSORS; i++)
  {
    int raw_light = analogRead(light_sensor_pins[i]); // read the raw value from light_sensor pin
    int light = map(raw_light, 0, 1023, 0, 100); // map the value from 0, 1023 to 0, 100
    Serial.print(String(light_sensor_pins[i]));
    Serial.println("Sensor [" +  String(i) + "]" + String(light)); 
    
    if (light>=thresh[i]){
      leds[i] = CRGB::Green;
    }
    else {
      leds[i] = CRGB::Red;
    }
  }
  FastLED.show();
  delay(30);
}
  
