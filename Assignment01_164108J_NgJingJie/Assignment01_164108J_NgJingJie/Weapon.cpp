#include "Weapon.h"


Weapon::Weapon(const string& name, const int& durability, const int& attack) : Item(name, durability), kAttackDmg(attack)
{

}

Weapon::~Weapon()
{
}

const int Weapon::getAttackDmg()
{
	return this->kAttackDmg;
}

void Weapon::receiveDamage(const int& dmg)
{
	this->durability_ -= dmg;
}