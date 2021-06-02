//
// Created by wojkly on 5/29/21.
//
#include "Application.h"

//todo df eliminate vectors
Application::Application(ArgumentParser argumentParser) {
    simDims = argumentParser.getSimDims();
    mouseYoffset = argumentParser.getMouseYoffset();
    mouseGrabThreshhold = argumentParser.getMouseGrabThreshhold();

    middleX = simDims / 2;
    middleY = simDims / 2;

    double l1 = argumentParser.getLength1();
    double l2 = argumentParser.getLength2();
    L1Scaled = (float ) l1 / (l1 + l2) * middleX - simDims / 50;
    L2Scaled = (float ) l2 / (l1 + l2) * middleX - simDims / 50;
}


//todo vector 2f
//function get x1(th1)
//function get y1(th1)
//function get x2(x1, x1, th2)
//function get y2(x1, y1, th2)

int Application::pendulumGrabbed(RenderWindow &window, Simulation &simulation) {
    float mouseX, mouseY;
    Vector2i mousePos = Mouse::getPosition();
    Vector2i windowPos = window.getPosition();
    mouseX = mousePos.x - windowPos.x;
    mouseY = mousePos.y - windowPos.y - mouseYoffset;

    double theta1, theta2, x1, y1, x2, y2, minDistance = 1000.0, distance;
    int grabbedID = -1;
    VertexArray lines(LineStrip, 3);
    for (int i = 0; i < simulation.size(); i++) {
        theta1 = simulation.getTheta1(i);
        theta2 = simulation.getTheta2(i);

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
    double theta, x1, y1;
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
        //todo use single getters instead of all-at-once
        x1 = middleX - L1Scaled*sin(simulation.getTheta1(grabbed_id));
        y1 = middleY + L1Scaled*cos(simulation.getTheta1(grabbed_id));
        theta = getMouseTheta(mouseX,mouseY,x1,y1);
        simulation.setTheta2(grabbed_id,theta);
    }
//    cout<<thetaOne<<endl;
}

void Application::handleMouse(RenderWindow &window, Simulation &simulation) {
    int grabbed_id = pendulumGrabbed(window, simulation);
//    cout<<grabbed_id<<endl;
    if (grabbed_id != -1) {
        //if grabbed
        bool mouse_released = false;
        while (true) {
            pendulumMove(window, simulation, (unsigned int) grabbed_id);
            window.clear();
            drawPendulums(window, simulation);
            window.display();
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == Event::MouseButtonReleased) {
                    mouse_released = true;
                    break;
                }
                if (event.type == Event::Closed)
                    window.close();
            }
            if (mouse_released)
                break;
        }
    }
}

//todo add args
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


void Application::drawPendulums(sf::RenderWindow &window, Simulation &simulation) const {
    double theta1, theta2, x1, y1, x2, y2;
    Color color;
    VertexArray lines(LineStrip, 3);
    for (int i = 0; i < simulation.size();  i++) {
        //todo copy into some function
        theta1 = simulation.getTheta1(i);
        theta2 = simulation.getTheta2(i);
        color = Color(simulation.getColor(i));

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