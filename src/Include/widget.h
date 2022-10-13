#pragma once

#include <cmath>
#include "vec2.h"
#include "vec3.h"
#include "render.h"
#include "actionManager.h"

class Widget 
{
protected:
    Vec2   pos_;
    Vec3   color_;  // Need to make Vec3 for this shit
    size_t width_;
    size_t height_;

    // Need to fix this method, cause pos is position of top left angle,
    // but here realization for middle of widget 
    bool is_hit(Vec2 &pos) const
    {
        return std::abs(ssize_t(pos.getX()) - ssize_t(pos_.getX())) < width_ &&
               std::abs(ssize_t(pos.getY()) - ssize_t(pos_.getY())) < height_; 
    }

    virtual void   draw(uint32_t *PixelArr) const = 0;
    virtual void   close()                        = 0;
    virtual void   move(Vec2 &delta)              = 0;
    virtual void   onClick(Vec2 &pos)             = 0;
    virtual size_t onKey()                        = 0;

public:
    Widget(Vec2 pos = {0, 0}, Vec3 color = {255, 255, 255}, size_t width = 30,
           size_t height = 30) : pos_(pos), color_(color), width_(width),
                                  height_(height)  {}

    void setWidth (size_t new_width)  { width_  = new_width; }
    void setHeight(size_t new_height) { height_ = new_height; }

    virtual void register_callbacks(ActionManager *mng, Render *rnd) = 0;

    virtual ~Widget() {};
};
