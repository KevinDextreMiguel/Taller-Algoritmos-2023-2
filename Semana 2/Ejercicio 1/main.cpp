#include"ArrEclipse.h"

int menu()
{
	int opc;
	do
	{
		cout << "\n===========Menú=========";
		cout << "\n1: Registrar";
		cout << "\n2: Modificar datos";
		cout << "\n3: Eliminar Eclipse";
		cout << "\n4: eclipses con sismos";
		cout << "\n5: eclipses lunares";
		cout << "\n6: eclipses visbles en europa";
		cout << "\n7: Imprimir todo";
		cout << "\n8: salir";
		cout << "\n\nOpción:? "; cin >> opc;
	} while (opc<1||opc>8);

	return opc;
}
int main()
{
	setlocale(LC_ALL, "spanish");
	string TipoEclipse;
	string Fecha;
	string Hora;
	string Sismos;
	string Lluvias;
	string Visibilidad;

	ArrEclipse* objetoArr = new ArrEclipse();
	Eclipse* eclipse;
	int opc;
	while (true)
	{
		system("cls");
		opc = menu();
		if (opc == 1)
		{
			cout << "\nTipoEclipse: "; cin >> TipoEclipse;
			cout << "Fecha: "; cin >> Fecha;
			cout << "Hora: "; cin >> Hora;
			cout << "Sismos: "; cin >> Sismos;
			cout << "Lluvias: "; cin >> Lluvias;
			cout << "Visibilidad: "; cin >> Visibilidad;

			eclipse = new Eclipse(TipoEclipse, Fecha, Hora, Sismos, Lluvias, Visibilidad);

			objetoArr->agregar_eclipse(eclipse);
		}
		else if (opc == 2)
		{
			int pos;
			cout << "\n\nPosición a modificar: "; cin >> pos;
			Eclipse* obj = objetoArr->modificar_dato(pos);

			cout << "\nTipoEclipse: "; cin >> TipoEclipse;
			cout << "Fecha: "; cin >> Fecha;
			cout << "Hora: "; cin >> Hora;
			cout << "Sismos: "; cin >> Sismos;
			cout << "Lluvias: "; cin >> Lluvias;
			cout << "Visibilidad: "; cin >> Visibilidad;

			obj->set_TipoEclipse(TipoEclipse);
			obj->set_Fecha(Fecha);
			obj->set_Hora(Hora);
			obj->set_Sismos(Sismos);
			obj->set_Lluvias(Lluvias);
			obj->set_Visibilidad(Visibilidad);
			cout << "\nModificado correctamente";
		}
		else if (opc == 3)
		{
			int pos;
			cout << "\n\nPosición a eliminar: "; cin >> pos;
			objetoArr->eliminar_eclipse(pos - 1);
			cout << "\nEliminado correctamente";
		}
		else if (opc == 4) objetoArr->eclipses_con_sismos();
		else if (opc == 5)objetoArr->eclipses_lunares();
		else if (opc == 6)objetoArr->eclipses_visbles_europa();
		else if (opc == 7)objetoArr->imprimir_todos();

		//else break;
		getch();

	}
	return 0;
}
