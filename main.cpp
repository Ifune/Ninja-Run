#include "string"
#include <iostream>
#include "fstream"
#include "ninja.h"
#include <vector>
#include "stdlib.h"

using namespace std;

string characterChange(char character)
{
    string characters = "error";
    //Switch the character to characters
    switch(character)
    {
        case 'a' | 'A':
            characters = "ka";
            break;
        case 'b' | 'B':
            characters = "zu";
            break;
        case 'c' | 'C':
            characters = "mi";
            break;
        case 'd' | 'D':
            characters = "te";
            break;
        case 'e' | 'E':
            characters = "ku";
            break;
        case 'f' | 'F':
            characters = "lu";
            break;
        case 'g' | 'G':
            characters = "ji";
            break;
        case 'h' | 'H':
            characters = "ri";
            break;
        case 'i' | 'I':
            characters = "ki";
            break;
        case 'j' | 'J':
            characters = "zu";
            break;
        case 'k' | 'K':
            characters = "me";
            break;
        case 'l' | 'L':
            characters = "ta";
            break;
        case 'm' | 'M':
            characters = "rin";
            break;
        case 'n' | 'N':
            characters = "to";
            break;
        case 'o' | 'O':
            characters = "mo";
            break;
        case 'p' | 'P':
            characters = "no";
            break;
        case 'q' | 'Q':
            characters = "ke";
            break;
        case 'r' | 'R':
            characters = "shi";
            break;
        case 's' | 'S':
            characters = "ari";
            break;
        case 't' | 'T':
            characters = "chi";
            break;
        case 'u' | 'U':
            characters = "do";
            break;
        case 'v' | 'V':
            characters = "ru";
            break;
        case 'w' | 'W':
            characters = "mei";
            break;
        case 'x' | 'X':
            characters = "na";
            break;
        case 'y' | 'Y':
            characters = "fu";
            break;
        case 'z' | 'Z':
            characters = "zi";
            break;
        }

   if (characters == "error")   //If the character is not in the case
    {
        cout << "Invalid character: " << character << endl;
        exit(1);
    } else
    {
        return characters;
    }
}

string firtsName(string &name)
{
    //The first name conversion to ninja name
    string fname = "";
    unsigned int fnameLength = name.length();
    fname += characterChange(name[fnameLength - 3]);
    fname += characterChange(name[fnameLength - 2]);
    fname += characterChange(name[fnameLength - 1]);

    return fname;
}

string lastName(string &name)
{
    //The last name conversion to ninja name
    string lname = "";
    unsigned int fnameLength = name.length();
    lname += characterChange(name[fnameLength - 4]);
    lname += characterChange(name[fnameLength - 3]);
    lname += characterChange(name[fnameLength - 2]);
    lname += characterChange(name[fnameLength - 1]);

    return lname;
}

void ninjaNaming()
{
    //The ask for your first and last name and call other converter functions
    string firstn;
    string lastn;
    do
    {
        if (firstn != "" or lastn != "")
        {
            cout << "To few character! (firstname min 3 and lastname min 4)" << endl;
        }
        cout << "Write your firstname." << endl;
        cin >> firstn;
        cout << "Write your lastname." << endl;
        cin >> lastn;
    } while (firstn.length() < 3 or lastn.length() < 4);

    cout <<  "Your ninja name is " << firtsName(firstn) << " " << lastName(lastn) << endl;
}

std::vector<std::vector<char> > inputMap()
{
    //
    ifstream inputFile("C:\\Users\\Ifune\\Desktop\\input\\maps\\11_in");
    if(!inputFile)
    {
        cout<<"Couldn't open the file"<<endl;   //If it could'not open the file
        exit(1);
    }

    unsigned int row = 0;
    string line;
    string inputInToString;
    while( getline(inputFile, line) )   //Give the file content to a string
    {
        inputInToString += line;
        row++;  //Count row
    }

    unsigned int column = (inputInToString.length() / row); //Count column
    std::vector <std::vector<char> > map(column,std::vector<char>(row));
    for (unsigned int i = 0; i < row; i++)
    {
        for (unsigned int j = 0; j < column; j++)
        {
            map[j][i] = inputInToString[(i * column) + j];  //Give the content to a 2d vector
        }
    }

    return map; //Return 2d vector
}

int main()
{
    ninjaNaming();  //Call the ninja nameing
    Ninja ninja;    //Create ninja
    ninja.setMissionMap(inputMap());    //Give ninja the 2d vector
    ninja.startPoint(); //Call starting coordiation counter and setter
    ninja.move();   //Call the movement

    return 0;
};
