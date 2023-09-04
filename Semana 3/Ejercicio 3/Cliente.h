#pragma once
#include"MisLibrerias.h"

class Cliente
{
public:
	Cliente(string DNI,string Nombres);
	~Cliente();
	void get_info();

private:
	string DNI, Nombres;
};

Cliente::Cliente(string DNI, string Nombres)
{
	this->DNI = DNI;
	this->Nombres = Nombres;
}

Cliente::~Cliente(){}


void Cliente::get_info()
{
	cout << "\nDNI: " << DNI;
	cout<<"\tNombre: "<<Nombres;
}