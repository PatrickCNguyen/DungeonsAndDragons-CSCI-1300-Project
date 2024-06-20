//#include "Map.h"
//#include <cassert>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//int printOptions()
//{
//    int choice;
//    cout << "Choose an action:" << endl;
//    cout << " 1) Move" << endl;
//    cout << " 2) Investigate" << endl;
//    cout << " 3) Pick a Fight" << endl;
//    cout << " 4) Cook & Eat" << endl;
//    cout << " 5) Equip Weapons/Armor" << endl;
//    cout << " 6) Give Up" << endl;
//    cin >> choice;
//    return choice;
//}
//
//int main()
//{
//    Map map;
//
//    assert(map.addRoom(2, 3));
//    assert(map.addRoom(8, 11));
//    assert(map.addRoom(2, 7));
//    assert(map.addRoom(8, 2));
//    assert(!map.addRoom(15, 15)); // should not show on map nor error out, out of bounds
//    assert(!map.addRoom(2, 3));   // will not do anything since space is occupied
//    assert(map.addRoom(5, 7));
//    assert(!map.addRoom(3, 7)); // will fail due to exceeding max_rooms_
//
//    assert(map.addNPC(4, 4));
//    assert(map.addNPC(1, 2));
//    assert(map.addNPC(7, 2));
//    assert(map.addNPC(10, 4));
//    assert(!map.addNPC(2, 7)); // should fail due to space being occupied
//    assert(map.addNPC(9, 0));
//    assert(!map.addNPC(10, 0)); // should fail due to max number of NPCs == 5
//
//    bool map_loop = false;
//    while(!map_loop)
//    {
//
//        map.displayMap();
//
//        int action = printOptions();
//        if (action == 1)
//        {
//            char direction;
//            cout << "What direction do you want to move?" << endl;
//            cin >> direction;
//            if (map.move(direction) == true)
//            {
//                // Ask riddle
//                bool riddle = true;
//                if (riddle == true)
//                {
//                    // merchant
//                    cout << "merchant menu" << endl;
//                }
//                else
//                {
//                    // fight
//                }
//            }
//        }
//        else if (action == 2)
//        {
//            map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
//            // Investigate
//        }
//        else if (action == 3)
//        {
//            // Fight
//        }
//        else if (action == 4)
//        {
//            // cook and eat
//        }
//        else if (action == 5)
//        {
//            // equip weapon
//        }
//        else
//        {
//            map_loop = true;
//        }
//
//        // if room is cleared
//        //  assert(map.removeRoom(map.getPlayerRow(), map.getPlayerCol()));
//
//
//    }
//    return 0;
//}