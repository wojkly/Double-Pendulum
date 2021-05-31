//
// Created by wojkly on 5/30/21.
//

#include "Simulation.h"
#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"
#define COLOR_SCALAR 4
using namespace sf;

Simulation::Simulation(int n, double posDiff, double d) {
    size_ = n;
    delta = d;
    pendulums = new DoublePendulum[n];

    int n_sixth = n / 6;
    int calor_value = 255 * 6 / n;
    for (int i = 0; i < n; ++i) {
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
        pendulums[i] = DoublePendulum(alpha + 256*(blue + 256 *(green + 256* red)), PendulumEquation(THETA1 + posDiff*i,THETA2 + posDiff*i));
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
