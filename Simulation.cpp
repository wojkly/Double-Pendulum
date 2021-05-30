//
// Created by wojkly on 5/30/21.
//

#include "Simulation.h"
#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"

using namespace sf;

Simulation::Simulation(int n, double posDiff, double d) {
    size_ = n;
    delta = d;
    pendulums = new DoublePendulum[n];
    for (int i = 0; i < n; ++i) {
        pendulums[i] = DoublePendulum(24354253, PendulumEquation(THETA1 + posDiff*i,THETA2 + posDiff*i));
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
        v.push_back(pendulums->getColor());
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
