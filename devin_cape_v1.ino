/*** LIBRARIES ***/
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

/*** CONSTANTS ***/
#define LONGEST_STRIP 30
#define NUM_STRIPS 7
#define COLOR_ORDER GRB
#define LED_PIN 14
#define BUTTON_UP 6
#define BUTTON_DOWN 3
#define NUM_LEDS 158
#define BRIGHTNESS 100
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
uint16_t animationSpeed = 0;
int animationMode = 0;
uint8_t numAnimations = 13;
uint8_t startIndex = 0;
uint8_t steps = 10;
uint8_t gHue = 0; 
boolean noKeysPressed = true;

/*** STRIPS ***/
uint8_t stripOne[18] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
uint8_t stripTwo[21] = {38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18};
uint8_t stripThree [25] = {39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63};
uint8_t stripFour [30] = {93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64};
uint8_t stripFive [25] = {94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118};
uint8_t stripSix [21] = {139,138,137,136,135,134,133,132,131,130,129,128,127,126,125,124,123,122,121,120,119};
uint8_t stripSeven [18] = {140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157};


/*** PALETTE FUNCTION DECLARATIONS ***/
extern const TProgmemPalette16 BriteNoBlack_p PROGMEM;
extern const TProgmemPalette16 BriteWithBlack_p PROGMEM;
extern const TProgmemPalette16 Love_p PROGMEM;
extern const TProgmemPalette16 Sunshine_p PROGMEM;
extern const TProgmemPalette16 PewPew_p PROGMEM;
extern const TProgmemPalette16 Vaporwave_p PROGMEM;
extern const TProgmemPalette16 Purple_p PROGMEM;

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



