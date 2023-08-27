#pragma once
#include"Contacto.h"

class ArrContacto
{
public:
	ArrContacto();
	~ArrContacto();

	void agregar_Contacto(Contacto* objeto);
	Contacto* modificar_dato(int pos);
	void eliminar_Contacto(int pos);

	//reportes
	void ContactoCumpleaniosMayo();
	void ContactoMasculinos();
	void ContactoFacebookyWhatsApp();
	void imprimir_todos();
private:
	Contacto** Arr;
	int size;
};

ArrContacto::ArrContacto()
{
	size = 0;
	Arr = nullptr;
}

ArrContacto::~ArrContacto()
{
	for (int i = 0; i < size; i++)
		delete Arr[i];

	delete[] Arr;
}

void ArrContacto::agregar_Contacto(Contacto* objeto)
{
	Contacto** aux_Arr = new Contacto * [size + 1];//2

	for (int i = 0; i < size; i++)
		aux_Arr[i] = Arr[i];

	aux_Arr[size] = objeto;//0
	size++;
	if (Arr != nullptr)delete[] Arr;

	Arr = aux_Arr;
}
Contacto* ArrContacto::modificar_dato(int pos)
{
	return Arr[pos];
}
void ArrContacto::eliminar_Contacto(int pos)
{
	Contacto** aux_Arr = new Contacto * [size - 1];

	for (int i = 0; i < size; i++)
	{
		if (i < pos)aux_Arr[i] = Arr[i];
		else aux_Arr[i] = Arr[i + 1];
	}

	size--;
	if (Arr != nullptr)delete[] Arr;

	Arr = aux_Arr;
}

//reportes
void ArrContacto::ContactoCumpleaniosMayo()
{
	for (int i = 0; i < size; i++)
		if (Arr[i]->get_MesNacimiento() == "mayo")
			Arr[i]->get_info();
}
void ArrContacto::ContactoMasculinos()
{
	for (int i = 0; i < size; i++)
		if (Arr[i]->get_Sexo() == "m")
			Arr[i]->get_info();
}
void ArrContacto::ContactoFacebookyWhatsApp()
{
	for (int i = 0; i < size; i++)
		if (Arr[i]->get_RedSocial() == "facebook" && Arr[i]->get_RedSocial() == "WhatsApp")
			Arr[i]->get_info();
}
void ArrContacto::imprimir_todos()
{
	for (int i = 0; i < size; i++)
		Arr[i]->get_info();
}
