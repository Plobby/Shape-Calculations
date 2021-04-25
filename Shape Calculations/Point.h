#pragma once
#include <string>

using namespace std;

class Point
{
private:
	// Co-ordinate variables
	int x;
	int y;
public:
	// Default constructor
	Point();

	// Constructor
	Point(int x, int y);

	// Override add operator
	Point operator + (Point const& obj);

	// Override subtract operator
	Point operator - (Point const& obj);

	// Override multiply operator
	Point operator * (Point const& obj);

	// Override division operator
	Point operator / (Point const& obj);

	// Getter for x value
	int getX();
		
	// Getter for y value
	int getY();
};

