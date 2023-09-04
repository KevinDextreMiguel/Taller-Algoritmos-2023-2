#pragma once
#include"MisLibrerias.h"

class Producto
{
public:
	Producto(int CodProducto,string Nombre,string Tipo,string Marca,int cantidad,double Precio);
	~Producto();

	void get_info();
private:
	int CodProducto; 
	string Nombre;
	string Tipo;
	string Marca;
	int cantidad;
	double Precio;
};

Producto::Producto(int CodProducto, string Nombre, string Tipo, string Marca, int cantidad,double Precio)
{
	this->CodProducto= CodProducto;
	this->Nombre= Nombre;
	this->Tipo= Tipo;
	this->Marca=Marca;
	this->cantidad = cantidad;
	this->Precio = this->cantidad * Precio;
}

Producto::~Producto(){}

void Producto::get_info()
{
	cout<<"\nCodProducto: "<< CodProducto;
	cout<<"\tNombre: "<< Nombre;
	cout<<"\tTipo: "<< Tipo;
	cout<<"\tMarca: "<< Marca;
	cout<<"\tcantidad: "<< cantidad;
	cout<<"\tPrecio: "<< Precio;
}