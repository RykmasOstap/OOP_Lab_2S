#include <stdio.h>


int const N=5;

int func(int* arr, int len)
{
	register int max_i = 0, min_i = 0, value=0, flag=1;
	int max = arr[0], min = arr[1];
	for (int i = 0; i < len; i++) //шукає макс. і мін.	 знач.
	{
		if (arr[i] > max)
		{
			max = arr[i];
			max_i = i;
		}
		if (arr[i] < min)
		{
			min = arr[i];
			min_i = i;
		}
	}

	if (max_i < min_i)
	{
		min_i = value;
		min_i = max_i;
		max_i = value;
	}

	if (arr[min_i] < 0)
	{
		flag = 0;
	}
	else flag = 1;
	for (int i = (min_i + 1); i < max_i; i++)
	{
		if (flag==1 & arr[i] < 0)
		{
			flag = 0;
			continue;
		}
		if (flag == 0 & arr[i] >= 0)
		{
			flag = 1;
			continue;
		}
		if ((flag==1 & arr[i]>=0)||(flag==0 & arr[i]<0))
		{
			printf("Integer arr error!");
			goto finish;
		}
	}
	printf("Integer arr no error.");
	finish:
	return 0;
}

int func(double* arr, int len)
{
	register int max_i = 0, min_i = 0, value=0, flag = 1;
	double max = arr[0], min = arr[1];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			max_i = i;
		}
		if (arr[i] < min)
		{
			min = arr[i];
			min_i = i;
		}
	}
	if (max_i < min_i)
	{
		min_i = value;
		min_i = max_i;
		max_i = value;
	}

	if (arr[min_i] < 0)
	{
		flag = 0;
	}
	else flag = 1;
	for (int i = min_i + 1; i < max_i; i++)
	{
		if (flag == 1 & arr[i] < 0)
		{
			flag = 0;
			continue;
		}
		if (flag == 0 & arr[i] >= 0)
		{
			flag = 1;
			continue;
		}
		if ((flag == 1 & arr[i] >= 0) || (flag == 0 & arr[i] < 0))
		{
			printf("Double arr error!");
			goto finish;
		}
	}
	printf("Double arr no error.");
	finish:
	return 0;
}

int main()
{
	int a1[N];
	double a2[N];
	for (int i = 0; i < N; i++)
	{
		printf("Enter your integer num:");
		scanf_s("%d", &a1[i]);

	}
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("Enter your double num:");
		scanf_s("%lf", &a2[i]);
	}

	func(a1, N);
	printf("\n");
	func(a2, N);

	return 0;
}