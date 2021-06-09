//
// Created by wojkly on 6/4/21.
//

#include "ColorManager.h"

std::size_t ColorManager::n = 10;
std::size_t ColorManager::move_by = 0;

void ColorManager::setInitialValues(size_t n_) {
    n = n_;
    move_by = rand()%256;
}
unsigned int ColorManager::getColor(int i) {

    unsigned int red,green,blue,alpha;

    std::size_t x = ((i + move_by) % n) * 6 * 256 / n;
    size_t interval = x / 256;
    int k = x % 256;

//    //start from RGB = 0,1,0
    switch (interval) {
//    //blue +
        case 0:
            red = 0;
            green = 255;
            blue = std::min(k, 255);
            break;
//        //green -
        case 1:
            red = 0;
            green = std::max(255 - k, 0);
            blue = 255;
            break;
//        //red +
        case 2:
            red = std::min(k, 255);
            green = 0;
            blue = 255;
            break;
//        //blue -
        case 3:
            red = 255;
            green = 0;
            blue = std::max(255 - k, 0);
            break;
//        //green +
        case 4:
            red = 255;
            green = std::min(k, 255);
            blue = 0;
            break;
//        //red -
        case 5:
            red = std::max(255 - k, 0);
            green = 255;
            blue = 0;
            break;
        default:
            throw std::out_of_range("not posiible");
    }

    alpha = 255;

    return alpha + 256*(blue + 256 *(green + 256* red));
}

