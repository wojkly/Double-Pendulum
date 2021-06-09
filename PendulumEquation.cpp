//
// Created by wojkly on 5/29/21.
//

#include "PendulumEquation.h"

PendulumEquation::PendulumEquation(double th1, double th2) {
    theta1 = th1;
    theta2 = th2;
}

double PendulumEquation::GRAVITY = 9.82;
double PendulumEquation::LENGTH1 = 1;
double PendulumEquation::LENGTH2 = 1;
double PendulumEquation::MASS1 = 1;
double PendulumEquation::MASS2 = 1;

double PendulumEquation::w1Prim() const {
    double result = 0;
    result -= GRAVITY*(2*MASS1 + MASS2)*sin(theta1);
    result -= MASS2 * GRAVITY * sin(theta1 - 2 * theta2);
    result -= 2 * sin(theta1 - theta2) * MASS2 * (w2*w2*LENGTH2 + w1*w1*LENGTH1*cos(theta1 - theta2));
    result /= LENGTH1 * (2*MASS1 + MASS2 - MASS2 * cos(2*theta1 - 2 * theta2));
    return result;
}
double PendulumEquation::w2Prim() const {
    double result = 0;
    result += 2 * sin(theta1 - theta2)*(w1*w1*LENGTH1*(MASS1 + MASS2) + GRAVITY*(MASS1+MASS2)*cos(theta1) + w2*w2*LENGTH2*MASS2*cos(theta1-theta2));
    result /= LENGTH1 * (2*MASS1 + MASS2 - MASS2 * cos(2*theta1 - 2 * theta2));
    return result;
}
void PendulumEquation::makeStep(double delta) {
    theta1 = theta1 + delta * w1;
    theta2 = theta2 + delta * w2;
    w1 = w1 + delta * w1Prim();
    w2 = w2 + delta * w2Prim();

}

double PendulumEquation::getTheta1() const {
    return theta1;
}

double PendulumEquation::getTheta2() const {
    return theta2;
}

void PendulumEquation::setTheta1(double th1) {
    theta1 = th1;
    w1 = 0;
    w2 = 0;
}
void PendulumEquation::setTheta2(double th2) {
    theta2 = th2;
    w1 = 0;
    w2 = 0;
}

 void PendulumEquation::setGravity(double g) {
    GRAVITY = g;
}

void PendulumEquation::setLength1(double l) {
    LENGTH1 = l;
}

void PendulumEquation::setLength2(double l) {
    LENGTH2 = l;
}

void PendulumEquation::setMass1(double m) {
    MASS1 = m;
}

void PendulumEquation::setMass2(double m) {
    MASS2 = m;
}


