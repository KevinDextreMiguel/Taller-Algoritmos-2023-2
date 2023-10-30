#pragma once
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Personaje
{
public:
	Personaje(int w,int h);
	~Personaje();
	void dibujar(Graphics^ g, Bitmap^ bitmapPersonaje);
	void mover(Graphics^ g,Keys tecla);
	Rectangle getRectangle();
private:
	int x, y;
	int dy,dx;
	int ancho, alto;
	int indX, indY;
};

Personaje::Personaje(int w, int h)
{
	x = y = 400;
	ancho = w;
	alto = h;
	indX = indY = 0;
	dy=dx = 10;
}

Personaje::~Personaje(){}

void Personaje::dibujar(Graphics^ g, Bitmap^ bitmapPersonaje)
{
	Rectangle section = Rectangle(indX * ancho, indY * alto, ancho, alto);
	Rectangle zoom= Rectangle(x, y, ancho, alto);
	//dibujar imagen
	g->DrawImage(bitmapPersonaje, zoom, section, GraphicsUnit::Pixel);
}
void Personaje::mover(Graphics^ g, Keys tecla)
{
	switch (tecla)
	{
	case Keys::Right:
		indY = 2;
		if (x + ancho < g->VisibleClipBounds.Width)x += dx; break;
	case ::Keys::Left:
		indY = 1;
		if (x>0)x -= dx; break;
	case ::Keys::Down:
		indY = 0;
		if (y + dy + alto < g->VisibleClipBounds.Height)y += dy; break;
	case::Keys::Up:
		indY = 3;
		if (y>0)y -= dy;
	}

	indX++;
	if (indX == 3)indX = 0;
}
Rectangle Personaje::getRectangle()
{
	return Rectangle(x, y, ancho, alto);
}