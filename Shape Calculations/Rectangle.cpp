#include "Rectangle.h"

#include <sstream>
#include <iomanip>
#include <iostream>

// Constructor
Rectangle::Rectangle(int xPos, int yPos, int height, int width) : height(height), width(width)
{
	// Assign left top point property
	leftTop = Point(xPos, yPos);
	// Call function to calculate area, perimeter and points
	calculateArea();
	calculatePerimeter();
	calculatePoints();
	// Set circular to false
	isCircular = false;
}

// Destructor
Rectangle::~Rectangle()
{
}

// Function to calculate the area of the rectangle
void Rectangle::calculateArea()
{
	// Multiply edges by each other to get resultant area
	area = (double)height * (double)width;
}

// Function to calculate the perimeter of the rectangle
void Rectangle::calculatePerimeter()
{
	// Multiply height and width by 2 to get resultant perimeter
	perimeter = ((double)height * 2) + ((double)width * 2);
}

// Function to calculate all points of the rectangle
void Rectangle::calculatePoints()
{
	// Clear any previous points
	points.clear();
	// Add points
	points.push_back(leftTop);
	points.push_back(leftTop + Point(width, 0));
	points.push_back(leftTop + Point(width, height));
	points.push_back(leftTop + Point(0, height));
}

// Function to move the rectangle to a new x and y position
void Rectangle::move(int xNew, int yNew)
{
	// Update the top left point of the shape
	leftTop = Point(xNew, yNew);
	// Calculate new points
	calculatePoints();
}

// Function to scale the rectangle by an x and y factor
void Rectangle::scale(float xFactor, float yFactor = 1)
{
	// Scale by the xChange and yChange value as appropriate
	width = (int)(width * xFactor);
	height = (int)(height * yFactor);
	// Update new area, perimeter and points
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}

// Function override for the multiply operator
void Rectangle::operator*(float scaleFactor)
{
	// Call the scale function with the xFactor and yFactor the same
	scale(scaleFactor, scaleFactor);
}

// Function to convert the rectangle to a string
string Rectangle::toString()
{
	// Create a ostreamstream to store output data and set to fixed, 1 decimal precision
	ostringstream stringConvert;
	stringConvert << fixed << setprecision(1);
	// Insert shape data
	stringConvert << "Rectangle[h=" << to_string(height) << ",w=" << to_string(width) << "]\nPoints[";
	// Append points to the stream
	for (Point point : points) {
		// Append the point
		stringConvert << "(" << to_string(point.getX()) + "," << to_string(point.getY()) << ")";
	}
	// Append final values to stream
	stringConvert << "]" << "\nArea=" << area << " Perimeter=" << perimeter;
	// Return the stream string
	return stringConvert.str();
}

// Override for the insertion operator
ostream& operator << (ostream& os, const Rectangle& r)
{
	// Create a ostreamstream to store output data and set to fixed, 1 decimal precision
	ostringstream stringConvert;
	stringConvert << fixed << setprecision(1);
	// Insert shape data
	stringConvert << "Rectangle[h=" << to_string(r.height) << ",w=" << to_string(r.width) << "]\nPoints[";
	// Append points to the stream
	for (Point point : r.points) {
		// Append the point
		stringConvert << "(" << to_string(point.getX()) + "," << to_string(point.getY()) << ")";
	}
	// Append final values to stream
	stringConvert << "]" << "\nArea=" << r.area << " Perimeter=" << r.perimeter;
	// Append stream string to the ostream and return
	os << stringConvert.str();
	return os;
}
