#include "Outfit.h"


Outfit::Outfit(const string& name, const int& durability, const int& SPECIAL) : Item(name, durability), kSPECIAL(SPECIAL)
{
}


Outfit::~Outfit()
{
}

const int Outfit::getSPECIAL()
{
	return kSPECIAL;
}

void Outfit::receiveDamage(const int& dmg)
{
	this->durability_ -= dmg;

	if (this->durability_ < 0)
		this->durability_ = 0;
}
