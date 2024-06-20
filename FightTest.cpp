#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Fight.h"
#include "Stats.h"
using namespace std;

//int split(string x, char y, string str_arr[], int arr_size)
//{
//    int size = 0;
//    if (x != "")
//    {
//        int sl = x.length();
//        int a = 0;
//        int z = 0;
//        for(int i=0; i<=sl; i++)
//        {
//            if(x[i] == y)
//            {
//                str_arr[a] = x.substr(z,i-z);
//                a++;
//                z = i + 1;
//                size++;
//            }
//            if(i == sl)
//            {
//                str_arr[a] = x.substr(z,sl-z);
//                size++;
//            }
//        }
//        if (size > arr_size)
//        {
//            return -1;
//        }
//        else if (a == 0)
//        {
//            return 1;
//        }
//    }
//    else
//    {
//        return 0;
//    }
//    return size;
//}

//int main()
//{
//    stats x;
//    x.setRooms(2);
//    string file = "Monster.txt";
//    string line = "";
//    ifstream inFile;
//    string power_arr[2];
//    vector<string> vmonster;
//    vector<string> vpower;
//    fight y;
//    int a = 0;
//    inFile.open(file);
//
//    if (inFile.is_open())
//    {
//        while (getline(inFile, line))
//        {
//            split(line, ',', power_arr, 2);
//            if (stoi(power_arr[1]) == x.getRooms() + 1)
//            {
//                vmonster[a] = power_arr[0];
//                vpower[a] = power_arr[1];
//                a++;
//            }
//        }
//        for (int i=0; i<vmonster.size(); i++)
//        {
//            cout << vmonster[i] << endl;
//            cout << vpower[i] << endl;
//        }
//    }
//}
