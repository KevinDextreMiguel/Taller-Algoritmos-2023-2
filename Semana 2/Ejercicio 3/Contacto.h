#pragma once
#include<iostream>
#include<conio.h>
using namespace std;

class Contacto
{
public:
	Contacto(string Nombrecontacto, string Telefono, string Sexo, string Facultad, 
		string MesNacimiento,string Email, string RedSocial);
	Contacto();
	~Contacto();

	//set
	void set_Nombrecontacto(string Nombrecontacto);
	void set_Telefono(string Telefono);
	void set_Sexo(string Sexo);
	void set_Facultad(string Facultad);
	void set_MesNacimiento(string MesNacimiento);
	void set_Email(string Email);
	void set_RedSocial(string RedSocial);
	//get
	string get_Nombrecontacto();
	string get_Telefono();
	string get_Sexo();
	string get_Facultad();
	string get_MesNacimiento();
	string get_Email();
	string get_RedSocial();
	void get_info();

private:
	string Nombrecontacto;
	string Telefono;
	string Sexo;
	string Facultad;
	string MesNacimiento;
	string Email;
	string RedSocial;
};

Contacto::Contacto(){}
Contacto::Contacto(string Nombrecontacto, string Telefono, string Sexo, string Facultad,
	string MesNacimiento, string Email, string RedSocial)
{
	this->Nombrecontacto= Nombrecontacto;
	this->Telefono= Telefono;
	this->Sexo= Sexo;
	this->Facultad= Facultad;
	this->MesNacimiento= MesNacimiento;
	this->Email= Email;
	this->RedSocial= RedSocial;
}
Contacto::~Contacto(){}

//set
void Contacto::set_Nombrecontacto(string Nombrecontacto) {this->Nombrecontacto= Nombrecontacto;}
void Contacto::set_Telefono(string Telefono) { this->Telefono = Telefono; }
void Contacto::set_Sexo(string Sexo) { Sexo = this->Sexo; }
void Contacto::set_Facultad(string Facultad) { this->Facultad= Facultad; }
void Contacto::set_MesNacimiento(string MesNacimiento) { this->MesNacimiento= MesNacimiento; }
void Contacto::set_Email(string Email) { this->Email= Email; }
void Contacto::set_RedSocial(string RedSocial) { this->RedSocial= RedSocial; }
//get
string Contacto::get_Nombrecontacto() { return Nombrecontacto; }
string Contacto::get_Telefono() { return Telefono; }
string Contacto::get_Sexo() { return Sexo; }
string Contacto::get_Facultad() { return Facultad; }
string Contacto::get_MesNacimiento(){ return MesNacimiento; }
string Contacto::get_Email() { return Email; }
string Contacto::get_RedSocial() { return RedSocial; }
void Contacto::get_info()
{
	cout << "\nNombrecontacto: " << Nombrecontacto;
	cout << "\tTelefono: " << Telefono;
	cout << "\tSexo: " << Sexo;
	cout << "\tFacultad: " << Facultad;
	cout << "\tMesNacimiento: " << MesNacimiento;
	cout << "\tEmail: " << Email;
	cout << "\tRedSocial: " << RedSocial;
}
