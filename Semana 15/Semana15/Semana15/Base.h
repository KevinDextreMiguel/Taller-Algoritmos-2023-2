#pragma once
#include<iostream>
#include<vector>
using namespace std;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Base
{
protected:
	int x, y;
	int dx, dy;
	int indy, indx;
	int ancho, alto;
	bool visible;
public:
	Base(int _ancho,int _alto)
	{
		visible = true;
		ancho = _ancho;
		alto = _alto;
		indy=indx=0;
	}
	~Base() {}
	//set
	void SetVisible(bool v) { visible = v; }
	void Setdx(int val) { dx = val; }
	void Setdy(int val) { dy = val; }
	void Setancho(int v) {ancho=v; }
	void Setalto(int v) { alto=v;}
	//get
	int Getx() { return x ;}
	int Gety() { return y ;}
	int Getdx() { return dx; }
	int Getdy() { return dy; }
	int Getancho() { return ancho; }
	int Getalto() { return alto; }
	bool GetVisible() { return visible; }
	Rectangle GetRectangle() { return Rectangle(x, y, ancho, alto); }
};
