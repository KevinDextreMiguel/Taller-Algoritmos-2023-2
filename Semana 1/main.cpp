#include"Cuenta.h"
#include"Persona.h"
void menu()
{
	cout << "\n1. ingresar monto";
	cout << "\n2. Retirar";
	cout << "\n3. Ver información";
	cout << "\n4. Salir";
}

void Ejercicio_Cuenta()
{
	Cuenta* obj = new Cuenta("Kevin", 2500.7);
	int opcion;
	double monto;
	do
	{
		Console::Clear;
		menu();
		do
		{
			cout << "\nIngrese una opción: "; cin >> opcion;
		} while (opcion < 0 || opcion>4);

		switch (opcion)
		{
		case 1:
			cout << "\nIngrese Monto: "; cin >> monto;
			obj->ingresar(monto); break;
		case 2:
			cout << "\n¿Cuánto dinero quiere retirar?: "; cin >> monto;
			obj->retirar(monto); break;
		case 3:
			obj->get_info();
		}
		system("pause>>null");
	} while (opcion != 4);
}

void ejercicio_persona()
{
	//Creando el objeto 1
	Persona* obj1 = new Persona();
	obj1->set_nombre("Gabriel");
	obj1->set_edad(17);
	obj1->set_dni("12345678");
	obj1->set_sexo('M');
	obj1->set_peso(60.4);
	obj1->set_altura(1.57);

	obj1->toString();
	obj1->esMayorDeEdad();
	obj1->IMC();

	//creamos el objeto 2
	cout << "\n============================================\n";
	Persona* obj2;
	obj2 = new Persona("juan", 19, "56745678", 'M', 50.4, 1.74);
	obj2->toString();
	obj2->esMayorDeEdad();
	obj2->IMC();
}
int main()
{
	setlocale(LC_ALL, "spanish");
	//Ejercicio_Cuenta();
	ejercicio_persona();
	getch();
	return 0;
}
