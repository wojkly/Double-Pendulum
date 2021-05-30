//
// Created by wojkly on 5/29/21.
//

#ifndef GAME_OF_LIFE_DOUBLEPENDULUM_H
#define GAME_OF_LIFE_DOUBLEPENDULUM_H
#include <iosfwd>
#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"
#include "PendulumEquation.h"

class DoublePendulum {
    PendulumEquation equation;
    sf::Color color;
public:
    DoublePendulum() = default;
    DoublePendulum(sf::Color c, PendulumEquation equation);
    void makeStep(double delta);
    double getTheta1() const;
    double getTheta2() const;
    sf::Color getColor();
};

std::ostream & operator<<(std::ostream & os, const DoublePendulum &pendulum);

#endif //GAME_OF_LIFE_DOUBLEPENDULUM_H
