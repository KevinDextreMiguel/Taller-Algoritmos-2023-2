#pragma once
#include"Agua.h"
#include"Animal.h"
#include"Fuego.h"
#include"Tanque.h"
class Jugar
{
private:
	Tanque* objTanque;
	vector<Animal*>animales;
	vector<Fuego*>fuegos;
	vector<Agua*>aguas;
	int cont;
public:
	Jugar(int _ancho,int _alto)
	{
		objTanque = new Tanque(_ancho,_alto);
		cont = 0;
	}
	~Jugar()
	{

	}
	void MoverTanque(Graphics^ g, Keys tecla)
	{
			objTanque->mover(g, tecla);
	}
	void dibujarTodos(Graphics^ g,Bitmap^ bmpTanque,Bitmap^ bmpanimales)
	{
		objTanque->dibujar(g, bmpTanque);

		for (int i = 0; i < animales.size(); i++)
			animales.at(i)->dibujar(g,bmpanimales);
		for (int i = 0; i < fuegos.size(); i++)
			fuegos.at(i)->dibujar(g);
		for (int i = 0; i < aguas.size(); i++)
			aguas.at(i)->dibujar(g);
	}

	void MoverTodos(Graphics^ g)
	{
		for (int i = 0; i < animales.size(); i++)
			animales.at(i)->mover(g);
		for (int i = 0; i < fuegos.size(); i++)
			fuegos.at(i)->mover(g);
		for (int i = 0; i < aguas.size(); i++)
			aguas.at(i)->mover(g);
	}

	void AgregarFuego()
	{
		fuegos.push_back(new Fuego());
	}

	void AgregarAgua()
	{
		aguas.push_back(new Agua(objTanque->Getdireccion(),
			objTanque->Getx(), objTanque->Gety()));
	}
	void AgregarAnimal(int _ancho, int _alto, int _anchoF, int _altoF)
	{
		//int _ancho,int _alto, int _anchoF, int _altoF,int _dx,int _dy
		int dx, dy;
		if (cont % 2 == 0)
		{
			dx = 3; dy = 0;
		}
		else
		{
			dx = 0; dy = 3;
		}
		cont++;
		animales.push_back(new Animal(_ancho, _alto, _anchoF, _altoF, dx, dy));
	}

	void Colision()
	{
		//verificar
		for (int i = 0; i < fuegos.size(); i++)
			for (int j = 0; j < aguas.size(); j++)
				if (fuegos.at(i)->GetRectangle().IntersectsWith(
					aguas.at(j)->GetRectangle()))
				{
					fuegos.at(i)->SetVisible(false);
					aguas.at(j)->SetVisible(false);
					objTanque->Setpuntos(5);
				}

		for (int i = 0; i < fuegos.size(); i++)
			if (fuegos.at(i)->GetRectangle().IntersectsWith(objTanque->GetRectangle()))
				objTanque->Setvida(-1);
		
		//eliminar
		for (int i = 0; i < fuegos.size(); i++)
			if (!fuegos.at(i)->GetVisible())
				fuegos.erase(fuegos.begin() + i);

		for (int i = 0; i < aguas.size(); i++)
			if (!aguas.at(i)->GetVisible())
				aguas.erase(aguas.begin() + i);

	}

	int GetPuntos() {return  objTanque->Getpuntos(); }
	int GetVida() {return objTanque->Getvida(); }

	Tanque* getTanque() { return objTanque; }
};
