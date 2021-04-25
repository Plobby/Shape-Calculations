#pragma once
#include <string>
#include "Shape.h"
#include "Movable.h"

using namespace std;

class Rectangle : public Shape, public Movable
{
private:
	// Variables
	int height;
	int width;
public:
	// Constructor
	Rectangle(int xPos, int yPos, int height, int width);

	// Destructor
	~Rectangle();

	// Function template for the "calculateArea" method
	void calculateArea();

	// Function template for the "calculatePerimeter" method
	void calculatePerimeter();

	// Function template for the "calculatePoints" method
	void calculatePoints();

	// Function template for the "move" method
	void move(int xNew, int yNew);

	// Function template for the "scale" method
	void scale(float xFactor, float yFactor);

	// Function override for the multiply operator
	void operator * (float scaleFactor);

	// Function template for the "toString" method
	string toString();

	// Function template to override the insertion operator
	friend ostream& operator << (ostream& os, const Rectangle& r);
};