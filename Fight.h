
#ifndef CSCI_FINAL_FIGHT_H
#define CSCI_FINAL_FIGHT_H

#endif //CSCI_FINAL_FIGHT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class fight
{
private:
    vector<string> monster1;
    vector<string> monster2;
    vector<string> monster3;
    vector<string> monster4;
    vector<string> monster5;
    string sorcerer;

public:
    fight();
    int getVectorSize(int powerLVL);
    int random_monster(int powerLVL);
    vector<string> getMonsterVector(int x);
    void printMonster(int monsterVectorNum, int index);
    void remove_monster(int index, int monster_power);
    bool fight_calc(int wpn_pwr, int armor, int powerLVL, int rand1, int rand2);
};