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

    switch(character){
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


   if (characters == "error")
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
    string fname = "";
    unsigned int fnameLength = name.length();
    fname += characterChange(name[fnameLength - 3]);
    fname += characterChange(name[fnameLength - 2]);
    fname += characterChange(name[fnameLength - 1]);

    return fname;
}

string lastName(string &name)
{
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

std::vector<std::vector<char>> inputMap()
{
    ifstream inputFile("C:\\Users\\Ifune\\Desktop\\input\\maps\\06_in");
    if(!inputFile)
    {
        cout<<"Couldn't open the file"<<endl;
        exit(1);
    }

    unsigned int row = 0;
    string line;
    string inputInToString;
    while( getline(inputFile, line)  )
    {
        inputInToString += line;
        row++;
        cout << line << endl;
    }

    unsigned int column = inputInToString.length() / row;
    std::vector <std::vector<char> > map(column ,std::vector<char>(row));
    for (unsigned int j = 0; j < row; j++)
    {
        for (unsigned int i = 0; i < column; i++)
        {
            map[j][i] = inputInToString[j * 5 + i];
        }
    }

    return map;
}

int main()
{
    ninjaNaming();
    std::vector<std::vector<char>> map = inputMap();
    Ninja n;
    n.startPoint(map);

    return 0;
};
