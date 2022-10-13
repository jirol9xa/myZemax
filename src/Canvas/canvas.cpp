#include "canvas.h"


void Canvas::onClick(Vec2 &pos)
{
    if (!is_hit(pos))
        return;
    
    Vec3 color = mng_->getColor();

    canvas_pixels_[pos.getX() + pos.getY() * width_] 
                                                = 0xFF000000 + uint32_t(color);
}