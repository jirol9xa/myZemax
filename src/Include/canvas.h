#pragma once

#include "actionManager.h"
#include "widget.h"
#include "videoSettings.h"
#include <utility>
#include <iostream>

/// @brief Widget for canvas, where we can draw
class Canvas : public Widget
{
private:
    void draw(uint32_t *Pixels) const;
    void close() {};
    void onClick(Vec2 &pos);

    uint32_t *canvas_pixels_;

    ActionManager *mng_;

public:
    Canvas(Vec2 pos, Vec3 color, ActionManager *mng) : Widget(pos, color), 
                                                       mng_(mng) 
    {
        try
        { 
            canvas_pixels_ = new uint32_t[width_ * height_];
            for (int i = 0; i < width_ * height_; ++i)
                canvas_pixels_[i] = uint32_t(-1); 
        }
        catch(std::bad_alloc except)
        {
            // Need make my own Exception Class
            std::cout << except.what() << std::endl;
            throw "Canvas Ctor error";
        }
    }

    ~Canvas() { delete [] canvas_pixels_; }
};



inline void Canvas::draw(uint32_t *PixelArr) const
{
    size_t x_start = pos_.getX() - width_  / 2,
           y_start = pos_.getY() - height_ / 2;

    for (int height = 0; height < height_; ++height)
        for (int width = 0; width < width_; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::Width]
                                   = canvas_pixels_[width + height * width_]; 
            // Need to make that operation correctly
}