#include <stdio.h>
#include <iostream>

using namespace std;

double input_positive(double* x)
{
	double tmp;
	while (1)
	{
		tmp = scanf_s("%lf", x);
		if (tmp < 1 || *x <= 0)
		{
			while (getchar() != '\n');
			cout << "Enter a positive number!\n";
			continue;
		}
		else
		{
			return *x;
		}
	}
}

void check_int(int* x)
{
	int check;
	while (1)
	{
		check = scanf_s("%d", x);
		if (check < 1)
		{
			while (getchar() != '\n');
			printf("Wrong input!\n");
			continue;
		}
		return;
	}
}

int input_positive(int* x)
{
	int tmp;
	while (1)
	{
		tmp = scanf_s("%lf", x);
		if (tmp < 1 || *x <= 0)
		{
			while (getchar() != '\n');
			cout << "Enter a positive number!\n";
			continue;
		}
		else
		{
			return *x;
		}
	}
}
