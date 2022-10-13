#include "canvas.h"
#include <iostream>


void Canvas::onClick(Vec2 &pos)
{
    if (!is_hit(pos))
        return;
    
    std::cout << "Drawing on canvas\n";

    Vec3 color = mng_->getColor();

    for (int i = 0; i < 4; ++i)
        canvas_pixels_[pos.getX() + i + pos.getY() * width_] 
                                                = 0xFF000000 + uint32_t(color);

}

void Canvas::draw(uint32_t *PixelArr) const
{
    size_t x_start = pos_.getX() /*- width_  / 2*/,
           y_start = pos_.getY() /*- height_ / 2*/;

    for (int height = 0; height < height_; ++height)
        for (int width = 0; width < width_; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::Width]
                                                = 0xFF000000 + uint32_t(color_); 

    for (int height = 0; height < height_; ++height)
        for (int width = 0; width < width_; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::Width]
                                   = canvas_pixels_[width + height * width_]; 
            // Need to make that operation correctly
}