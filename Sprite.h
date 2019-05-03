/**
 * Created by titimoby
 * Class to manage sprite
 * 
**/

#ifndef SPRITE_H
#define SPRITE_H

#include <Gamebuino-Meta.h>
#include "constants.h"

class Sprite {
    private:
        Image         sheet; // spritesheet
    public:
        uint8_t           x;
        uint8_t           y;
        uint8_t           w; // width
        uint8_t           h; // height
        uint8_t    orientation; // left | right
        int8_t           vx; // horizontal velocity
        uint8_t       frame; // current frame
        uint8_t      frames; // number of frames

        Sprite(
            uint8_t x, uint8_t y,
            uint8_t orientation,
            const uint16_t* imageData
        );
        void draw(Gamebuino* gb);
};

#endif