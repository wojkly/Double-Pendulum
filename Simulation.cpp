//
// Created by wojkly on 5/30/21.
//

#include "Simulation.h"

Simulation::Simulation(ArgumentParser argumentParser) {
    size_ = argumentParser.getPendulumCount();
    delta = argumentParser.getTimeInterval();
    pendulums = new DoublePendulum[size_];

    PendulumEquation::setGravity(argumentParser.getGravity());
    PendulumEquation::setLength1(argumentParser.getLength1());
    PendulumEquation::setLength2(argumentParser.getLength2());
    PendulumEquation::setMass1(argumentParser.getMass1());
    PendulumEquation::setMass2(argumentParser.getMass2());

    double initTheta1 = argumentParser.getThetaInit1();
    double initTheta2 = argumentParser.getThetaInit2();
    double posDiff = argumentParser.getPendulumInitPositionDifference();

    //todo add color getter class
    int n_sixth = size_ / 6;
    int calor_value = 255 * 6 / size_;
    for (int i = 0; i < size_; ++i) {
        unsigned int red,green,blue,alpha;
        int k = i % n_sixth;
        //start from RGB = 0,1,0

        //blue +
        if (i < n_sixth) {
            red = 0;
            green = 255;
            blue = std::min(calor_value*i, 255);
        }
        //green -
        else if (i < 2*n_sixth) {
            red = 0;
            green = std::max(255 - calor_value*k, 0);
            blue = 255;
        }
        //red +
        else if (i < 3*n_sixth) {
            red = std::min(calor_value*k, 255);
            green = 0;
            blue = 255;
        }
        //blue -
        else if (i < 4*n_sixth) {
            red = 255;
            green = 0;
            blue = std::max(255 - calor_value*k, 0);
        }
        //green +
        else if (i < 5*n_sixth) {
            red = 255;
            green = std::min(calor_value*k, 255);
            blue = 0;
        }
        //red -
        else{
            red = std::max(255 - calor_value*k, 0);
            green = 255;
            blue = 0;
        }
        alpha = 255;
        pendulums[i] = DoublePendulum(alpha + 256*(blue + 256 *(green + 256* red)), PendulumEquation(initTheta1 + posDiff*i,initTheta2 + posDiff*i));
    }
}

Simulation::~Simulation() {
    delete pendulums;
}

void Simulation::step() {
    for (int i = 0; i < size_; ++i) {
        pendulums[i].makeStep(delta);
    }
}

size_t Simulation::size() const {
    return size_;
}

void Simulation::setTheta1(int id, double theta1) {
    if (id > size())
        throw std::out_of_range("error, trying to set theta of nonexistent id");
    pendulums[id].setTheta1(theta1);
}

void Simulation::setTheta2(int id, double theta2) {
    if (id > size())
        throw std::out_of_range("error, trying to set theta2 of nonexistent id");
    pendulums[id].setTheta2(theta2);
}

double Simulation::getTheta1(unsigned int id) {
    if (id > size())
        throw std::out_of_range("error, trying to get theta1 of nonexistent id");
    return pendulums[id].getTheta1();
}

double Simulation::getTheta2(unsigned int id) {
    if (id > size())
        throw std::out_of_range("error, trying to get theta2 of nonexistent id");
    return pendulums[id].getTheta2();
}

unsigned int Simulation::getColor(unsigned int id) {
    if (id > size())
        throw std::out_of_range("error, trying to get color of nonexistent id");
    return pendulums[id].getColor();
}
