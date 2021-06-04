//
// Created by wojkly on 6/4/21.
//

#ifndef DOUBLE_PENDULUM_SIMULATION_COLORMANAGER_H
#define DOUBLE_PENDULUM_SIMULATION_COLORMANAGER_H

#include <algorithm>

class ColorManager {
public:
    static int n_sixth;
    static int color_value;
    static void setInitialValues(int n);
    static unsigned int getColor(int i);
};


#endif //DOUBLE_PENDULUM_SIMULATION_COLORMANAGER_H
