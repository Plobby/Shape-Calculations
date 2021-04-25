#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "Square.h"
#include "Point.h"

// Constructor
Square::Square(int xPos, int yPos, int edge): edge(edge)
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
Square::~Square()
{
	// Clear any assigned values
	edge = NULL;
}

// Function to calculate the area of the square
void Square::calculateArea()
{
	// Multiply edges by each other to get resultant area
	area = (double)edge * (double)edge;
}

// Function to calculate the perimeter of the square
void Square::calculatePerimeter()
{
	// Multiply edges by 4 to get resultant perimeter
	perimeter = (double)edge * 4;
}

// Function to calculate all points of the square
void Square::calculatePoints()
{
	// Clear any previous points
	points.clear();
	// Add points
	points.push_back(leftTop);
	points.push_back(leftTop + Point(edge, 0));
	points.push_back(leftTop + Point(edge, edge));
	points.push_back(leftTop + Point(0, edge));
}

// Function to move the square
void Square::move(int xNew, int yNew)
{
	// Update the top left point of the shape
	leftTop = Point(xNew, yNew);
	// Calculate new points
	calculatePoints();
}

// Function to scale the square
void Square::scale(float xFactor, float yFactor = 1)
{
	// Scale by the xChange value, as only 1 dimension is valid for a square edge
	edge = (int)(edge * xFactor);
	// Update new area, perimeter and points
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}

// Function override for the multiply operator
void Square::operator*(float scaleFactor)
{
	// Call the scale function with the xFactor and yFactor the same
	scale(scaleFactor, scaleFactor);
}

// Function to convert the square to a string
string Square::toString()
{
	// Create a ostreamstream to store output data and set to fixed, 1 decimal precision
	ostringstream stringConvert;
	stringConvert << fixed << setprecision(1);
	// Insert shape data
	stringConvert << "Square[e=" << to_string(edge) << "]\nPoints[";
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
ostream& operator << (ostream& os, const Square& s)
{
	// Create a ostreamstream to store output data and set to fixed, 1 decimal precision
	ostringstream stringConvert;
	stringConvert << fixed << setprecision(1);
	// Insert shape data
	stringConvert << "Square[e=" << to_string(s.edge) << "]\nPoints[";
	// Append points to the stream
	for (Point point : s.points) {
		// Append the point
		stringConvert << "(" << to_string(point.getX()) + "," << to_string(point.getY()) << ")";
	}
	// Append final values to stream
	stringConvert << "]" << "\nArea=" << s.area << " Perimeter=" << s.perimeter;
	// Append stream string to the ostream and return
	os << stringConvert.str();
	return os;
}