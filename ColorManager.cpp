//
// Created by wojkly on 6/4/21.
//

#include "ColorManager.h"

int ColorManager::n_sixth = 10;
int ColorManager::color_value = 255 / 10;

void ColorManager::setInitialValues(int n) {
    if (n >= 6)
        n_sixth = n / 6;
    else
        n_sixth = 1;
    color_value = 255 * 6 / n;
}
unsigned int ColorManager::getColor(int i) {
    unsigned int red,green,blue,alpha;
    int k = i % n_sixth;
    //start from RGB = 0,1,0

    //blue +
    if (i < n_sixth) {
        red = 0;
        green = 255;
        blue = std::min(color_value*i, 255);
    }
        //green -
    else if (i < 2*n_sixth) {
        red = 0;
        green = std::max(255 - color_value*k, 0);
        blue = 255;
    }
        //red +
    else if (i < 3*n_sixth) {
        red = std::min(color_value*k, 255);
        green = 0;
        blue = 255;
    }
        //blue -
    else if (i < 4*n_sixth) {
        red = 255;
        green = 0;
        blue = std::max(255 - color_value*k, 0);
    }
        //green +
    else if (i < 5*n_sixth) {
        red = 255;
        green = std::min(color_value*k, 255);
        blue = 0;
    }
        //red -
    else{
        red = std::max(255 - color_value*k, 0);
        green = 255;
        blue = 0;
    }
    alpha = 255;

    return alpha + 256*(blue + 256 *(green + 256* red));
}

