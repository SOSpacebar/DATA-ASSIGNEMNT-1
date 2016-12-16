#include "Item.h"


Item::Item(const string& name, const int& durability) : GameObject(name), durability(durability)
{
}


Item::~Item()
{
}

const int Item::getDurabiltiy()
{
	return durability;
}
