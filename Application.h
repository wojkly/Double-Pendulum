//
// Created by wojkly on 5/29/21.
//

#ifndef DOUBLE_PENDULUM_SIMULATION_APPLICATION_H
#define DOUBLE_PENDULUM_SIMULATION_APPLICATION_H

#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"
#include "DoublePendulum.h"
#include "Simulation.h"
#include "ArgumentParser.h"
#include <iostream>
#include <unistd.h>
#include <cmath>
using namespace std;
using namespace sf;

class Application {
    unsigned int simDims;
    unsigned int mouseYoffset;
    unsigned int mouseGrabThreshhold;
    double middleX;
    double middleY;
    double L1Scaled;
    double L2Scaled;
public:
    explicit Application(ArgumentParser argumentParser);
    void initApp(Simulation simulation);
    void drawPendulums(RenderWindow &window, Simulation &simulation) const;


    int pendulumGrabbed(RenderWindow &window, Simulation &simulation);
    double getMouseTheta(double x, double y, double xRelativeTo, double yRelativeTo) const;
    void pendulumMove(RenderWindow &window, Simulation &simulation, unsigned int  grabbed_id) const;

    void handleMouse(RenderWindow &window, Simulation &simulation);

};


#endif //DOUBLE_PENDULUM_SIMULATION_APPLICATION_H