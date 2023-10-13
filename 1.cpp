#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#define m 1500 // ��������� ��������� "����� ��������"
#define n 1500// ��������� ��������� "����� �����"

int main2(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // ��������� ���������� ��� ����������� ������� ����������

	int i = 0, j = 0, r;
	int elem_c;

	int **one = (int**)malloc(n * sizeof(int*)); // �������� ������ ��� ������������ ��������� ������ a[n][m]
	for(int i = 0; i < n; i++)
	{
		one[i] = (int*)malloc(m * sizeof(int));
	}

	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	while(i < n)
	{
		while(j < m)
		{
			one[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}

	int **two = (int**)malloc(n * sizeof(int*)); // �������� ������ ��� ������������ ��������� ������ b[n][m]
	for(int i = 0; i < n; i++)
	{
		two[i] = (int*)malloc(m * sizeof(int));
	}

	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0; j = 0;
	while(i < n)
	{
		while(j < m)
		{
			two[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}

	int **tree = (int**)malloc(n * sizeof(int*)); // �������� ������ ��� ������������ ��������� ������ c[n][m]
	for(int i = 0; i < n; i++)
	{
		tree[i] = (int*)malloc(m * sizeof(int));
	}

	start = clock(); // � ���������� start ���������� ����� �� ������ ������� ���������

	for(i=0;i < n;i++)
	{
		for(j=0;j < m;j++)
		{
			elem_c=0;
			for(r=0;r < n;r++)
			{
				elem_c=elem_c+one[i][r] * two[r][j];
				tree[i][j]=elem_c;
			}
		}
	}

	end = clock(); // � ���������� end ���������� ����� �� ������ ������� ���������
	double time = (end - start) / CLOCKS_PER_SEC; // ��������� ��������(�.�. �����, ����������� �� ��������� ������)

	printf("%lf s\n", time); // ������� ��������� ������ ��������� � ��������


	for(int i = 0; i < n; i++) // ������� ������ ������������� ���������� ������� a[n][m]
	{
		free(one[i]);
	}
	free(one);

	for(int i = 0; i < n; i++) // ������� ������ ������������� ���������� ������� b[n][m]
	{
		free(two[i]);
	}
	free(two);

	for(int i = 0; i < n; i++) // ������� ������ ������������� ���������� ������� c[n][m]
	{
		free(tree[i]);
	}
	free(tree);

	return(0);
}