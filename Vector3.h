#pragma once
/////////////////////////////////////////////////////////////////////////////
//
// class Vector3 � a simple 3D vector class
//
/////////////////////////////////////////////////////////////////////////////
#include<math.h>
#define dataType float

class Vector3 {
public:
	// Public representation: Not many options here.
	dataType x, y, z;
	// Constructors

	// Default constructor
	Vector3() :x(0), y(0), z(0) {}
	// Copy constructor
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}
	// Construct given three values
	Vector3(dataType nx, dataType ny, dataType nz) : x(nx), y(ny), z(nz) {}

	// Standard object maintenance
	// Assignment. We adhere to C convention and
	// return reference to the lvalue
	Vector3& operator =(const Vector3& a) {
		x = a.x; y = a.y; z = a.z;
		return *this;
	}
	// Check for equality
	bool operator ==(const Vector3& a) const {
		return x == a.x && y == a.y && z == a.z;
	}
	bool operator !=(const Vector3& a) const {
		return x != a.x || y != a.y || z != a.z;
	}
	// Vector operations
	// Set the vector to zero
	void zero() { x = y = z = 0.0f; }
	// Unary minus returns the negative of the vector
	Vector3 operator -() const { return Vector3(-x, -y, -z); }
	// Binary + and - add and subtract vectors
	Vector3 operator +(const Vector3& a) const {
		return Vector3(x + a.x, y + a.y, z + a.z);
	}
	Vector3 operator -(const Vector3& a) const {
		return Vector3(x - a.x, y - a.y, z - a.z);
	}
	// Multiplication and division by scalar
	Vector3 operator *(dataType a) const {
		return Vector3(x * a, y * a, z * a);
	}
	Vector3 operator /(dataType a) const {
		dataType oneOverA = 1.0f / a; // NOTE: no check for divide by zero here
		return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
	}
	// Combined assignment operators to conform to
	// C notation convention
	Vector3& operator +=(const Vector3& a) {
		x += a.x; y += a.y; z += a.z;
		return *this;
	}
	Vector3& operator -= (const Vector3& a) {
		x -= a.x; y -= a.y; z -= a.z;
		return *this;
	}
	Vector3& operator *=(dataType a) {
		x *= a; y *= a; z *= a;
		return *this;
	}
	Vector3& operator /=(dataType a) {
		dataType oneOverA = 1.0f / a;
		x *= oneOverA; y *= oneOverA; z *= oneOverA;
		return *this;
	}
	// Normalize the vector
	void normalize() {
		dataType magSq = x * x + y * y + z * z;
		if (magSq > 0.0f) { // check for divide-by-zero
			dataType oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}
	// Vector dot product. We overload the standard
	// multiplication symbol to do this
	dataType operator *(const Vector3& a) const {
		return x * a.x + y * a.y + z * a.z;
	}
};

/////////////////////////////////////////////////////////////////////////////
//
// Nonmember functions
//
/////////////////////////////////////////////////////////////////////////////
// Compute the magnitude of a vector
inline float vectorMag(const Vector3& a) {
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
// Compute the cross product of two vectors
inline Vector3 crossProduct(const Vector3& a, const Vector3& b) {
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}
// Scalar on the left multiplication, for symmetry
inline Vector3 operator *(float k, const Vector3& v) {
	return Vector3(k * v.x, k * v.y, k * v.z);
}
// Compute the distance between two points
inline float distance(const Vector3& a, const Vector3& b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}
/////////////////////////////////////////////////////////////////////////////
//
// Global variables
//
/////////////////////////////////////////////////////////////////////////////
// We provide a global zero vector constant
extern const Vector3 kZeroVector;