#include "FastLED.h"
#include <AudioAnalyzer.h>

Analyzer Audio = Analyzer(4,5,5);//Strobe pin ->4  RST pin ->5 Analog Pin ->5
//Analyzer Audio = Analyzer();//Strobe->4 RST->5 Analog->0
 
int FreqVal[7];// Read Stored Values 
int LedFreq[7];// Mapped read values to control num leds on 

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
  Serial.begin(57600);
  //Analyzer Initialization
  Audio.Init();//Init module  

  //Matrix Initialization
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  //Switch Initialization
  pinMode(SWITCH, INPUT); 
   

}

void loop() {
//Analyzer Driver

Audio.ReadFreq(FreqVal);//Return 7 values of 7 bands pass filiter
                          //Frequency(Hz):63  160  400  1K  2.5K  6.25K  16K
                          //FreqVal[]:      0    1    2    3    4    5    6  
  for(int i=0;i<7;i++)            
  {
    FreqVal[i] = FreqVal[i]-100;
    LedFreq[i] = map(max(FreqVal[i],0), 0, 350, 0, 16);  
    LedFreq[i] = constrain(LedFreq[i], 0, 16); 
    Serial.print(LedFreq[i]);
    if(i<6)  Serial.print(",");
    else Serial.println();
  }

//Led Driver  
////band 1 
    leds(BAND_1_start,BAND_1_start+LedFreq[0]) = CRGB::Red; 
    leds(BAND_1_stop,BAND_1_stop-LedFreq[0])   = CRGB::Red; 
////band 2
    leds(BAND_2_start,BAND_2_start+LedFreq[1]) = CRGB::Blue; 
    leds(BAND_2_stop,BAND_2_stop-LedFreq[1])   = CRGB::Blue; 
////band 3
    leds(BAND_3_start,BAND_3_start+LedFreq[2]) = CRGB::White; 
    leds(BAND_3_stop,BAND_3_stop-LedFreq[2])   = CRGB::White; 
////band 4
    leds(BAND_4_start,BAND_4_start+LedFreq[3]) = CRGB::Yellow; 
    leds(BAND_4_stop,BAND_4_stop-LedFreq[3])   = CRGB::Yellow; 
//band 5
    leds(BAND_5_start,BAND_5_start+LedFreq[4]) = CRGB::Purple; 
    leds(BAND_5_stop,BAND_5_stop-LedFreq[4])   = CRGB::Purple; 
//band 6
    leds(BAND_6_start,BAND_6_start+LedFreq[5]) = CRGB::Green; 
    leds(BAND_6_stop,BAND_6_stop-LedFreq[5])   = CRGB::Green; 
////band 7
      leds(BAND_7_start,BAND_7_start+LedFreq[6]) = CRGB::Orange; 
      leds(BAND_7_stop,BAND_7_stop-LedFreq[6])   = CRGB::Orange;  

FastLED.show();

delay(60); //Sampling Rate

FastLED.clear();   
}
