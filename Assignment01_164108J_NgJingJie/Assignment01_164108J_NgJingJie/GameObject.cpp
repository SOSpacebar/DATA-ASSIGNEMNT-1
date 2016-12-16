#include "GameObject.h"

int GameObject::count_ = 0;

GameObject::GameObject(const string& name) : kName(name)
{
	this->count_++;
}

GameObject::~GameObject()
{
}

int GameObject::getCount()
{
	return count_;
}

string GameObject::getName()
{
	return kName;
}
