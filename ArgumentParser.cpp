//
// Created by wojkly on 6/1/21.
//

#include "ArgumentParser.h"



void ArgumentParser::init(const string& filename) {

    fstream configFile;
    configFile.open(filename, ios::in);
    if (configFile.is_open()){
        string line;
        //============ VISUALIZATION PARAMETERS
        getline(configFile,line);
        if (line == "simDims") {
            getline(configFile, line);
            simDims = stoi(line);
        } else
            throw std::invalid_argument("config file line 1 - should be: simDims");
        getline(configFile,line);
        if (line == "mouseYoffset") {
            getline(configFile, line);
            mouseYoffset = stoi(line);
        } else
            throw std::invalid_argument("config file line 3 - should be: mouseYoffset");
        getline(configFile,line);
        if (line == "mouseGrabThreshhold") {
            getline(configFile, line);
            mouseGrabThreshhold = stoi(line);
        } else
            throw std::invalid_argument("config file line 5 - should be: mouseGrabThreshhold");
        //============ SIMULATION PARAMETERS
        getline(configFile,line);
        if (line == "pendulumCount") {
            getline(configFile, line);
            pendulumCount = stoi(line);
        } else
            throw std::invalid_argument("config file line 7 - should be: pendulumCount");
        getline(configFile,line);
        if (line == "pendulumInitPositionDifference") {
            getline(configFile, line);
            pendulumInitPositionDifference = stod(line);
        } else
            throw std::invalid_argument("config file line 9 - should be: pendulumInitPositionDifference");
        getline(configFile,line);
        if (line == "timeInterval") {
            getline(configFile, line);
            timeInterval = stod(line);
        } else
            throw std::invalid_argument("config file line 11 - should be: timeInterval");
        getline(configFile,line);
        if (line == "gravity") {
            getline(configFile, line);
            gravity = stod(line);
        } else
            throw std::invalid_argument("config file line 13 - should be: gravity");
        //============ PENDULUMS' PARAMETERS
        getline(configFile,line);
        if (line == "mass1") {
            getline(configFile, line);
            mass1 = stod(line);
        } else
            throw std::invalid_argument("config file line 15 - should be: mass1");
        getline(configFile,line);
        if (line == "mass2") {
            getline(configFile, line);
            mass2 = stod(line);
        } else
            throw std::invalid_argument("config file line 17- should be: mass2");
        getline(configFile,line);
        if (line == "thetaInit1") {
            getline(configFile, line);
            thetaInit1 = stod(line);
        } else
            throw std::invalid_argument("config file line 19 - should be: thetaInit1");
        getline(configFile,line);
        if (line == "thetaInit2") {
            getline(configFile, line);
            thetaInit2 = stod(line);
        } else
            throw std::invalid_argument("config file line 21 - should be: thetaInit2");
        getline(configFile,line);
        if (line == "length1") {
            getline(configFile, line);
            length1 = stod(line);
        } else
            throw std::invalid_argument("config file line 23 - should be: length1");
        getline(configFile,line);
        if (line == "length2") {
            getline(configFile, line);
            length2 = stod(line);
        } else
            throw std::invalid_argument("config file line 25 - should be: length2");
        configFile.close();
    } else {
        perror("error with reading config file\n");
        exit(EXIT_FAILURE);
    }
}