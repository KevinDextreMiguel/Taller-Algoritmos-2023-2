#pragma once
#include<vector>
#include"Circulo.h"
#include"Rectangulo.h"
#include"Rombo.h"

using namespace std;

class Jugar
{
public:
	Jugar(int w,int h);
	~Jugar();
	void dibujarTodo(Graphics^ g);
	void moverTodo();
	void dibujarMeta(Graphics^ g);
	void analizarMeta();
	void ordenarVector();
	//get
	int getcantidadCompetencias();
	int getPuntos(int pos);
	string GetNombre(int pos);
private:
	vector<Figura*>figuras;
	int anchoForm;
	int altoForm;
	int cantidadCompetencias;
};

Jugar::Jugar(int w, int h)
{
	anchoForm = w;
	altoForm = h;
	cantidadCompetencias = 0;

	figuras.push_back(new Rectangulo());
	figuras.push_back(new Circulo());
	figuras.push_back(new Rombo());
}

Jugar::~Jugar(){}

void Jugar::dibujarTodo(Graphics^ g)
{
	for (int i = 0; i < figuras.size(); i++)
		figuras.at(i)->dibujar(g);
}
void Jugar::moverTodo()
{
	for (int i = 0; i < figuras.size(); i++)
		figuras.at(i)->mover();
}
void Jugar::dibujarMeta(Graphics^ g)
{
	Pen^ p = gcnew Pen(Color::Orange,5);
	g->DrawLine(p, anchoForm-100, 0, anchoForm - 100, altoForm);
}
void Jugar::analizarMeta()
{
	bool valor = false;
	for (int i = 0; i < figuras.size(); i++)
		if (figuras.at(i)->getX() + figuras.at(i)->getAncho() > anchoForm - 100)
		{
			figuras.at(i)->setPuntos(1);
			cantidadCompetencias++;
			valor = true;
		}

	if (valor)
	{
		for (int i = 0; i < figuras.size(); i++)
		{
			figuras.at(i)->setX(0);
			figuras.at(i)->setDx();
		}
	}
}

void Jugar::ordenarVector()
{
	for (int i = 0; i < figuras.size()-1; i++)
		for (int j = i+1;j< figuras.size(); j++)
			if (figuras.at(i)->getPuntos() < figuras.at(j)->getPuntos())
			{
				Figura *aux = figuras[i];
				figuras[i] = figuras[j];
				figuras[j] = aux;
			}

}
//get
int Jugar::getcantidadCompetencias() { return cantidadCompetencias; }
int Jugar::getPuntos(int pos){ return figuras.at(pos)->getPuntos(); }
string Jugar::GetNombre(int pos) { return figuras.at(pos)->getNombre(); }