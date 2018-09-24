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
    unsigned int x; //Ninja x cordinate
    unsigned int y; //Ninja y cordinate

public:
    Ninja();
    void startPoint(std::vector<std::vector<char>> map);
    unsigned int getX() const;
    void setX(unsigned int value);
    unsigned int getY() const;
    void setY(unsigned int value);
};

#endif // NINJA_H
