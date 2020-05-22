#include "Matrix3x3.h"

Matrix3x3::Matrix3x3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Matrix3x3::Print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix[i][j] << "\t";
			if (j == 2) std::cout << std::endl;
		}
	}
}

int Matrix3x3::element(const int i, const int j)
{
	return matrix[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value)
{
	matrix[i][j] = value;
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			static const double ft = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
			matrix[i][j] = static_cast<int>(rand() * ft * (maxVal - minVal + 1) + minVal);
		}
	}
}

int Matrix3x3::sumPrincipalDiag()
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}

int Matrix3x3::sumSecondaryDiag()
{
	int max = 2;
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == max)
			{
				sum += matrix[i][j];
				max--;
				break;
			}
		}
	}
	return sum;
}

int Matrix3x3::productPrincipalDiag()
{
	int product = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				product *= matrix[i][j];
			}
		}
	}
	return product;
}

int Matrix3x3::productSecondaryDiag()
{
	int max = 2;
	int product = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == max)
			{
				product *= matrix[i][j];
				max--;
				break;
			}
		}
	}
	return product;
}

int Matrix3x3::sumRow(const int iRow)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += matrix[iRow][i];
	}
	return sum;
}

int Matrix3x3::minColumn(const int iCol)
{
	int min = matrix[0][iCol];
	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][iCol] < min)
		{
			min = matrix[i][iCol];
		}
	}
	return min;
}

int Matrix3x3::maxColumn(const int iCol)
{
	int max = matrix[0][iCol];
	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][iCol] > max)
		{
			max = matrix[i][iCol];
		}
	}
	return max;
}