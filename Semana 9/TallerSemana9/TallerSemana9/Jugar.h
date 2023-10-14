#pragma once
#include<vector>
#include"Circulo.h"
#include"Triangulo.h"

using namespace std;

class Jugar
{
private:
	vector<Circulo*>circulos;
	vector<Triangulo*>triangulos;
public:
	Jugar();
	~Jugar();

	void agregarCirculo();
	void agregarTriangulo();
	void dibujarTodo(Graphics^ g);
	void moverTodo(Graphics^ g);
	void colision();
};

Jugar::Jugar() {}
Jugar::~Jugar() {}

void Jugar::agregarCirculo()
{
	Circulo* obj = new Circulo();
	circulos.push_back(obj);
}
void Jugar::agregarTriangulo()
{
	triangulos.push_back(new Triangulo());
}
void Jugar::dibujarTodo(Graphics^ g)
{
	for (int i = 0; i < circulos.size(); i++)
		circulos.at(i)->dibujar(g);

	for (int i = 0; i < triangulos.size(); i++)
		triangulos[i]->dibujar(g);
}
void Jugar::moverTodo(Graphics^ g)
{
	for (int i = 0; i < circulos.size(); i++)
		circulos.at(i)->mover(g);

	for (int i = 0; i < triangulos.size(); i++)
		triangulos[i]->mover(g);
}
void Jugar::colision()
{
	//verificamos si hay colisión
	for (int i = 0; i < circulos.size(); i++)
		for (int j = 0; j < triangulos.size(); j++)
			if (circulos[i]->getRectagle().IntersectsWith(triangulos[j]->getRectangle()))
			{
				circulos[i]->setVisible(false);
				triangulos[j]->setVisible(false);
			}

	//eliminamos los objetos que colisionaron
	for (int i = 0; i < circulos.size(); i++)
		if (!circulos[i]->getVisible())
			circulos.erase(circulos.begin() + i);

	for (int i = 0; i < triangulos.size(); i++)
		if (!triangulos[i]->getVisible())
			triangulos.erase(triangulos.begin() + i);
}