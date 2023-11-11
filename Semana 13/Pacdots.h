#pragma once
#include"Base.h"

class PacDots :public Base
{
public:
	PacDots(int anchoForm, int altoForm);
	~PacDots();
	void Dibujar(Graphics^ g);
};

PacDots::PacDots(int anchoForm, int altoForm) :Base(20, 20)
{
	x = rand() % (anchoForm - ancho);
	y = rand() % (altoForm - alto);
}

PacDots::~PacDots() {}
void PacDots::Dibujar(Graphics^ g)
{
	g->FillEllipse(Brushes::Black, getRectangle());
}
