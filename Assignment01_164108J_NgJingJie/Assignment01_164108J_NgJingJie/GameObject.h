#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

using std::string;

class GameObject
{
public:
	~GameObject();

	string getName(void);
	static int getCount();

private:
	static int count_;

protected:
	const string kName;
	GameObject(const string&);
};



#endif
