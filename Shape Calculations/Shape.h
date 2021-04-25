#pragma once
#include <string>
#include <vector>
#include "Point.h"

using namespace std;

class Shape
{
protected:
	// Variables
	double area;
	bool isCircular;
	Point leftTop;
	double perimeter;
	vector<Point> points;
public:
	// Default constructor
	Shape();

	// Destructor
	virtual ~Shape();

	// Function template for the "calculateArea" method
	virtual void calculateArea() = 0;

	// Function template for the "calculatePerimeter" method
	virtual void calculatePerimeter() = 0;

	// Function template for the "calculatePoints" method
	virtual void calculatePoints() = 0;

	// Function template for the "toString" method
	virtual string toString();
};
