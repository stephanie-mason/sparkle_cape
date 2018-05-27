void upKeyPress() {
  animationMode++;
  if (animationMode > (numAnimations - 1)) {
    animationMode = 0; 
  }  
}

void downKeyPress() {
  animationMode--;
  if (animationMode < 0) {
    animationMode = numAnimations;
  }
}

void alternatingPaletteFill( uint8_t colorIndex) {
  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    colorIndex += steps;              
  }
}
