#include <stack>
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

int const N = 10000;

int Search(int *arr, int number)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == number)
		{
			return i;
		}
	}
	return -1;
}

void QuickSort(int *arr, int first, int last)
{
	int i = first, j = last;
	int tmp;
	int middle = arr[(first + last) / 2];
	while (i <= j) {
		while (arr[i] < middle)
			i++;
		while (arr[j] > middle)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	if (first < j)
		QuickSort(arr, first, j);
	if (i < last)
		QuickSort(arr, i, last);
}

void QuickSort(int *arr, int n)
{
	int mid, left, right, l, r;
	mid = left = right = l = r = 0;
	stack <int> st;

	st.push(n - 1);
	st.push(0);
	do {
		left = st.top();
		st.pop();
		right = st.top();
		st.pop();
		{
			mid = arr[(left + right) / 2];
			l = left;
			r = right;
			while (l < r)
			{
				while (arr[l] < mid) l++;
				while (mid < arr[r]) r--;
				if (l <= r)
				{
					swap(arr[l], arr[r]);
					l++;
					r--;
				}
			}
		}
		if (left < r)
		{
			st.push(r);
			st.push(left);
		}
		if (l < right)
		{
			st.push(right);
			st.push(l);
		}
	} while (st.size() != NULL);
}

int BSearch(int *arr, int left, int right, int number)
{
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (number < arr[mid])       
			right = mid - 1;      
		else if (number > arr[mid]) 
			left = mid + 1;    
		else                      
			return mid;                   		
	}
	return -1;
}

int BSearch(int number, int *arr, int left, int right)
{
	if (right < left) return -1;
	int mid = (left + right) / 2;
	if (arr[mid] > number) return BSearch(number, arr, left, mid - 1);
	if (arr[mid] < number) return BSearch(number, arr, mid + 1, right);
	if (number == arr[mid]) return mid;
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int arr[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 2000 - 1000;
	}
	cout << Search(arr, -753) << endl;
	int arr2[100];
	for (int i = 0; i < 100; i++)
	{
		arr2[i] = rand() % 20 - 10;
	}
	auto start1 = chrono::high_resolution_clock::now();
	Search(arr2, 4);
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double> duration1 = end1 - start1;
	for (int i = 0; i < 50; i++)
	{
		cout << "\t" << arr2[i];
	}
	QuickSort(arr2, 100);
	cout << endl;
	for (int i = 0; i < 50; i++)
	{
		cout << "\t" << arr2[i];
	}
	auto start2 = chrono::high_resolution_clock::now();
	int result = BSearch(arr2, 0, 100, -9);
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double> duration2 = end2 - start2;
	if (result != -1)
		cout << endl << "Найденное значение = " << arr2[result] << "\tИндекс = " << result << endl;
	else cout << "Значение в массиве отсутствует";
	cout << endl << BSearch(-9, arr2, 0, 100) << endl;
	cout << "Время в секундах поиска в неотсортированном массиве = " << duration1.count()*1000 << " мс" << endl;
	cout << "Время в секундах поиска в отсортированном массиве = "  << duration2.count()*1000 << " мс" << endl;
 }

