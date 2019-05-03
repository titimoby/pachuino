#include "Sprite.h"

Sprite::Sprite(
    uint8_t x, uint8_t y,
    uint8_t orientation,
    const uint16_t* imageData
) : x(x), y(y), 
    w(imageData[0]), h(imageData[1]),
    orientation(orientation), 
    vx(0), 
    frame(0), frames(imageData[2]),
    sheet(Image(imageData)){
    
}

void Sprite::draw(Gamebuino* gb) {
    sheet.setFrame(frame);

    gb->display.drawImage(
      x, y,
      sheet,
      w * (orientation == ASTRO_ORIENTATION_LEFT ? -1 : 1),
      h
    );
}
