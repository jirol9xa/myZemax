#pragma once

#include <cmath>
#include "vec2.h"
#include "vec3.h"

class Widget 
{
protected:
    Vec2   pos_;
    Vec3   color_;  // Need to make Vec3 for this shit
    size_t width_;
    size_t height_;

    bool is_hit(Vec2 &pos) const
    {
        return abs(pos.getX() - pos_.getX()) < width_ &&
               abs(pos.getY() - pos_.getY()) < height_; 
    }

    virtual void   draw(uint32_t *PixelArr) const = 0;
    virtual void   close()                        = 0;
    virtual void   move(Vec2 &delta)              = 0;
    virtual void   onClick(Vec2 &pos)             = 0;
    virtual size_t onKey()                        = 0;

public:
    Widget(Vec2 pos = {0, 0}, Vec3 color = {255, 255, 255}, size_t width = 20,
           size_t height = 20) : pos_(pos), color_(color), width_(width),
                                  height_(height)  {}

    virtual void register_callbacks(ActionManager *mng, Render *rnd) = 0;

    virtual ~Widget();
};
