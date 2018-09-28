#ifndef NINJA_H
#define NINJA_H

#include "string"
#include <iostream>
#include "fstream"
#include <vector>
#include "stdlib.h"
using namespace std;

class Ninja
{
    bool mirror;    //Mirror direction to yous or not
    bool win;   //The ninja destroyd the artifact or not
    bool breakerMode;   //Ninja it's in breaker mode or not
    unsigned int x;     //Ninja x cordinate
    unsigned int y;     //Ninja y cordinate
    std::vector<std::vector<char>> missionmap;  //The dojo blueprint
    unsigned int shuriken;  //What is the number of shuriken that the ninja has
    vector <string> output; //What has to print out in the program end
    unsigned int loopCount; //It's count the loops for force stop the program

public:
    Ninja();
    void throwing();
    void Winning();
    void startPoint();
    void move();
    void moveSouth();
    void moveEast();
    void moveNorth();
    void moveWest();
    void shurikenThrow(const char direction);
    void infinityLoop();
    unsigned int getX() const;
    void setX(unsigned int value);
    unsigned int getY() const;
    void setY(unsigned int value);
    std::vector<std::vector<char> > getMissionMap() const;
    void setMissionMapTile(unsigned int x, unsigned int y,const char character);
    bool getBreakerMode() const;
    void setBreakerMode(bool value);
    unsigned int getShuriken() const;
    void setShuriken(unsigned int value);
    bool getMirror() const;
    void setMirror(bool value);
    bool getWin() const;
    void setWin(bool value);
    void setMissionMap(const std::vector<std::vector<char> > &value);
    vector<string> getOutput() const;
    void setOutput(vector<string> &value);
    void addOutput(const string &value);
    unsigned int getLoopCount() const;
    void addLoopCount();
    char getMissionMapTile(unsigned int x, unsigned int y);
};

#endif // NINJA_H
