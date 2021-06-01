//
// Created by wojkly on 5/30/21.
//

#include "Simulation.h"

Simulation::Simulation(ArgumentParser argumentParser) {
    size_ = argumentParser.getPendulumCount();
    delta = argumentParser.getTimeInterval();
    pendulums = new DoublePendulum[size_];

    double initTheta1 = argumentParser.getThetaInit1();
    double initTheta2 = argumentParser.getThetaInit2();
    double posDiff = argumentParser.getPendulumInitPositionDifference();

    int n_sixth = size_ / 6;
    int calor_value = 255 * 6 / size_;
    for (int i = 0; i < size_; ++i) {
        unsigned int red,green,blue,alpha;
        int k;
        //start from RGB = 0,1,0

        //blue +
        if (i < n_sixth) {
            red = 0;
            green = 255;
            blue = std::min(calor_value*i, 255);
        }
        //green -
        else if (i < 2*n_sixth) {
            k = i - n_sixth;
            red = 0;
            green = std::max(255 - calor_value*k, 0);
            blue = 255;
        }
        //red +
        else if (i < 3*n_sixth) {
            k = i - 2*n_sixth;
            red = std::min(calor_value*k, 255);
            green = 0;
            blue = 255;
        }
        //blue -
        else if (i < 4*n_sixth) {
            k = i - 3*n_sixth;
            red = 255;
            green = 0;
            blue = std::max(255 - calor_value*k, 0);
        }
        //green +
        else if (i < 5*n_sixth) {
            k = i - 4*n_sixth;
            red = 255;
            green = std::min(calor_value*k, 255);
            blue = 0;
        }
        //red -
        else{
            k = i - 5*n_sixth;
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

std::vector<unsigned int> Simulation::getColors() {
    std::vector<unsigned int> v;
    v.reserve(size_);
    for (int i = 0; i < size_; ++i) {
            v.push_back(pendulums[i].getColor());
    }
    return v;
}

std::vector<double> Simulation::getPositions() {
    std::vector<double> v;
    for (int i = 0; i < size_; ++i) {
        v.push_back(pendulums[i].getTheta1());
        v.push_back(pendulums[i].getTheta2());
    }
    return v;
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
    return pendulums[id].getTheta1();
}
//todo getTheta2
