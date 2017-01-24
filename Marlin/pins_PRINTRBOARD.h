/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Printrboard pin assignments (AT90USB1286)
 * Requires the Teensyduino software with Teensy++ 2.0 selected in Arduino IDE!
 * http://www.pjrc.com/teensy/teensyduino.html
 * See http://reprap.org/wiki/Printrboard for more info
 */

#ifndef __AVR_AT90USB1286__
  #error "Oops!  Make sure you have 'Teensy++ 2.0' selected from the 'Tools -> Boards' menu."
#endif

//#if ENABLED(AT90USBxx_TEENSYPP_ASSIGNMENTS)  // use Teensyduino Teensy++2.0 pin assignments instead of Marlin traditional.
//  #error "These Printrboard assignments depend on traditional Marlin assignments, not AT90USBxx_TEENSYPP_ASSIGNMENTS in fastio.h"
//#endif

#define BOARD_NAME         "Printrboard"

#define USBCON 1286  // Disable MarlinSerial etc.
#define LARGE_FLASH        true

// Disable JTAG pins so they can be used for the Extrudrboard
#define DISABLE_JTAG       true

//
// Limit Switches
//
#define X_STOP_PIN         47
#define Y_STOP_PIN         37 // Move Ystop to Estop socket
#define Z_STOP_PIN         36
#ifndef Z_MIN_PROBE_PIN
	#define Z_MIN_PROBE_PIN	   20
#endif
//
// Steppers
//
#define X_STEP_PIN         28
#define X_DIR_PIN          29
#define X_ENABLE_PIN       19

#define Y_STEP_PIN         30
#define Y_DIR_PIN          31
#define Y_ENABLE_PIN       18

#define Z_STEP_PIN         32
#define Z_DIR_PIN          33
#define Z_ENABLE_PIN       17

#define E0_STEP_PIN        34
#define E0_DIR_PIN         35
#define E0_ENABLE_PIN      13

//
// Temperature Sensors
//
#define TEMP_0_PIN          1   // Analog Input
#define TEMP_BED_PIN        0   // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN       15 // Extruder
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1
#define HEATER_BED_PIN     14

// If soft or fast PWM is off then use Teensyduino pin numbering, Marlin
// fastio pin numbering otherwise
#if ENABLED(FAN_SOFT_PWM) || ENABLED(FAST_PWM_FAN)
  #define FAN_PIN          22
#else
  #define FAN_PIN          16
#endif

//
// Misc. Functions
//
#define SDSS               40
#define FILWIDTH_PIN       -1   // Analog Input

//
// LCD / Controller
//
#if ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL)
  // we have no buzzer installed
  #define BEEPER_PIN -1 //45

  // LCD Pins
  #if ENABLED(LCD_I2C_PANELOLU2)
    #define BTN_EN1 10 // RX1 - fastio.h pin mapping 27
    #define BTN_EN2 11 // TX1 - fastio.h pin mapping 26
    #define BTN_ENC 12 // A3 - fastio.h pin mapping 43
    #define SDSS    40 // use SD card on Panelolu2 (Teensyduino pin mapping)
  #else
    #define BTN_EN1 10
    #define BTN_EN2 11
    #define BTN_ENC 12 // the click
	#define SDSS    40
  #endif // LCD_I2C_PANELOLU2

  // not connected to a pin
  #define SD_DETECT_PIN -1

  #define LCD_PINS_RS 8
  #define LCD_PINS_ENABLE 9
  #define LCD_PINS_D4 4
  #define LCD_PINS_D5 5
  #define LCD_PINS_D6 6
  #define LCD_PINS_D7 7

#endif // ULTRA_LCD && NEWPANEL
