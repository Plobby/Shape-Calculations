#pragma once
class Movable
{
public:
	// Function template for the "move" method
	virtual void move(int xChange, int yChange) = 0;

	// Function template for the "scale" method
	virtual void scale(float xChange, float yChange) = 0;

	// Function override for the multiply operator
	virtual void operator * (float scaleFactor) = 0;
};

