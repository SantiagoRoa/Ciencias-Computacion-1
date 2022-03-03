#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include "pila.h"
#include "cola.h"
#include <locale.h>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Spanish");
	cola Cola;
	pila Pila[3];
	int i, j, tam, grupo = 0, orden[3];
	char x;

	do {
		cout << "Escriba un mùltiplo de 3: ";
		cin >> tam;
	} while (tam % 3 != 0);
	i = 1;
	x = 30;
	cout << x;
	while (i <= tam && i < 255)
	{
		if ((x == 0) || (x == 13) || (x == 32) || (x > 6 && x < 11))
			x++;
		else
		{
			Cola.InsCola(x);
			i++;
			x++;
		}
	}

	cout << "mire cuidadosamente los sìmbolos y elija uno\n";

	for (j = 1; j < tam / 3; j++)
	{
		cout << "  Gr1  " <<
			"Gr2  " <<
			"Gr3  " << endl;
		while (!Cola.ColaVacia())
		{
			for (i = 0; i < 3; i++)
			{
				x = Cola.AtenderCola();
				cout << setw(4) << x;
				Pila[i].Push(x);
			}

			cout << "\n";
		}

		cout << "elija el grupo en el que quedò el sìmbolo elegido (1, 2 o 3): ";
		cin >> grupo;
		switch (grupo)
		{
			case 1:
				{
					orden[0] = 1;
					orden[1] = 0;
					orden[2] = 2;
					break;
				}

			case 2:
				{
					orden[0] = 0;
					orden[1] = 1;
					orden[2] = 2;
					break;
				}

			case 3:
				{
					orden[0] = 0;
					orden[1] = 2;
					orden[2] = 1;
					break;
				}
		}

		for (i = 0; i < 3; i++)
		{
			while (!Pila[orden[i]].PilaVacia())
			{
				Cola.InsCola(Pila[orden[i]].Pop());
			}
		}
	}

	j = tam - tam / 2;

	for (i = 1; i <= j; i++)
	{
		x = Cola.AtenderCola();
	}

	cout << "La figura elegida es: " << x << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
