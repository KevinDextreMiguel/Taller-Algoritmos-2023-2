#pragma once
#include"Base.h"

class Pacman:public Base
{
public:
	Pacman(int _x,int _y,int _vida,int anchoImg,int altoImg);
	~Pacman();
	void Mover(Graphics^ g, Keys tecla);
	void Dibujar(Graphics^ g, Bitmap^ imagen);
	void quitarVida();
	int DevolverVida();
	void AumentarVelocidad();
private:
	int vida;
	int cont;
};

Pacman::Pacman(int _x, int _y, int _vida, int anchoImg, int altoImg):Base(anchoImg,altoImg)
{
	x = _x;
	y = _y;
	vida = _vida;
	cont = -1;
	posInicialX = x;
	posInicialY = y;
}

Pacman::~Pacman(){}

void Pacman::Mover(Graphics^ g, Keys tecla)
{
	switch (tecla)
	{
	case Keys::Right:
		dy = 0;
		dx = 1;
		indy = 2;
		break;
	case Keys::Left:
		dy = 0;
		dx = -1;
		indy = 1;
		break;
	case Keys::Down:
		dy = 1;
		dx = 0;
		indy = 0;
		break;
	case Keys::Up:
		dy = -1;
		dx = 0;
		indy = 3;
	}

	if (x + dx<0 || x + dx * velocidad + ancho>g->VisibleClipBounds.Width)dx=0;
	if (y + dy<0 || y + dy * velocidad + alto>g->VisibleClipBounds.Height)dy=0;

	x += dx * velocidad;
	y += dy * velocidad;

	if (cont > -1)cont--;
	if (cont == 0)velocidad=velocidad/2;
}
void Pacman::Dibujar(Graphics^ g, Bitmap^ imagen)
{
	imagen->MakeTransparent(imagen->GetPixel(1, 1));
	Rectangle porcion(ancho * indx, alto * indy, ancho, alto);
	g->DrawImage(imagen, x, y, porcion, GraphicsUnit::Pixel);

	indx++;
	if (indx == 2)indx = 0;
}
void Pacman::quitarVida()
{
	vida--;
}
int Pacman::DevolverVida()
{
	return vida;
}
void Pacman::AumentarVelocidad()
{
	if (cont > 0)
	{
		velocidad *= 2;
		cont = 50;
	}
}