//
// Created by wojkly on 5/29/21.
//

#ifndef GAME_OF_LIFE_PENDULUMEQUATION_H
#define GAME_OF_LIFE_PENDULUMEQUATION_H


class PendulumEquation {
    double theta1{};
    double theta2{};
    double w1{0};
    double w2{0};
public:
    PendulumEquation() = default;
    PendulumEquation(double , double);
    double w1Prim() const;
    double w2Prim() const;
    void makeStep(double delta);
    double getTheta1() const;
    double getTheta2() const;
    void setTheta1(double th1);
    void setTheta2(double th2);
};


#endif //GAME_OF_LIFE_PENDULUMEQUATION_H
