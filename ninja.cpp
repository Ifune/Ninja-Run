#include "ninja.h"

unsigned int Ninja::getX() const
{
    return x;
}

void Ninja::setX(unsigned int value)
{
    x = value;
}

unsigned int Ninja::getY() const
{
    return y;
}

void Ninja::setY(unsigned int value)
{
    y = value;
}

Ninja::Ninja():
    x(0),
    y(0)
{

}

void Ninja::startPoint(std::vector<std::vector<char> > map)
{
    //The starting position finding and setting.
    for (unsigned int j = 0; j < map.size(); j++)
    {
        for (unsigned int i = 0; i < map[0].size(); i++)
        {
            if (map[j][i] == '@')
            {
                setX(j);
                setY(i);
            }
        }
    }

    //If not found stanting character.
    if (getX() == 0 and getY() == 0)
    {
        cout << "In the map there is not a starting point." << endl;
    }
}
