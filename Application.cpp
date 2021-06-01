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
using namespace std;
using namespace sf;

Application::Application() {
    L1Scaled = (float ) LENGTH1 / (LENGTH1 + LENGTH2) * middleX - SIM_DIMS / 50;
    L2Scaled = (float ) LENGTH2 / (LENGTH1 + LENGTH2) * middleX - SIM_DIMS / 50;
}

void Application::handleMouse(unsigned int mouseX, unsigned int mouseY) {

//    cout<<mouseX<<" "<<mouseY<<endl;
}

int Application::pendulumGrabbed(RenderWindow &window, Simulation &simulation, unsigned int debug) {
    float mouseX, mouseY;
    Vector2i mousePos = Mouse::getPosition();
    Vector2i windowPos = window.getPosition();
    mouseX = mousePos.x - windowPos.x;
    mouseY = mousePos.y - windowPos.y - MOUSE_Y_OFFSET;

    //todo use single getters instead of all-at-once
    vector<double> thetas = simulation.getPositions();
    double theta1, theta2, x1, y1, x2, y2, minDistance = 1000.0, distance;
    int grabbedID = -1;
    VertexArray lines(LineStrip, 3);
    for (int i = 0; i < simulation.size(); i++) {
        theta1 = thetas[2 * i];
        theta2 = thetas[2 * i + 1];

        x1 = middleX - L1Scaled * sin(theta1);
        y1 = middleY + L1Scaled * cos(theta1);
        distance = sqrt((mouseX - x1)*(mouseX - x1) + (mouseY - y1)*(mouseY - y1));
        if (distance < minDistance){
            minDistance = distance;
            grabbedID = i;
        }
        x2 = x1 - L2Scaled*sin(theta2);
        y2 = y1 + L2Scaled*cos(theta2);
        distance = sqrt((mouseX - x2)*(mouseX - x2) + (mouseY - y2)*(mouseY - y2));
        if (distance < minDistance){
            minDistance = distance;
            grabbedID = i + (int)simulation.size();
        }
    }

    if (minDistance < MOUSE_PENDULUM_MAX_DIST)
        return grabbedID;
    return -1;
}

double Application::getMouseTheta(double x, double y, double xRelativeTo, double yRelativeTo) {
    double L, Y,X, theta;
    if (xRelativeTo < 0 || yRelativeTo < 0){
        xRelativeTo = middleX;
        yRelativeTo = middleY;
    }
    Y = abs(y - yRelativeTo);
    X = abs(x - xRelativeTo);
    theta = atan(Y / X);
    //left-down
    if (x <= xRelativeTo && y >= yRelativeTo)
        theta = M_PI / 2 - theta;
    //left-up
    else if (x <= xRelativeTo &&  y <= yRelativeTo)
        theta += M_PI / 2;
    //right-up
    else if (x >= xRelativeTo &&  y <= yRelativeTo)
        theta = 3 * M_PI / 2 - theta;
    //right-down
    else if (x >= xRelativeTo &&  y >= yRelativeTo)
        theta += 3 * M_PI / 2;
    return theta;
}


void Application::pendulumMove(RenderWindow &window, Simulation &simulation, unsigned int grabbed_id, unsigned int debug) {
    float mouseX, mouseY;
    double theta, x1, y1;
    Vector2i mousePos = Mouse::getPosition();
    Vector2i windowPos = window.getPosition();
    mouseX = mousePos.x - windowPos.x;
    mouseY = mousePos.y - windowPos.y - MOUSE_Y_OFFSET;
    if (grabbed_id < simulation.size()) {
        theta = getMouseTheta(mouseX, mouseY, -1, -1);
        simulation.setTheta1(grabbed_id, theta);
    }
    else{
        grabbed_id -= simulation.size();
        //todo use single getters instead of all-at-once
        x1 = middleX - L1Scaled*sin(simulation.getTheta1(grabbed_id));
        y1 = middleY + L1Scaled*cos(simulation.getTheta1(grabbed_id));
        theta = getMouseTheta(mouseX,mouseY,x1,y1);
        simulation.setTheta2(grabbed_id,theta);
    }
//    cout<<thetaOne<<endl;

}

//todo add args
void Application::initApp(Simulation simulation) {
    RenderWindow simWindow( VideoMode(SIM_DIMS,SIM_DIMS),"Double Pendulum Simulation");
    simWindow.setVerticalSyncEnabled(true);
    //todo remove debug variable
    unsigned int debug=0;
    bool mouse_released;
    int grabbed_id = -1;
    while (simWindow.isOpen())
    {
        sf::Event event{};
        while (simWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                simWindow.close();
            if (event.type == Event::MouseButtonPressed) {
                //todo copy that into mouse pressed handler
                grabbed_id = pendulumGrabbed(simWindow, simulation, debug);
                cout<<grabbed_id<<endl;
                if (grabbed_id != -1) {
                    //if grabbed
                    mouse_released = false;
                    while (true) {
                        pendulumMove(simWindow, simulation, (unsigned int) grabbed_id, debug);
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
    Color color;
    VertexArray lines(LineStrip, 3);
    for (int i = 0; i < simulation.size();  i++) {
        theta1 = thetas[2*i];
        theta2 = thetas[2*i+1];
        color = Color(colors[i]);
        //todo use single getters instead of all-at-once
        x1 = middleX - L1Scaled*sin(theta1);
        y1 = middleY + L1Scaled*cos(theta1);
        x2 = x1 - L2Scaled*sin(theta2);
        y2 = y1 + L2Scaled*cos(theta2);

        lines[0].position = Vector2f(middleX,middleY);
        lines[0].color = color;
        lines[1].position = Vector2f(x1, y1);
        lines[1].color = color;
        lines[2].position = Vector2f(x2, y2);
        lines[2].color = color;
        //todo draw circles in the middle, at the end itd. proportional to mass
        window.draw(lines);
    }
}