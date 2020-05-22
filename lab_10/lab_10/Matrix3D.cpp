#include "Matrix3D.h"

int Matrix3D::element(unsigned int i, unsigned int j) const 
{
	return matrix[i][j];
}

int &Matrix3D::element(unsigned int i, unsigned int j) 
{
	return matrix[i][j];
}

Matrix3D::Matrix3D() :MatrixBase(size) 
{
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			matrix[i][j] = i * 3 + j + 1;
};