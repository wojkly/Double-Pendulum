//
// Created by wojkly on 6/4/21.
//

#ifndef DOUBLE_PENDULUM_SIMULATION_COLORMANAGER_H
#define DOUBLE_PENDULUM_SIMULATION_COLORMANAGER_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class ColorManager {
public:
    static size_t n;
    static size_t move_by;
    static void setInitialValues(size_t n);
    static unsigned int getColor(int i);
};


#endif //DOUBLE_PENDULUM_SIMULATION_COLORMANAGER_H
