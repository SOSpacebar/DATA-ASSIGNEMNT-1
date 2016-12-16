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
