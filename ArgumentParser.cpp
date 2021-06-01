//
// Created by wojkly on 6/1/21.
//

#include "ArgumentParser.h"



void ArgumentParser::init(const string& filename) {

    fstream configFile;
    configFile.open(filename, ios::in);
    if (configFile.is_open()){
        string line;
        getline(configFile,line);
        if (line == "simDims") {
            getline(configFile, line);
            simDims = stoi(line);
        }
        if (line == "mouseYoffset") {
            getline(configFile, line);
            mouseYoffset = stoi(line);
        }
        if (line == "mouseGrabThreshhold") {
            getline(configFile, line);
            mouseGrabThreshhold = stoi(line);
        }
        if (line == "gravity") {
            getline(configFile, line);
            gravity = stoi(line);
        }
        if (line == "mass1") {
            getline(configFile, line);
            mass1 = stoi(line);
        }
        if (line == "mass2") {
            getline(configFile, line);
            mass2 = stoi(line);
        }
        if (line == "thetaInit1") {
            getline(configFile, line);
            thetaInit1 = stoi(line);
        }
        if (line == "thetaInit2") {
            getline(configFile, line);
            thetaInit2 = stoi(line);
        }
        if (line == "length1") {
            getline(configFile, line);
            length1 = stoi(line);
        }
        if (line == "length2") {
            getline(configFile, line);
            length2 = stoi(line);
        }
        configFile.close();
    } else {
        perror("error with reading config file\n");
        exit(EXIT_FAILURE);
    }
}

unsigned int ArgumentParser::getSimDims() const {
    return simDims;
}

unsigned int ArgumentParser::getMouseYoffset() const {
    return mouseYoffset;
}

unsigned int ArgumentParser::getMouseGrabThreshhold() const{
    return mouseGrabThreshhold;
}

double ArgumentParser::getGravity() const{
    return gravity;
}

double ArgumentParser::getMass1() const{
    return mass1;
}
double ArgumentParser::getMass2() const{
    return mass2;
}

double ArgumentParser::getThetaInit1() const{
    return thetaInit1;
}
double ArgumentParser::getThetaInit2() const{
    return thetaInit2;
}

double ArgumentParser::getLength1() const{
    return length1;
}
double ArgumentParser::getLength2() const{
    return length2;
}
