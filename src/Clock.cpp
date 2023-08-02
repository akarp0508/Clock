#include "Clock.h"
#include <FastLED.h>

// All digits in segments.
const bool digitSegments[10][7] = {
    // A,  B,  C,  D,  E,  F,  G
    {  1,  1,  1,  1,  1,  1,  0 }, // Digit 0
    {  0,  1,  1,  0,  0,  0,  0 }, // Digit 1
    {  1,  1,  0,  1,  1,  0,  1 }, // Digit 2
    {  1,  1,  1,  1,  0,  0,  1 }, // Digit 3
    {  0,  1,  1,  0,  0,  1,  1 }, // Digit 4
    {  1,  0,  1,  1,  0,  1,  1 }, // Digit 5
    {  1,  0,  1,  1,  1,  1,  1 }, // Digit 6
    {  1,  1,  1,  0,  0,  0,  0 }, // Digit 7
    {  1,  1,  1,  1,  1,  1,  1 }, // Digit 8
    {  1,  1,  1,  1,  0,  1,  1 }  // Digit 9
};

const int DIGIT_SEGMENTS[4][7] = {
    // A,  B,  C,  D,  E,  F,  G
    {  9,  8, 12, 13, 14, 10, 11 }, // 1st digit
    {  2,  1,  5,  6,  7,  3,  4 }, // 2nd digit
    {  6,  7,  3,  2,  1,  5,  4 }, // 3rd digit
    { 13, 14, 10,  9,  8, 12, 11 }  // 4th digit
};

CRGB leds0[NUM_LEDS0];
CRGB leds1[NUM_LEDS1];



void Clock::setup() {
  // Initialize clock settings, e.g., from EEPROM or LittleFS
  FastLED.addLeds<NEOPIXEL, DATA_PIN0>(leds0, NUM_LEDS0);
  FastLED.addLeds<NEOPIXEL, DATA_PIN1>(leds1, NUM_LEDS1);
  leds0[0]=CRGB::Green;
  leds1[0]=CRGB::Green;
  FastLED.show();
}

void Clock::displayDigits(const char* digits) {
  // Check if the input digits string is valid
  if (digits == nullptr) {
    // Invalid input, return without doing anything
    return;
  }

  // Iterate through the digits and update the corresponding LED strip
  for (int i = 0; i < 4; i++) {
    char digit = digits[i];

    // Determine the LED strip based on the digit position
    CRGB* ledStrip = nullptr;
    if (i < 2) {
      ledStrip = leds1; // Use leds1 for digits 1 and 2
    } else {
      ledStrip = leds0; // Use leds0 for digits 3 and 4
    }

    // Check if the digit is a valid number ('0' to '9')
    if (digit >= '0' && digit <= '9') {
      // Get the segments for the current digit from the const table
      const bool* segments = digitSegments[digit - '0'];

      // Update the segments accordingly
      for (int j = 0; j < 7; j++) {
        if (segments[j]) 
          // Set the segment to the desired color
          ledStrip[DIGIT_SEGMENTS[i][j]] = CRGB(r, g, b);
        else
          ledStrip[DIGIT_SEGMENTS[i][j]] = CRGB(0, 0, 0);

      }
    } else {
      // Handle any unsupported or invalid digits or symbols
      // You can add a default behavior here, like displaying a specific symbol.
    }
  }

  // Show the updated LED strips
  FastLED.show();
}

void Clock::setColor(int8_t r,int8_t g,int8_t b){
  this->r=r;
  this->g=g;
  this->b=b;
}
  
void Clock::flickColon(){

}