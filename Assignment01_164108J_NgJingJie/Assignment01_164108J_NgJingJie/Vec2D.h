#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
public:
	struct Coord
	{
		double x;
		double y;
	}; 

	Vec2D();
	Vec2D(double, double);
	~Vec2D();

private:
	Coord position;
};

#endif
