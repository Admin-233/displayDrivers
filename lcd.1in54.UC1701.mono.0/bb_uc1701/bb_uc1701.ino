//
// bb_uc1701 demo sketch
// Shows off a few features of the library
// The large (16x32) font is disabled on AVR MCUs to save
// 8K of FLASH. The 1K RAM backbuffer can be disabled by
// commenting out "BACKING_RAM" in the bb_uc1701.h file
// This will disable the pixel and line drawing functions
//
#include "bb_uc1701.h"

#define DC_PIN 4
#define RESET_PIN 5
#define LED_PIN 0
#define CS_PIN 16

// 16x16 (2 bytes x 16 lines) Arrow pointing up
const uint8_t ucArrow[] PROGMEM = {
 0x01,0x80,0x02,0x40,0x04,0x20,0x08,0x10,0x10,0x08,0x20,0x04,0x40,0x02,0x80,0x01,
 0x80,0x01,0xfc,0x3f,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x07,0xe0
};

void setup() {
  // put your setup code here, to run once:
//int uc1701Init(int iDC, int iReset, int iLED, int iCS, byte bFlip180, byte bInvert, int32_t iClock);
  uc1701Init(DC_PIN,RESET_PIN,LED_PIN, CS_PIN, true, false, 4000000L);
}

void loop() {
  // put your main code here, to run repeatedly:
int x, y;

// Text Demo
  uc1701Fill(0); // fill the display with 0's
  uc1701WriteString(12,0,(char *)"BB_UC1701 Library", FONT_SMALL,1);
  uc1701WriteString(0,2,(char *)"6x8 Small font", FONT_SMALL,0);
  uc1701WriteString(0,3,(char *)"8x8 Normal font", FONT_NORMAL,0);
  uc1701WriteString(0,4,(char *)"16x16", FONT_STRETCHED,0);
  uc1701WriteString(0,6,(char *)"Stretch", FONT_STRETCHED,0);
  delay(3000);
// Line demo
  uc1701Fill(0);
  uc1701WriteString(8,0,(char *)"Optimized Line", FONT_NORMAL,0);
  uc1701WriteString(36,1,(char *)"Drawing", FONT_NORMAL,0);
  delay(2000);
  uc1701Fill(0);
  for (x=0; x<128; x+= 2)
    uc1701DrawLine(x,0,127-x,63);
  for (y=0; y<63; y+= 2)
    uc1701DrawLine(127,y,0,63-y);
  delay(3000);
 // rotated tile drawing
  uc1701Fill(0);
  uc1701WriteString(16,0,(char *)"Rotated Tile", FONT_NORMAL,0);
  uc1701WriteString(36,1,(char *)"Drawing", FONT_NORMAL,0);
  delay(3000);
} // loop()
