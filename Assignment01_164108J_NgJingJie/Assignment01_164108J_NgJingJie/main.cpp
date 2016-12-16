#include <iostream>
using std::cout;
using std::endl;

#include "Dweller.h"
#include "Outfit.h"
#include "Weapon.h"
#include "Item.h"
#include "GameObject.h"
#include "Vec2D.h"

void testNames();
void shouldNotCompile();

int main()
{
    testNames();
    shouldNotCompile();

    Dweller d("One", 5555555);
    Outfit o("Outfit", 0, 1234567);
    cout << "Nothing should appear above" << endl;
    cout << d.getSPECIAL() << endl;
    d.assignOutfit(&o);
    cout << d.getSPECIAL() << endl;
    
    return 0;
}