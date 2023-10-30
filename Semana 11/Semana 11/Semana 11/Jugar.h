#pragma once
#include<vector>
#include"Bomba.h"
#include"Personaje.h"

using namespace std;

class Jugar
{
public:
	Jugar(int anchoPersonaje, int altoPersonaje);
	~Jugar();
	void dibujarTodos(Graphics^ g, Bitmap^ bpmPersonaje);
	void moverTodos();
	void moverPersonaje(Graphics^ g, Keys tecla);
	void GenerarBomba();
	bool colision();
private:
	Personaje* objP;
	vector<Bomba*>bombas;
};

Jugar::Jugar(int anchoPersonaje, int altoPersonaje)
{
	objP = new Personaje(anchoPersonaje, altoPersonaje);
}

Jugar::~Jugar()
{
	//delete objP;
}
void Jugar::dibujarTodos(Graphics^ g, Bitmap^ bpmPersonaje)
{
	for (int i = 0; i < bombas.size(); i++)
		bombas.at(i)->dibujar(g);

	objP->dibujar(g, bpmPersonaje);
}
void Jugar::moverTodos()
{
	for (int i = 0; i < bombas.size(); i++)
		bombas.at(i)->mover();
}
void Jugar::moverPersonaje(Graphics^ g, Keys tecla)
{
	objP->mover(g, tecla);
}
void Jugar::GenerarBomba()
{
	bombas.push_back(new Bomba());
}
bool Jugar::colision()
{
	for (int i = 0; i < bombas.size(); i++)
		if (bombas.at(i)->getRectangle().IntersectsWith(objP->getRectangle()))
			return true;

	return false;
}
