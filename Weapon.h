#ifndef CSCI_FINAL_WEAPON_H
#define CSCI_FINAL_WEAPON_H

#include <string>
using namespace std;

struct Weapon {
    string name;
    char name_char;
    int cost;
    int damage;

    Weapon() {
        name = "Null";
        name_char = 'N';
        cost = 0;
        damage = 0;
    }

    void intialize(const string _name)
    {
        if(_name == "Club")
        {
            set(_name, 'C', 2, 1);
        }
        else if (_name == "Spear")
        {
            set(_name, 'S', 2, 1);
        }
        else if (_name == "Rapier +1")
        {
            set(_name, 'R', 5, 2);
        }
        else if (_name == "Battle-Axe +2")
        {
            set(_name, 'B', 15, 3);
        }
        else if (_name == "Longsword +3")
        {
            set(_name, 'L', 50, 4);
        }
    }

    void set(string _name, char _name_char, int _cost, int _damage)
    {
        name = _name;
        name_char = _name_char;
        cost = _cost;
        damage = _damage;
    }
};

#endif //CSCI_FINAL_WEAPON_H
