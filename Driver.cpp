#include "Stats.h"
#include "Merchant.h"
#include "Fight.h"
#include "PartyMember.h"
#include "Weapon.h"
#include "Action.h"
#include "Map.h"
#include <cassert>
using namespace std;
#include <iostream>
#include <fstream>
#include <ctime>


merchant m;
Map map;
stats s;
action a;
fight f;
vector<PartyMember> party_members;
char confirm;
int merc = 0;


void Ingredients()
{
    int amount = m.buyIngredients();
    if (amount != -1) {
        bool validInput = false;
        bool validInput2 = false;
        while (!validInput) {
            if (amount * m.getIngredientPrice() <= s.getGold()) {
                validInput = true;
            } else {
                cout << "You do not have enough gold to purchase " << amount << " kg of ingredients" << endl;
                amount = m.buyIngredients();
            }
        }
        do {
            cout << "You want to buy " << amount << " kg of ingredients for " << amount * m.getIngredientPrice()
                 << " Gold? (y/n)" << endl;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'n') {
                validInput2 = true;
            } else {
                cout << "Please enter a valid input." << endl;
            }
        } while (!validInput2);

        if (confirm == 'y') {
            cout << "Thank you for your patronage! What else can I get for you?" << endl;
            s.setIngredients(amount + s.getIngredients());
            s.setGold(s.getGold() - amount * m.getIngredientPrice());
        } else if (confirm == 'n') {
            cout << "You did not buy any ingredients" << endl;
        }
    }
    else
    {
        cout << "You did not buy any ingredients" << endl;
    }
}

