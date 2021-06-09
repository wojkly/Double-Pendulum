//
// Created by wojkly on 5/30/21.
//

#ifndef DOUBLE_PENDULUM_SIMULATION_SIMULATION_H
#define DOUBLE_PENDULUM_SIMULATION_SIMULATION_H

#include "DoublePendulum.h"
#include "ArgumentParser.h"
#include "ColorManager.h"

class Simulation {
    size_t size_;
    DoublePendulum *pendulums;
    double delta;
public:
    explicit Simulation(ArgumentParser argumentParser);
    ~Simulation();
    void step();

    size_t size() const;
    double getTheta1(unsigned int id);
    double getTheta2(unsigned int id);
    unsigned int getColor(unsigned int id);

    void setTheta1(unsigned int id, double theta1);
    void setTheta2(unsigned int id, double theta2);

};


#endif //DOUBLE_PENDULUM_SIMULATION_SIMULATION_H
