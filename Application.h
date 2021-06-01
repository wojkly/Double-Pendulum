//
// Created by wojkly on 5/29/21.
//

#ifndef DOUBLE_PENDULUM_SIMULATION_APPLICATION_H
#define DOUBLE_PENDULUM_SIMULATION_APPLICATION_H


//
// Created by wojkly on 5/29/21.
//

#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"
#include "config.h"
#include "DoublePendulum.h"
#include "Simulation.h"
#include "ArgumentParser.h"
#include <vector>

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
    void drawPendulums(sf::RenderWindow &window, Simulation &simulation, unsigned int debug);

    void handleMouse(unsigned int mouseX, unsigned int mouseY);

    int pendulumGrabbed(sf::RenderWindow &window, Simulation &simulation, unsigned int debug);
    double getMouseTheta(double x, double y, double xRelativeTo, double yRelativeTo);
    void pendulumMove(sf::RenderWindow &window, Simulation &simulation, unsigned int  grabbed_id, unsigned int debug);

};


#endif //DOUBLE_PENDULUM_SIMULATION_APPLICATION_H