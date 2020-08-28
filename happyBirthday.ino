/*
* This code example shows how to scroll a line of text
* across the screen on an Arduboy.
* The OLED screen dimensions are 128 x 60 pixels (width x height)
*/
#include <Arduboy2.h>
#include <ArduboyTones.h>
 
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

#define NDUR 500
uint16_t inRAM[] = {
  NOTE_C4, NDUR, NOTE_C4, NDUR, NOTE_D4, NDUR, NOTE_C4, NDUR, NOTE_F4, NDUR, NOTE_E4, NDUR,
  NOTE_C4, NDUR, NOTE_C4, NDUR, NOTE_D4, NDUR, NOTE_C4, NDUR, NOTE_G4, NDUR, NOTE_F4, NDUR,
  NOTE_C4, NDUR, NOTE_C4, NDUR, NOTE_C5, NDUR ,NOTE_A4, NDUR, NOTE_F4, NDUR, NOTE_E4, NDUR,
  NOTE_D4, NDUR, NOTE_AS4, NDUR, NOTE_AS4, NDUR ,NOTE_A4, NDUR, NOTE_F4, NDUR, NOTE_G4, NDUR, NOTE_F4, NDUR,
  NOTE_C4, NDUR, NOTE_C4, NDUR, NOTE_D4, NDUR, NOTE_C4, NDUR, NOTE_F4, NDUR, NOTE_E4, NDUR,
  NOTE_C4, NDUR, NOTE_C4, NDUR, NOTE_D4, NDUR, NOTE_C4, NDUR, NOTE_G4, NDUR, NOTE_F4, NDUR,
  NOTE_C4, NDUR, NOTE_C4, NDUR, NOTE_C5, NDUR, NOTE_A4, NDUR, NOTE_F4, NDUR, NOTE_E4, NDUR, NOTE_D4, NDUR,
  NOTE_AS4, NDUR, NOTE_AS4, NDUR, NOTE_A4, NDUR, NOTE_F4, NDUR, NOTE_G4, NDUR, NOTE_F4, NDUR,
  TONES_REPEAT
};
// Create the variables needed
int x;
int y;
char* myGreeting = ("Happy Birthday have a wonderful Day!");

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
}

void loop() {
  arduboy.audio.on();
  
  sound.tonesInRAM(inRAM);

  while (sound.playing()) {
  if (!(arduboy.nextFrame()))
    return;
  
  // Set the coordinates to start at the right edge of the screen
  // and midway down on the Y-axis
  x = 127;
  y = 30;
  
  // In the for() loop, use the screen width x 2
  // this allows the entire message to scroll across
  // before starting over
  // Standard value is 256
  for(int i = 0; i < 625; i++) {

  arduboy.clear();
  arduboy.setCursor(x, y);
  arduboy.print(myGreeting);
  arduboy.display();
  delay(50);
  
  x--;
  
  }
  }
  



}
