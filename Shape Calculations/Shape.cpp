#include <sstream>
#include <iomanip>

#include "Shape.h"

// Constructor
Shape::Shape(): area(0), isCircular(false), perimeter(0)
{
}

Shape::~Shape()
{
	// Clear points vector
	points.clear();
}

// Function to convert the shape to a string
string Shape::toString()
{
	// Create a ostreamstream to store output data and set to fixed, 1 decimal precision
	ostringstream stringConvert;
	stringConvert << fixed << setprecision(1);
	// Insert shape data
	stringConvert << "Shape\nPoints[";
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