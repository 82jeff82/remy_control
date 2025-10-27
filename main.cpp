#include "pico/stdlib.h"

#include "servo2040.hpp"

/*
Demonstrates how to create a Servo object and control it.
*/

using namespace servo;

// The time in milliseconds between each step of the sequence
const uint STEPS_INTERVAL_MS = 5;

// How far from zero to move the servo when sweeping
constexpr float SWEEP_EXTENT = 45.0f;


// Create a servo on pins 0 and 1
Servo s1 = Servo(servo2040::SERVO_1);
Servo s2 = Servo(servo2040::SERVO_2);



int main() {
  stdio_init_all();

  // Initialise the servo
  s1.init();
  s2.init();

  // Enable the servo (this puts it at the middle)
  s1.enable();
  s2.enable();
  sleep_ms(2000);

  while (1)
  {
    // Do a sine sweep
    for(auto i = 0u; i < 360; i++) {
      s1.value(sin(((float)i * (float)M_PI) / 180.0f) * SWEEP_EXTENT);
      s2.value(sin(((float)i * (float)M_PI) / 180.0f) * SWEEP_EXTENT);
      sleep_ms(STEPS_INTERVAL_MS);
    }
  }

  // Disable the servo
  s1.disable();
  s2.disable();
}
