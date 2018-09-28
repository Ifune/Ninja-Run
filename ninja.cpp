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

std::vector<std::vector<char> > Ninja::getMissionMap() const
{
    return missionmap;
}

void Ninja::setMissionMapTile(unsigned int x, unsigned int y, const char character)
{
    missionmap[y][x] = character;
}

char Ninja::getMissionMapTile(unsigned int x, unsigned int y)
{
    return missionmap[y][x];
}

bool Ninja::getBreakerMode() const
{
    return breakerMode;
}

void Ninja::setBreakerMode(bool value)
{
    breakerMode = value;
}

unsigned int Ninja::getShuriken() const
{
    return shuriken;
}

void Ninja::setShuriken(unsigned int value)
{
    shuriken = value;
}

bool Ninja::getMirror() const
{
    return mirror;
}

void Ninja::setMirror(bool value)
{
    mirror = value;
}

bool Ninja::getWin() const
{
    return win;
}

void Ninja::setWin(bool value)
{
    win = value;
}

void Ninja::setMissionMap(const std::vector<std::vector<char> > &value)
{
    missionmap.resize(value.size(),std::vector<char>(value[0].size()));
    for (unsigned int i = 0; i < value.size(); i++)
    {
        for (unsigned int j = 0; j < value[i].size(); j++)
        {
            this->setMissionMapTile(i,j,value[i][j]);
        }
    }
}

vector<string> Ninja::getOutput() const
{
    return output;
}

void Ninja::setOutput(vector<string> &value)
{
    output.swap(value);
}

void Ninja::addOutput(const string &value)
{
    output.push_back(value);
}

unsigned int Ninja::getLoopCount() const
{
    return loopCount;
}

void Ninja::addLoopCount()
{
    loopCount++;
}

Ninja::Ninja():
    mirror(false),
    win(false),
    breakerMode(false),
    x(0),
    y(0),
    missionmap(),
    shuriken(3),
    output(),
    loopCount(0)
{

}

void Ninja::throwing()
{
    addLoopCount(); //I increase here the loop becouse the throwing always be called
    if (getLoopCount() > (getMissionMap().size() * getMissionMap()[0].size() * 2))  //If loop number greater then the element's of the (map * 2)
    {
        setWin(true);
        this->infinityLoop();
    }

    if (!getMirror())   //Shuriken throwing call
    {
        shurikenThrow('S');
        shurikenThrow('E');
        shurikenThrow('N');
        shurikenThrow('W');
    } else
    {
        shurikenThrow('W');
        shurikenThrow('N');
        shurikenThrow('E');
        shurikenThrow('S');
    }
}

void Ninja::Winning()
{
    getMissionMap().clear();    //This will call the destroctor of the vectors
    for (unsigned int i = 0;i < this->getOutput().size();i++)
    {
        cout << this->getOutput()[i] << endl;   //Print out what was the ninja actions (move,shuriken throw,loop)
    }
    exit(0);
}

void Ninja::startPoint()
{
    //The starting position finding and setting.
    unsigned int i = 1;
    unsigned int j = 1;

    while (getMissionMapTile(i - 1,j) != '@' and i != getMissionMap().size() - 1)
    {
        j = 1;
        while (getMissionMapTile(i,j) != '@' and j != getMissionMap()[0].size() - 1)
        {
            j++;
        }
        i++;
    }
    setX(i - 1);
    setY(j);

    //If not found stanting character.
    if (getX() == 0 and getY() == 0)
    {
        cout << "In the map there is not a starting point." << endl;
    }
    else
    {
        this->move();
    }


}

