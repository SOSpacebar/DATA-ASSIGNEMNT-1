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
	//Set the position of the dweller.
	this->position_ = coord;
}

const int Dweller::getSPECIAL()
{
	//Check is there a outfit equipped.
	if (outfit_ == 0)
		return this->SPECIAL_;

	//If there outfit equipped, using digit extraction to add the values one by one base on the placement of both dweller SPECIAL and outfit SPECIAL.
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
	//Return position value
	return this->position_;
}

const int Dweller::getCurrentHealth()
{
	//Return health_ value and checks for above 100 or lower the 0
	if (this->health_ > 100)
	{
		this->health_ = 100;
	}

	if (this->health_ < 0)
	{
		this->health_ = 0;
	}

	return this->health_ - radiation_;
}

const int Dweller::getCurrentRadDamage()
{
	//Return radition_ value and checks for above 100 or lower the 0
	if (this->radiation_ > 100)
	{
		this->radiation_ = 100;
	}

	if (this->radiation_ < 0)
	{
		this->radiation_ = 0;
	}

	return this->radiation_;
}

const int Dweller::getAttackDamage()
{
	//Check is there a weapon equipped if equip attack will use weapon damg else it just return 1
	if (this->weapon_ != 0 && this->weapon_->getDurability() > 0)
	{
		return this->weapon_->getAttackDmg();
	}

	return 1;
}

void Dweller::receiveHealthDamage(const int& dmg)
{
	//Reduce health base on damage and radiation
	this->health_ = health_ - radiation_ - dmg;
}

void Dweller::receiveRadDamage(const int& dmg)
{
	//Increase radiation base on damage and reduce health due to rediation.
	this->radiation_ += dmg;
	this->health_ -= radiation_;
}

void Dweller::receiveEquipmentDamage(const int& dmg)
{
	//Check if there a outfit/weapon equipped or not damage. Outfit takes full damage while weapon takes half
	if (this->outfit_ != 0 && this->outfit_->getDurability() > 0)
	{
		outfit_->receiveDamage(dmg);
	}

	if (this->weapon_ != 0 && this->weapon_->getDurability() > 0)
	{
		weapon_->receiveDamage(dmg * 0.5f);
	}
}

void Dweller::addStimpak(const int& value)
{
	//Increase stimpak_ count base on value
	this->stimpak_ += value;
}

void Dweller::addRadAway(const int& value)
{
	//Increase radaway_ count base on value
	this->radaway_ += value;
}

void Dweller::useStimpak()
{
	//Stimpak only heals 20
	const int healAmount = 20;

	//Check if dweller can us stimpak, also to heal dweller health value base on healAmount plus radiation.
	if (this->health_ < 100)
	{
		this->health_ = (health_ - radiation_) + healAmount;
		this->stimpak_--;
	}

	//Stop health value from going above 100.
	if (this->health_ > 100)
		this->health_ = 100;
}

void Dweller::useRadAway()
{
	//RadAway only heals 10
	const int radHealAmount = 10;

	//Check if dweller can use radAway
	if (this->radiation_ > 0)
	{
		this->radiation_ -= radHealAmount;
		this->radaway_--;
	}

	//Check the radiation amount not to go below 0
	if (this->radiation_ < 0)
		this->radiation_ = 0;
}

Outfit* Dweller::assignOutfit(Outfit* newOutfit)
{
	//Assign new outfit in to outfit_
	return this->outfit_ = newOutfit;
}

Weapon* Dweller::assignWeapon(Weapon* newWeapon)
{
	//Assign new weapon in to weapon_
	return this->weapon_ = newWeapon;
}

bool Dweller::isDead()
{
	//Checks if the object dead.
	if (health_ < 1) 
	{
		return true;
	}

	return false;
}
