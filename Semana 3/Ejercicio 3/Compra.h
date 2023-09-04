#pragma once
#include"Producto.h"
#include"Cliente.h"

class Compra
{
public:
	Compra(int id, string fecha, Cliente* obj);
	~Compra();
	void agregar_Producto(Producto* obj);
	void get_info_compra();
private:
	int id;
	string fecha;
	Cliente* ObjCliente;
	Producto** arrProducto;
	int n;
};

Compra::Compra(int id, string fecha, Cliente* obj)
{
	this->id = id;
	this->fecha = fecha;
	ObjCliente=obj;
	n = 0;
	arrProducto = new Producto*[n];

}
Compra::~Compra() { delete ObjCliente; }

void Compra::agregar_Producto(Producto* obj)
{
	Producto** aux = new Producto * [n + 1];
	for (int i = 0; i < n; i++)
		aux[i] = arrProducto[i];

	aux[n] = obj;
	delete[]arrProducto;
	arrProducto = aux;
	n++;
}

void Compra::get_info_compra()
{
	cout << "\n===========================================\n";
	cout << "\nid: " << id;
	cout << "\tfecha: " << fecha << endl;
	ObjCliente->get_info();
	for (int i = 0; i < n; i++)
		arrProducto[i]->get_info();
}

