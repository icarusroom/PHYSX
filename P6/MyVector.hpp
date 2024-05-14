#pragma once

#include <cmath>

namespace Sample {
	class MyVector {
		private:
			float x, y, z;

		public:
			MyVector(float x, float y, float z);

		public:
			float magnitude();
			MyVector direction();
			MyVector addition(MyVector CVector);
			MyVector subtraction(MyVector CVector);
			MyVector scalarMultiplication(float fScalar);
			MyVector componentMultiplication(MyVector CVector);
			float scalarProduct(MyVector CVector);
			MyVector vectorProduct(MyVector CVector);

		public:
			float getX();
			float getY();
			float getZ();
			void setX(float x);
			void setY(float y);
			void setZ(float z);
			MyVector getVector();
	};
}