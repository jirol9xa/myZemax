#pragma once

#include "widget.h"
#include "actionManager.h"
#include "render.h"
#include <iostream>

class Button : public Widget
{
    private:
        bool is_pressed;
    
    protected:
        void   press() { is_pressed = !is_pressed; }
        void   draw(uint32_t *PixelArr) const override;
        void   close() override{};
        void   onClick(Vec2 &pos, bool is_left) override;
        size_t onKey() override { return 0; };
    
        uint32_t getColor() { return uint32_t(color_) * is_pressed; }
    
    public:
        Button(Vec2 pos, Vec3 color) : Widget(pos, color), is_pressed(false) {};
        void register_callbacks(ActionManager *mng, Render *rnd) override
        {
            mng->register_callback_color([this](){ return getColor(); });
            mng->register_callbacks_onclick(
                            {[this](Vec2 &pos, bool is_left){ onClick(pos, is_left); },
                             ON_CLICK});
            rnd->register_callbacks([this](uint32_t *pixels){ draw(pixels); });
        }

        void   move(Vec2 &&delta) override { pos_ += delta; }
};
