void loop() {  
  startIndex = startIndex + 1;
  
  /** Check Button State **/
  uint8_t upKeyState = digitalRead(BUTTON_UP);
  uint8_t downKeyState = digitalRead(BUTTON_DOWN);
  
  if ((prevUpKeyState == LOW) && (upKeyState == HIGH)) {
    upKeyPress();    
  } 
  if ((prevDownKeyState == LOW) && (downKeyState == HIGH)) {
    downKeyPress();
  } 
  prevUpKeyState = upKeyState;
  prevDownKeyState = downKeyState;

  switch (animationMode) {
    case 0:
      currentPalette = RainbowColors_p;  //All the colors!
      break;
    case 1:    
      currentPalette = PurpleColors_p;   //Rainbow stripes
      break;
    case 2:
      currentPalette = ForestColors_p;    //Foresty greens and yellows
      break;
    case 3: 
      currentPalette = OceanColors_p;  //Oceans are pretty and filled with mermaids
      break;
  }   

  alternatingPaletteFill(startIndex);
    
  FastLED.show(); 
  FastLED.delay(1000 / animationSpeed);  
}
