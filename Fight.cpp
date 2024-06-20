#include <iostream>
#include "Fight.h"
#include <ctime>
#include <vector>

using namespace std;


fight::fight() {
    monster1.push_back("Animated Armor");
    monster1.push_back("Bigbear");
    monster1.push_back("Harpy");
    monster1.push_back("Scarecrow");
    monster2.push_back("Minotaur");
    monster2.push_back("Owlbear");
    monster2.push_back("Banshee");
    monster2.push_back("Wereboar");
    monster3.push_back("Giant Crocodile");
    monster3.push_back("Troll");
    monster3.push_back("Hobgoblin Warlord");
    monster3.push_back("Mammoth");
    monster4.push_back("Stone Giant");
    monster4.push_back("Night Hag");
    monster4.push_back("Assassin");
    monster4.push_back("Hydra");
    monster5.push_back("Cloud Giant");
    monster5.push_back("Silver Dragon");
    monster5.push_back("Vampire");
    monster5.push_back("Lich");


}

int fight::getVectorSize(int power)
{
    if (power == 1)
    {
        return monster1.size();
    }
    else if (power == 2)
    {
        return monster2.size();
    }
    else if (power == 3)
    {
        return monster3.size();
    }
    else if (power == 4)
    {
        return monster4.size();
    }
    else if (power == 5)
    {
        return monster5.size();
    }

}

int fight::random_monster(int power_level)
{
    int random;
    if (power_level == 1)
    {
        random = rand() % monster1.size();
    }
    else if (power_level == 2)
    {
        random = rand() % monster2.size();
    }
    else if (power_level == 3)
    {
        random = rand() % monster3.size();
    }
    else if (power_level == 4)
    {
        random = rand() % monster4.size();
    }
    else
    {
        random = rand() % monster5.size();
    }
    return random;
}
void fight::remove_monster(int ind, int monster_pwr)
{
    if(monster_pwr == 1)
    {
        monster1.erase(monster1.begin() + ind);
    }
    else if(monster_pwr == 2)
    {
        monster2.erase(monster2.begin() + ind);
    }
    else if(monster_pwr == 3)
    {
        monster3.erase(monster3.begin() + ind);
    }
    else if(monster_pwr == 4)
    {
        monster4.erase(monster4.begin() + ind);
    }
    else if(monster_pwr == 5)
    {
        monster5.erase(monster5.begin() + ind);
    }


}
// weapon_power is #of weapons + bonuses
bool fight::fight_calc(int weapon_power, int num_armor, int power_level, int r1, int r2)
{

    float calc = float((r1 * weapon_power)-(r2 * power_level)/(num_armor+1));
    if (calc > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void fight::printMonster(int monVec, int ind)
{
    if(monVec == 1)
    {
        cout << monster1[ind];
    }
    else if(monVec == 2)
    {
        cout << monster2[ind];
    }
    else if(monVec == 3)
    {
        cout << monster3[ind];
    }
    else if(monVec == 4)
    {
        cout << monster4[ind];
    }
    else if(monVec == 5)
    {
        cout << monster5[ind];
    }
    else
    {
        cout << "Sorcerer";
    }
}
vector<string> fight::getMonsterVector(int x)
{
    if (x == 1)
    {
        return monster1;
    }
    else if (x == 2)
    {
        return monster2;
    }
    else if (x == 3)
    {
        return monster3;
    }
    else if (x == 4)
    {
        return monster4;
    }
    else
    {
        return monster5;
    }
}