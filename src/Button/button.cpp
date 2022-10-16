#include <cstdio>
#include "button.h"
#include "videoSettings.h"

void Button::draw(uint32_t *PixelArr) const
{
    size_t x_start = pos_.getX(),
           y_start = pos_.getY();

    for (int height = 0; height < height_; ++height)
        for (int width = 0; width < width_; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::Width]
                                             = 0xFF000000 + uint32_t(color_); 
};

void Button::onClick(Vec2 &pos, bool is_left) 
{ 
    if (!is_hit(pos))
        return;
    is_pressed = is_left; 
    std::cout << "is button pressed = " << is_pressed << '\n';
}
