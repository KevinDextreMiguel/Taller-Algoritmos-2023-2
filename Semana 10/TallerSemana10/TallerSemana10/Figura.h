#pragma once
#include<iostream>
#include<string>
using namespace System::Drawing;
using namespace std;
class Figura
{
public:
	Figura(int w,int h,string nom);
	~Figura();
	void mover();
	virtual void dibujar(Graphics^ g){}
	//set
	void setPuntos(int valor);
	void setX(int _x);
	void setDx();
	//get
	int getPuntos();
	int getX();
	int getY();
	int getAncho();
	int getAlto();
	string getNombre();

protected:
	int x, y;
	int dx;
	int alto, ancho;
	int puntos;
	string nombre;
};

Figura::Figura(int w, int h,string nom)
{
	x = 0;
	ancho = w;
	alto = h;
	dx = rand() % 15 + 5;
	puntos = 0;
	nombre = nom;
}

Figura::~Figura(){}

void Figura::mover()
{
	x += dx;
}
//set
void Figura::setPuntos(int valor) { puntos += valor; }
void Figura::setX(int _x) { x = _x; }
void Figura::setDx(){ dx = rand() % 15 + 5; }
//get
int Figura::getPuntos() { return puntos; }
int Figura::getX() { return x; }
int Figura::getY() { return y; }
int Figura::getAncho() { return ancho; }
int Figura::getAlto() { return alto; }
string Figura::getNombre(){ return nombre;}