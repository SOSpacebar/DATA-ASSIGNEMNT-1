#include "Dweller.h"

Dweller::Dweller(const string& name, const int& specialValue) : GameObject(name), SPECIAL_(specialValue)
{
	this->position_ = Vec2D(0, 0);
	this->SPECIAL_ = 0000000;

	this->health_ = 100;
	this->radiation_ = 0;
	this->stimpak_ = 0;
	this->radaway_ = 0;
	this->outfit_ = 0;
	this->weapon_ = 0;
}


Dweller::~Dweller()
{
}

void Dweller::setPosition(const Vec2D& coord)
{
	this->position_ = coord;
}

const int Dweller::getSPECIAL()
{
	return this->SPECIAL_;
}


const Vec2D Dweller::getPosition()
{
	return this->position_;
}

const int Dweller::getCurrentHealth()
{
	if (isDead())
	{
		//Die
	}

	return this->health_;
}

const int Dweller::getCurrentRadDamage()
{
	return this->radiation_;
}

const int Dweller::getAttackDamage()
{
	if (weapon_ != 0 && weapon_->getDurability() > 0)
	{
		return this->weapon_->getAttackDmg();
	}

	return 1;
}

void Dweller::receiveHealthDamage(const int& dmg)
{
	health_ -= dmg;
}

void Dweller::receiveRadDamage(const int& dmg)
{
	radiation_ += dmg;
}

void Dweller::receiveEquipmentDamage(const int& dmg)
{
	if (outfit_ != 0 && outfit_->getDurability() > 0)
	{
		outfit_->receiveDamage(dmg);
	}

	if (weapon_ != 0 && weapon_->getDurability() > 0)
	{
		weapon_->receiveDamage(dmg * 0.5f);
	}
}

void Dweller::addStimpak(const int& value)
{
	stimpak_ += value;
}

void Dweller::addRadAway(const int& value)
{
	radaway_ += value;
}

void Dweller::useStimpak()
{
	if (health_ < 100)
	{
		health_ += 20;
		stimpak_--;
	}
}

void Dweller::useRadAway()
{
	if (radiation_ > 0)
	{
		radiation_ -= 10;
		radaway_--;
	}
}

Outfit* Dweller::assignOutfit(Outfit* newOutfit)
{
	return this->outfit_ = newOutfit;
}

Weapon* Dweller::assignWeapon(Weapon* newWeapon)
{
	return this->weapon_ = newWeapon;
}

bool Dweller::isDead()
{
	if (health_ < 1)
	{
		return true;
	}

	return false;
}
