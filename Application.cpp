//
// Created by wojkly on 5/29/21.
//
#include "Application.h"

Application::Application(ArgumentParser argumentParser) {
    simDims = argumentParser.getSimDims();
    mouseYoffset = argumentParser.getMouseYoffset();
    mouseGrabThreshhold = argumentParser.getMouseGrabThreshhold();

    middleX = simDims / 2;
    middleY = simDims / 2;

    double l1 = argumentParser.getLength1();
    double l2 = argumentParser.getLength2();
    L1Scaled = (float ) l1 / (l1 + l2) * middleX - simDims / 100;
    L2Scaled = (float ) l2 / (l1 + l2) * middleX - simDims / 100;
}


//todo vector 2f


int Application::pendulumGrabbed(RenderWindow &window, Simulation &simulation) {
    float mouseX, mouseY;
    Vector2i mousePos = Mouse::getPosition();
    Vector2i windowPos = window.getPosition();
    mouseX = mousePos.x - windowPos.x;
    mouseY = mousePos.y - windowPos.y - mouseYoffset;

    double theta1, theta2, minDistance = 1000.0, distance;

    const Vector2f position0(middleX, middleY);
    Vector2f position1, position2;

    int grabbedID = -1;
    VertexArray lines(LineStrip, 3);
    for (int i = 0; i < simulation.size(); i++) {
        theta1 = simulation.getTheta1(i);
        theta2 = simulation.getTheta2(i);

        position1 = getPendulumCoords(theta1, position0, true);
        distance = sqrt((mouseX - position1.x)*(mouseX - position1.x) + (mouseY - position1.y)*(mouseY - position1.y));
        if (distance < minDistance){
            minDistance = distance;
            grabbedID = i;
        }
        position2 = getPendulumCoords(theta2, position1, false);
        distance = sqrt((mouseX - position2.x)*(mouseX - position2.x) + (mouseY - position2.y)*(mouseY - position2.y));
        if (distance < minDistance){
            minDistance = distance;
            grabbedID = i + (int)simulation.size();
        }
    }

    if (minDistance < mouseGrabThreshhold)
        return grabbedID;
    return -1;
}

double Application::getMouseTheta(double x, double y, double xRelativeTo, double yRelativeTo) const {
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

void Application::pendulumMove(RenderWindow &window, Simulation &simulation, unsigned int grabbed_id) const {
    float mouseX, mouseY;
    double theta;
    Vector2i mousePos = Mouse::getPosition();
    Vector2i windowPos = window.getPosition();
    mouseX = mousePos.x - windowPos.x;
    mouseY = mousePos.y - windowPos.y - mouseYoffset;
    if (grabbed_id < simulation.size()) {
        theta = getMouseTheta(mouseX, mouseY, -1, -1);
        simulation.setTheta1(grabbed_id, theta);
    }
    else{
        grabbed_id -= simulation.size();
        const Vector2f position0(middleX, middleY);
        Vector2f position1;
        position1 = getPendulumCoords(simulation.getTheta1(grabbed_id), position0, true);

        theta = getMouseTheta(mouseX,mouseY,position1.x,position1.y);
        simulation.setTheta2(grabbed_id,theta);
    }
}

//handles clicking -> holding -> releasing the mouse button
void Application::handleMouse(RenderWindow &window, Simulation &simulation) {
    int grabbed_id = pendulumGrabbed(window, simulation);
    if (grabbed_id != -1) {
        while (true) {
            pendulumMove(window, simulation, (unsigned int) grabbed_id);
            window.clear();
            drawPendulums(window, simulation);
            window.display();
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == Event::MouseButtonReleased) {
                    return;
                }
                if (event.type == Event::Closed)
                    window.close();
            }
        }
    }
}

void Application::initApp(Simulation simulation) {
    RenderWindow simWindow( VideoMode(simDims,simDims),"Double Pendulum Simulation");
    simWindow.setVerticalSyncEnabled(true);
    while (simWindow.isOpen())
    {
        sf::Event event{};
        while (simWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                simWindow.close();
            if (event.type == Event::MouseButtonPressed) {
                handleMouse(simWindow, simulation);
            }
        }
        simWindow.clear();
        drawPendulums(simWindow, simulation);
        simulation.step();
        simWindow.display();
    }
}

Vector2f Application::getPendulumCoords(double theta, Vector2f relativeTo, bool firstArm) const {
    Vector2f result;
    double l;
    if (firstArm){
        l = L1Scaled;
    } else {
        l = L2Scaled;
    }
    result.x = relativeTo.x - l * sin(theta);
    result.y  = relativeTo.y + l * cos(theta);
    return result;
}

void Application::drawPendulums(sf::RenderWindow &window, Simulation &simulation) const {
    double theta1, theta2;
    const Vector2f position0(middleX, middleY);
    Vector2f position1, position2;
    Color color;
    VertexArray lines(LineStrip, 3);
    for (int i = 0; i < simulation.size();  i++) {
        theta1 = simulation.getTheta1(i);
        theta2 = simulation.getTheta2(i);
        color = Color(simulation.getColor(i));

        position1 = getPendulumCoords(theta1, position0, true);
        position2 = getPendulumCoords(theta2, position1, false);

        lines[0].position = position0;
        lines[0].color = color;
        lines[1].position = position1;
        lines[1].color = color;
        lines[2].position = position2;
        lines[2].color = color;
        //todo draw circles in the middle, at the end itd. proportional to mass
        window.draw(lines);
    }
}