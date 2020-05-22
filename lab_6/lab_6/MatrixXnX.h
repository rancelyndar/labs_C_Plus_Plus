#pragma once
#include <iostream>
class MatrixXnX
{
private:
	int size = 0;
	int **matrix = new int*[size];
public:
	MatrixXnX(const int iDim);
	~MatrixXnX();
	void Print();
	int element(const int i, const int j);
	void setElement(const int i, const int j, const int value);
	void fillRandomElements(const int minVal, const int maxVal);
	int sumPrincipalDiag();
	int sumSecondaryDiag();
	int productPrincipalDiag();
	int productSecondaryDiag();
	int sumRow(const int iRow);
	int minColumn(const int iCol);
	int maxColumn(const int iCol);
};

