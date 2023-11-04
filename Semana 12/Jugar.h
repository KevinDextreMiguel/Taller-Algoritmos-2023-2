#pragma once
#include"Bala.h"
#include"Enemigo.h"
#include"Heroe.h"

class Jugar
{
public:
	Jugar(int anchHeroe,int altoHeroe);
	~Jugar();
	void mover_Heroe(Graphics^ g, Keys tecla);
	void dibujarTodo(Graphics^ g,Bitmap^bmpHeroe, Bitmap^ bmpEnemigo);
	void moverTodo(Graphics^ g);

	void generarEnemigo(int anchEnemigo, int altoEnemigo);
	void generarBala();
	void colision();
	void eliminarFueraFormulario(Graphics^ g);

private:
	Heroe* objHeroe;
	vector<Enemigo*>enemigos;
	vector<Bala*>balas;
};

Jugar::Jugar(int anchHeroe, int altoHeroe)
{
	objHeroe = new Heroe(anchHeroe, altoHeroe);
}
Jugar::~Jugar() {
	delete objHeroe;
}
void Jugar::mover_Heroe(Graphics^ g, Keys tecla)
{
	objHeroe->mover(g, tecla);
}
void Jugar::dibujarTodo(Graphics^ g, Bitmap^ bmpHeroe, Bitmap^ bmpEnemigo)
{
	objHeroe->dibujar(g, bmpHeroe);

	for (int i = 0; i < enemigos.size(); i++)
		enemigos.at(i)->dibujar(g, bmpEnemigo);
	for (int i = 0; i < balas.size(); i++)
		balas.at(i)->dibujar(g);
}
void Jugar::moverTodo(Graphics^ g)
{
	for (int i = 0; i < enemigos.size(); i++)
		enemigos.at(i)->mover(g);
	for (int i = 0; i < balas.size(); i++)
		balas.at(i)->mover();
}

void Jugar::generarEnemigo(int anchEnemigo, int altoEnemigo)
{
	enemigos.push_back(new Enemigo(anchEnemigo, altoEnemigo));
}
void Jugar::generarBala()
{
	int x = objHeroe->getx() + (objHeroe->getancho() / 2);
	int y = objHeroe->gety() + (objHeroe->getalto() / 2);
	balas.push_back(new Bala(x, y, objHeroe->getDireccion()));
}
void Jugar::colision()
{
	//verificar
	for (int i = 0; i < enemigos.size(); i++)
		for (int j = 0; j < balas.size(); j++)
			if (enemigos.at(i)->getRectangulo().IntersectsWith(balas.at(j)->getRectangulo()))
			{
				enemigos.at(i)->setVisble(false);
				balas.at(j)->setVisble(false);
			}

	//eliminar
	for (int i = 0; i < enemigos.size(); i++)
		if (!enemigos.at(i)->getvisible())
			enemigos.erase(enemigos.begin() + i);
	for (int i = 0; i < balas.size(); i++)
		if (!balas.at(i)->getvisible())
			balas.erase(balas.begin() + i);
}


void Jugar::eliminarFueraFormulario(Graphics^ g)
{
	for (int i = 0; i < enemigos.size(); i++)
		if (enemigos.at(i)->gety()>g->VisibleClipBounds.Height)
			enemigos.erase(enemigos.begin() + i);



	for (int i = 0; i < balas.size(); i++)
		if (balas.at(i)->getx()<0 || balas.at(i)->getx()>g->VisibleClipBounds.Width ||
			balas.at(i)->gety() < 0 || balas.at(i)->gety() > g->VisibleClipBounds.Height)
			balas.erase(balas.begin() + i);
}