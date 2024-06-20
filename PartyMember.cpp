#include "PartyMember.h"
#include <string>

using namespace std;

#include "Stats.h"
using namespace std;


PartyMember::PartyMember(string pm, bool player)
{
    fullness = 50;
    member_weapon = Weapon();
    armor = false;
    is_dead = false;
    name = pm;
    is_player = player;
}

string PartyMember::getName()
{
    return name;
}

int PartyMember::getFullness()
{
    return fullness;
}
void PartyMember::setFullness(int new_fullness)
{
    fullness = new_fullness;
}

bool PartyMember::getArmor()
{
    return armor;
}
void PartyMember::setArmor(bool new_armor)
{
    armor = new_armor;
}

void PartyMember::setWeapon(Weapon weapon)
{
    member_weapon = weapon;
}
Weapon PartyMember::getWeapon()
{
    return member_weapon;
}

string PartyMember::getWeaponStr()
{
    return member_weapon.name;
}

bool PartyMember::isDead()
{
    return is_dead;
}

void PartyMember::setIsDead(bool isDead)
{
    is_dead = isDead;
}

bool PartyMember::isPlayer()
{
    return is_player;
}

void PartyMember::setIsPlayer(bool isDead)
{
    is_player = isDead;
}
