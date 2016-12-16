#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

class Item : public GameObject
{
public:
	Item(const string&, const int&);
	virtual ~Item();
	virtual void receiveDamage(const int&) = 0;
	const int getDurability();

protected:
	int durability_;

};

#endif