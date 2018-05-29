void upKeyPress() {
  if (animationMode == numAnimations) {
    animationMode = 0;     
  } else {
    animationMode++;      
  }
  noKeysPressed = false;
}

void downKeyPress() {  
  if (animationMode == 0) {
    animationMode = numAnimations;
  } else {
    animationMode--;
  }
  noKeysPressed = false;
}

void alternatingPaletteFill(uint8_t colorIndex) {
  for(uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    colorIndex += steps;              
  }
}

void burstPaletteFill (uint8_t colorIndex) {
  for (uint8_t i = 0; i < LONGEST_STRIP; i++) {
    if (i < 18) {
      leds[stripOne[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
      leds[stripSeven[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    }
    if (i < 21) {
      leds[stripTwo[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
      leds[stripSix[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);      
    }
    if (i < 25) {
      leds[stripThree[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
      leds[stripFive[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    }
      leds[stripFour[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    
    colorIndex += steps;
  }
}

void confetti() 
{ 
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sparkle() 
{ 
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CRGB::White;
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = gHue;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
    dothue += 12;
  }
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 120;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(currentPalette, gHue+(i*2), beat-gHue+(i*10));
  }
}
