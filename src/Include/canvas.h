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
    void move(Vec2 &delta) {};
    size_t onKey() { return 0; };

    uint32_t *canvas_pixels_;

    ActionManager *mng_;

public:
    Canvas(Vec2 pos, Vec3 color, ActionManager *mng) : Widget(pos, color), 
                                                       mng_(mng) 
    {
        try
        { 
            // Make Normal Realloc
            canvas_pixels_ = new uint32_t[500 * 500/*width_ * height_*/];
            for (int i = 0; i < 500 * 500/*width_ * height_*/; ++i)
                canvas_pixels_[i] = 0xFF000000 + uint32_t(color_); 
        }
        catch(std::bad_alloc except)
        {
            // Need make my own Exception Class
            std::cout << except.what() << std::endl;
            throw "Canvas Ctor error";
        }
    }

    void register_callbacks(ActionManager *mng, Render *rnd);


    ~Canvas() { delete [] canvas_pixels_; }
};

inline void Canvas::register_callbacks(ActionManager *mng, Render *rnd)
{
    mng->register_callbacks_onclick(
                                {[this](Vec2 &pos){ onClick(pos); }, ON_CLICK});
    rnd->register_callbacks([this](uint32_t *pixels){ draw(pixels); });
}
