#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

class Item : public GameObject
{
public:
	Item(const string&, const int&);
	~Item();
	virtual void receiveDamage(const int&) = 0;
	const int getDurabiltiy();

protected:
	int durability;

};

#endif