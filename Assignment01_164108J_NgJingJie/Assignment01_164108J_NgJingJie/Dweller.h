#ifndef DWELLER_H
#define DWELLER_H

#include "GameObject.h"
#include "Vec2D.h"
#include "Weapon.h"
#include "Outfit.h"

class Dweller :public GameObject
{
public:
	Dweller(const string&, const int&);
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
	Outfit* assignOutfit(Outfit*);
	Weapon* assignWeapon(Weapon*);
	bool isDead();

protected:
	Vec2D position_;
	int SPECIAL_;
	int health_;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit* outfit_;
	Weapon* weapon_;

};

#endif
