#include <FastLED.h>

#define NUM_LEDS 15
#define NUM_SENSORS 15
#define DATA_PIN 10
#define DEFAULT_THRESH 10
#define LED_BRIGHTNESS 30
#define MAX_TICKS 500
#define LOOP_DELAY 30

CRGB leds[NUM_LEDS];
uint8_t light_sensor_pins[NUM_SENSORS] = {A1, A2, A3, A6, A5, A4, A7, A8, A9, A12, A11, A10, A13, A14, A15};
int thresh[NUM_SENSORS];
unsigned long startTime;
unsigned long stopTime;
int greenTicks[NUM_SENSORS] = {0};
int redTicks[NUM_SENSORS] = {0};

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

  for (int i=0; i<NUM_SENSORS; i++) {
    redTicks[i] = {MAX_TICKS};
  }

//Set modified thresh values here

  //Setup console
  Serial.begin(9600); //begin Serial Communication
}
// the loop function runs over and over again forever

void loop() {
  for(int i=0; i<NUM_SENSORS; i++)
  {
    int raw_light = analogRead(light_sensor_pins[i]); // read the raw value from light_sensor pin
    int light = map(raw_light, 0, 1023, 0, 100); // map the value from 0, 1023 to 0, 100
    //Serial.print(String(light_sensor_pins[i]));
    //Serial.println("Sensor [" +  String(i) + "]" + String(light)); 
    
    if (light>=thresh[i]){
      if (redTicks[i]>0) {
       redTicks[i] = 0;
      }
      greenTicks[i]++;
    }
    else {
      if (greenTicks[i]>0) {
       greenTicks[i] = 0;
      }
       redTicks[i]++;
    }
    
    if (greenTicks[i]>=MAX_TICKS) {
        leds[i] = CRGB::Green;
        greenTicks[i] = MAX_TICKS;
        if (i==2) {
          Serial.println("Sensor [" + String(i) + "] reset: Green");
        }
    }
    else if (redTicks[i]>=MAX_TICKS) {
        leds[i] = CRGB::Red;
        redTicks[i] = MAX_TICKS;
        if (i==2) {
          Serial.println("Sensor [" + String(i) + "] reset: Red");
        }
    }
    else {
      leds[i] = CRGB(255, 96, 0); //Change this to add different state color
    }
  }
  FastLED.show();
  delay(LOOP_DELAY);
}
  
