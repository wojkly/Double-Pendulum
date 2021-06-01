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
#include "ArgumentParser.h"
#include <vector>

class Application {
    float middleX{(float )SIM_DIMS / 2};
    float middleY{(float )SIM_DIMS / 2};
    float L1Scaled;
    float L2Scaled;
public:
    Application();
    void initApp(Simulation simulation);
    void drawPendulums(sf::RenderWindow &window, Simulation &simulation, unsigned int debug);

    void handleMouse(unsigned int mouseX, unsigned int mouseY);

    int pendulumGrabbed(sf::RenderWindow &window, Simulation &simulation, unsigned int debug);
    double getMouseTheta(double x, double y, double xRelativeTo, double yRelativeTo);
    void pendulumMove(sf::RenderWindow &window, Simulation &simulation, unsigned int  grabbed_id, unsigned int debug);

};


#endif //GAME_OF_LIFE_APPLICATION_H