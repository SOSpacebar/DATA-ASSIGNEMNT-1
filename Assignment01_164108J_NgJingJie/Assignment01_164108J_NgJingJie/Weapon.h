#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(const string&, const int&, const int&);
	~Weapon();

	const int getAttackDmg();
	void receiveDamage(const int&);

protected:
	const int kAttackDmg;
};

#endif
