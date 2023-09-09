#pragma once
#include"Avion.h"

class ArrAvion
{
public:
	ArrAvion(int _n);
	~ArrAvion();
	void generar_Aviones();
	void mostrar_todos();
	void volver_todos_y0();
private:
	Avion** arr;
	int n;
};

ArrAvion::ArrAvion(int _n)
{
	n = _n;
	arr = new Avion * [n];
}

ArrAvion::~ArrAvion()
{
	for (int i = 0; i < n; i++)
		delete arr[i];
	delete[] arr;
}
void ArrAvion::generar_Aviones()
{
	for (int i = 0; i < n; i++)
		arr[i] = new Avion();
}
void ArrAvion::mostrar_todos()
{
	for (int i = 0; i < n; i++)
	{
		arr[i]->borrar();
		arr[i]->mover();
		arr[i]->mostrar();
	}
}
void ArrAvion::volver_todos_y0()
{
	bool valor = false;
	for (int i = 0; i < n; i++)
		if (arr[i]->get_y() > 25)valor = true;

	if (valor)
	{
		Console::Clear();
		for (int i = 0; i < n; i++)
			arr[i]->set_y(0);
	}
}