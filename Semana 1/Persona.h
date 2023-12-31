#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
using namespace System;

class Persona
{
private:
	string nombre;
	int edad;
	string dni;
	char sexo;
	double peso;
	double altura;
public:
	Persona(string _nombre, int _edad, string _dni, char _sexo, double _peso, double _altura)
	{
		nombre=_nombre;
		edad=_edad;
		dni = _dni;;
		sexo=_sexo;
		peso=_peso;
		altura= _altura;
	}
	Persona(){}
	~Persona(){}

	void IMC()
	{
		double imc = peso / (altura * altura);
		if(imc<20) cout<<"\nPeso por debajo";
		else if (imc < 26)cout << "\nPeso Ideal";
		else cout<<"\nSobrepeso";
	}
	bool esMayorDeEdad() { return edad > 17; }
	bool comprobarSexo(char sexo) { return sexo == 'F' || sexo == 'M'; }
	void toString()
	{
		cout << "\nnombre: "<<nombre;
		cout << "\nedad: " << edad;
		cout << "\ndni: " << dni;
		cout << "\nsexo: " << sexo;
		cout << "\npeso: " << peso;
		cout << "\naltura: " << altura;
	}
	//set
	void set_nombre(string nombre) { this->nombre = nombre; }
	void set_edad(int _edad) { edad = _edad; }
	void set_dni(string _dni) { dni = _dni; }
	void set_sexo(char _sexo) { sexo = _sexo; }
	void set_peso(double _peso) { peso = _peso; }
	void set_altura(double _altura) { altura = _altura; }

	//get
	string get_nombre() { return nombre; }
	int get_edad() { return edad; }
	string get_dni() {return dni;}
	char get_sexo() { return sexo; }
	double get_peso() { return peso; }
	double get_altura() { return altura; }
};
