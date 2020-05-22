#include "MatrixXnX.h"



	MatrixXnX::MatrixXnX(const int iDim)
	{
		size = iDim;
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new int[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	MatrixXnX::~MatrixXnX()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	void MatrixXnX::Print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cout << matrix[i][j] << "\t";
				if (j == (size - 1)) std::cout << std::endl;
			}
		}
	}

	int MatrixXnX::element(const int i, const int j)
	{
		return matrix[i][j];
	}

	void MatrixXnX::setElement(const int i, const int j, const int value)
	{
		matrix[i][j] = value;
	}

	void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				static const double ft = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
				matrix[i][j] = static_cast<int>(rand() * ft * (maxVal - minVal + 1) + minVal);
			}
		}
	}

	int MatrixXnX::sumPrincipalDiag()
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i == j)
				{
					sum += matrix[i][j];
				}
			}
		}
		return sum;
	}

	int MatrixXnX::sumSecondaryDiag()
	{
		int max = size - 1;
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
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

	int MatrixXnX::productPrincipalDiag()
	{
		int product = 1;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i == j)
				{
					product *= matrix[i][j];
				}
			}
		}
		return product;
	}

	int MatrixXnX::productSecondaryDiag()
	{
		int max = size - 1;
		int product = 1;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
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

	int MatrixXnX::sumRow(const int iRow)
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += matrix[iRow][i];
		}
		return sum;
	}

	int MatrixXnX::minColumn(const int iCol)
	{
		int min = matrix[0][iCol];
		for (int i = 0; i < size; i++)
		{
			if (matrix[i][iCol] < min)
			{
				min = matrix[i][iCol];
			}
		}
		return min;
	}

	int MatrixXnX::maxColumn(const int iCol)
	{
		int max = matrix[0][iCol];
		for (int i = 0; i < size; i++)
		{
			if (matrix[i][iCol] > max)
			{
				max = matrix[i][iCol];
			}
		}
		return max;
	}