void Ninja::shurikenThrow(const char direction)
{
    string indestructible = "#FGHIJKLM";    //It's the indesctructuble odject's
    string destrctuble = "$X";  //It's the destructable odject's
    string tile;    //It's in a string to be able to use string.find

    unsigned int n = 0;
    do
    {
       n++;
       switch (direction)
       {
            //Give the tile to what's the elem
            case 'S':
            tile = getMissionMapTile(getX(),getY() + n);
            break;
            case 'E':
            tile = getMissionMapTile(getX() + n,getY());
            break;
            case 'N':
            tile = getMissionMapTile(getX(),getY() - n);
            break;
            case 'W':
            tile = getMissionMapTile(getX() - n,getY());
            break;
        }

        if (tile.find_first_of(destrctuble) != tile.npos and getShuriken() != 0)
        {
            setShuriken(getShuriken() - 1);
            switch (direction)
            {
                //Set the elem to *
                case 'S':
                setMissionMapTile(getX(),getY() + n,'*');
                break;
                case 'E':
                setMissionMapTile(getX() + n,getY(),'*');
                break;
                case 'N':
                setMissionMapTile(getX(),getY() - n,'*');
                break;
                case 'W':
                setMissionMapTile(getX() - n,getY(),'*');
                break;
            }

            addOutput("TRHOW");

            if (tile[0] == '$')
            {
                this->Winning();    //If the artifact the ninja win
            }
        }

    }while (getShuriken() != 0 and tile.find_first_of(indestructible) == tile.npos);    //Repeat until it's has no shuriken or it's a idestructible object
}

void Ninja::move()
{
    if (getWin())
    {
        Winning();  //If the ninja win then call winnig
    }

    if (!getMirror())   //Call the moves
    {
        moveSouth();
    }
    else
    {
        moveWest();
    }
}

void Ninja::moveSouth()
{
    //All the moving function hass the same cases but not the same direction and x,y counting
    throwing(); //Call to throw shuriken
    unsigned int i = 1;
    unsigned int j = 1;
    char path;

    switch(getMissionMapTile(getX(),getY() + 1))
    {
    case '#':   //If it's in the dicertion has # then call move depending on the mirror
        if (!getMirror())
        {
            moveEast();
        }
        else
        {
            moveWest();
        }
        break;
    case '$':   //If it's in breaker mode then set win true, if it's not, then move depending on the mirror
        if (getBreakerMode())
        {
            setWin(true);
        }
        else
        {
            if (!getMirror())
            {
                moveEast();
            }
            else
            {
                moveWest();
            }
        }
        break;
    case 'X':   //If it's in breaker then it's destroy the X if not, then move depending on the mirror
        if (getBreakerMode())
        {
            setY(getY() + 1);
            addOutput("SOUTH");
            setMissionMapTile(getX(),getY(),' ');
        }
        else
        {
            if (!getMirror())
            {
                moveEast();
            }
            else
            {
                moveWest();
            }
        }
        break;
    case 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L':   //If it's a secret passag then search and set x,y to there, then move the initial direction
        path = getMissionMapTile(getX(),getY() + 1);
        while ((getMissionMapTile(i,j) != path and j == getY() + 1) or i == getMissionMap().size() - 1)
        {
            while ((getMissionMapTile(i,j) != path and j == getY() + 1) or j ==  getMissionMap()[i].size() - 1)
            {
                j++;
            }
            i++;
        }
        setX(i);
        setY(j);
        addOutput("SOUTH");
        moveSouth();
        break;
    case 'S':   //Change the direction to south
        setY(getY() + 1);
        addOutput("SOUTH");
        moveSouth();
        break;
    case 'E':   //Change the direction to east
        setY(getY() + 1);
        addOutput("SOUTH");
        moveEast();
        break;
    case 'N':   //Change the direction to west
        setY(getY() + 1);
        addOutput("SOUTH");
        moveNorth();
        break;
    case 'W':   //Change the direction to north
        setY(getY() + 1);
        addOutput("SOUTH");
        moveWest();
        break;
    case 'M':   //Change the mirror to true if was false or if was true change false, then move depending on the mirror
        if (getMirror())
        {
            setMirror(false);
        }
        else
        {
            setMirror(true);
        }

        if (!getMirror())
        {
            moveSouth();
        }
        else
        {
            moveWest();
        }
        break;
    case 'B':   //Go to breaker mode and if it's in then go out breaker mode, then move depending on the mirror
        if (getBreakerMode())
        {
            setBreakerMode(false);
        }
        else
        {
            setBreakerMode(true);
        }
        setY(getY() + 1);
        addOutput("SOUTH");
        moveSouth();
        break;
    case '*':   //Increase the shuriken count
        setShuriken(getShuriken() + 1);
        setY(getY() + 1);
        addOutput("SOUTH");
        moveSouth();
        break;
    case ' ':   //Move the intinial direction
        setY(getY() + 1);
        addOutput("SOUTH");
        moveSouth();
        break;
    }

    move();   //It's call move if it's out of the case
}

