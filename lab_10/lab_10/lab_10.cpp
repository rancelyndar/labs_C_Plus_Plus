
#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"
using namespace std;

int main() {
	Matrix2D m2a, m2b;
	Matrix3D m3a, m3b;
	cout << "Matrix2Da " << endl << m2a << endl;
	cout << "Matrix2Db " << endl << m2b << endl;
	cout << "Matrix3Da " << endl << m3a << endl;
	cout << "Matrix3Db " << endl << m3b << endl;
	m2a *= 7;
	m3a += m3b;
	cout << "Matrix3Da + Matrix3Db " << endl << m3a << endl;
	cout << "Matrix2Da * 7 " << endl << m2a << endl;
	m3b *= 3;
	m2b += m2a;
	cout << "Matrix2Db + Matrix2Da " << endl << m2b << endl;
	cout << "Matrix3Db * 3 " << endl << m3b << endl;
	return 0;
}