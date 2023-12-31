#pragma once
#include"Eclipse.h"

class ArrEclipse
{
public:
	ArrEclipse();
	~ArrEclipse();

	void agregar_eclipse(Eclipse* objeto);
	Eclipse* modificar_dato(int pos);
	void eliminar_eclipse(int pos);

	//reportes
	void eclipses_visbles_europa();
	void eclipses_con_sismos();
	void eclipses_lunares();
	void imprimir_todos();
private:
	Eclipse** Arr;
	int size;
};

ArrEclipse::ArrEclipse()
{
	size = 0;
	Arr = nullptr;
}

ArrEclipse::~ArrEclipse()
{
	for (int i = 0; i < size; i++)
		delete Arr[i];

	delete[] Arr;
}

void ArrEclipse::agregar_eclipse(Eclipse* objeto)
{
	Eclipse** aux_Arr = new Eclipse * [size + 1];//2

	for (int i = 0; i < size; i++)
		aux_Arr[i]= Arr[i];

	aux_Arr[size] = objeto;//0
	size++;
	if(Arr!=nullptr)delete[] Arr;

	Arr = aux_Arr;
}
Eclipse* ArrEclipse::modificar_dato(int pos)
{
	return Arr[pos];
}
void ArrEclipse::eliminar_eclipse(int pos)
{
	Eclipse** aux_Arr = new Eclipse * [size - 1];

	for (int i = 0; i < size-1; i++)
	{
		if(i<pos)aux_Arr[i] = Arr[i];
		else aux_Arr[i] = Arr[i+1];
	}

	size--;
	if (Arr != nullptr)delete[] Arr;

	Arr = aux_Arr;
}

//reportes
void ArrEclipse::eclipses_visbles_europa()
{
	for (int i = 0; i < size; i++)
		if (Arr[i]->get_Visibilidad() == "Europa")
			Arr[i]->imprimir();
}
void ArrEclipse::eclipses_con_sismos()
{
	for (int i = 0; i < size; i++)
		if (Arr[i]->get_Sismos() == "si")
			Arr[i]->imprimir();
}
void ArrEclipse::eclipses_lunares()
{
	for (int i = 0; i < size; i++)
		if (Arr[i]->get_TipoEclipse() == "lunar")
			Arr[i]->imprimir();
}
void ArrEclipse::imprimir_todos()
{
	for (int i = 0; i < size; i++)
			Arr[i]->imprimir();
}
