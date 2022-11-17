#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<Windows.h>
#include<malloc.h>
#include <math.h>

int main() 
{
	
	system("chcp 1251>nul");
	HANDLE hFile = CreateFile(L"data.txt",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	HANDLE file = CreateFile(L"rezult.txt",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
}

void kv_yr(float a, float b, float c, char* result)
{
	FILE* fileResult = fopen(result, "w");
	fprintf(fileResult, "Уравнение: %3.2f*a + %3.2f * b + %3.2f = 0\n", a, b, c);
	float D = b * b - 4 * a * c;
	fprintf(fileResult, "Дискриминант равен %g\n", D);
	if (D > 0)
	{
		float x1, x2;
		x1 = (-b - sqrt(D)) / (2 * a);
		x2 = (-b + sqrt(D)) / (2 * a);
		fprintf(fileResult, "Уравнение имеет два корня: %3.2f и %3.2f", x1, x2);
	}
	else if (D == 0)
	{
		float x;
		x = (-b) / (2 * a);
		fprintf(fileResult, "Уравнение имеет один корень: %3.2f", x);
	}
	else if (D < 0)
	{
		fprintf(fileResult, "Действительных корней нет");
	}
	fclose(fileResult);
}