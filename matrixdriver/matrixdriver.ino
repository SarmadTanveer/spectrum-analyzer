#include "FastLED.h"

// Matrix size
#define NUM_ROWS 16
#define NUM_COLS 16

// LEDs pin
#define DATA_PIN 6

//Switch 
#define SWITCH 3

// LED brightness
#define BRIGHTNESS 30

//Number of LEDs 
#define NUM_LEDS NUM_ROWS * NUM_COLS

//First Band 
#define BAND_1_start 16
#define BAND_1_stop  47

//Second Band 
#define BAND_2_start 48
#define BAND_2_stop  79

//Third Band 
#define BAND_3_start 80
#define BAND_3_stop  111

//Fourth Band 
#define BAND_4_start 112
#define BAND_4_stop  143

//Fifth Band 
#define BAND_5_start 144
#define BAND_5_stop  175

//Sixth Band 
#define BAND_6_start 176
#define BAND_6_stop  207

//Seventh Band 
#define BAND_7_start 208
#define BAND_7_stop  239


// Define the array of leds
CRGBArray<NUM_LEDS> leds;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(SWITCH, INPUT); 
   
}
 
void loop() { 
  int randomNumber[7]; 
  for(int i= 0; i<7; i++){
    randomNumber[i] = random(0,16);
    }
////band 1 
    leds(BAND_1_start,BAND_1_start+randomNumber[0]) = CRGB::Red; 
    leds(BAND_1_stop,BAND_1_stop-randomNumber[0])   = CRGB::Red; 
////band 2
    leds(BAND_2_start,BAND_2_start+randomNumber[1]) = CRGB::Blue; 
    leds(BAND_2_stop,BAND_2_stop-randomNumber[1])   = CRGB::Blue; 
////band 3
    leds(BAND_3_start,BAND_3_start+randomNumber[2]) = CRGB::Pink; 
    leds(BAND_3_stop,BAND_3_stop-randomNumber[2])   = CRGB::Pink; 
////band 4
    leds(BAND_4_start,BAND_4_start+randomNumber[3]) = CRGB::Red; 
    leds(BAND_4_stop,BAND_4_stop-randomNumber[3])   = CRGB::Red; 
//band 5
    leds(BAND_5_start,BAND_5_start+randomNumber[4]) = CRGB::Blue; 
    leds(BAND_5_stop,BAND_5_stop-randomNumber[4])   = CRGB::Blue; 
//band 6
    leds(BAND_6_start,BAND_6_start+randomNumber[5]) = CRGB::Pink; 
    leds(BAND_6_stop,BAND_6_stop-randomNumber[5])   = CRGB::Pink; 
////band 7
      leds(BAND_7_start,BAND_7_start+randomNumber[6]) = CRGB::Red; 
      leds(BAND_7_stop,BAND_7_stop-randomNumber[6])   = CRGB::Red;  
FastLED.show();
delay(500); 
FastLED.clear();   
}
  
