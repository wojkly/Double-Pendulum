//
// Created by wojkly on 5/30/21.
//

#ifndef DOUBLE_PENDULUM_SIMULATION_SIMULATION_H
#define DOUBLE_PENDULUM_SIMULATION_SIMULATION_H

#include "config.h"
#include "DoublePendulum.h"
#include "ArgumentParser.h"
#include <vector>

class Simulation {
    size_t size_;
    DoublePendulum *pendulums;
    double delta;
public:
    explicit Simulation(ArgumentParser argumentParser);
    ~Simulation();
    void step();

    //todo remove these vectors
    std::vector<unsigned int> getColors();
    std::vector<double> getPositions();
    double getTheta1(unsigned int id);
    size_t size() const;
    void setTheta1(int id, double theta1);
    void setTheta2(int id, double theta2);

};


#endif //DOUBLE_PENDULUM_SIMULATION_SIMULATION_H
