//
// Created by wojkly on 5/29/21.
//
#include <iostream>

#include "DoublePendulum.h"
#include "PendulumEquation.h"

using namespace std;

DoublePendulum::DoublePendulum(unsigned int c, PendulumEquation equation): equation(equation), color(c) {}

void DoublePendulum::makeStep(double delta) {
    equation.makeStep(delta);
}

double DoublePendulum::getTheta1() const{
    return equation.getTheta1();
}

double DoublePendulum::getTheta2() const{
    return equation.getTheta2();
}

unsigned int DoublePendulum::getColor() const {
    return color;
}

void DoublePendulum::setTheta1(double th1) {
    equation.setTheta1(th1);
}

void DoublePendulum::setTheta2(double th2) {
    equation.setTheta2(th2);
}

std::ostream & operator<<(std::ostream & os, const DoublePendulum &pendulum){
    os << "theta 1 is: ";
    os << pendulum.getTheta1();
    os << " theta 2 is: ";
    os << pendulum.getTheta2();
    os << endl;
    return os;
}