void Ninja::moveEast()
{
    throwing();
    unsigned int i = 1;
    unsigned int j = 1;
    char path;

    switch(getMissionMapTile(getX() + 1,getY()))
    {
    case '#':
        if (!getMirror())
        {
            moveNorth();
        }
        else
        {
            moveSouth();
        }
        break;
    case '$':
        if (getBreakerMode())
        {
            setWin(true);
        }
        else
        {
            if (!getMirror())
            {
                moveNorth();
            }
            else
            {
                moveSouth();
            }
        }
        break;
    case 'X':
        if (getBreakerMode())
        {
            setX(getX() + 1);
            addOutput("EAST");
            setMissionMapTile(getX(),getY(),' ');
            moveEast();
        }
        else
        {
            if (!getMirror())
            {
                moveNorth();
            }
            else
            {
                moveSouth();
            }
        }
        break;
    case 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L':
        path = getMissionMapTile(getX(),getY() - 1);
        while ((getMissionMapTile(i,j) != path and j == getX() + 1) or i == getMissionMap().size() - 1)
        {
            while ((getMissionMapTile(i,j) != path and j == getX() + 1) or j == getMissionMap()[0].size() - 1)
            {
                j++;
            }
            i++;
        }
        setX(i);
        setY(j);
        addOutput("EAST");
        moveEast();
        break;
    case 'S':
        setX(getX() + 1);
        addOutput("EAST");
        moveSouth();
        break;
    case 'E':
        setX(getX() + 1);
        addOutput("EAST");
        moveEast();
        break;
    case 'N':
        setX(getX() + 1);
        addOutput("EAST");
        moveNorth();
        break;
    case 'W':
        setX(getX() + 1);
        addOutput("EAST");
        moveWest();
        break;
    case 'M':
        if (getMirror())
        {
            setMirror(false);
        }
        else
        {
            setMirror(true);
        }

        if (!getMirror())
        {
            moveSouth();
        }
        else
        {
            moveWest();
        }
        break;
    case 'B':
        if (getBreakerMode())
        {
            setBreakerMode(false);
        }
        else
        {
            setBreakerMode(true);
        }
        setX(getX() + 1);
        addOutput("EAST");
        moveEast();
        break;
    case '*':
        setShuriken(getShuriken() + 1);
        setX(getX() + 1);
        addOutput("EAST");
        break;
    case ' ':
        setX(getX() + 1);
        addOutput("EAST");
        moveEast();
        break;
    }

    move();
}

