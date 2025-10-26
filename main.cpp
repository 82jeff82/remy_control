// #include "pico_explorer.hpp"
// #include "drivers/st7789/st7789.hpp"
// #include "libraries/pico_graphics/pico_graphics.hpp"

// using namespace pimoroni;

// ST7789 st7789(PicoExplorer::WIDTH, PicoExplorer::HEIGHT, ROTATE_0, false, get_spi_pins(BG_SPI_FRONT));
// PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);

// int main() {
//     graphics.set_pen(255, 0, 0);

//     while(true) {
//         graphics.pixel(Point(0, 0));

//         // now we've done our drawing let's update the screen
//         st7789.update(&graphics);
//     }
// }

// #endif


#include "pico/stdlib.h"

#include "servo2040.hpp"

/*
Demonstrates how to create a Servo object and control it.
*/

using namespace servo;

// How many sweeps of the servo to perform
const uint SWEEPS = 3;

// The number of discrete sweep steps
const uint STEPS = 10;

// The time in milliseconds between each step of the sequence
const uint STEPS_INTERVAL_MS = 500;

// How far from zero to move the servo when sweeping
constexpr float SWEEP_EXTENT = 90.0f;


// Create a servo on pin 0
Servo s = Servo(servo2040::SERVO_1);


int main() {
  stdio_init_all();

  // Initialise the servo
  s.init();

  // Enable the servo (this puts it at the middle)
  s.enable();
  sleep_ms(2000);

  // Go to min
  s.to_min();
  sleep_ms(2000);

  // Go to max
  s.to_max();
  sleep_ms(2000);

  // Go back to mid
  s.to_mid();
  sleep_ms(2000);

  // Do a sine sweep
  for(auto j = 0u; j < SWEEPS; j++) {
    for(auto i = 0u; i < 360; i++) {
      s.value(sin(((float)i * (float)M_PI) / 180.0f) * SWEEP_EXTENT);
      sleep_ms(20);
    }
  }

  // Do a stepped sweep
  for(auto j = 0u; j < SWEEPS; j++) {
    for(auto i = 0u; i < STEPS; i++) {
      s.to_percent(i, 0, STEPS, 0.0 - SWEEP_EXTENT, SWEEP_EXTENT);
      sleep_ms(STEPS_INTERVAL_MS);
    }
    for(auto i = 0u; i < STEPS; i++) {
      s.to_percent(i, STEPS, 0, 0.0 - SWEEP_EXTENT, SWEEP_EXTENT);
      sleep_ms(STEPS_INTERVAL_MS);
    }
  }

  // Disable the servo
  s.disable();
}
