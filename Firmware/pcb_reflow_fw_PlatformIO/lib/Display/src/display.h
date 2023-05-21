#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <controll.h>
#include <preference.h>


#define MAX_RESISTANCE 10.0
// Screen Definitions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define SCREEN_ADDRESS 0x3C // I2C Address

// Solder Reflow Plate Logo
static const uint8_t PROGMEM logo[] = {
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x80, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x31, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x1f, 0xe0, 0x03, 0x01, 0x80, 0x00, 0x00, 0x30, 0x70, 0x00, 0x21, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x20, 0x03, 0x00, 0xc7, 0x80, 0x00, 0x20,
    0x18, 0xf0, 0x61, 0x80, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03, 0x3e,
    0xcc, 0xc0, 0xc0, 0x04, 0x19, 0x98, 0x61, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x1c, 0x01, 0xf3, 0x77, 0xd8, 0xc7, 0xe0, 0x06, 0x33, 0x18, 0x61, 0x8f,
    0x88, 0x00, 0x00, 0x00, 0x06, 0x03, 0x3b, 0x61, 0xd0, 0xc6, 0x00, 0x07,
    0xe2, 0x18, 0x61, 0x98, 0xd8, 0x04, 0x00, 0x00, 0x01, 0xc6, 0x0b, 0x60,
    0xd9, 0x86, 0x00, 0x06, 0x03, 0x30, 0xff, 0xb0, 0x78, 0x66, 0x00, 0x00,
    0x40, 0xe4, 0x0f, 0x60, 0xdf, 0x06, 0x00, 0x07, 0x03, 0xe0, 0x31, 0xe0,
    0x78, 0x62, 0x00, 0x00, 0x40, 0x3c, 0x0f, 0x61, 0xd8, 0x06, 0x00, 0x07,
    0x83, 0x00, 0x31, 0xe0, 0x78, 0x63, 0x00, 0x00, 0x60, 0x36, 0x1b, 0x63,
    0xc8, 0x02, 0x00, 0x02, 0xc1, 0x00, 0x18, 0xb0, 0xcc, 0xe2, 0x00, 0x00,
    0x30, 0x33, 0x3b, 0x36, 0x4e, 0x03, 0x00, 0x02, 0x61, 0xc0, 0x0c, 0x99,
    0xcd, 0xfe, 0x00, 0x00, 0x0f, 0xe1, 0xe1, 0x3c, 0x03, 0xf3, 0x00, 0x02,
    0x38, 0x7e, 0x0c, 0x8f, 0x07, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7f, 0x84, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe4, 0x00, 0x18,
    0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x3c, 0x3c, 0x18, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x1e, 0x06, 0x7f, 0xc6, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x3e, 0x03, 0x18,
    0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x36, 0x7f, 0x19, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0xe6, 0xc7, 0x19, 0xf8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x83, 0x18,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x06, 0x07, 0x81, 0x18, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0xc3, 0x98, 0x70, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x7e, 0x08,
    0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const uint8_t logo_width = 128;
static const uint8_t logo_height = 27;

// Heating Animation
static const uint8_t PROGMEM heat_animate[] = {
    0b00000001, 0b00000000, 0b00000001, 0b10000000, 0b00000001, 0b10000000,
    0b00000001, 0b01000000, 0b00000010, 0b01000000, 0b00100010, 0b01000100,
    0b00100100, 0b00100100, 0b01010101, 0b00100110, 0b01001001, 0b10010110,
    0b10000010, 0b10001001, 0b10100100, 0b01000001, 0b10011000, 0b01010010,
    0b01000100, 0b01100010, 0b00100011, 0b10000100, 0b00011000, 0b00011000,
    0b00000111, 0b11100000};
static const uint8_t heat_animate_width = 16;
static const uint8_t heat_animate_height = 16;

// Tick
static const uint8_t PROGMEM tick[] = {
    0b00000000, 0b00000100, 0b00000000, 0b00001010, 0b00000000, 0b00010101,
    0b00000000, 0b00101010, 0b00000000, 0b01010100, 0b00000000, 0b10101000,
    0b00000001, 0b01010000, 0b00100010, 0b10100000, 0b01010101, 0b01000000,
    0b10101010, 0b10000000, 0b01010101, 0b00000000, 0b00101010, 0b00000000,
    0b00010100, 0b00000000, 0b00001000, 0b00000000, 0b01111111, 0b11100000};
static const uint8_t tick_width = 16;
static const uint8_t tick_height = 15;

class Display
{

public:
    void clearMainMenu();
    void getResistanceFromUser(Preference preference, buttons_state_t(*getButtonsState)(void));
    void heatAnimate(int &x, int &y, float v, float t, float target);
    void showHeatMenu(byte max_temp);
    void showMainMenuLeft(int &x, int &y);
    void showMainMenuRight(int index);
    uint8_t getProfile(buttons_state_t(*getButtonsState)(void));
    void showLogo(void (*doSetup)(void), buttons_state_t(*getButtonsState)(void));
    void coolDown(float(*getTemp)(void), buttons_state_t(*getButtonsState)(void));
    void cancelledTimer(buttons_state_t(*getButtonsState)(void));
    void cancelledPB();
    void completed(buttons_state_t(*getButtonsState)(void));

private:
    void displayProfileRight(int8_t cur_profile);
};