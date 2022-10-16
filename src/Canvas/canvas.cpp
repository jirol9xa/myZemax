#include "canvas.h"
#include <iostream>


void Canvas::onClick(Vec2 &pos, bool is_left)
{
    if (!is_hit(pos))
        return;
    
    Vec2 canv_pos = pos - pos_;

    std::cout << "Drawing on canvas\n";

    Vec3 color = mng_->getColor();
    std::cout << "color =" << uint32_t(color) << '\n';
    std::cout << "width = " << width_ << '\n' << "Canv_pos: " << canv_pos << '\n';

    canvas_pixels_[canv_pos.getX() + canv_pos.getY() * width_] 
                                        = 0xFF000000 + is_left * uint32_t(color);

}

void Canvas::draw(uint32_t *PixelArr) const
{
    size_t x_start = pos_.getX() /*- width_  / 2*/,
           y_start = pos_.getY() /*- height_ / 2*/;
    
    // make an operator for converting sf::Vec2 to Vec2

    for (int height = 0; height < height_; ++height)
        for (int width = 0; width < width_; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::Width]
                                                = 0xFF000000 + uint32_t(color_); 

    for (int height = 0; height < 200/*height_*/; ++height)
        for (int width = 0; width < 200/*width_*/; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::Width]
                                   = canvas_pixels_[width + height * width_]; 
            // Need to make that operation correctly
}