#pragma once

#include "button.h"
#include <utility>

class Palette : public Widget
{
    private:
        Button red_,
               green_,
               blue_;

    public:
        Palette(Vec2 pos) : red_(pos, {1, 0, 0}), green_(pos, {0, 1, 0}),
                            blue_(pos, {0, 0, 1})
        {
            Vec2 delta = {50, 0};
            green_.move({50, 0});
            blue_.move({100, 0});
        }

        Vec3 getColor()
        {

        }
};
