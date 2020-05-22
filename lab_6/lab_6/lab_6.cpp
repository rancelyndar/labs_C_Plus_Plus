
#include <iostream>
#include "Matrix3x3.h"
#include "MatrixXnX.h"
#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix3x3 a;
	a.fillRandomElements(-10, 10); 
	a.Print();
	cout << "Сумма элементов 1 строки = " << a.sumRow(0) << endl;
	cout << "Сумма элементов 2 строки = " << a.sumRow(1) << endl;
	cout << "Сумма элементов 3 строки = " << a.sumRow(2) << endl;
	cout << "Минимальный элемент 1 столбца = " << a.minColumn(0) << endl;
	cout << "Минимальный элемент 2 столбца = " << a.minColumn(1) << endl;
	cout << "Минимальный элемент 3 столбца = " << a.minColumn(2) << endl;
	cout << "Максимальный элемент 1 столбца = " << a.maxColumn(0) << endl;
	cout << "Максимальный элемент 2 столбца = " << a.maxColumn(1) << endl;
	cout << "Максимальный элемент 3 столбца = " << a.maxColumn(2) << endl;
	cout << "Сумма элементов главной диагонали = " << a.sumPrincipalDiag() << endl;
	cout << "Сумма элементов побочной диагонали = " << a.sumSecondaryDiag() << endl;
	cout << "Произведение элементов главной диагонали = " << a.productPrincipalDiag() << endl;
	cout << "Произведение элементов побочной диагонали = " << a.productSecondaryDiag() << endl;
	MatrixXnX b(11);
	b.fillRandomElements(-10, 10);
	b.Print();
	cout << "Сумма элементов главной диагонали = " << b.sumPrincipalDiag() << endl;
	cout << "Сумма элементов побочной диагонали = " << b.sumSecondaryDiag() << endl;
	cout << "Произведение элементов главной диагонали = " << b.productPrincipalDiag() << endl;
	cout << "Произведение элементов побочной диагонали = " << b.productSecondaryDiag() << endl;
	
	List<char> lst; // Создаем список и заполняем его
	lst.push_back('a');
	lst.push_back('b');
	lst.push_back('c');
	lst.push_back('a');
	lst.push_back('c');
	lst.push_back('c');
	lst.push_back('e');
	lst.push_back('b');
	lst.push_back('f');
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl;

	lst.DeleteDub(); // Удаляем дубликаты
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl;

	cout << lst.elementFromTheEnd(3); // 3 элемент с конца
	cout << lst.elementFromTheEnd(2); // 2 элемент с конца
	return 0;
}

