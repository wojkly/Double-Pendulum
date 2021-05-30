//
// Created by wojkly on 5/29/21.
//
#include <iostream>
#include <unistd.h>
#include <cmath>
#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"
#include "Application.h"

Application::Application() = default;

using namespace std;
using namespace sf;

void Application::initApp() {
    RenderWindow simWindow( VideoMode(SIM_WIDTH,SIM_HEIGHT),"Pendulum Simulation");
    simWindow.setVerticalSyncEnabled(true);
    DoublePendulum pendulums[PENDULUM_COUNT];
    for (int i = 0; i < PENDULUM_COUNT; ++i) {
        pendulums[i] = DoublePendulum(Color(i, 0, 150), PendulumEquation(THETA1 + 0.00001*i,THETA2 + 0.00001*i));
    }
//    DoublePendulum pendulum(sf::Color::Green, PendulumEquation(THETA1,THETA2));

    float middleX = (float )SIM_WIDTH / 2;
    float middleY = (float )SIM_HEIGHT / 2;
    float circleRadius = 5;
    float L1Scaled = (float ) LENGTH1 / (LENGTH1 + LENGTH2) * middleX;
    float L2Scaled = (float ) LENGTH2 / (LENGTH1 + LENGTH2) * middleX;
    VertexArray lines(LineStrip, 3);
    CircleShape circle0;
    circle0.setRadius(circleRadius);
    circle0.setPosition(middleX - circleRadius, middleY - circleRadius);
    circle0.setFillColor(Color::Red);
    while (simWindow.isOpen())
    {
        sf::Event event{};
        while (simWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                simWindow.close();
        }
        simWindow.clear();
        for (auto & pendulum : pendulums) {
            double theta1 = pendulum.getTheta1();
            double theta2 = pendulum.getTheta2();
            double x1, y1, x2, y2;
            x1 = middleX - L1Scaled*sin(theta1);
            y1 = middleY + L1Scaled*cos(theta1);
            x2 = x1 - L2Scaled*sin(theta2);
            y2 = y1 + L2Scaled*cos(theta2);
            Color color = pendulum.getColor();
            lines[0].position = Vector2f(middleX,middleY);
            lines[0].color = color;
            lines[1].position = Vector2f(x1, y1);
            lines[1].color = color;
            lines[2].position = Vector2f(x2, y2);
            lines[2].color = color;
            simWindow.draw(lines);

            pendulum.makeStep(0.005);
        }
        simWindow.display();


//        usleep(100);
//        cout << pendulum;
    }
}