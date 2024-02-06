#ifndef VECTORCLASS_H
#define VECTORCLASS_H
#define EnableVectorClassLogMessages() VectorClass::StartLogging()
#define DisableVectorClassLogMessages() VectorClass::StopLogging()
#include <iostream>

// A class for manipulating 3D vectors
class VectorClass
{
private: 
	double x;
	double y;
	double z;
public: 
	static bool allowLogs;
	// Constructors
	VectorClass () : x (0), y (0), z (0)
	{
		if (allowLogs == true) {
			std::cout << "New vector with coordinates " << *this << " created.\n";
		}
	}

	VectorClass (double xValue, double yValue, double zValue) : x (xValue), y (yValue), z (zValue)
	{
		if (allowLogs == true) {
			std::cout << "New vector with coordinates " << *this << " created.\n";
		}
	}

	double getX () const
	{
		return x;
	}

	double getY () const
	{
		return y;
	}

	double getZ () const
	{
		return z;
	}

	void setX (double xValue)
	{
		x = xValue;
		if (allowLogs == true) {
			std::cout << "Set x to " << xValue << ".\n";
		}
	}

	void setY (double yValue)
	{
		y = yValue;
		if (allowLogs == true) {
			std::cout << "Set y to " << yValue << ".\n";
		}
	}

	void setZ (double zValue)
	{
		z = zValue;
		if (allowLogs == true) {
			std::cout << "Set z to " << zValue << ".\n";
		}
	}

	VectorClass operator+ (const VectorClass& otherVector)
	{
		return this->add (otherVector);
	}

	VectorClass add (const VectorClass& otherVector)
	{
		bool initAllow = allowLogs;
		allowLogs = false;

		VectorClass result (x + otherVector.getX (), y + otherVector.getY (), z + otherVector.getZ ());

		allowLogs = initAllow;

		return result;
	}

	VectorClass operator- (const VectorClass& otherVector)
	{
		return this->subtract (otherVector);
	}
	VectorClass subtract (const VectorClass& otherVector)
	{
		bool initAllow = allowLogs;
		allowLogs = false;

		VectorClass result (x - otherVector.getX (), y - otherVector.getY (), z - otherVector.getZ ());

		allowLogs = initAllow;

		return result;
	}

	VectorClass operator* (const double scalarValue)
	{
		return this->multiply (scalarValue);
	}
	VectorClass multiply (const double scalarValue)
	{
		bool initAllow = allowLogs;
		allowLogs = false;

		VectorClass result (x*scalarValue, y*scalarValue, z*scalarValue);

		allowLogs = initAllow;

		return result;
	}

	VectorClass operator/ (const double scalarValue)
	{
		return this->divide (scalarValue);
	}
	VectorClass divide (const double scalarValue)
	{
		if (scalarValue == 0) {
			std::cout << "Division by 0 not possible.\n";
			return *this;
		} else {
			bool initAllow = allowLogs;
			allowLogs = false;

			VectorClass result (x / scalarValue, y / scalarValue, z / scalarValue);

			allowLogs = initAllow;

			return result;
		}
	}

	// Vector printing function provided in VectorClass.cpp
	friend std::ostream& operator<< (std::ostream& stream, const VectorClass& vector);

	// Console logging

	static void StopLogging ()
	{
		allowLogs = false;
		std::cout << "Vector Logging disabled.\n";
	}

	static void StartLogging ()
	{
		allowLogs = true;
		std::cout << "Vector Logging enabled.\n";
	}

	double Modulus ()
	{
		double result = (std::sqrt (x * x + y * y + z * z));
		if (allowLogs == true) {
			std::cout << "The length of this vector is " << result << " units.\n";
		}
		return result;
	}

};


std::ostream& operator<< (std::ostream& stream, const VectorClass& vector)
{
	stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return stream;
}


bool VectorClass::allowLogs = true;

#endif
