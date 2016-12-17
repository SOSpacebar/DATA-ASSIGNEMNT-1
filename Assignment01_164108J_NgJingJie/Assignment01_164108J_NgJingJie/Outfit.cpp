#include "Outfit.h"


Outfit::Outfit(const string& name, const int& durability, const int& SPECIAL) : Item(name, durability), kSPECIAL(SPECIAL)
{
}


Outfit::~Outfit()
{
}

const int Outfit::getSPECIAL()
{
	//returns outfit SPECIAL
	return kSPECIAL;
}

void Outfit::receiveDamage(const int& dmg)
{
	//Reduce outfit durability with dmg and checks if durability_ go lower then 0.
	this->durability_ -= dmg;

	if (this->durability_ < 0)
		this->durability_ = 0;
}
