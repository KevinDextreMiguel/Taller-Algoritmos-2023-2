#include"ArrAvion.h"
int main() {
	Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
	Console::CursorVisible = false;
	srand(time(0));
	int n = rand() % 3 + 3;

	obj->generar_Aviones();

	while (true)
	{
		obj->mostrar_todos();
		obj->volver_todos_y0();
		_sleep(300);
	}
	delete obj;

	return 0;
}

