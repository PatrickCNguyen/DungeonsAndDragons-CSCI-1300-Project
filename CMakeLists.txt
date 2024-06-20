cmake_minimum_required(VERSION 3.23)
project(CSCI_Final)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCI_Final Driver.cpp FightTest.cpp Stats.h Stats.cpp Action.h Fight.h Merchant.h Merchant.cpp Backups/MerchantBackup.cpp Fight.cpp PartyMember.cpp PartyMember.h Weapon.h Map.h MapDriver.cpp Map.cpp Action.cpp)
