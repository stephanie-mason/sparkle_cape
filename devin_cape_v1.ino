/*** LIBRARIES ***/
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

/*** CONSTANTS ***/
#define COLOR_ORDER GRB
#define LED_PIN 14
#define BUTTON_UP 6
#define BUTTON_DOWN 3
#define NUM_LEDS 158
#define BRIGHTNESS 255
#define SATURATION 255

/*** FASTLED SETUP ***/
CRGB leds[NUM_LEDS];
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

/*** BUTTON SETUP ***/
unsigned long keyPrevMillis = 0;
const unsigned long keySampleIntervalMs = 25;
uint8_t prevUpKeyState = HIGH;         // button is active low
uint8_t prevDownKeyState = HIGH;

/*** VARIABLES ***/
uint16_t animationSpeed = 500;
int animationMode = 0;
uint8_t numAnimations = 4;
uint8_t startIndex = 0;
uint8_t steps = 10;


/*** STRIPS ***/
uint8_t stripMatrix[7][30] = { 
{17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38},
{63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 39, 39, 39, 39, 39},
{64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93},
{117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 94, 94, 94, 94, 94},
{118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 139, 139, 139, 139, 139, 139, 139, 139},
{157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140}
};

/*** PALETTE FUNCTION DECLARATIONS ***/
extern const TProgmemPalette16 PurpleColors_p PROGMEM;

/*** SETUP ***/
void setup() {
  // Trinket 5V 16MHz, do not remove
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif

  // Safety Delay
  delay(3000);

  // FastLED Setup
  FastLED.addLeds<WS2812B, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);
  currentBlending = LINEARBLEND;
  currentPalette = RainbowColors_p;

  // Button Setup
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
}



