#pragma once
#include<iostream>
#include<conio.h>
using namespace std;

class Eclipse
{
public:
	Eclipse(string _TipoEclipse,string _Fecha,string _Hora,string Sismos,string Lluvias,string Visibilidad);
	Eclipse();
	~Eclipse();

	//set
	void set_TipoEclipse(string _TipoEclipse);
	void set_Fecha(string _Fecha);
	void set_Hora(string _Hora);
	void set_Sismos(string _Sismos);
	void set_Lluvias(string _Lluvias);
	void set_Visibilidad(string _Visibilidad);

	//get
	string get_TipoEclipse();
	string get_Fecha();
	string get_Hora();
	string get_Sismos();
	string get_Lluvias();
	string get_Visibilidad();
	void imprimir();
private:
	string TipoEclipse;
	string Fecha;
	string Hora;
	string Sismos;
	string Lluvias;
	string Visibilidad;
};

Eclipse::Eclipse(){}
Eclipse::Eclipse(string _TipoEclipse, string _Fecha, string _Hora, string Sismos, string Lluvias, string Visibilidad)
{
	TipoEclipse = _TipoEclipse;
	Fecha= _Fecha;
	Hora= _Hora;
	this->Sismos = Sismos;
	this->Lluvias= Lluvias;
	this->Visibilidad= Visibilidad;
}

Eclipse::~Eclipse(){}

//set
void Eclipse::set_TipoEclipse(string _TipoEclipse) { TipoEclipse = _TipoEclipse; }
void Eclipse::set_Fecha(string _Fecha) {Fecha = _Fecha;}
void Eclipse::set_Hora(string _Hora) { Hora = _Hora; }
void Eclipse::set_Sismos(string _Sismos) { Sismos = _Sismos; }
void Eclipse::set_Lluvias(string _Lluvias) { Lluvias = _Lluvias; }
void Eclipse::set_Visibilidad(string _Visibilidad) { Visibilidad = _Visibilidad; }

//get
string Eclipse::get_TipoEclipse() { return TipoEclipse; }
string Eclipse::get_Fecha() {return Fecha; }
string Eclipse::get_Hora() { return Hora; }
string Eclipse::get_Sismos() { return Sismos; }
string Eclipse::get_Lluvias() { return Lluvias; }
string Eclipse::get_Visibilidad() { return Visibilidad; }

void Eclipse::imprimir()
{
	cout << "\nTipoEclipse: "<<TipoEclipse;
	cout << "\tFecha: " << Fecha;
	cout<<"\tHora: "<< Hora;
	cout << "\tSismos: "<< Sismos;
	cout << "\tLluvias: "<< Lluvias;
	cout << "\tVisibilidad: "<< Visibilidad;
}
