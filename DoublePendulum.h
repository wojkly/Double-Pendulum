//
// Created by wojkly on 5/29/21.
//
#ifndef DOUBLE_PENDULUM_SIMULATION_DOUBLEPENDULUM_H
#define DOUBLE_PENDULUM_SIMULATION_DOUBLEPENDULUM_H

#include <iostream>
#include "PendulumEquation.h"

using namespace std;

class DoublePendulum {
    PendulumEquation equation;
    unsigned int color{};
public:
    DoublePendulum() = default;
    DoublePendulum(unsigned int c, PendulumEquation equation);
    void makeStep(double delta);
    double getTheta1() const;
    double getTheta2() const;
    void setTheta1(double th1);
    void setTheta2(double th2);
    unsigned int getColor() const;
};

ostream & operator<<(ostream & os, const DoublePendulum &pendulum);

#endif //DOUBLE_PENDULUM_SIMULATION_DOUBLEPENDULUM_H
