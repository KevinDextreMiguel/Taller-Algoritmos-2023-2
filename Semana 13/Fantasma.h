#pragma once
#include"Base.h"

class Fantasma:public Base
{
public:
	Fantasma(int anchoForm,int altoForm, int anchoImg, int altoImg);
	~Fantasma();
	void Dibujar(Graphics^ g, Bitmap^ imagen);
};

Fantasma::Fantasma(int anchoForm, int altoForm, int anchoImg, int altoImg):Base(anchoImg,altoImg)
{
	x = rand() % (anchoForm - ancho);
	y = rand() % (altoForm - alto);
	dx = rand() % 3 + 1;
	dy = rand() % 3 + 1;
	velocidad = rand() % 3 + 1;
}

Fantasma::~Fantasma(){}
void Fantasma::Dibujar(Graphics^ g, Bitmap^ imagen)
{
	imagen->MakeTransparent(imagen->GetPixel(1, 1));
	Rectangle porcion(ancho * indx, alto * indy, ancho, alto);
	g->DrawImage(imagen, x, y, porcion, GraphicsUnit::Pixel);

	indx++;
	if (indx == 4)indx = 0;
}