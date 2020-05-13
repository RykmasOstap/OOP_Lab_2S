#include <iostream>
#include <iomanip>
using namespace std;

void func(int** arr, int size)
{
	int ind_s = 0, ind_f = size;

	for (int i = size-1; i >= 0; i--)
	{
		for (int j = ind_s; j < ind_f; j++)
		{
			arr[i][j] = 0;
		}
		ind_s++;
		ind_f--;
	}

	return;
}

int main()
{
	int size;
	cout << "Enter size of matrix:";
	cin >> size;
	cout << endl << endl;
	int** arr;
	arr = new int*[size];
	if (arr == NULL)
	{
		cout << "Error";
		return 1;
	}
	for (int i = 0; i < size; i++) arr[i] = new int[size];
	if (arr == NULL)
	{
		cout << "Error";
		return 1;
	}

	for (int i = 0; i < size; i++)  //Започнення всіх елементів матриці 1;
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = 1;
		}
	}

	func(arr, size);

	cout << "Your new matrix:" << endl << endl;
	for (int i = 0; i < size; i++) //Вивід матриці;
	{
		for (int j = 0; j < size; j++)
		{
			cout.setf(ios::left);
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl << endl;
	}

	for (int i = 0; i < size; i++) delete[] arr[i];
	delete[] arr;
	return 0;
}