#ifndef OUTFIT_H
#define OUTFIT_H

#include "Item.h"

class Outfit : public Item
{
public:
	Outfit(const string&, const int&, const int&);
	virtual ~Outfit();

	void receiveDamage(const int&);
	const int getSPECIAL();

protected:
	const int kSPECIAL;
};


#endif
