//
// Created by wojkly on 5/29/21.
//

#ifndef GAME_OF_LIFE_APPLICATION_H
#define GAME_OF_LIFE_APPLICATION_H


//
// Created by wojkly on 5/29/21.
//

#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"
#include "config.h"
#include "DoublePendulum.h"
#include "Simulation.h"
#include <vector>

class Application {
    float middleX{(float )SIM_DIMS / 2};
    float middleY{(float )SIM_DIMS / 2};
    float L1Scaled;
    float L2Scaled;
public:
    Application();
    void initApp();
    void drawPendulums(sf::RenderWindow &window, Simulation &simulation, unsigned int debug);
    void handleMouse(unsigned int mouseX, unsigned int mouseY);
    int pendulumOneGrabbed(sf::RenderWindow &window, Simulation &simulation, unsigned int debug);
    void pendulumOneMove(sf::RenderWindow &window, Simulation &simulation, unsigned int  grabbed_id, unsigned int debug);
    double getMouseThetaOne(double x, double y);
};


#endif //GAME_OF_LIFE_APPLICATION_H