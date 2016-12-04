#include "Dweller.h"


Dweller::Dweller()
{
	//position = new Vec2D(0, 0);
}


Dweller::~Dweller()
{
}

void Dweller::setPosition(const Vec2D& coord)
{
	this->position = coord;
}
