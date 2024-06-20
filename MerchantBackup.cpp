////
//// Created by mjsbl on 11/21/2022.
////
//#include "Merchant.h"
//#include <iostream>
//#include "Stats.h"
//using namespace std;
//
//
//merchant::merchant()
//{
//    ingredientPrice = 1;
//    cookwarePPrice = 2;
//    cookwareFPrice = 10;
//    cookwareCPrice = 20;
//    weapon0Price = 2;
//    weapon1Price = 2;
//    weapon2Price = 5;
//    weapon3Price = 15;
//    weapon4Price = 50;
//    armorPrice = 5;
//    treasureRPrice = 10;
//    treasureNPrice = 20;
//    treasureBPrice = 30;
//    treasureCPrice = 40;
//    treasureGPrice = 50;
//}
//void merchant::setNewPrice(int roomsCleared)
//{
//    ingredientPrice = int(1 * (1 + roomsCleared * .25));
//    cookwarePPrice = int(2 * (1 + roomsCleared * .25));
//    cookwareFPrice = int(10 * (1 + roomsCleared * .25));
//    cookwareCPrice = int(20 * (1 + roomsCleared * .25));
//    weapon0Price = int(2 * (1 + roomsCleared * .25));
//    weapon1Price = int(2 * (1 + roomsCleared * .25));
//    weapon2Price = int(5 * (1 + roomsCleared * .25));
//    weapon3Price = int(15 * (1 + roomsCleared * .25));
//    weapon4Price = int(50 * (1 + roomsCleared * .25));
//    armorPrice = int(5 * (1 + roomsCleared * .25));
//    treasureRPrice = int(10 * (1 + roomsCleared * .25));
//    treasureNPrice = int(20 * (1 + roomsCleared * .25));
//    treasureBPrice = int(30 * (1 + roomsCleared * .25));
//    treasureCPrice = int(40 * (1 + roomsCleared * .25));
//    treasureGPrice = int(50 * (1 + roomsCleared * .25));
//}
//
//void merchant::buyIngredients()
//{
//    stats m;
//    int choice;
//    char confirm;
//    cout << "How many kg of ingredients do you need [" << ingredientPrice << " Gold/kg]? (Enter a positive multiple of 5, or 0 to cancel)" << endl;
//    cin >> choice;
//    if (choice == 0)
//    {
//        merchantOptions();
//    }
//    else if (choice % 5 == 0)
//    {
//        if (choice * ingredientPrice > m.getGold())
//        {
//            cout << "You do not have enough gold to purchase " << choice << " kg of ingredients" << endl;
//            merchantOptions();
//        }
//        else
//        {
//            cout << "You want to buy " << choice << " kg of ingredients for " << choice * ingredientPrice << " Gold? (Y/N)" << endl;
//            cin >> confirm;
//            if (confirm == 'Y')
//            {
//                cout << "Thank you for your patronage! What else can I get for you?" << endl;
//                m.setIngredients(choice);
//                m.setGold(m.getGold() - choice * ingredientPrice);
//            }
//            else if (confirm == 'N')
//            {
//                cout << "You did not buy any ingredients" << endl;
//                merchantOptions();
//            }
//        }
//    }
//}
//void merchant::buyCookware()
//{
//    int choice;
//    int amount;
//    char confirm;
//    stats m;
//    cout << "Choose on of the following:" << endl;
//    cout << " 1. (25%) Ceramic Pot [" << cookwarePPrice << " Gold]" << endl;
//    cout << " 2. (10%) Frying Pan [" << cookwareFPrice << " Gold]" << endl;
//    cout << " 3. (2%) Cauldron [" << cookwareCPrice << " Gold]" << endl;
//    cout << " 4. Cancel" << endl;
//    cin >> choice;
//    if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
//    {
//        cout << "Enter a valid input" << endl;
//        buyCookware();
//    }
//    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
//    cin >> amount;
//    if (choice == 1)
//    {
//        if (cookwarePPrice * amount < m.getGold())
//        {
//            cout << "You want to buy " << amount << " Ceramic Pot(s) (Y/N)" << endl;
//            cin >> confirm;
//            if (confirm == 'Y')
//            {
//                cout << "Thank you for your patronage! What else can I get for you?" << endl;
//                m.setCookware(0,amount);
//                m.setGold(cookwarePPrice * m.getGold());
//                m.printStats();
//                merchantOptions();
//            }
//            else if (confirm == 'N')
//            {
//                cout << "You did not buy any Ceramic Pots" << endl;
//                m.printStats();
//                merchantOptions();
//            }
//        }
//        else
//        {
//            cout << "You do not have enough gold to purchase " << amount << " Ceramic Pot(s)" << endl;
//            m.printStats();
//            merchantOptions();
//        }
//    }
//    else if (choice == 2)
//    {
//        if (cookwareFPrice * amount < m.getGold())
//        {
//            cout << "You want to buy " << amount << " Frying Pan(s) (Y/N)" << endl;
//            cin >> confirm;
//            if (confirm == 'Y')
//            {
//                cout << "Thank you for your patronage! What else can I get for you?" << endl;
//                m.setCookware(1,amount);
//                m.setGold(cookwareFPrice * m.getGold());
//                m.printStats();
//                merchantOptions();
//            }
//            else if (confirm == 'N')
//            {
//                cout << "You did not buy any Frying Pans" << endl;
//                m.printStats();
//                merchantOptions();
//            }
//
//        }
//        else
//        {
//            cout << "You do not have enough gold to purchase " << amount << " Frying Pan(s)" << endl;
//            m.printStats();
//            merchantOptions();
//        }
//    }
//    else if (choice == 3)
//    {
//        if (cookwareCPrice * amount < m.getGold())
//        {
//            cout << "You want to buy " << amount << " Cauldron(s) (Y/N)" << endl;
//            cin >> confirm;
//            if (confirm == 'Y')
//            {
//                cout << "Thank you for your patronage! What else can I get for you?" << endl;
//                m.setCookware(2, amount);
//                m.setGold(cookwareCPrice * m.getGold());
//                m.printStats();
//                merchantOptions();
//            }
//            else if (confirm == 'N')
//            {
//                cout << "You did not buy any Ceramic Pots" << endl;
//                m.printStats();
//                merchantOptions();
//            }
//
//        }
//        else
//        {
//            cout << "You do not have enough gold to purchase " << amount << " Ceramic Pot(s)" << endl;
//            m.printStats();
//            merchantOptions();
//        }
//    }
//    else if (choice == 4)
//    {
//        cout << "Are you sure you're finished? You won't be able to buy anything else from me! (Y/N)" << endl;
//        cin >> confirm;
//        if (confirm == 'Y')
//        {
//            m.printStats();
//            merchantOptions();
//        }
//        else if (confirm == 'N')
//        {
//
//        }
//    }
//}
//void merchant::buyWeapons()
//{
//
//}
//void merchant::buyArmor()
//{
//
//}
//void merchant::sellTreasure()
//{
//
//}
//int merchant::merchantOptions()
//{
//    int a;
//    merchant b;
//    cout << "Choose one of the following:" << endl;
//    cout << " 1. Ingredients: To make food, you have to cook raw ingredients." << endl;
//    cout << " 2. Cookware: You will need something to cook those ingredients." << endl;
//    cout << " 3. Weapons: It's dangerous to go alone, take this!" << endl;
//    cout << " 4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
//    cout << " 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
//    cout << " 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
//    cout << endl;
//    cin >> a;
//    if (a == 1)
//    {
//        b.buyIngredients();
//        return 1;
//    }
//    else if (a == 2)
//    {
//        b.buyCookware();
//        return 1;
//    }
//    else if (a == 6)
//    {
//        return 2;
//    }
//    else
//    {
//        return 1;
//    }
//}