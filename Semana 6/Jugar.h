#pragma once
#include"Bicicleta.h"
#include"Bus.h"
#include"Carro.h"
#include"Persona.h"

class Jugar
{
public:
	Jugar();
	~Jugar();
	void dibujar_todos();
	void borrar_todos();
	void mover_todos();
	void direccion_persona(char tecla);
	bool colision_objetos();
private:
	vector<Terrestre*> terrestres;
	Persona *obj;
};

Jugar::Jugar()
{
	obj = new Persona();
	terrestres.push_back(new Bus());
	terrestres.push_back(new Carro());
	terrestres.push_back(new Bicicleta());
}

Jugar::~Jugar()
{
	delete obj;
}
void Jugar::dibujar_todos()
{
	obj->dibujar();
	for (int i = 0; i < terrestres.size(); i++)
		terrestres.at(i)->dibujar();
}
void Jugar::borrar_todos()
{
	obj->borrar();
	for (int i = 0; i < terrestres.size(); i++)
		terrestres[i]->borrar();
}
void Jugar::mover_todos()
{
	obj->mover();
	for (int i = 0; i< terrestres.size(); i++)
		terrestres[i]->mover();
}

void Jugar::direccion_persona(char tecla)
{
	switch (tecla)
	{
	case 75:
		obj->set_dx_dy(-1, 0); break;
	case 72:
		obj->set_dx_dy(0,-1); break;
	case 77:
		obj->set_dx_dy(1,0); break;
	case 80:
		obj->set_dx_dy(0,1);
	}
}
bool Jugar::colision_objetos()
{
	for (int i = 0; i < terrestres.size(); i++)
		if (terrestres.at(i)->colision(obj->get_x(), obj->get_y(),
			obj->get_ancho(), obj->get_alto()))
			obj->set_terminar(false);

	return obj->get_terminar();
}


