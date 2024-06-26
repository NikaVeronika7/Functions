﻿
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(const int arr[], const int n);
void Sort(int arr[], const int n);
int Sum(int arr[], const int n);//возвращает сумму элементов массива//
double Avg(int arr[], const int n);//возвращает среднее-арифметическое элементов массива//
int minValueIn (int arr[], int n);//возвращает минимальное значение в массиве
int maxValueIn(int arr[], int n);//возвращает максимальное значение в массиве
void shiftleft(int arr[], int n, int number_of_shifts);//сдвигает массив на заданное число элементов влево
void shiftRight(int arr[], int n, int number_of_shifts);//сдвигает массив на заданное число элементов вправо



void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива:" << Sum(arr, n) << endl;
	cout << "Средне-арифметическое:" << Avg(arr, n) << endl;
	cout << "Минимальное значение:" << minValueIn(arr, n) << endl;
	cout << "Максимальное значение:" << maxValueIn(arr, n) << endl;
	int number_of_shifts;
	cout << "ввелите количесво сдвигов:"; cin >> number_of_shifts;
	shiftleft(arr, n, number_of_shifts);
	Print(arr, n);
	cout << "ввелите количесво сдвигов:"; cin >> number_of_shifts;
	shiftRight(arr, n, number_of_shifts);
	Print(arr, n);


}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	 }
}
int Sum (int arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
	}
double Avg(int arr[], const int n)
{
	return Sum(arr, n) / (double)n;// неявное преобразование  - или перед суммой или после. в нач. нельзя инт
}

int minValueIn(int arr[], const int n)
{
	int min =  arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
int maxValueIn(int arr[], int n)
{
int  max = arr[0];
for (int i = 0; i < n; i++)
{
		if (arr[i] > max)max = arr[i];
}
return max;
}
void shiftleft(int arr[], int n, int number_of_shifts)
{
	
	for (int i = 0; i < number_of_shifts; i++)
	{
		int buffer = arr[0];
		for (int i = 1; i < n; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[n - 1] = buffer;
	}
	
}
void shiftRight(int arr[], int n, int number_of_shifts)
{
	shiftleft(arr, n, n - number_of_shifts);
		
	/*for (int i = 0; i < number_of_shifts; i++)
	{
		int buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}*/
	
}