void Pots()
{
    int choice = m.buyCookware();
    int amount = -1;
    bool valid = false;
    int valid2 = false;


    if (choice == 1)
    {
        do
        {
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
            if (amount >= 0)
            {
                if (m.getCookwarePPrice() * amount <= s.getGold())
                {
                    valid = true;
                }
                else
                {
                    cout << "You do not have enough gold to purchase " << amount << " Ceramic Pot(s)" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (!valid);
        if (amount != 0)
        {
            do
            {
                cout << "You want to buy " << amount << " Ceramic Pot(s) for " << amount * m.getCookwarePPrice() << " (y/n)" << endl;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'n')
                {
                    valid2 = true;
                }
                else
                {
                    cout << "Please enter a valid input." << endl;
                }
            }
            while (valid2 == false);

            if (confirm == 'y')
            {
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                s.setCookware(0, amount);
                s.setGold(s.getGold() - m.getCookwarePPrice() * amount);
            }
            else if (confirm == 'n')
            {
                cout << "You did not buy any Ceramic Pots" << endl;
            }
        }
    }
    else if (choice == 2)
    {
        do
        {
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
            if (amount >= 0)
            {
                if (m.getCookwareFPrice() * amount <= s.getGold())
                {
                    valid = true;
                }
                else
                {
                    cout << "You do not have enough gold to purchase " << amount << " Frying Pan(s)" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (!valid);
        do
        {
            cout << "You want to buy " << amount << " Frying Pan(s) for " << amount * m.getCookwareFPrice() << " (y/n)" << endl;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'n')
            {
                valid2 = true;
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (valid2 == false);
        if (amount != 0)
        {
            if (confirm == 'y')
            {
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                s.setCookware(1, amount);
                s.setGold(s.getGold() - m.getCookwareFPrice() * amount);
            }
            else if (confirm == 'n')
            {
                cout << "You did not buy any Frying Pans" << endl;
            }
        }
        else
        {
            cout << "You did not buy any Frying Pans" << endl;
        }
    }
    else if (choice == 3)
    {
        do
        {
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
            if (amount >= 0)
            {
                if (m.getCookwareCPrice() * amount <= s.getGold())
                {
                    valid = true;
                }
                else
                {
                    cout << "You do not have enough gold to purchase " << amount << " Cauldron(s)" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (!valid);
        do
        {
            cout << "You want to buy " << amount << " Cauldron(s) for " << amount * m.getCookwareCPrice() << " (y/n)" << endl;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'n')
            {
                valid2 = true;
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (valid2 == false);
        if (amount != 0)
        {
            if (confirm == 'y')
            {
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                s.setCookware(2, amount);
                s.setGold(s.getGold() - m.getCookwareCPrice() * amount);
            }
            else if (confirm == 'n')
            {
                cout << "You did not buy any Cauldrons" << endl;
            }
        }
        else
        {
            cout << "You did not buy any Cauldrons" << endl;
        }
    }
    else if (choice == 4)
    {

    }
}

void Weapons()
{
    int choice = m.buyWeapons();
    int amount = -1;
    bool valid = false;
    bool valid2 = false;
    if (choice == 1)
    {
        do
        {
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
            if (amount >= 0)
            {
                if (m.getWeaponCPrice() * amount <= s.getGold())
                {
                    valid = true;
                }
                else
                {
                    cout << "You do not have enough gold to purchase " << amount << " Stone Club(s)" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (!valid);
        if (amount != 0)
        {
            do
            {
                cout << "You want to buy " << amount << " Stone Club(s) for " << amount * m.getWeaponCPrice() << " (y/n)" << endl;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'n')
                {
                    valid2 = true;
                }
                else
                {
                    cout << "Please enter a valid input." << endl;
                }
            }
            while (!valid2);

            if (confirm == 'y')
            {
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                s.setWeaponArr("Club", amount);
                s.setGold(s.getGold() - m.getWeaponCPrice() * amount);
            }
            else if (confirm == 'n')
            {
                cout << "You did not buy any Stone Clubs" << endl;
            }
        }
    }
    else if (choice == 2)
    {
        do
        {
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
            if (amount >= 0)
            {
                if (m.getWeaponSPrice() * amount <= s.getGold())
                {
                    valid = true;
                }
                else
                {
                    cout << "You do not have enough gold to purchase " << amount << " Iron Spear(s)" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (!valid);
        if (amount != 0)
        {
            do
            {
                cout << "You want to buy " << amount << " Iron Spear(s) for " << amount * m.getWeaponSPrice() << " (y/n)" << endl;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'n')
                {
                    valid2 = true;
                }
                else
                {
                    cout << "Please enter a valid input." << endl;
                }
            }
            while (!valid2);

            if (confirm == 'y')
            {
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                s.setWeaponArr("Spear", amount);
                s.setGold(s.getGold() - m.getWeaponSPrice() * amount);
            }
            else if (confirm == 'n')
            {
                cout << "You did not buy any Iron Spears" << endl;
            }
        }
    }
    else if (choice == 3)
    {
        do
        {
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
            if (amount >= 0)
            {
                if (m.getWeaponRPrice() * amount <= s.getGold())
                {
                    valid = true;
                }
                else
                {
                    cout << "You do not have enough gold to purchase " << amount << " (+1) Mythril Rapier(s)" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (!valid);
        if (amount != 0)
        {
            do
            {
                cout << "You want to buy " << amount << " (+1) Mythril Rapier(s) for " << amount * m.getWeaponRPrice() << " (y/n)" << endl;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'n')
                {
                    valid2 = true;
                }
                else
                {
                    cout << "Please enter a valid input." << endl;
                }
            }
            while (!valid2);

            if (confirm == 'y')
            {
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                s.setWeaponArr("Rapier +1", amount);
                s.setGold(s.getGold() - m.getWeaponRPrice() * amount);
            }
            else if (confirm == 'n')
            {
                cout << "You did not buy any (+1) Mythril Rapiers" << endl;
            }
        }
    }
    else if (choice == 4)
    {
        do
        {
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
            if (amount >= 0)
            {
                if (m.getWeaponBPrice() * amount <= s.getGold())
                {
                    valid = true;
                }
                else
                {
                    cout << "You do not have enough gold to purchase " << amount << " (+2) Flaming Battle-Axe(s)" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (!valid);
        if (amount != 0)
        {
            do
            {
                cout << "You want to buy " << amount << " (+2) Flaming Battle-Axe(s) for " << amount * m.getWeaponBPrice() << " (y/n)" << endl;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'n')
                {
                    valid2 = true;
                }
                else
                {
                    cout << "Please enter a valid input." << endl;
                }
            }
            while (!valid2);

            if (confirm == 'y')
            {
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                s.setWeaponArr("Battle-Axe +2", amount);
                s.setGold(s.getGold() - m.getWeaponBPrice() * amount);
            }
            else if (confirm == 'n')
            {
                cout << "You did not buy any (+2) Flaming Battle-Axes" << endl;
            }
        }
    }
    else if (choice == 5)
    {
        do
        {
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
            if (amount >= 0)
            {
                if (m.getWeaponLPrice() * amount <= s.getGold())
                {
                    valid = true;
                }
                else
                {
                    cout << "You do not have enough gold to purchase " << amount << " (+3) Vorpal Longsword(s)" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (!valid);
        if (amount != 0)
        {
            do
            {
                cout << "You want to buy " << amount << " (+3) Vorpal Longsword(s) for " << amount * m.getWeaponLPrice() << " (y/n)" << endl;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'n')
                {
                    valid2 = true;
                }
                else
                {
                    cout << "Please enter a valid input." << endl;
                }
            }
            while (!valid2);

            if (confirm == 'y')
            {
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                s.setWeaponArr("Longsword +3", amount);
                s.setGold(s.getGold() - m.getWeaponLPrice() * amount);
            }
            else if (confirm == 'n')
            {
                cout << "You did not buy any (+3) Vorpal Longswords" << endl;
            }
        }
    }
    else if (choice == 6)
    {

    }
}

void Armor()
{

    int amount = -1;
    bool money_check = false;
    bool confirm_check = false;
    while (!money_check)
    {
        amount = m.buyArmor();
        if (amount * m.getArmorPrice() <= s.getGold())
        {
            money_check = true;
        }
        else
        {
            cout << "You do not have enough gold to buy " << amount << " Armor(s)" << endl;
        }
    }
    if (amount != 0)
    {
        do
        {
            cout << "You want to buy " << amount << " Armor(s) for " << amount * m.getArmorPrice() << " (y/n)" << endl;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'n')
            {
                confirm_check = true;
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        while (!confirm_check);
        if (confirm == 'y')
        {
            cout << "Thank you for your patronage! What else can I get for you?" << endl;
            s.setArmor(amount);
            s.setGold(s.getGold() - m.getArmorPrice() * amount);
        }
        else
        {
            cout << "You did not purchase any Armors." << endl;
        }
    }
    else
    {
        cout << "You did not purchase any Armors." << endl;
    }
}

void Treasure()
{
    int sum = 0;
    sum += s.getTreasure(0) * 10;
    sum += s.getTreasure(1) * 20;
    sum += s.getTreasure(2) * 30;
    sum += s.getTreasure(3) * 40;
    sum += s.getTreasure(4) * 50;
    if (sum == 0)
    {
        cout << "You do not have any treasure to sell." << endl;
    }
    else
    {
        bool check = false;
        cout << "I will buy all of your treasure for " << sum << " Gold." << endl;
        while (!check)
        {
            cout << "Do you wish to sell all of your treasure? (y/n)" << endl;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'n')
            {
                check = true;
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        if (confirm == 'y')
        {
            cout << "Pleasure doing business with you!" << endl;
            s.setGold(sum + s.getGold());
            for (int i=0; i<5; i++)
            {
                s.setTreasure(i,0);
            }
        }
        else
        {
            cout << "You did not sell any Treasures." << endl;
        }
    }
}

void merchantShop(int clearedRooms)
{
    m.setNewPrice(clearedRooms);
    merc = 0;
    int option;
    while (merc == 0)
    {
        s.printInventory();
        option = m.merchantOptions();
        if (option == 1)
        {
            Ingredients();
        }
        else if (option == 2)
        {
            Pots();
        }
        else if (option == 3)
        {
            Weapons();
        }
        else if (option == 4)
        {
            Armor();
        }
        else if (option == 5)
        {
            Treasure();
        }
        else if (option == 6)
        {
            bool leave = false;
            do
            {
                cout << "Are you you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'n')
                {
                    leave = true;
                }
                else
                {
                    cout << "Please enter a valid input." << endl;
                }
            }
            while (!leave);
            if (confirm == 'y')
            {
                merc = 1;
                leave = true;
            }
            else if (confirm == 'n')
            {

            }
        }
    }
}

int partySize()
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if(!party_members[i].isDead())
        {
            count++;
        }
    }
    return count;
}

void cookAndEat()
{
    int pot;
    cout << "Choose cookware:" << endl;
    cout << " 1) Ceramic Pot (25%) " << s.getCookware(0) << endl;
    cout << " 2) Frying Pan (10%) " << s.getCookware(1) << endl;
    cout << " 3) Cauldron (2%) " << s.getCookware(2) << endl;
    cin >> pot;
    if (s.getCookware(pot-1) > 0)
    {
        bool check = false;
        while (!check)
        {
            int amount;
            cout << "How many meals do you want to make? (1 meal = 5 kg)" << endl;
            cin >> amount;
            if (amount * 5 > s.getIngredients())
            {
                cout << "You do not have enough ingredients" << endl;
            }
            else
            {
                check = true;
                if (pot-1 == 0)
                {
                    int randNum = rand() % 4;
                    if (randNum == 0)
                    {
                        cout << "The Ceramic Pot broke. No food was made. Ingredients were lost." << endl;
                        s.setIngredients(s.getIngredients()-(amount * 5));
                        s.setCookware(0,-1);
                    }
                    else
                    {
                        cout << "Success!" << endl;
                        s.setIngredients(s.getIngredients() - (amount * 5));
                        for (int i=0; i<5; i++)
                        {
                            party_members[i].setFullness(party_members[i].getFullness()+amount);
                        }
                    }
                }
                else if (pot-1 == 1)
                {
                    int randNum = rand() % 10;
                    if (randNum == 0)
                    {
                        cout << "The Frying Pan broke. No food was made. Ingredients were lost." << endl;
                        s.setIngredients(s.getIngredients()-(amount * 5));
                        s.setCookware(1,-1);
                    }
                    else
                    {
                        cout << "Success!" << endl;
                        s.setIngredients(s.getIngredients() - (amount * 5));
                        for (int i=0; i<5; i++)
                        {
                            party_members[i].setFullness(party_members[i].getFullness()+amount);
                        }
                    }
                }
                else
                {
                    int randNum = rand() % 50;
                    if (randNum == 0)
                    {
                        cout << "The Cauldron broke. No food was made. Ingredients were lost." << endl;
                        s.setIngredients(s.getIngredients()-(amount * 5));
                        s.setCookware(2,-1);
                    }
                    else
                    {
                        cout << "Success!" << endl;
                        s.setIngredients(s.getIngredients() - (amount * 5));
                        for (int i=0; i<5; i++)
                        {
                            party_members[i].setFullness(party_members[i].getFullness()+amount);
                        }
                    }
                }
            }
        }
    }
    else
    {
        cookAndEat();
    }
}

void misfortunes()
{
    int fortune = rand() % 10;
    if (fortune == 0 || fortune == 1 || fortune == 2)
    {
        // ingredients stolen
        if (rand() % 2 == 0)
        {
            s.setIngredients(s.getIngredients()-10);
            cout << "You were robbed of 10 kg of ingredients" << endl;
        }
        else
        {
            // armor stolen
            int pmember = rand() % partySize();
            s.setArmor(s.getArmor()-1);
            party_members[pmember].setArmor(0);
            cout << party_members[pmember].getName() << " lost their armor." << endl;
        }
    }
    else if (fortune == 3)
    {
        // armor can break
        int pmember = rand() % partySize();
        s.setArmor(s.getArmor()-1);
        party_members[pmember].setArmor(0);
        cout << party_members[pmember].getName() << " lost their armor." << endl;
    }
    else if (fortune == 4 || fortune == 5 || fortune == 6)
    {
        // party member gets food poisoning
        int pmember = (rand() % partySize() - 1) + 1;
        party_members[pmember].setFullness(party_members[pmember].getFullness()-20);
        cout << party_members[pmember].getName() << " got food poisoning." << endl;
        if (party_members[pmember].getFullness() == 0)
        {
            cout << party_members[pmember].getName() << " died from hunger" << endl;
        }
        else
        {
            cout << party_members[pmember].getName() << " has " << party_members[pmember].getFullness() << " fullness left." << endl;
        }
    }
    else if (fortune == 7 || fortune == 8 || fortune == 9)
    {
        // party member gets locked in room
        int pmember = (rand() % partySize() - 1) + 1;
        cout << party_members[pmember].getName() << " got locked in a room. You must continue the journey without them." << endl;
        party_members[pmember].setIsDead(true);
    }
}

void addToLeaderboard(string playerName)
{
    // write to file
    string file = "C:\\Users\\mjsbl\\CLionProjects\\CSCI_Final\\Scoreboard.txt";
    ofstream inFile;
    inFile.open(file);
    inFile << playerName << endl;
    inFile.close();
}
void printLeaderboard()
{
    // read file
    string file = "C:\\Users\\mjsbl\\CLionProjects\\CSCI_Final\\Scoreboard.txt";
    ifstream inFile;
    string line;
    inFile.open(file);
    while(getline(inFile,line))
    {
        cout << line << endl;
    }
}

int printOptions()
{
    int choice;
    cout << "Choose an action:" << endl;
    cout << " 1) Move" << endl;
    cout << " 2) Investigate" << endl;
    cout << " 3) Pick a Fight" << endl;
    cout << " 4) Cook & Eat" << endl;
    cout << " 5) Equip Weapons" << endl;
    cout << " 6) Equip Armor" << endl;
    cout << " 7) Give Up" << endl;
    cin >> choice;
    if (choice == 2 || choice == 3 || choice == 4)
    {
        // 40% chance of misfortune
        int random = rand() % 5;
        if (random == 0 || random == 1)
        {
            misfortunes();
        }
    }
    return choice;
}

int choosePartyMember(vector<PartyMember> vs)
{
    int max_num;
    int member;
    cout << "Choose a party member" << endl;
    for (int i = 0; i < vs.size(); i++) {
        if (!vs[i].isDead()) {
            cout << i+1 << ") " << vs[i].getName() << endl;
            max_num = i+2;
        }
    }
    cout << "Or enter '0' to quit" << endl;
    cin >> member;

    if (member > max_num && member >= 0)
    {
        cout << "Please enter a valid input" << endl;
        return choosePartyMember(vs);
    }

    if (member == 0)
    {
        return -1;
    }

    return member;
}


int getTotalWeaponPower()
{
    int weapon_power = 0;
    for (int i=0; i<party_members.size(); i++)
    {
        if (!party_members[i].isDead()) {
            weapon_power += party_members[i].getWeapon().damage;
        }
    }
    return weapon_power;
}

void equipWeapon() {
    int party_member_index;
    party_member_index = choosePartyMember(party_members);
    if (party_member_index == -1)
    {
        return;
    }
    else
    {
        // print choose a weapon
        int weapon_choice;
        cout << "Choose a Weapon: " << endl;

        int max_num = 0;
        // only shows available weapons that can be equipped
        for (int i = 0; i < 5; i++)
        {
            if (s.available_Weapons[i].second > 0)
            {
                cout << i + 1 << ") " << s.available_Weapons[i].first.name << endl;
                max_num = i + 1;
            }
        }

        cout << "Or enter '0' to quit" << endl;
        cin >> weapon_choice;
        if (weapon_choice < 0 || weapon_choice > max_num)
        {
            //invalid input
            cout << "Invalid Input" << endl;
            equipWeapon();
            return;
        }
        else if (weapon_choice == 0)
        {
            return;
        }
        party_members[party_member_index-1].setWeapon(s.available_Weapons[weapon_choice - 1].first);
        s.setWeaponArr(s.available_Weapons[weapon_choice-1].first.name,-1);
        cout << "Weapon successfully equipped!" << endl;
    }
}

void equipArmor()
{
    int party_member_index;
    party_member_index = choosePartyMember(party_members);
    if (party_member_index == -1)
    {
        return;
    }
    else
    {
        if (s.getUnequippedArmor() > 0)
        {
            party_members[party_member_index-1].setArmor(1);
            cout << "Armor successfully equipped!" << endl;
        }

    }
}

void getNames()
{
    string name;

    cout << "Enter Player name: " << endl;
    cin >> name;
    PartyMember user(name, true);
    party_members.push_back(user);

    for (int i=1; i<5; i++)
    {
        cout << "Enter npc #" << i << " name: " << endl;
        cin >> name;
        PartyMember tmp(name, false);
        party_members.push_back(tmp);
    }
}

int Battle(int power)
{
    if (power == 6)
    {
        cout << "The Sorcerer has appeared!" << endl;
        int r1 = (rand() % 5) + 1;
        int r2 = (rand() % 5) + 1;
        if (f.fight_calc(getTotalWeaponPower(), s.getArmor(), s.getRooms(), r1, r2) == true)
        {
            cout << "The Sorcerer has been defeated. You can now leave the dungeon!" << endl;
            return true;
        }
        else
        {
            s.setGold(int(s.getGold() * 0.75));
            if (s.getIngredients() >= 30)
            {
                s.setIngredients(s.getIngredients() - 30);
            }
            else
            {
                s.setIngredients(0);
            }
            for (int i = 1; i < 5; i++)
            {
                if (party_members[i].getArmor() == 1)
                {
                    if (rand() % 20 == 0)
                    {
                        party_members[i].setIsDead(true);
                        s.setArmor(s.getArmor() - 1);
                    }
                }
                else
                {
                    if (rand() % 10 == 0)
                    {
                        party_members[i].setIsDead(true);
                        s.setArmor(s.getArmor() - 1);
                    }
                }
            }
        }
        for (int i = 0; i < 5; i++)
        {
            if (rand() % 2 == 0)
            {
                party_members[i].setFullness(party_members[i].getFullness() - 1);
            }
        }
    }
    else if (!f.getVectorSize(power) == 0)
    {
        bool wl;
        int mon = f.random_monster(power);
        cout << "Oh No! A ", f.printMonster(power, mon), cout << " (power: " << power << ") Appeared!" << endl;
        int r1 = (rand() % 5) + 1;
        int r2 = (rand() % 5) + 1;
        bool win = f.fight_calc(getTotalWeaponPower(), s.getArmor(), s.getRooms() + 1, r1, r2);
        if (win)
        {
            wl = true;
            cout << "The ", f.printMonster(power, mon), cout << " has been defeated!" << endl;
            f.remove_monster(mon, power);
            s.setGold(s.getGold() + (10 * power));
            s.setIngredients(s.getIngredients() + (5 * power));
            if (rand() % 10 == 0)
            {
                s.setKeys(1);
            }
        } else {
            wl = false;
            s.setGold(int(s.getGold() * 0.75));
            if (s.getIngredients() >= 30) {
                s.setIngredients(s.getIngredients() - 30);
            } else {
                s.setIngredients(0);
            }
            for (int i = 1; i < 5; i++) {
                if (party_members[i].getArmor() == 1) {
                    if (rand() % 20 == 0) {
                        party_members[i].setIsDead(true);
                        s.setArmor(s.getArmor() - 1);
                    }
                } else {
                    if (rand() % 10 == 0) {
                        party_members[i].setIsDead(true);
                        s.setArmor(s.getArmor() - 1);
                    }
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            if (rand() % 2 == 0) {
                party_members[i].setFullness(party_members[i].getFullness() - 1);
            }
        }
        return wl;
    }
    else
    {
        cout << "There are no monsters of this power level left." << endl;
        return 2;
    }
}

void checkFullness()
{
    for (int i=0; i<5; i++)
    {
        if (party_members[i].getFullness() == 1 && !party_members[i].isDead())
        {
            cout << party_members[i].getName() << " will starve to death on the next turn. It is recommended to use this turn to cook and eat food." << endl;
        }
        else if (party_members[i].getFullness() == 0 && !party_members[i].isDead())
        {
            party_members[i].setIsDead(true);
            cout << party_members[i].getName() << " has died from starvation." << endl;
            cout << "Your party size has been reduced." << endl;
        }
    }

}
void roomFight()
{
    if (Battle(s.getRooms()+2) == true)
    {
        // 60% chance of misfortune
        int random = rand() % 5;
        if (random == 0 || random == 1 || random == 2)
        {
            misfortunes();
        }
        map.isExplored(map.getPlayerRow(),map.getPlayerCol());
        s.setRooms(s.getRooms()+1);
        map.removeRoom(map.getPlayerRow(),map.getPlayerCol());
    }

}

void clearingRoom(bool mainLoop)
{
    int enter;
    cout << "Choose an option:" << endl;
    cout << " 1) Open the door" << endl;
    cout << " 2) Move" << endl;
    cout << " 3) Give up" << endl;
    cin >> enter;
    if (enter == 1)
    {
        if (s.getKeys() > 0)
        {
            if (Battle(s.getRooms()+2) == true)
            {
                // 60% chance of misfortune
                int random = rand() % 5;
                if (random == 0 || random == 1 || random == 2)
                {
                    misfortunes();
                }
                map.isExplored(map.getPlayerRow(),map.getPlayerCol());
                s.setRooms(s.getRooms()+1);
                map.removeRoom(map.getPlayerRow(),map.getPlayerCol());


            }
            else
            {
                s.setKeys(-1);
                // 40% chance of misfortune
                int random = rand() % 5;
                if (random == 0 || random == 1)
                {
                    misfortunes();
                }
            }
        }
        else
        {
            // rock paper scissors
            // if win then enter room
            // if lose, lose one party member (not player)
            if (a.doorGame() == true)
            {
                roomFight();
            }
            else
            {
                party_members[(rand() % (partySize() - 1)) + 1].setIsDead(true);
            }

        }
    }
    else if (enter == 2)
    {
        char direction;
        cout << "Move a direction" << endl;
        cin >> direction;
        map.move(direction);
    }
    else
    {
        char conf;
        cout << "Are you sure you want to give up? (y/n)" << endl;
        cin >> conf;
        if (conf == 'y')
        {
            mainLoop = true;
        }
    }
}



int main()
{

    a.readText();
    getNames();
    merchantShop(0);

    srand(time(0));


    assert(map.addRoom(2, 3));
    assert(map.addRoom(8, 11));
    assert(map.addRoom(2, 7));
    assert(map.addRoom(8, 2));
    assert(!map.addRoom(15, 15)); // should not show on map nor error out, out of bounds
    assert(!map.addRoom(2, 3));   // will not do anything since space is occupied
    assert(map.addRoom(5, 7));
    assert(!map.addRoom(3, 7)); // will fail due to exceeding max_rooms_

    assert(map.addNPC(4, 4));
    assert(map.addNPC(1, 2));
    assert(map.addNPC(7, 2));
    assert(map.addNPC(10, 4));
    assert(!map.addNPC(2, 7)); // should fail due to space being occupied
    assert(map.addNPC(9, 0));
    assert(!map.addNPC(10, 0)); // should fail due to max number of NPCs == 5

    // if game_loop becomes true, game ends
    bool game_loop = false;
    while(!game_loop)
    {
        if (s.getSorcererAnger() == 100)
        {
            game_loop = true;
            continue;
        }
        checkFullness();

        if (party_members[0].isDead())
        {
            game_loop = true;
            continue;
        }

        if (partySize() <= 1)
        {
            game_loop = true;
            continue;
        }

        s.printStats();
        s.printInventory();
        s.printParty(party_members);
        map.displayMap();
        if (map.isFreeSpace(map.getPlayerRow(),map.getPlayerCol()))
        {
            int action = printOptions();
            if (action == 1)
            {
                char direction;
                cout << "What direction do you want to move?" << endl;
                cin >> direction;
                map.move(direction);

                s.setSorcererAnger(1);

                int randomNum;
                for (int i=0; i<5; i++)
                {
                    randomNum = rand() % 5;
                    if (randomNum == 0 && !party_members[i].isDead())
                    {
                        party_members[i].setFullness(party_members[i].getFullness() - 1);
                        cout << party_members[i].getName() << " lost 1 fullness" << endl;
                    }

                }

            }
            else if (action == 2)
            {
                // Investigate
                map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());

                int randomNum = rand() % 10;
                if (randomNum == 0)
                {
                    s.setKeys(1);
                    cout << "You found a key!" << endl;
                }
                else if (randomNum == 1 || randomNum == 2)
                {
                    s.setTreasure(s.getRooms(), 1);
                    cout << "You found a treasure!" << endl;
                }
                else if (randomNum == 3 || randomNum == 4)
                {
                    Battle(s.getRooms()+1);
                }

                if (randomNum != 3 && randomNum != 4)
                {
                    for (int i=0; i<5; i++)
                    {
                        int randomNum2 = rand() % 2;
                        if (randomNum2 == 0)
                        {
                            party_members[i].setFullness(party_members[i].getFullness() - 1);
                            cout << party_members[i].getName() << " lost 1 fullness." << endl;
                        }
                    }
                }

            }
            else if (action == 3)
            {
                // Fight
                Battle(s.getRooms()+1);
            }
            else if (action == 4)
            {
                cookAndEat();
            }
            else if (action == 5)
            {
                // equip weapon
                equipWeapon();
            }
            else if (action == 6)
            {
                // equip Armor
                equipArmor();
            }
            else
            {
                char check;
                cout << "Are you sure you want to quit? (y/n)" << endl;
                cin >> check;
                if (check == 'y')
                {
                    cout << "Goodbye!" << endl;
                    game_loop = true;
                }
            }
        }
        else if (map.isRoomLocation(map.getPlayerRow(),map.getPlayerCol()))
        {
            clearingRoom(game_loop);
        }
        else if (map.isNPCLocation(map.getPlayerRow(),map.getPlayerCol()))
        {
            if (a.askQuestion(rand() % 20) == true)
            {
                merchantShop(s.getRooms());
                map.removeNPC(map.getPlayerRow(),map.getPlayerCol());
            }
            else
            {
                if (f.getVectorSize(s.getRooms()+1) > 0)
                {
                    Battle(s.getRooms()+1);
                }
                else
                {
                    cout << "There are no more monsters to fight." << endl;
                }
            }
            map.isExplored(map.getPlayerRow(),map.getPlayerCol());
        }
        else if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
        {
            if (s.getRooms() == 5)
            {
                // congratulate player and add to leaderboard
                cout << "Congratulations! You escaped the Sorcerer's duncgeon!" << endl;
                addToLeaderboard(party_members[0].getName());
                cout << "You have joined the leaderboards!" << endl;
                cout << endl;
                printLeaderboard();
                game_loop = true;
            }
            else
            {
                cout << "You can not leave yet. You must first defeat the Sorcerer." << endl;
            }
        }



    }
    cout << "Game over" << endl;
    return 0;
}

