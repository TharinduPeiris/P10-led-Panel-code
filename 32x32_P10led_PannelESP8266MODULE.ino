#include <SPI.h>
#include <DMD2.h>
#include <fonts/SystemFont5x7.h>
#include <fonts/Droid_Sans_16.h>

// Set Width to the number of displays wide you have
const int WIDTH = 1;

// You can change to a smaller font (two lines) by commenting this line,
// and uncommenting the line after it:
const uint8_t *FONT = Droid_Sans_16;
//const uint8_t *FONT = SystemFont5x7;

const char *MESSAGE = “ HELLO WELCOME “;//giving 3 or more letters

SPIDMD dmd(WIDTH,1); // DMD controls the entire display
DMD_TextBox box(dmd, 1, 1, 32, 16); // “box” provides a text box to automatically write to/scroll the display
SPIDMD dmd1(1, 1); // Number of P10 panels used X, Y

// the setup routine runs once when you press reset:
void setup() {
 //////////////////////////Letters display////////////////////////
 Serial.begin(9600);
 dmd.setBrightness(255);
 dmd.selectFont(FONT);
 dmd.begin();
 
/////////////////////////////////////////////////////////////////////

/////////////////////////box border//////////////////////////////////////////////
 dmd1.setBrightness(10); // Set brightness 0–255
 dmd1.selectFont(FONT); // Font used
 dmd1.begin();
 dmd1.drawBox(31, 15, 0, 0); //{x,y,} // drawing box bording led pannel

////////////////////////////////////////////////////////////////////////////
}

// the loop routine runs over and over again forever:
void loop() {
 const char *next = MESSAGE;
 while(*next) {
 Serial.print(*next);
 box.print(*next);
 delay(500);
 next++;
 }
}
