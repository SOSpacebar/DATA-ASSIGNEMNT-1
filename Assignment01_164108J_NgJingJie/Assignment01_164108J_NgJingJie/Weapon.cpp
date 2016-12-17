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
	//Reduce weapon durability with dmg and checks if durability_ go lower then 0.
	this->durability_ -= dmg;

	if (this->durability_ < 0)
		this->durability_ = 0;
}