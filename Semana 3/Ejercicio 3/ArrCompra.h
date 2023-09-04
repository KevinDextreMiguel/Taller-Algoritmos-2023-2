#pragma once
#include"Compra.h"
class ArrCompra
{
public:
	ArrCompra();
	~ArrCompra();
	void agregar(Compra* dato);
	void eliminar(int pos);
	void info_ArrCompra();
private:
	int n;
	Compra** arr;
};

ArrCompra::ArrCompra()
{
	n = 0;
	arr = new Compra * [n];
}

ArrCompra::~ArrCompra() { delete[]arr; }

void ArrCompra::agregar(Compra* dato)
{
	Compra** aux = new Compra * [n + 1];
	for (int i = 0; i < n; i++)
		aux[i] = arr[i];
	aux[n] = dato;
	delete[]arr;
	arr = aux;
	n++;
}
void ArrCompra::eliminar(int pos)
{
	Compra** aux = new Compra * [n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		if (i < pos)aux[i] = arr[i];
		else aux[i] = arr[i + 1];
	}
	delete[]arr;
	arr = aux;
	n--;
}
void ArrCompra::info_ArrCompra()
{
	for (int i = 0; i < n; i++)
		arr[i]->get_info_compra();
}