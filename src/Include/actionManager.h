#pragma once

#include <vector>
#include <functional>
#include "vec2.h"
#include "vec3.h"


/// @brief Enum for specific events type (uses in storring callbacks)
enum events
{
    ON_CLICK,
    ON_KEY,
    DRAW,
    MOVE,
};

/// @brief Structure for storring CallBacks and argument for making 
/// callbacks only for specific events
struct cb_storage_t
{
    std::function<void(Vec2&, bool)> callback;
    events type;
};


/// @brief  Action Manager for Buttons
class ActionManager
{  
    private:
        std::vector<cb_storage_t> callbacks_;
        std::vector<std::function<uint32_t()>> color_callbacks;
    
    public:
        virtual void register_callbacks_onclick(cb_storage_t action);
        virtual void register_callback_color(std::function<uint32_t()> colorBotton);
        virtual void onClick(Vec2 &pos, bool is_left);
    
        Vec3 getColor();
};

inline Vec3 ActionManager::getColor()
{
    uint32_t red   = 0,
             green = 0,
             blue  = 0;
    
    uint32_t color = 0;

    for (const auto &cb : color_callbacks)
        color  += cb();

    blue  += (color >> 16) & 0x000000FF;
    green += (color >> 8)  & 0x000000FF;
    red   += color         & 0x000000FF;

    return Vec3(red, green, blue);
}

inline void ActionManager::register_callback_color(std::function<uint32_t()> color_botton)
{
    color_callbacks.push_back(color_botton);
}

inline void ActionManager::register_callbacks_onclick(cb_storage_t action)
{
    callbacks_.push_back(action);
}

inline void ActionManager::onClick(Vec2 &pos, bool is_left)
{
    for (const auto &cb_obj : callbacks_)
        if (cb_obj.type == ON_CLICK)
            cb_obj.callback(pos, is_left);
}
