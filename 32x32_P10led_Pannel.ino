// Tharindu Peiris

// Libraries
#include <SPI.h>
#include <DMD2.h>
#include <fonts/Droid_Sans_36.h> // font libaray


/*P10 led pannel pins to ESP 8266
  A  D0
  B   D6
  CLK   D5
  SCK   D3
  R   D7
  NOE   D8
  GND   GND
*/

int i = 0;

const uint8_t *FONT = Droid_Sans_36;

/////////////////////////////////////////////////////////////////////////////////////////////
SPIDMD dmd(1, 2); // Number of P10 panels used X, Y // change the "SPIDMD", this is very important to change this

SPIDMD dmd1(1, 2); // Number of P10 panels used X, Y
//////////////////////////////////////////////////////////////////////////////////////////////


DMD_TextBox box(dmd, -4, 0, 32, 16); // x, y change text posistion [ Set Box (dmd, x, y, Height, Width)]
const char *MESSAGE = "ABCD";


void setup() {
  Serial.begin(9600);
  
/////////////////////////////text display////////////////////////////////////////////////////
  dmd.setBrightness(10); // Set brightness 0 - 255
  dmd.selectFont(FONT); // Font used
  dmd.begin();
////////////////////////////////////////////////////////////////////////////////


  /////////////////////////box border//////////////////////////////////////////////
  dmd1.setBrightness(10); // Set brightness 0 - 255
  dmd1.selectFont(FONT); // Font used
  dmd1.begin();
  dmd1.drawBox(31, 31, 0, 0); //{x,y,} // drawing box bording led pannel

  ////////////////////////////////////////////////////////////////////////////
}

void loop() {

  scrolling();

}

void scrolling() {
  const char *next = MESSAGE;

  while (*next) {
    dmd.clearScreen();// clear screen
    if (i != 0) {
      box.print(*next); //print the led pannel
    }

    i++;
    delay(800); // letters speed changing
    next++;

  }

}



