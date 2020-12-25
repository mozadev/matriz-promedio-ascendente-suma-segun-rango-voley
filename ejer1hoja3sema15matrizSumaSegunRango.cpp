/*
ejercicio 1 hoja 3 bidimensionales
*/
#include<iostream>
#include<stdlib.h>
#include <time.h>

using namespace std;

int IngresaPositivo()
{
    int Num;
	do
	{
		cout << "numero positivo:"; cin >> Num;
	} while (Num <= 1 || Num > 80);
	return Num;
}
void IngresaDatos(int N, float **Matriz)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		Matriz[i][0] = i + 1;
		Matriz[i][1] = (155 + rand() % (221-155))/100.0;

	}
}
void ImprimirDatos(int N, float **Matriz)
{
	cout << endl << " DATOS DE LA MATRIZ" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j< 2; j++)
			cout << Matriz[i][j] << " ";
		cout << endl;
	}
}

void Estadistica(int N, float **Matriz)
{
	float Suma = 0, Promedio, Temp;
	int Cont1 = 0, Cont2 = 0, Cont3 = 0;
	cout << endl << " RESULTADOS" << endl;
	for (int i = 0; i < N; i++)
	{
		Suma = Suma + Matriz[i][1];
		for(int j=i; j< N; j++)
			if (Matriz[i][1] > Matriz[j][1])
			{	Temp = Matriz[i][1];
				Matriz[i][1] = Matriz[j][1];
				Matriz[j][1] = Temp;
			}
	}
	Promedio = Suma / N;
	cout << "El promedio es :" << Promedio << endl;
}


int main()
{
	int N = IngresaPositivo();
	float **Matriz;
	Matriz = new float *[N];
	for (int i = 0; i<N; i++)
		Matriz[i] = new float[2];
	IngresaDatos(N, Matriz);
	ImprimirDatos(N, Matriz);
	Estadistica(N, Matriz);
	ImprimirDatos(N, Matriz);
	for (int i = 0; i<N; i++)
		delete[] Matriz[i];
	delete[] Matriz;

}