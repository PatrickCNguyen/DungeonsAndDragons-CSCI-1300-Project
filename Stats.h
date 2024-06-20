#ifndef CSCI_FINAL_STAT_H
#define CSCI_FINAL_STAT_H

#endif //CSCI_FINAL_STAT_H

#include <iostream>
#include <vector>
#include <string>
#include "Weapon.h"
#include "PartyMember.h"
using namespace std;

class stats
{
private:
    int rooms; // merchant
    int keys;
    int ingredients;
    int armor;
    int armor_unequipped;
    int cookware[3];
    int gold; // merchant
    int treasure[5]; // merchant
    int sorcerer_anger;

public:
    stats();
    pair<Weapon, int> available_Weapons[5]; // inventory weapons (weapon, count)
    int getRooms();
    void setRooms(int new_rooms);
    int getKeys();
    void setKeys(int key);
    int getIngredients();
    void setIngredients(int food);
    void setCookware(int new_cookware, int num);
    int getCookware(int index);
    void setWeaponArr(string type, int num);
    int getGold();
    void setGold(int new_gold);
    int getTreasure(int index);
    void setTreasure(int index, int amount);
    int getSorcererAnger();
    void setSorcererAnger(int anger);
    void printInventory();
    void printStats();
    void printParty(vector<PartyMember> party_mem);
    void printWeapons();
//    int getWeaponStrength(vector<PartyMember> party_);

    int getArmor() const;
    int getUnequippedArmor() const;

    void setArmor(int armor);
};
