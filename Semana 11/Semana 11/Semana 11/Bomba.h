#pragma once
#include<iostream>
using namespace System::Drawing;//Sistema dibujo
class Bomba
{
public:
    Bomba();
    ~Bomba();
    void dibujar(Graphics^ g);//gr�fico
    void mover();
    Rectangle getRectangle();//Rect�ngulo
private:
    int x, y;
    int diametro;
    int dy;
};
Bomba::Bomba()
{
    x = rand() % 900;
    y = 0;
    dy = 10;
    diametro = 50;
}
Bomba::~Bomba() {}
void Bomba::dibujar(Graphics^ g)
{
    //Pincel S�lido
    SolidBrush^ b = gcnew SolidBrush(Color::Black);
    //Rellenar Elipse
    g->FillEllipse(b, x, y, diametro, diametro);
}
void Bomba::mover()
{
    y += dy;
}
Rectangle Bomba::getRectangle()
{
    return Rectangle(x, y, diametro, diametro);
}