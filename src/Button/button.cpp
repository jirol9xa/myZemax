#include <cstdio>
#include "button.h"
#include "videoSettings.h"

void Button::draw(uint32_t *PixelArr) const
{
    size_t x_start = pos_.getX() - width_  / 2,
           y_start = pos_.getY() - height_ / 2;

    for (int height = 0; height < height_; ++height)
        for (int width = 0; width < width_; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::Width]
                                                          = uint32_t(color_); 
            // Need to make that operation correctly
};


