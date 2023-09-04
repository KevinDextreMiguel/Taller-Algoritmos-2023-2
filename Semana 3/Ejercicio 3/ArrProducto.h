#pragma once
#include"Producto.h"
class ArrProducto
{
public:
	ArrProducto();
	~ArrProducto();
	void agregar(Producto* dato);
	void eliminar(int pos);
	Producto* get_Producto(int pos);
	void info_ArrProducto();
private:
	int n;
	Producto** arr;
};

ArrProducto::ArrProducto()
{
	n = 0;
	arr = new Producto * [n];
}

ArrProducto::~ArrProducto() { delete[]arr; }

void ArrProducto::agregar(Producto* dato)
{
	Producto** aux = new Producto * [n + 1];
	for (int i = 0; i < n; i++)
		aux[i] = arr[i];
	aux[n] = dato;
	delete[]arr;
	arr = aux;
	n++;
}
void ArrProducto::eliminar(int pos)
{
	Producto** aux = new Producto * [n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		if (i < pos)aux[i] = arr[i];
		else aux[i] = arr[i + 1];
	}
	delete[]arr;
	arr = aux;
	n--;
}
Producto* ArrProducto::get_Producto(int pos) { return arr[pos]; }
void ArrProducto::info_ArrProducto()
{
	for (int i = 0; i < n; i++)
		arr[i]->get_info();
}