void Ninja::moveNorth()
{
    throwing();
    unsigned int i = 1;
    unsigned int j = 1;
    char path;

    switch(getMissionMapTile(getX(),getY() - 1))
    {
    case '#':
        if (!getMirror())
        {
            moveWest();
        }
        else
        {
            moveEast();
        }
        break;
    case '$':
        if (getBreakerMode())
        {
            setWin(true);
        }
        else
        {   if (!getMirror())
            {
                moveWest();
            }
            else
            {
                moveEast();
            }
        }
        break;
    case 'X':
        if (getBreakerMode())
        {
            setY(getY() - 1);
            addOutput("NORTH");
            setMissionMapTile(getX(),getY(),' ');
            moveNorth();
        }
        else
        {
            this->moveWest();
            if (!getMirror())
            {
                moveWest();
            }
            else
            {
                moveEast();
            }
        }
        break;
    case 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L':
        path = getMissionMapTile(getX(),getY() - 1);
        while ((getMissionMapTile(i,j) != path and j == getY() - 1) or i == getMissionMap().size() - 1)
        {
            while ((getMissionMapTile(i,j) != path and j == getY() - 1) or j == getMissionMap()[0].size() - 1)
            {
                j++;
            }
            i++;
        }
        setX(i);
        setY(j);
        addOutput("NORTH");
        moveNorth();
        break;
    case 'S':
        setY(getY() - 1);
        addOutput("NORTH");
        moveSouth();
        break;
    case 'E':
        setY(getY() - 1);
        addOutput("NORTH");
        moveEast();
        break;
    case 'N':
        setY(getY() - 1);
        addOutput("NORTH");
        moveNorth();
        break;
    case 'W':
        setY(getY() - 1);
        addOutput("NORTH");
        moveWest();
        break;
    case 'M':
        if (getMirror())
        {
            setMirror(false);
        }
        else
        {
            setMirror(true);
        }

        if (!getMirror())
        {
            moveSouth();
        }
        else
        {
            moveWest();
        }
        break;
    case 'B':
        if (getBreakerMode())
        {
            setBreakerMode(false);
        }
        else
        {
            setBreakerMode(true);
        }
        setY(getY() - 1);
        addOutput("NORTH");
        moveNorth();
        break;
    case '*':
        setShuriken(getShuriken() + 1);
        setY(getY() - 1);
        addOutput("NORTH");
        moveNorth();
        break;
    case ' ':
        setY(getY() - 1);
        addOutput("NORTH");
        moveNorth();
        break;
    }

    this->move();
}

void Ninja::moveWest()
{
    throwing();
    unsigned int i = 1;
    unsigned int j = 1;
    char path;

    switch(getMissionMapTile(getX() - 1,getY()))
    {
    case '#':
        if (!getMirror())
        {
            moveSouth();
        }
        else
        {
            moveNorth();
        }
        break;
    case '$':
        if (getBreakerMode())
        {
            setWin(true);
        }
        else
        {
            if (!getMirror())
            {
                moveSouth();
            }
            else
            {
                moveNorth();
            }
        }
        break;
    case 'X':
        if (getBreakerMode())
        {
            setX(getX() - 1);
            addOutput("WEST");
            setMissionMapTile(getX(),getY(),' ');
            moveWest();
        }
        else
        {
            if (!getMirror())
            {
                moveSouth();
            }
            else
            {
                moveNorth();
            }
        }
        break;
    case 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L':
        path = getMissionMapTile(getX() - 1,getY());
        while ((getMissionMapTile(i,j) != path and i == getX() - 1) or i == getMissionMap().size() - 1)
        {
            while ((getMissionMapTile(i,j) != path and i == getX() - 1) or j == getMissionMap()[i].size() - 1)
            {
                j++;
            }
            i++;
        }
        setX(i);
        setY(j);
        addOutput("WEST");
        moveWest();
        break;
    case 'S':
        setX(getX() - 1);
        addOutput("WEST");
        moveSouth();
        break;
    case 'E':
        setX(getX() - 1);
        addOutput("WEST");
        moveEast();
        break;
    case 'N':
        setX(getX() - 1);
        addOutput("WEST");
        moveNorth();
        break;
    case 'W':
        setX(getX() - 1);
        addOutput("WEST");
        moveWest();
        break;
    case 'M':
        if (getMirror())
        {
            setMirror(false);
        }
        else
        {
            setMirror(true);
        }

        if (!getMirror())
        {
            moveSouth();
        }
        else
        {
            moveWest();
        }
        break;
    case 'B':
        if (getBreakerMode())
        {
            setBreakerMode(false);
        }
        else
        {
            setBreakerMode(true);
        }
        setX(getX() - 1);
        addOutput("WEST");
        moveWest();
        break;
    case '*':
        setShuriken(getShuriken() + 1);
        setX(getX() - 1);
        addOutput("WEST");
        moveWest();
        break;
    case ' ':
        setX(getX() - 1);
        addOutput("WEST");
        moveWest();
        break;
    }

    move();
}

void Ninja::infinityLoop()
{
    std::vector <string> infinity (1,"LOOP");
    setOutput(infinity);
    this->Winning();
}


