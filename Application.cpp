//
// Created by wojkly on 5/29/21.
//
#include <iostream>
#include <unistd.h>
#include <cmath>
#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"
#include "SFML/include/SFML/Window/Mouse.hpp"
#include "Application.h"
#include "Simulation.h"
#include <vector>
#include <cmath>
using namespace std;
using namespace sf;

Application::Application() {
    L1Scaled = (float ) LENGTH1 / (LENGTH1 + LENGTH2) * middleX - SIM_DIMS / 50;
    L2Scaled = (float ) LENGTH2 / (LENGTH1 + LENGTH2) * middleX - SIM_DIMS / 50;
}
//todo coords ->> thetas
//todo thetas -> coords
void Application::handleMouse(unsigned int mouseX, unsigned int mouseY) {

//    cout<<mouseX<<" "<<mouseY<<endl;
}

int Application::pendulumOneGrabbed(RenderWindow &window, Simulation &simulation, unsigned int debug) {
    float mouseX, mouseY;
    Vector2i mousePos = Mouse::getPosition();
    Vector2i windowPos = window.getPosition();
    mouseX = mousePos.x - windowPos.x;
    mouseY = mousePos.y - windowPos.y - MOUSE_Y_OFFSET;

    vector<double> thetas = simulation.getPositions();
    double theta1, x1, y1, minDistance = 1000.0, distance;
    int grabbedID = -1;
    VertexArray lines(LineStrip, 3);
    for (int i = 0; i < simulation.size(); i++) {
        theta1 = thetas[2 * i];

        x1 = middleX - L1Scaled * sin(theta1);
        y1 = middleY + L1Scaled * cos(theta1);
        distance = sqrt((mouseX - x1)*(mouseX - x1) + (mouseY - y1)*(mouseY - y1));
        if (distance < minDistance){
            minDistance = distance;
            grabbedID = i;
        }
    }

    if (minDistance < 100)
        return grabbedID;
    return -1;
}

double Application::getMouseThetaOne(double x, double y) {
    double L, Y,X, theta;
    Y = abs(y - middleY);
    X = abs(x - middleX);
    theta = atan(Y / X);
    //left-down
    if (x <= middleX && y >= middleY)
        theta = M_PI / 2 - theta;
    //left-up
    else if (x <= middleX &&  y <= middleY)
        theta += M_PI / 2;
    //right-up
    else if (x >= middleX &&  y <= middleY)
        theta = 3 * M_PI / 2 - theta;
    //right-down
    else if (x >= middleX &&  y >= middleY)
        theta += 3 * M_PI / 2;
    return theta;
}


void Application::pendulumOneMove(RenderWindow &window, Simulation &simulation, unsigned int grabbed_id, unsigned int debug) {
    float mouseX, mouseY;
    Vector2i mousePos = Mouse::getPosition();
    Vector2i windowPos = window.getPosition();
    mouseX = mousePos.x - windowPos.x;
    mouseY = mousePos.y - windowPos.y - MOUSE_Y_OFFSET;
    double thetaOne = getMouseThetaOne(mouseX,mouseY);
//    cout<<thetaOne<<endl;
    simulation.setTheta1(grabbed_id,thetaOne);
}

//todo add args
void Application::initApp() {Simulation simulation(1,0.0001,0.005);


    RenderWindow simWindow( VideoMode(SIM_DIMS,SIM_DIMS),"Pendulum Simulation");
    simWindow.setVerticalSyncEnabled(true);
    unsigned int debug=0;
    bool mouse_released;
    while (simWindow.isOpen())
    {
        sf::Event event{};
        while (simWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                simWindow.close();
            if (event.type == Event::MouseButtonPressed) {
                int grabbed_id = pendulumOneGrabbed(simWindow, simulation, debug);
                cout<<grabbed_id<<endl;
                if (grabbed_id != -1) {
                    mouse_released = false;
                    while (true) {
                        pendulumOneMove(simWindow, simulation, (unsigned int)grabbed_id, debug);
                        simWindow.clear();
                        drawPendulums(simWindow, simulation, debug);
                        simWindow.display();
                        while (simWindow.pollEvent(event)) {
                            if (event.type == Event::MouseButtonReleased) {
                                mouse_released = true;
                                break;
                            }
                            if (event.type == Event::Closed)
                                simWindow.close();
                        }
                        if (mouse_released)
                            break;
                    }
                }
            }
        }
        simWindow.clear();
        drawPendulums(simWindow, simulation, debug);
        debug++;
        simulation.step();
        simWindow.display();
    }
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
        if (debug % 25 == 0)
            cout<<theta1<<" "<<theta2<<" "<<endl;

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

