#include "Merchant.h"
#include <iostream>
#include "Stats.h"
using namespace std;


merchant::merchant()
{
    ingredientPrice = 1;
    cookwarePPrice = 2;
    cookwareFPrice = 10;
    cookwareCPrice = 20;
    weapon0Price = 2;
    weapon1Price = 2;
    weapon2Price = 5;
    weapon3Price = 15;
    weapon4Price = 50;
    armorPrice = 5;
    treasureRPrice = 10;
    treasureNPrice = 20;
    treasureBPrice = 30;
    treasureCPrice = 40;
    treasureGPrice = 50;
}
void merchant::setNewPrice(int roomsCleared)
{
    ingredientPrice = int(1 * (1 + roomsCleared * .25));
    cookwarePPrice = int(2 * (1 + roomsCleared * .25));
    cookwareFPrice = int(10 * (1 + roomsCleared * .25));
    cookwareCPrice = int(20 * (1 + roomsCleared * .25));
    weapon0Price = int(2 * (1 + roomsCleared * .25));
    weapon1Price = int(2 * (1 + roomsCleared * .25));
    weapon2Price = int(5 * (1 + roomsCleared * .25));
    weapon3Price = int(15 * (1 + roomsCleared * .25));
    weapon4Price = int(50 * (1 + roomsCleared * .25));
    armorPrice = int(5 * (1 + roomsCleared * .25));
//    treasureRPrice = int(10 * (1 + roomsCleared * .25));
//    treasureNPrice = int(20 * (1 + roomsCleared * .25));
//    treasureBPrice = int(30 * (1 + roomsCleared * .25));
//    treasureCPrice = int(40 * (1 + roomsCleared * .25));
//    treasureGPrice = int(50 * (1 + roomsCleared * .25));
}
int merchant::getIngredientPrice() const
{
    return ingredientPrice;
}
int merchant::getCookwarePPrice() const
{
    return cookwarePPrice;
}
int merchant::getCookwareFPrice() const
{
    return cookwareFPrice;
}
int merchant::getCookwareCPrice() const
{
    return cookwareCPrice;
}
int merchant::buyIngredients() const
{
    int choice;
    bool food_check = false;
    do
    {
        cout << "How many kg of ingredients do you need [" << ingredientPrice << " Gold/kg]? (Enter a positive multiple of 5, or 0 to cancel)" << endl;
        cin >> choice;
        if (choice % 5 == 0)
        {
            food_check = true;
        }
        else
        {
            cout << "Please enter a valid input." << endl;
        }
    }
    while (!food_check);
    if (choice == 0)
    {
        return -1;
    }
    return choice;
}
int merchant::buyCookware() const
{
    int choice;
    bool validInput = false;
    do
    {
        cout << "Choose on of the following:" << endl;
        cout << " 1. (25%) Ceramic Pot [" << cookwarePPrice << " Gold]" << endl;
        cout << " 2. (10%) Frying Pan [" << cookwareFPrice << " Gold]" << endl;
        cout << " 3. (2%) Cauldron [" << cookwareCPrice << " Gold]" << endl;
        cout << " 4. Cancel" << endl;
        cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
        {
            validInput = true;
        }
        else
        {
            cout << "Please enter a valid input." << endl;
        }
    }
    while (!validInput);
    return choice;
}
int merchant::getWeaponCPrice() const
{
    return weapon0Price;
}
int merchant::getWeaponSPrice() const
{
    return weapon1Price;
}
int merchant::getWeaponRPrice() const
{
    return weapon2Price;
}
int merchant::getWeaponBPrice() const
{
    return weapon3Price;
}
int merchant::getWeaponLPrice() const
{
    return weapon4Price;
}
int merchant::buyWeapons() const
{
    int choice;
    bool check = false;
    cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
    cout << "Note that some of them provide you with a special bonus in combat, marked by a (+X)." << endl;
    cout << endl;
    do
    {
        cout << "Choose one of the following:" << endl;
        cout << " 1. Stone Club [" << weapon0Price << " Gold]" << endl;
        cout << " 2. Iron Spear [" << weapon1Price << " Gold]" << endl;
        cout << " 3. (+1) Mythril Rapier [" << weapon2Price << " Gold]" << endl;
        cout << " 4. (+2) Flaming Battle-Axe [" << weapon3Price << " Gold]" << endl;
        cout << " 5. (+3) Vorpal Longsword [" << weapon4Price << " Gold]" << endl;
        cout << " 6. Cancel" << endl;
        cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6)
        {
            check = true;
        }
        else
        {
            cout << "Please enter a valid input." << endl;
        }

    }
    while (!check);
    return choice;


}

int merchant::getArmorPrice() const
{
    return armorPrice;
}

int merchant::buyArmor() const
{
    bool armor_check = false;
    int num_armor = -1;
    do
    {
        cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> num_armor;
        if (num_armor >= 0)
        {
            armor_check = true;
        }
        else
        {
            cout << "Please enter a valid input." << endl;
        }
    }
    while (!armor_check);
    return num_armor;
}
void merchant::sellTreasure()
{

}
int merchant::merchantOptions()
{
    int a;
    merchant b;
    bool option_check = false;
    do
    {
        cout << "Choose one of the following:" << endl;
        cout << " 1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << " 2. Cookware: You will need something to cook those ingredients." << endl;
        cout << " 3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << " 4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << " 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << " 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        cout << endl;
        cin >> a;
        if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6)
        {
            option_check = true;
        }
        else
        {
            cout << "Please enter a valid input." << endl;
        }
    }
    while (!option_check);

    if (a == 1)
    {
        return 1;
    }
    else if (a == 2)
    {
        return 2;
    }
    else if (a == 3)
    {
        return 3;
    }
    else if (a == 4)
    {
        return 4;
    }
    else if (a == 5)
    {
        return 5;
    }
    else if (a == 6)
    {
        return 6;
    }
    else
    {
        return 1;
    }
}