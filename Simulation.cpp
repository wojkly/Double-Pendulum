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

    ColorManager::setInitialValues(size_);

    double initTheta1 = argumentParser.getThetaInit1();
    double initTheta2 = argumentParser.getThetaInit2();
    double posDiff = argumentParser.getPendulumInitPositionDifference();

    for (int i = 0; i < size_; ++i) {
        pendulums[i] = DoublePendulum(ColorManager::getColor(i),
                                      PendulumEquation(initTheta1 + posDiff*i,initTheta2 + posDiff*i));
    }
}

Simulation::~Simulation() {
    delete[] pendulums;
}

void Simulation::step() {
    for (int i = 0; i < size_; ++i) {
        pendulums[i].makeStep(delta);
    }
}

size_t Simulation::size() const {
    return size_;
}

void Simulation::setTheta1(unsigned int id, double theta1) {
    if (id > size())
        throw std::out_of_range("error, trying to set theta1 of nonexistent id");
    pendulums[id].setTheta1(theta1);
}

void Simulation::setTheta2(unsigned int id, double theta2) {
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
