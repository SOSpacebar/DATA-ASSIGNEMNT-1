#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

using std::string;

class GameObject
{
public:
	GameObject();
	GameObject(const string&);
	~GameObject();

	virtual string getName(void) = 0;
	virtual int getCount() = 0;

private:
	const string kName;
	int count;
};



#endif
