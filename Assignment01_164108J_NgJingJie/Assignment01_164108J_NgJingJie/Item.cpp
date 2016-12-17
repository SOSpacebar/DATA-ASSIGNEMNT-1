#include "Item.h"


Item::Item(const string& name, const int& durability) : GameObject(name), durability_(durability)
{
}


Item::~Item()
{
}



const int Item::getDurability()
{
	//returns the durability of the item.
	return this->durability_;
}
