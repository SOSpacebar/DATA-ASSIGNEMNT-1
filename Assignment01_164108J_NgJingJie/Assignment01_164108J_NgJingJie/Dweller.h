#ifndef DWELLER_H
#define DWELLER_H

#include "GameObject.h"
#include "Vec2D.h"

class Dweller :public GameObject
{
public:
	Dweller();
	Dweller(const string& name, const int& specialValue);
	~Dweller();

	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDamage();
	void setPosition(const Vec2D&);
	const Vec2D getPosition();
	void receiveHealthDamage(const int&);
	void receiveRadDamage(const int&);
	void receiveEquipmentDamage(const int&);
	void addStimpak(const int&);
	void addRadAway(const int&);
	void useStimpak();
	void useRadAway();
	//Outfit* assignOutfit(Outfit*);
	//Weapon* assignWeapon(Weapon*);
	bool isDead();

private:
	Vec2D position;
	int SPECIAL;
	int health;
	int radiation;
	int stimpak;
	int radaway;
	//Outfit* outfit;
	//Weapon* weapon;
};

#endif
