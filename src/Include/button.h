#pragma once

#include "widget.h"
#include "actionManager.h"
#include "render.h"

class Button : public Widget
{
private:
    bool is_pressed;

protected:
    void   press() { is_pressed = !is_pressed; }
    void   draw(uint32_t *PixelArr) const override;
    void   close() {};
    void   move(Vec2 &delta) { pos_ += delta; }
    void   onClick(Vec2 &pos) { is_pressed = !is_pressed; };
    size_t onKey();

    uint32_t getColor() { return uint32_t(color_); }

public:
    Button(Vec2 pos, Vec3 color) : Widget(pos, color) {};
    void register_callbacks(ActionManager *mng, Render *rnd) override
    {
        mng->register_callback_color([this]() -> uint32_t{ getColor(); });
        mng->register_callbacks_onclick(
                           {[this](Vec2 &pos){ onClick(pos); }, ON_CLICK});
        rnd->register_callbacks([this](uint32_t *pixels){ draw(pixels); });
    }
};