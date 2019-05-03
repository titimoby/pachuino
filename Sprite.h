/**
 * Created by titimoby
 * Class to manage sprite
 * 
**/

#ifndef SPRITE_H
#define SPRITE_H

#include <Gamebuino-Meta.h>

class Sprite {
    public:
        uint8_t           x;
        uint8_t           y;
        uint8_t           w; // width
        uint8_t           h; // height
        uint8_t    orientation; // left | right
        int8_t           vx; // horizontal velocity
        uint8_t       frame; // current frame
        uint8_t      frames; // number of frames
        Image         sheet; // spritesheet

        Sprite(
            uint8_t x, uint8_t y,
            uint8_t w, uint8_t h,
            uint8_t orientation,
            int8_t vx,
            uint8_t frame, uint8_t frames,
            Image         sheet
        );
};

#endif