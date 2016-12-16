#include "Dweller.h"

Dweller::Dweller(const string& name, const int& specialValue) : GameObject(name), SPECIAL_(specialValue)
{
	this->position_ = Vec2D(0, 0);
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
	if (outfit_ == 0)
		return this->SPECIAL_;

	int tempStorage;
	int specialHolder = SPECIAL_;
	int specialOutfitHolder = outfit_->getSPECIAL();
	SPECIAL_ = 0;

	for (unsigned i = 0; i < 7; i++)
	{
		tempStorage = specialHolder % 10 + specialOutfitHolder % 10;
		specialHolder /= 10;
		specialOutfitHolder /= 10;

		if (tempStorage > 9)
		{
			tempStorage = 9;
		}
		
		SPECIAL_ += tempStorage * pow(10, i);
	}


	return this->SPECIAL_;
}


const Vec2D Dweller::getPosition()
{
	return this->position_;
}

const int Dweller::getCurrentHealth()
{
	if (health_ > 100)
	{
		health_ = 100;
	}

	if (health_ < 0)
	{
		health_ = 0;
	}

	return this->health_ - radiation_;
}

const int Dweller::getCurrentRadDamage()
{
	if (radiation_ > 100)
	{
		radiation_ = 100;
	}

	if (radiation_ < 0)
	{
		radiation_ = 0;
	}

	this->health_ - radiation_;

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
	health_ = health_ - radiation_ - dmg;
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

	if (health_ > 100)
		health_ = 100;
}

void Dweller::useRadAway()
{
	if (radiation_ > 0)
	{
		radiation_ -= 10;
		radaway_--;
	}

	if (radiation_ < 0)
	{
		radiation_ = 0;
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
