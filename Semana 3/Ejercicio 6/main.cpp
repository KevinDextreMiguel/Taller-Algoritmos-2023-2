#include"Equilatero.h"
#include"Rectangulo.h"

int menu()
{
	int opc;
	do
	{
		cout << "========Menu=======";
		cout << "\n1. Dibujar un Triángulo rectángulo";
		cout << "\n2. Dibujar un Triángulo Equilátero";
		cout << "\nOpción: ";
		cin >> opc;
	} while (opc<1||opc>2);
	return opc;
}
int main()
{
	setlocale(LC_ALL, "spanish");
	Equilatero *objEquilatero;
	Rectangulo* objRectangulo;
	int l1, l2;
	int opc;
	char car;
	while (true)
	{
		system("cls");
		opc = menu();
		cout << "Ingrese un caracter: ";
		cin >> car;
		switch (opc)
		{
		case 1:
			cout << "Ingrese l1,l2: ";
			cin >> l1 >> l2;
			objRectangulo = new Rectangulo(l1, l2, car);
			objRectangulo->dibujar();
			break;
		case 2:
			cout << "Ingrese l1: ";
			cin >> l1;
			objEquilatero = new Equilatero(l1, car);
			objEquilatero->dibujar();
		}
		_getch();
	}
	return 0;
}
