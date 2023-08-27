#include"ArrContacto.h"
int menu()
{
	int opc;
	do
	{
		cout << "\n===========Menú=========";
		cout << "\n1: Registrar Contacto";
		cout << "\n2: Modificar Contacto";
		cout << "\n3: Eliminar Contacto";
		cout << "\n4: Contactos que cumplen años en mayo";
		cout << "\n5: Contactos varones";
		cout << "\n6: Contactos que utilizan Facebook y WhatsApp";
		cout << "\n7: Imprimir todos los contactos";
		cout << "\n8: salir";
		cout << "\n\nIngrese una opción: "; cin >> opc;
	} while (opc<1||opc>8);

	return opc;
}

int main()
{
	setlocale(LC_ALL, "spanish");
	string Nombrecontacto;
	string Telefono;
	string Sexo;
	string Facultad;
	string MesNacimiento;
	string Email;
	string RedSocial;

	ArrContacto* objetoArr = new ArrContacto();
	Contacto* contacto;
	int opc=0;
	while (opc!=8)
	{
		system("cls");
		opc = menu();
		if (opc == 1)
		{
			cout << "\nNombrecontacto: "; cin >> Nombrecontacto;
			cout << "Telefono: "; cin >> Telefono;
			cout << "Sexo: "; cin >> Sexo;
			cout << "Facultad: "; cin >> Facultad;
			cout << "MesNacimiento: "; cin >> MesNacimiento;
			cout << "Email: "; cin >> Email;
			cout << "RedSocial: "; cin >> RedSocial;

			contacto = new Contacto(Nombrecontacto, Telefono, Sexo, Facultad, MesNacimiento, Email, RedSocial);

			objetoArr->agregar_Contacto(contacto);
		}
		else if (opc == 2)
		{
			int pos;
			cout << "\n\nPosición a modificar: "; cin >> pos;
			Contacto* obj = objetoArr->modificar_dato(pos);

			cout << "\nNombrecontacto: "; cin >> Nombrecontacto;
			cout << "Telefono: "; cin >> Telefono;
			cout << "Sexo: "; cin >> Sexo;
			cout << "Facultad: "; cin >> Facultad;
			cout << "MesNacimiento: "; cin >> MesNacimiento;
			cout << "Email: "; cin >> Email;
			cout << "RedSocial: "; cin >> RedSocial;

			obj->set_Nombrecontacto(Nombrecontacto);
			obj->set_Telefono(Telefono);
			obj->set_Sexo(Sexo);
			obj->set_Facultad(Facultad);
			obj->set_MesNacimiento(MesNacimiento);
			obj->set_Email(Email);
			obj->set_RedSocial(RedSocial);
			cout << "\nModificado correctamente";
		}
		else if (opc == 3)
		{
			int pos;
			cout << "\n\nPosición a eliminar: "; cin >> pos;
			objetoArr->eliminar_Contacto(pos - 1);
			cout << "\nEliminado correctamente";
		}
		else if (opc == 4) objetoArr->ContactoCumpleaniosMayo();
		else if (opc == 5)objetoArr->ContactoMasculinos();
		else if (opc == 6)objetoArr->ContactoFacebookyWhatsApp();
		else if (opc == 7)objetoArr->imprimir_todos();

		else opc=8;
		getch();
	}
	return 0;
}
