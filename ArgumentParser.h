//
// Created by wojkly on 6/1/21.
//

#ifndef DOUBLE_PENDULUM_SIMULATION_ARGUMENTPARSER_H
#define DOUBLE_PENDULUM_SIMULATION_ARGUMENTPARSER_H


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ArgumentParser {
    unsigned int simDims;
    unsigned int mouseYoffset;
    unsigned int mouseGrabThreshhold;
    unsigned int pendulumCount;
    double pendulumInitPositionDifference;
    double timeInterval;
    double gravity;
    double mass1;
    double mass2;
    double thetaInit1;
    double thetaInit2;
    double length1;
    double length2;

public:
    void init(const string& filename);

    unsigned int getSimDims() const{return simDims;};
    unsigned int getMouseYoffset() const{return mouseYoffset;};
    unsigned int getMouseGrabThreshhold()const{return mouseGrabThreshhold;};

    unsigned int getPendulumCount()const{return pendulumCount;};
    double getPendulumInitPositionDifference()const{return pendulumInitPositionDifference;};
    double getTimeInterval()const{return timeInterval;};

    double getGravity()const{return gravity;};
    double getMass1()const{return mass1;};
    double getMass2()const{return mass2;};
    double getThetaInit1()const{return thetaInit1;};
    double getThetaInit2()const{return thetaInit2;};
    double getLength1()const{return length1;};
    double getLength2()const{return length2;};

};


#endif //DOUBLE_PENDULUM_SIMULATION_ARGUMENTPARSER_H
