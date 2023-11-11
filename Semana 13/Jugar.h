#pragma once
#include"Bonus.h"
#include"Fantasma.h"
#include"Pacdots.h"
#include"Pacman.h"
#include<fstream>
class Jugar
{
public:
	Jugar(int anchoForm, int altoForm, int anchoPacman, int altoPacman, int anchoFantasma, int altoFantasma);
	~Jugar();
	void MoverPacman(Graphics^ g, Keys tecla);
	void Dibujar(Graphics^ g, Bitmap^ imagenPacman);
	void MoverFantasmaYDibujar(Graphics^ g, Bitmap^ imagenFantasma);
	bool colision();
	bool Colision_Pacman_Pacdots();
	void PosicionBunus();
	void DuplicarVelocidad();

private:
	Pacman* objPacman;
	Bonus* objBonus;
	vector<PacDots*> vecPacDots;
	vector<Fantasma*> vecFantasma;
	int anchoF, altoF;
	clock_t tiempo;
};

Jugar::Jugar(int anchoForm, int altoForm, int anchoPacman, int altoPacman, int anchoFantasma, int altoFantasma)
{
	anchoF = anchoForm;
	altoF = altoForm;
	objBonus = new Bonus(anchoF, altoF);

	//archivo
	fstream archivo;
	archivo.open("datos.txt", ios::in);
	int x, y, vida;
	archivo >> x;
	archivo >> y;
	archivo >> vida;

	objPacman = new Pacman(x, y, vida, anchoPacman, altoPacman);
	archivo.close();

	tiempo = clock();
	for (int i = 0; i < 2; i++)
		vecFantasma.push_back(new Fantasma(anchoF, altoF,anchoFantasma,altoFantasma));
	for (int i = 0; i < 10; i++)
		vecPacDots.push_back(new PacDots(anchoF, altoF));
}

Jugar::~Jugar()
{
	delete  objPacman;
	delete objBonus;
}
void Jugar::MoverPacman(Graphics^ g, Keys tecla)
{
	objPacman->Mover(g,tecla);
}
void Jugar::Dibujar(Graphics^ g, Bitmap^ imagenPacman)
{
	objBonus->Dibujar(g);
	objPacman->Dibujar(g, imagenPacman);
	for (int i = 0; i < vecPacDots.size(); i++)
		vecPacDots.at(i)->Dibujar(g);
}
void Jugar::MoverFantasmaYDibujar(Graphics^ g, Bitmap^ imagenFantasma)
{
	for (int i = 0; i < vecFantasma.size(); i++)
	{
		vecFantasma.at(i)->mover(g);
		vecFantasma.at(i)->Dibujar(g,imagenFantasma);
	}
}
bool Jugar::colision()
{
	for (int i = 0; i < vecFantasma.size(); i++)
		if (vecFantasma.at(i)->getRectangle().IntersectsWith(objPacman->getRectangle()))
		{
			objPacman->posicision_Inicial();
			objPacman->quitarVida();
		}
	return objPacman->DevolverVida() > 0;
}
bool Jugar::Colision_Pacman_Pacdots()
{
	for (int i = 0; i < vecPacDots.size(); i++)
		if (vecPacDots.at(i)->getRectangle().IntersectsWith(objPacman->getRectangle()))
			vecPacDots.erase(vecPacDots.begin() + i);
	return vecPacDots.size() > 0;
}
void Jugar::PosicionBunus()
{
	if ((clock() - tiempo) / CLOCKS_PER_SEC >= 10)
	{
		objBonus->Cambiar_Lugar();
		tiempo = clock();
	}
}
void Jugar::DuplicarVelocidad()
{
	if (objPacman->getRectangle().IntersectsWith(objBonus->getRectangle()))
	{
		objBonus->Cambiar_Lugar();
		objPacman->AumentarVelocidad();
	}
}
