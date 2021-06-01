//
// Created by wojkly on 6/1/21.
//

#ifndef GAME_OF_LIFE_ARGUMENTPARSER_H
#define GAME_OF_LIFE_ARGUMENTPARSER_H


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ArgumentParser {
    unsigned int simDims;
    unsigned int mouseYoffset;
    unsigned int mouseGrabThreshhold;
    double gravity;
    double mass1;
    double mass2;
    double thetaInit1;
    double thetaInit2;
    double length1;
    double length2;

public:
    void init(const string& filename);

    unsigned int getSimDims() const;
    unsigned int getMouseYoffset() const;
    unsigned int getMouseGrabThreshhold()const;
    double getGravity()const;
    double getMass1()const;
    double getMass2()const;
    double getThetaInit1()const;
    double getThetaInit2()const;
    double getLength1()const;
    double getLength2()const;

};


#endif //GAME_OF_LIFE_ARGUMENTPARSER_H
