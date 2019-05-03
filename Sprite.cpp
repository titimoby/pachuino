#include "Sprite.h"

Sprite::Sprite(
    uint8_t x, uint8_t y,
    uint8_t w, uint8_t h,
    uint8_t orientation,
    int8_t vx,
    uint8_t frame, uint8_t frames,
    Image         sheet
) : x(x), y(y), w(w), h(h), orientation(orientation), vx(vx), frame(frame), frames(frames), sheet(sheet){
    
}
