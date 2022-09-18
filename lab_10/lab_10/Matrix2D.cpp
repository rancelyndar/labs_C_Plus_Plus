#include "Matrix2D.h"

int Matrix2D::element(unsigned int i, unsigned int j) const 
{
	return matrix[i][j];
}

int &Matrix2D::element(unsigned int i, unsigned int j) 
{
	return matrix[i][j];
}

Matrix2D::Matrix2D() : MatrixBase(size) 
{
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			matrix[i][j] = i * 3 + j + 1;
};
