#pragma once
#include <iostream>
class Matrix3x3
{
private:
	int matrix[3][3];
public:
	Matrix3x3();
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

