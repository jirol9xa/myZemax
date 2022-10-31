#include "canvas.h"
#include <iostream>


void Canvas::onClick(Vec2 &pos, bool is_left)
{
    if (!is_hit(pos))
        return;
    
    Vec2 canv_pos = pos - pos_;
    Vec3 color    = mng_->getColor();

    canvas_pixels_[canv_pos.getX() + canv_pos.getY() * width_] 
                                        = 0xFF000000 + is_left * uint32_t(color);
}

void Canvas::draw(uint32_t *PixelArr) const
{
    size_t x_start = pos_.getX(),
           y_start = pos_.getY();
    
    for (int height = 0; height < height_; ++height)
        for (int width = 0; width < width_; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::Width]
                                                = 0xFF000000 + uint32_t(color_); 

    for (int height = 0; height < 200; ++height)
        for (int width = 0; width < 200; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::Width]
                                   = canvas_pixels_[width + height * width_]; 
}

