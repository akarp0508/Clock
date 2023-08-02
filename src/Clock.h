#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS0 15
#define NUM_LEDS1 15
#define DATA_PIN0 D6
#define DATA_PIN1 D7

class Clock {
public:
  void setup();
  void displayDigits(const char* digits);
  void setColor(int8_t r,int8_t g,int8_t b);
  void flickColon();

private:
  int8_t r;
  int8_t g;
  int8_t b;
  int8_t brightness;
  bool autoBrightness;
};

#endif // CLOCK_H
