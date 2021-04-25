#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

#include <iostream>
#include <string>

using namespace std;

// Main entry point for the program
int main()
{
	// Variables
	string userCommand;			// String to hold the user command
	vector <Shape*> shapes;		// Shape pointer vector to hold the shapes
	vector <string> parameters;	// String vector to hold the parameters

	// Print out user menu
	cout << "--=== Shape Generator and Manipulator - Menu ===--" << endl << endl;
	cout << "Commands:" << endl;
	cout << "- addR <xPos> <yPos> <height> <width>" << endl;
	cout << "- addS <xPos> <yPos> <edgeLength>" << endl;
	cout << "- addC <xPos> <yPos> <radius>" << endl;
	cout << "- move <index> <xPosNew> <yPosNew>" << endl;
	cout << "- scale <index> <xFactor> [yFactor]" << endl;
	cout << "- display" << endl;
	cout << "- exit" << endl << endl;

	// Iterate while the user entered command is not exit
	while (userCommand.compare("exit") != 0)
	{
		// Prompt the user to enter a command
		cout << "Please enter a command: ";

		// Get the next line from cin
		getline(cin, userCommand);

		// Create a cstring and copy the user command from a string to a c string
		char* cstr = new char[userCommand.length() + 1];
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		// Use strtok_s to split the line input into different parameters - break on a space
		char* token1 = nullptr;
		char* item = strtok_s(cstr, " ", &token1);
		// Iterate while token returns a new string value
		while (item) {
			// Add the found item to the vector
			parameters.push_back(item);
			// Update p with next item
			item = strtok_s(nullptr, " ", &token1);
		}

		// Get the command as the 0th parameter
		string command = parameters[0];

		// Add rectangle command
		if (command.compare("addR") == 0) {
			try {
				// Check the command has the required number of parameters
				if (parameters.size() < 5) {
					// Output error message
					throw "Not enough parameters for add rectangle command!\nCorrect usage: addR <xPos> <yPos> <height> <width>";
				}
				// Try to convert parameters to integers
				int x = stoi(parameters[1]);
				int y = stoi(parameters[2]);
				int h = stoi(parameters[3]);
				int w = stoi(parameters[4]);
				// Validate that height and width are greater than 0
				if (h <= 0) {
					// Output error stating the height must be greater than 0
					throw "Height must be greater than 0!";
				}
				if (w <= 0) {
					// Output error stating the width must be greater than 0
					throw "Width must be greater than 0!";
				}
				// Create a new rectangle
				Rectangle* r = new Rectangle(x, y, h, w);
				// Push the new shape
				shapes.push_back(r);
				// Output the new shape
				cout << *r;
			}
			catch (const char* e) {
				// Custom error occurred
				cout << "Error: " << e;
			}
			catch (invalid_argument const& e) {
				// Parameter was invalid
				cout << "Error: Parameter input was invalid!";
			}
			catch (out_of_range const& e) {
				// Parameter was out of integer range
				cout << "Error: Parameter input was out of range!";
			}
		}
		else if (command.compare("addS") == 0) {
			try {
				// Check the command has the required number of parameters
				if (parameters.size() < 4) {
					// Output error message
					throw "Not enough parameters for add square command!\nCorrect usage: addS <xPos> <yPos> <edgeLength>";
				}
				// Try to convert parameters to integers
				int x = stoi(parameters[1]);
				int y = stoi(parameters[2]);
				int e = stoi(parameters[3]);
				// Validate that edge length is greater than 0
				if (e <= 0) {
					// Output error stating the edge length must be greater than 0
					throw "Edge length must be greater than 0!";
				}
				// Create a new square
				Square* s = new Square(x, y, e);
				// Push the new shape
				shapes.push_back(s);
				// Output the new shape
				cout << *s;
			}
			catch (const char* e) {
				// Custom error occurred
				cout << "Error: " << e;
			}
			catch (invalid_argument const& e) {
				// Parameter was invalid
				cout << "Error: Parameter input was invalid!";
			}
			catch (out_of_range const& e) {
				// Parameter was out of integer range
				cout << "Error: Parameter input was out of range!";
			}
		} else if (command.compare("addC") == 0) {
			try {
				// Check the command has the required number of parameters
				if (parameters.size() < 4) {
					// Output error message
					throw "Not enough parameters for add circle command!\nCorrect usage: addC <xPos> <yPos> <radius>";
				}
				// Try to convert parameters to integers
				int x = stoi(parameters[1]);
				int y = stoi(parameters[2]);
				int r = stoi(parameters[3]);
				// Validate that radius is greater than 0
				if (r <= 0) {
					// Output error stating the radius must be greater than 0
					throw "Radius must be greater than 0!";
				}
				// Create a new circle
				Circle* c = new Circle(x, y, r);
				// Push the new shape
				shapes.push_back(c);
				// Output the new shape
				cout << *c;
			}
			catch (const char* e) {
				// Custom error occurred
				cout << "Error: " << e;
			}
			catch (invalid_argument const& e) {
				// Parameter was invalid
				cout << "Error: Parameter input was invalid!";
			}
			catch (out_of_range const& e) {
				// Parameter was out of integer range
				cout << "Error: Parameter input was out of range!";
			}
		}
		else if (command.compare("scale") == 0) {
			try {
				// Check the command has the required number of parameters
				if (parameters.size() < 4) {
					// Output error message
					throw "Not enough parameters for scale command!\nCorrect usage: scale <shapeNo> <xFactor> <yFactor>";
				}
				// Try to convert parameters to integers
				int shapeNo = stoi(parameters[1]);
				double xFactor = stod(parameters[2]);
				double yFactor = stod(parameters[3]);
				// Check a shape is present
				if (shapes.empty()) {
					throw "You haven't created any shapes!";
				}
				// Check the index is within range
				if (shapeNo < 1 || shapeNo > shapes.size()) {
					throw "Selected index is not within range!";
				}
				// Get the shape from the array
				Shape* shape = shapes[shapeNo - 1];
				// Validate the factor is isometric in the case of a square or circle
				if ((dynamic_cast<Circle*>(shape) || dynamic_cast<Square*>(shape))) {
					if (xFactor != yFactor) {
						// Output error that the scaling factor must be isometric
						throw "Scaling factor must be isometric when scaling a square or circle!";
					}
					// Downcast to a movable and scale the shape
					Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
					// Check the m was successfully cast and is a valid movable object
					if (m != nullptr) {
						*m * xFactor;
					}
					// Print the scaled shape
					cout << shapes[shapeNo - 1]->toString();
				}
				else {
					// Downcast to a movable and scale the shape
					Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
					// Check the m was successfully cast and is a valid movable object
					if (m != nullptr) {
						m->scale(xFactor, yFactor);
					}
					// Print the scaled shape
					cout << shapes[shapeNo - 1]->toString();
				}
			}
			catch (const char* e) {
				// Custom error occurred
				cout << "Error: " << e;
			}
			catch (invalid_argument const& e) {
				// Parameter was invalid
				cout << "Error: Parameter input was invalid!";
			}
			catch (out_of_range const& e) {
				// Parameter was out of integer range
				cout << "Error: Parameter input was out of range!";
			}
		}
		else if (command.compare("move") == 0) {
			try {
				// Check the command has the required number of parameters
				if (parameters.size() < 4) {
					// Output error message
					throw "Not enough parameters for move command!\nCorrect usage: move <shapeNo> <newX> <newY>";
				}
				// Try to convert parameters to integers
				int shapeNo = stoi(parameters[1]);
				int xNew = stoi(parameters[2]);
				int yNew = stoi(parameters[3]);
				// Check a shape is present
				if (shapes.empty()) {
					throw "You haven't created any shapes!";
				}
				// Check the index is within range
				if (shapeNo < 1 || shapeNo > shapes.size()) {
					throw "Selected index is not within range!";
				}
				// Get the shape from the array
				Shape* shape = shapes[shapeNo - 1];
				// Downcast to a movable and move the shape
				Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				// Check the m was successfully cast and is a valid movable object
				if (m != nullptr) {
					m->move(xNew, yNew);
				}
				// Print the moved shape
				cout << shapes[shapeNo - 1]->toString();
			}
			catch (const char* e) {
				// Custom error occurred
				cout << "Error: " << e;
			}
			catch (invalid_argument const& e) {
				// Parameter was invalid
				cout << "Error: Parameter input was invalid!";
			}
			catch (out_of_range const& e) {
				// Parameter was out of integer range
				cout << "Error: Parameter input was out of range!";
			}
		}
		else if (command.compare("display") == 0) {
			try {
				// Check shapes are created
				if (shapes.empty()) {
					throw "No shapes have been created!";
				}
				// Create variable to store counter
				unsigned int counter = 1;
				// Define an iterator for the shapes vector
				vector<Shape*>::iterator shapeIter;
				// Use an STL iterator to go through shapes list
				for (shapeIter = shapes.begin(); shapeIter < shapes.end(); shapeIter++) {
					// Output the formatted shape as a string
					cout << "[" << counter++ << "]" << endl << (*shapeIter)->toString() << endl;
				}
				// Output total length count
				cout << endl << "Total shapes: " << --counter;
			}
			catch (const char* e) {
				// Custom error occurred
				cout << "Error: " << e;
			}
		}
		else if (command.compare("exit") == 0) {
			cout << "Program will now exit!";
		}
		else {
			cout << "Error: Unknown command entered!";
		}

		// Clear previous parameters
		parameters.clear();
		// Output line break for formatting
		cout << endl << endl;
	}

	// Iterate and delete all shapes left to ensure no memory leak
	for (Shape* shape : shapes) {
		delete shape;
	} 

	// Processing has finished - prompt and wait for the user to press a key before finishing
	cout << "Press any key to continue...";
	getchar();

	// Return 0 to inform that no error has occurred
	return 0;
}