#include "Stats.h"
using namespace std;


stats::stats()
{
    rooms = 0;
    keys = 0;
    ingredients = 0;
    gold = 100;
    sorcerer_anger = 0;
    for (int i=0; i<3; i++)
    {
        cookware[i] = 0;
    }
    available_Weapons[0].first.intialize("Club");
    available_Weapons[1].first.intialize("Spear");
    available_Weapons[2].first.intialize("Rapier +1");
    available_Weapons[3].first.intialize("Battle-Axe +2");
    available_Weapons[4].first.intialize("Longsword +3");
}

void stats::setRooms(int new_rooms)
{
    rooms = new_rooms;
}
int stats::getRooms()
{
    return rooms;
}
int stats::getKeys()
{
    return keys;
}
void stats::setKeys(int key)
{
    keys += key;
}
int stats::getIngredients()
{
    return ingredients;
}
void stats::setIngredients(int food)
{
    ingredients = food;
}

void stats::setCookware(int cook, int amount)
{
    cookware[cook] += amount;
}

int stats::getCookware(int index)
{
    return cookware[index];
}

void stats::setWeaponArr(string weapon_name, int amount)
{
    for (int i=0; i<5; i++)
    {
        if (weapon_name == available_Weapons[i].first.name)
        {
            available_Weapons[i] = pair(available_Weapons[i].first, amount+available_Weapons[i].second);
        }
    }
}
int stats::getGold()
{
    return gold;
}
void stats::setGold(int new_gold)
{
    gold = new_gold;
}
int stats::getTreasure(int ind)
{
    return treasure[ind];
}
void stats::setTreasure(int ind, int num)
{
    treasure[ind] += num;
}
int stats::getSorcererAnger()
{
    return sorcerer_anger;
}
void stats:: setSorcererAnger(int anger)
{
    sorcerer_anger += anger;
}

void stats::printInventory()
{
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << gold << endl;
    cout << "| Ingredients | " << ingredients << " kg" << endl;
    cout << "| Cookware    | P: " << cookware[0] << " | F: " << cookware[1] << " | C: " << cookware[2] << endl;
    printWeapons();
    cout << "| Armor       | " << armor << endl;
    cout << "| Treasures   | R: " << treasure[0] << " | N: " << treasure[1] << " | B: " << treasure[2] << " | C: " << treasure[3] << " | G: " << treasure[4] << endl;

}

void stats::printWeapons()
{
    cout << "| Weapons    ";
    for (int i = 0; i < 5; i++)
    {
        char c = available_Weapons[i].first.name_char;
        cout << " | " << available_Weapons[i].first.name_char << ": " << available_Weapons[i].second;
    }
    cout << endl;
}

void stats::printStats()
{
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << rooms << " | Keys: " << keys << " | Anger Level: " << sorcerer_anger << endl;


}
void stats::printParty(vector<PartyMember> party_members)
{
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (!party_members[i].isDead())
        {
            cout << "| " << party_members[i].getName() << " | Fullness: " << party_members[i].getFullness() << " | Armor " << party_members[i].getArmor() << " | Weapon " << party_members[i].getWeaponStr() << endl;
        }
    }
    cout << "+-------------+" << endl;
}

int stats::getArmor() const
{
    return armor;
}
int stats::getUnequippedArmor() const
{
    return armor_unequipped;
}

void stats::setArmor(int armor_)
{
    armor += armor_;
    armor_unequipped += armor_;
}
//int stats::getWeaponStrength(vector<PartyMember> party_members)
//{
//    int power = 0;
//    for (int i=0; i<5; i++)
//    {
//        if (!party_members[i].isDead())
//        {
//            power += party_members[i].getWeapon().damage;
//        }
//    }
//    return power;
//}

