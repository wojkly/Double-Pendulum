//
// Created by wojkly on 5/30/21.
//

#ifndef GAME_OF_LIFE_SIMULATION_H
#define GAME_OF_LIFE_SIMULATION_H

#include "config.h"
#include "DoublePendulum.h"
#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"
#include <vector>

class Simulation {
    size_t size_;
    DoublePendulum *pendulums;
    double delta;
public:
    Simulation(int n, double posDiff, double d);
    ~Simulation();
    void step();
    std::vector<unsigned int> getColors();
    std::vector<double> getPositions();
    size_t size() const;

};


#endif //GAME_OF_LIFE_SIMULATION_H
