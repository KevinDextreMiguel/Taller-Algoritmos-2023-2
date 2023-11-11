#pragma once
#include"Base.h"

class Bonus:public Base
{
public:
	Bonus(int anchoForm,int altoForm);
	~Bonus();
	void Dibujar(Graphics^ g);
	void Cambiar_Lugar();
private:
	int anchoForm;
	int altoForm;
};

Bonus::Bonus(int anchoForm, int altoForm):Base(20,20)
{
	this->anchoForm=anchoForm;
	this->altoForm=altoForm;
	x = rand() % (anchoForm - ancho);
	y = rand() % (altoForm - alto);
}

Bonus::~Bonus(){}
void Bonus::Dibujar(Graphics^ g)
{
	g->FillEllipse(Brushes::Red, getRectangle());
	g->DrawString("Bonus", gcnew Font("Times new Roman", 10), Brushes::Blue, x, y);
}
void Bonus::Cambiar_Lugar()
{
	x = rand() % (anchoForm - ancho);
	y = rand() % (altoForm - alto);
}