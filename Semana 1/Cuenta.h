#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
using namespace System;

class Cuenta
{
public:
	Cuenta(string nombre,double monto);
	~Cuenta();
	void ingresar(double _monto);
	void retirar(double _monto);

	//set
	void set_nombre(string nombre);
	void set_monto(double _monto);

	//get
	string get_nombre();
	double get_monto();

	void get_info();
private:
	string nombre;
	double monto;
};

Cuenta::Cuenta(string nombre, double _monto)
{
	this->nombre = nombre;
	monto = _monto;
}

Cuenta::~Cuenta(){}//destructor
void Cuenta ::ingresar(double _monto)
{
	if (_monto > 0)monto += _monto;
	else cout << "El monto debe ser positivo";
}
void Cuenta::retirar(double _monto)
{
	if (monto - _monto >= 0)monto -= _monto;
	else cout << "\nSaldo insuficiente";
}
//set
void Cuenta::set_nombre(string _nombre) { nombre = _nombre; }
void Cuenta::set_monto(double _monto) { monto = _monto; }
//get
string Cuenta::get_nombre() { return nombre; }
double Cuenta::get_monto() { return monto; }

void Cuenta::get_info()
{
	cout << "\nNombre: " << nombre;
	cout << "\nMonto: " << monto;
}
