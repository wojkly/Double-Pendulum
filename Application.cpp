//
// Created by wojkly on 5/29/21.
//
#include <iostream>
#include <unistd.h>
#include <cmath>
#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"
#include "Application.h"
#include "Simulation.h"
#include <vector>
Application::Application() {
    L1Scaled = (float ) LENGTH1 / (LENGTH1 + LENGTH2) * middleX - SIM_DIMS / 50;
    L2Scaled = (float ) LENGTH2 / (LENGTH1 + LENGTH2) * middleX - SIM_DIMS / 50;
}

using namespace std;
using namespace sf;

//todo add args
void Application::initApp() {
    Simulation simulation(1,0.0001,0.005);


    RenderWindow simWindow( VideoMode(SIM_DIMS,SIM_DIMS),"Pendulum Simulation");
    simWindow.setVerticalSyncEnabled(true);
    unsigned int debug=0;
    while (simWindow.isOpen())
    {
        sf::Event event{};
        while (simWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                simWindow.close();
        }
        simWindow.clear();
        drawPendulums(simWindow, simulation, debug);
        debug++;
        simulation.step();
        simWindow.display();
    }
}

void Application::handleMouse() {

}

void Application::drawPendulums(sf::RenderWindow &window, Simulation &simulation, unsigned int debug) {
    vector<unsigned int> colors = simulation.getColors();
    vector<double> thetas = simulation.getPositions();
    double theta1, theta2, x1, y1, x2, y2;
    unsigned int color;
    VertexArray lines(LineStrip, 3);
    for (int i = 0; i < simulation.size();  i++) {
        theta1 = thetas[2*i];
        theta2 = thetas[2*i+1];
        color = colors[i];

        x1 = middleX - L1Scaled*sin(theta1);
        y1 = middleY + L1Scaled*cos(theta1);
        x2 = x1 - L2Scaled*sin(theta2);
        y2 = y1 + L2Scaled*cos(theta2);
//        if (debug % 25 == 0)
//            cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
//        if (debug % 25 == 0)
//            cout<<theta1<<" "<<theta2<<" "<<endl;

        lines[0].position = Vector2f(middleX,middleY);
        lines[0].color = Color(color);
        lines[1].position = Vector2f(x1, y1);
        lines[1].color = Color(color);
        lines[2].position = Vector2f(x2, y2);
        lines[2].color = Color(color);
        window.draw(lines);
    }
//    if (debug % 25 == 0) {
//        cout << "============================" << endl;
//        sleep(5);
//    }
}
