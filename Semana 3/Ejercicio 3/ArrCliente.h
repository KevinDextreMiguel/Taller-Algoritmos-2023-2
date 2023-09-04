#pragma once
#include"Cliente.h"

class ArrCliente
{
public:
	ArrCliente();
	~ArrCliente();
	void agregar(Cliente* dato);
	void eliminar(int pos);
	Cliente* get_cliente(int pos);
	void info_ArrCliente();
private:
	int n;
	Cliente** arr;
};

ArrCliente::ArrCliente()
{
	n = 0;
	arr = new Cliente * [n];
}

ArrCliente::~ArrCliente() { delete[]arr;}

void ArrCliente::agregar(Cliente* dato)
{
	Cliente** aux = new Cliente * [n + 1];
	for (int i = 0; i < n; i++)
		aux[i] = arr[i];
	aux[n] = dato;
	delete[]arr;
	arr = aux;
	n++;
}
void ArrCliente::eliminar(int pos)
{
	Cliente** aux = new Cliente * [n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		if (i < pos)aux[i] = arr[i];
		else aux[i] = arr[i + 1];
	}
	delete[]arr;
	arr = aux;
	n--;
}
Cliente* ArrCliente::get_cliente(int pos) { return arr[pos]; }
void ArrCliente::info_ArrCliente()
{
	for (int i = 0; i < n; i++)
		arr[i]->get_info();
}
