#ifndef CSCI_FINAL_PARTYMEMBER_H
#define CSCI_FINAL_PARTYMEMBER_H


#include <string>
#include "Weapon.h"
using namespace std;

class PartyMember {
private:
    int fullness;
    Weapon member_weapon;
    bool armor;
    string name;
    bool is_dead;
    bool is_player;

public:
    PartyMember(string _name, bool _isPlayer);

    int getFullness();
    void setFullness(int hunger);

    void setWeapon(Weapon weap);
    Weapon getWeapon();

    bool getArmor();
    void setArmor(bool new_armor);

    string getName();

    bool isDead();
    void setIsDead(bool isDead);

    bool isPlayer();
    void setIsPlayer(bool isDead);

    string getWeaponStr();
};


#endif
