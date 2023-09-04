#pragma once
#include"ArrProducto.h"
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
	ArrProducto* objArrProducto;
};

Compra::Compra(int id, string fecha, Cliente* obj)
{
	this->id = id;
	this->fecha = fecha;
	ObjCliente=obj;
	objArrProducto = new ArrProducto();
}
Compra::~Compra() 
{ 
	delete ObjCliente;
	delete objArrProducto;
}

void Compra::agregar_Producto(Producto* obj)
{
	objArrProducto->agregar(obj);
}

void Compra::get_info_compra()
{
	cout << "\n===========================================\n";
	cout << "\nid: " << id;
	cout << "\tfecha: " << fecha << endl;
	ObjCliente->get_info();
	objArrProducto->info_ArrProducto();
}

