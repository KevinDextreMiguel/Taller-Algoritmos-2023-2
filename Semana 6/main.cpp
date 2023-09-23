#include<conio.h>
#include"Jugar.h"

void main()
{
	srand(time(NULL));
	Console::CursorVisible = false;
	Jugar* obj = new Jugar();
	char tecla;
	while (obj->colision_objetos())
	{
		if (_kbhit())
			tecla = getch();
		obj->borrar_todos();
		obj->mover_todos();
		obj->dibujar_todos();
		obj->direccion_persona(tecla);
		_sleep(100);
	}
	
	Console::Clear();
	Console::SetCursorPosition(50, 15);
	cout << "Tener cuidado al cruzar la pista!!";
	delete obj;

	getch();
	getch();
}


