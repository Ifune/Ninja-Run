#include "string.h"
#include "iostream"
#include "fstream"
#include "ninja.h"

using namespace std;

string characterChange(char character)
{
    string characters;

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
        default:
            cout << "Invalid character" << endl;
        }
    return characters;
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

int main()
{
    string firstnametest = "Tamas";
    string lastnametest = "Horvath";
    cout << firtsName(firstnametest) << endl;
    cout << lastName(lastnametest) << endl;

    return 0;
};
