#include "Weapon.h"


Weapon::Weapon(const string& name, const int& durability, const int& attack) : Item(name, durability), kAttackDmg(attack)
{
}


Weapon::~Weapon()
{
}
