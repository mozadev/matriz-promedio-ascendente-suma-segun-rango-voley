#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
using namespace System;
int ingresapositivo()
{
	int n;
	do {
		cout << "ingresa numero de señoritas: "; cin >> n;
	} while (n < 0 || n>80);
	return n;
}
void generatallas(aint *n, float **tallas)
{
	Random r;
	for (int j = 0; j < *n; j++)
	{
		tallas[0][j] = j + 1;
		tallas[1][j] = (r.Next(155, 221)) / 100.0;
	}
}
void ordenascendente(int *n, float **tallas)
{
	float temp;
	for (int i = 0; i < *n - 1; i++)
		for (int j = i + 1; j < *n; j++)
			if (tallas[1][i] > tallas[1][j])
			{
				temp = tallas[1][i];
				tallas[1][i] = tallas[1][j];
				tallas[1][j] = temp;
			}
}
void promedionperticipantes(int *n, float **tallas)
{
	float suma = 0;
	for (int i = 0; i < *n; i++)
		suma += tallas[1][i];
	cout << "el promedio de tallas es: " << suma / (*n) << endl;


}
void salidadatos(int *n, float **tallas)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < *n; j++)
			cout << tallas[i][j] << "\t";
		cout << endl;
	}
}
void determinarliberomatadoralevantadora(int *n, float **tallas)
{
	int contadorlibero = 0, contadorlevanta = 0, contamatadora = 0;
	for (int i = 0; i < *n; i++)
	{
		if (tallas[1][i] >= 1.55 && tallas[1][i] <= 1.69)
			contadorlibero++;
		if (tallas[1][i] >= 1.7 && tallas[1][i] <= 1.85)
			contadorlevanta++;
		if (tallas[1][i] >= 1.86)
			contamatadora++;
	}
	cout << "LIBERO: " << contadorlibero << endl;
	cout << "LEVANTADORA: " << contadorlevanta << endl;
	cout << "MATADADORA: " << contamatadora << endl;

	if(contamatadora<*n/2)
		cout << "REALIZAR NUEVA CONVOCATORIA  " << endl;
}

int main()
{
	int n = ingresapositivo();
	float **tallas;
	tallas = new float*[2];
	for (int i = 0; i < 2; i++)
		tallas[i] = new float[n];
	generatallas(&n, tallas);
	salidadatos(&n, tallas);
	ordenascendente(&n, tallas);
	salidadatos(&n, tallas);
	promedionperticipantes(&n, tallas);
	determinarliberomatadoralevantadora(&n, tallas);
	for (int i = 0; i < 2; i++)
		delete[] tallas[i];
	delete[] tallas;
	_getch();
}