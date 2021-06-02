//
// Created by wojkly on 5/29/21.
//

#ifndef DOUBLE_PENDULUM_SIMULATION_PENDULUMEQUATION_H
#define DOUBLE_PENDULUM_SIMULATION_PENDULUMEQUATION_H

#include <cmath>
#include <iostream>

class PendulumEquation {
    double theta1{};
    double theta2{};
    double w1{0};
    double w2{0};

public:
    static double GRAVITY;
    static double LENGTH1;
    static double LENGTH2;
    static double MASS1;
    static double MASS2;

    PendulumEquation() = default;
    PendulumEquation(double th1, double th2);
    double w1Prim() const;
    double w2Prim() const;
    void makeStep(double delta);
    double getTheta1() const;
    double getTheta2() const;
    void setTheta1(double th1);
    void setTheta2(double th2);

    static void setGravity(double g);
    static void setLength1(double l);
    static void setLength2(double l);
    static void setMass1(double m);
    static void setMass2(double m);
};


#endif //DOUBLE_PENDULUM_SIMULATION_PENDULUMEQUATION_H
