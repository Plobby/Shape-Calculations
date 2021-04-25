#include "Point.h"

// Constructor
Point::Point(): x(0), y(0)
{
}

// Alternate constructor with x and y mentioned
Point::Point(int x, int y): x(x), y(y)
{
}

// Override "+" operator function to allow points to be added
Point Point::operator+(Point const& obj)
{
	return Point(x + obj.x, y + obj.y);
}

// Override "-" operator function to allow points to be subtracted
Point Point::operator-(Point const& obj)
{
	return Point(x - obj.x, y - obj.y);
}

// Override "*" operator function to allow points to be multiplied
Point Point::operator*(Point const& obj)
{
	return Point(x * obj.x, y * obj.y);
}

// Override "/" operator function to allow points to be divided
Point Point::operator/(Point const& obj)
{
	return Point(x / obj.x, y / obj.y);
}

// Function getter for x
int Point::getX()
{
	return x;
}

// Function getter for y value
int Point::getY()
{
	return y;
}