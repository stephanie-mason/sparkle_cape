void loop() {  
  /** Update Variables **/
  startIndex = startIndex + 1;
  EVERY_N_MILLISECONDS(20) { gHue++; }

  if (noKeysPressed) {
    EVERY_N_SECONDS( 12 ) { animationMode = random(numAnimations); }
  }
  
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
      /** BRITE BOOUNCE **/    
      FastLED.setBrightness(100);
      currentPalette = BriteNoBlack_p;
      alternatingPaletteFill(startIndex);   
      currentBlending = LINEARBLEND;   
      steps = 5;
      break;
    case 1:
      /** BRITE & SHINE **/
      FastLED.setBrightness(130);
      currentPalette = BriteWithBlack_p;
      burstPaletteFill(startIndex);      
      currentBlending = LINEARBLEND;
      steps = 7;      
      break;
    case 2: 
      /** BRITE BEATS **/
      FastLED.setBrightness(150); 
      currentPalette = BriteWithBlack_p;
      currentBlending = LINEARBLEND;
      bpm();
      break;

    case 3:
      /** LOVE CONNECTION - PINK **/
      FastLED.setBrightness(100); 
      currentPalette = Love_p;  
      alternatingPaletteFill(startIndex);
      currentBlending = NOBLEND;
      steps = 10;      
      break;      
    case 4: 
      /** LAVA FLOWS - RED **/ 
      FastLED.setBrightness(100); 
      currentPalette = LavaColors_p;  
      burstPaletteFill(startIndex);
      currentBlending = LINEARBLEND;
      steps = 3;      
      break;      
    case 5:
      /** RAYS OF SUNSHINE **/ 
      FastLED.setBrightness(150); 
      currentPalette = Sunshine_p;  
      burstPaletteFill(startIndex);
      currentBlending = LINEARBLEND;
      steps = 4;      
      break;      
    case 6:
      /** PEW PEW **/ 
      FastLED.setBrightness(100); 
      currentPalette = PewPew_p;  
      alternatingPaletteFill(startIndex);
      currentBlending = LINEARBLEND;
      steps = 5;      
      break;            
    case 7: 
      /** GREEN CURTAIN **/   
      /* pretty good as is but maybe alter palette a little */
      FastLED.setBrightness(80);
      currentPalette = ForestColors_p;
      alternatingPaletteFill(startIndex);     
      currentBlending = LINEARBLEND;    
      steps = 1;      
      break;
    case 8:
      /** WATERFALL  **/
      FastLED.setBrightness(80);
      currentPalette = OceanColors_p;
      burstPaletteFill(startIndex);
      currentBlending = LINEARBLEND;
      steps = 8;      
      break;
    case 9:
      /** VAPORWAVE **/
      FastLED.setBrightness(100);
      currentPalette = Vaporwave_p;  
      alternatingPaletteFill(startIndex);     
      currentBlending = LINEARBLEND; 
      steps = 10;      
      break;
    case 10:
      /** PURPLE RAIN, PURPLE RAIN **/ /* DONE */
      FastLED.setBrightness(255);
      currentPalette = Purple_p;  
      burstPaletteFill(startIndex);    
      currentBlending = LINEARBLEND;  
      steps = 8;      
      break;
    
    
    case 11:
      /** CONFETTI **/
      FastLED.setBrightness(255);
      confetti() ;      
      break;
    case 12: 
      /** SPARKLE **/
      FastLED.setBrightness(200);
      sparkle();      
      break;          
    case 13: 
      /** JUGGLE **/
      FastLED.setBrightness(200); 
      juggle();
      break;       
  }   
  
    
  FastLED.show(); 
  delay(animationSpeed);  
}
