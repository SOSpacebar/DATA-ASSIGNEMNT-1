#include "GameObject.h"

int GameObject::count_ = 0;

GameObject::GameObject(const string& name) : kName(name)
{
	//increase count value for each game object created.
	this->count_++;
}

GameObject::~GameObject()
{
}

int GameObject::getCount()
{
	//return the amount of game objects.
	return count_;
}

string GameObject::getName()
{
	//return the name of the object
	return this->kName;
}
