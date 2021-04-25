#define _USE_MATH_DEFINES

#include <math.h>
#include <sstream>
#include <iomanip>
#include "Circle.h"
#include <iostream>

// Constructor
Circle::Circle(int x, int y, int radius): radius(radius)
{
	// Assign left top point property
	leftTop = Point(x, y);
	// Set circular to true
	isCircular = true;
	// Call function to calculate area, perimeter and points
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}

// Destructor
Circle::~Circle()
{
	// Clear any custom values
	radius = NULL;
}

// Function to calculate the area of the circle
void Circle::calculateArea()
{
	// Multiply pi by radius squared to get the area
	area = M_PI * ((double)radius * (double)radius);
}

// Function to calculate the perimeter of the circle
void Circle::calculatePerimeter()
{
	// Multiply 2 by pi and radius to get the circumference
	perimeter = 2 * M_PI * radius;
}

// Function to calculate all points of the circle
void Circle::calculatePoints()
{
	// Clear any previous points
	points.clear();
	// Add points to the vector - this will be the points of the bounding box for the circle
	points.push_back(leftTop);
	points.push_back(leftTop + Point((radius * 2), (radius * 2)));
}

// Function to move the circle
void Circle::move(int xNew, int yNew)
{
	// Update the top left point of the shape
	leftTop = Point(xNew, yNew);
	// Calculate new points
	calculatePoints();
}

// Function to scale the circle
void Circle::scale(float xFactor, float yFactor = 1)
{
	// Scale by the xChange value, as only 1 dimension is valid for a circle radius
	radius = (int)(radius * xFactor);
	// Update new area, perimeter and points
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}

// Function override for the multiply operator
void Circle::operator*(float scaleFactor)
{
	// Call the scale function with the xFactor and yFactor the same
	scale(scaleFactor, scaleFactor);
}

// Function to convert the circle to a string
string Circle::toString()
{
	// Create a ostreamstream to store output data and set to fixed, 1 decimal precision
	ostringstream stringConvert;
	stringConvert << fixed << setprecision(1);
	// Insert shape data
	stringConvert << "Circle[r=" << to_string(radius) << "]\nPoints[";
	// Append points to the stream
	for (Point point : points) {
		// Append the point
		stringConvert << "(" << to_string(point.getX()) + "," << to_string(point.getY()) << ")";
	}
	// Append final values to stream
	stringConvert << "]" << "\nArea=" << area << " Perimeter=" << perimeter;
	// Append stream string to the ostream and return
	return stringConvert.str();
}

// Override for the insertion operator
ostream& operator << (ostream& os, const Circle& c)
{
	// Create a ostreamstream to store output data and set to fixed, 1 decimal precision
	ostringstream stringConvert;
	stringConvert << fixed << setprecision(1);
	// Insert shape data
	stringConvert << "Circle[r=" << to_string(c.radius) << "]\nPoints[";
	// Append points to the stream
	for (Point point : c.points) {
		// Append the point
		stringConvert << "(" << to_string(point.getX()) + "," << to_string(point.getY()) << ")";
	}
	// Append final values to stream
	stringConvert << "]" << "\nArea=" << c.area << " Perimeter=" << c.perimeter;
	// Append stream string to the ostream and return
	os << stringConvert.str();
	return os;
}