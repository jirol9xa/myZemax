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
        void draw(uint32_t *Pixels) const override;
        void close() override {};
        void onClick(Vec2 &pos, bool is_left) override;
        void move(Vec2 &&delta) override {};
        size_t onKey() override { return 0; };
    
        uint32_t *canvas_pixels_;
    
        ActionManager *mng_;
    
    public:
        Canvas(Vec2 pos, Vec3 color, ActionManager *mng, size_t width = 200,
               size_t height = 200) : Widget(pos, color), mng_(mng) 
        {
            width_  = width;
            height_ = height; 
    
            try
            { 
                canvas_pixels_ = new uint32_t[width_ * height_];
                for (int i = 0; i < width_ * height_; ++i)
                    canvas_pixels_[i] = 0xFF000000 + uint32_t(color_); 
            }
            catch(std::bad_alloc except)
            {
                // Need make my own Exception Class
                std::cout << except.what() << std::endl;
                throw "Canvas Ctor error";
            }
        }
    
        void register_callbacks(ActionManager *mng, Render *rnd) override;
    
        ~Canvas() { delete [] canvas_pixels_; }
};

inline void Canvas::register_callbacks(ActionManager *mng, Render *rnd)
{
    mng->register_callbacks_onclick(
                    {[this](Vec2 &pos, bool is_left){ onClick(pos, is_left); },
                      ON_CLICK});
    rnd->register_callbacks([this](uint32_t *pixels){ draw(pixels); });
}
