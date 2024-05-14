#include "MyVector.hpp"

using namespace Sample;

/* Constructor */
MyVector::MyVector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

/* Magnitude */
float MyVector::magnitude() {
	return std::sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

/* Direction */
MyVector MyVector::direction() {
	float fMagnitude = magnitude();

	if (fMagnitude == 0) {
		return MyVector(0, 0, 0);
	}

	return MyVector(this->x / fMagnitude, this->y / fMagnitude, this->z / fMagnitude);
}

/* Addition */
MyVector MyVector::addition(MyVector CVector) {
	return MyVector(this->x + CVector.x, this->y + CVector.y, this->z + CVector.z);
}

/* Subtraction */
MyVector MyVector::subtraction(MyVector CVector) {
	return MyVector(this->x - CVector.x, this->y - CVector.y, this->z - CVector.z);
}

/* Scalar Multiplication */
MyVector MyVector::scalarMultiplication(float fScalar) {
	return MyVector(this->x * fScalar, this->y * fScalar, this->z * fScalar);
}

/* Component Product */
MyVector MyVector::componentMultiplication(MyVector CVector) {
	return MyVector(this->x * CVector.x, this->y * CVector.y, this->z * CVector.z);
}

/* Scalar Product */
float MyVector::scalarProduct(MyVector CVector) {
	return (this->x * CVector.x) + (this->y * CVector.y) + (this->z * CVector.z);
}

/* Vector Product */
MyVector MyVector::vectorProduct(MyVector CVector) {
	float fX = (this->y * CVector.z) - (this->z * CVector.y);
	float fY = (this->z * CVector.x) - (this->x * CVector.z);
	float fZ = (this->x * CVector.y) - (this->y * CVector.x);
	return MyVector(fX, fY, fZ);
}

/* Getters and Setters */
float MyVector::getX() {
	return this->x;
}

float MyVector::getY() {
	return this->y;
}

float MyVector::getZ() {
	return this->z;
}

void MyVector::setX(float x) {
	this->x = x;
}

void MyVector::setY(float y) {
	this->y = y;
}

void MyVector::setZ(float z) {
	this->z = z;
}

MyVector MyVector::getVector() {
	return MyVector(this->x, this->y, this->z);
}