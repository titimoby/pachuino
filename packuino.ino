// Load a sprite and move it
#include <Gamebuino-Meta.h>
#include "constants.h"
#include "astroBuffers.h"
#include "Sprite.h"

Sprite astro(
    .5*(SCREEN_WIDTH  - ASTRO_WIDTH),  // x
    .5*(SCREEN_HEIGHT - ASTRO_HEIGHT), // y
    ASTRO_WIDTH,                       // w
    ASTRO_HEIGHT,                      // h
    ASTRO_ORIENTATION_RIGHT,           // orientation
    0,                                 // vx
    ASTRO_DEFAULT_FRAME,               // frame
    ASTRO_FRAMES,                      // frames
    Image(astroWalkBuff)			   // sheet
  );

void setup() {
  gb.begin();
  // SerialUSB.println("end setup");
}

void loop() {
  while (!gb.update());
  
  inputs();

  logic();

  draw();
}

void inputs() {
    if (gb.buttons.repeat(BUTTON_LEFT, 0)) {
        astro.orientation = ASTRO_ORIENTATION_LEFT;
        astro.vx = -2;
    } else if (gb.buttons.repeat(BUTTON_RIGHT, 0)) {
        astro.orientation = ASTRO_ORIENTATION_RIGHT;
        astro.vx = 2;
    } else if (gb.buttons.released(BUTTON_LEFT) || gb.buttons.released(BUTTON_RIGHT)) {
        astro.vx    = 0;
        astro.frame = ASTRO_DEFAULT_FRAME;
    }
}

void logic() {
  
    if (astro.vx != 0) {
        astro.x += astro.vx;
        if (astro.x < 0 || astro.x + astro.w > SCREEN_WIDTH-1) {
            astro.x -= astro.vx;
        }
        astro.frame = ++astro.frame % astro.frames;        
    }
}

void draw() {
  gb.display.clear();
  
  astro.sheet.setFrame(astro.frame);
  gb.display.drawImage(
      astro.x, astro.y,
      astro.sheet,
      astro.w * (astro.orientation == ASTRO_ORIENTATION_LEFT ? -1 : 1),
      astro.h
    );

}
