#include "Dweller.h"

Dweller::Dweller() : GameObject(kName)
{
	this->position_ = Vec2D(0, 0);
}

Dweller::Dweller(const string& name, const int& specialValue) : GameObject(name), SPECIAL_(specialValue)
{

}


Dweller::~Dweller()
{
}

void Dweller::setPosition(const Vec2D& coord)
{
	this->position_ = coord;
}
