#pragma once

#include "button.h"

class ColorButtonManager : public Widget
{
private:
    Button RedButton;
    Button GreenButton;
    Button BlueButton;

    Vec3 color_;

public:
    ColorButtonManager() : RedButton  ({0, 0}, {255, 0, 0}), 
                           GreenButton({10, 0}, {0, 255, 0}),
                           BlueButton ({20, 0}, {0, 0, 255}) {}
};