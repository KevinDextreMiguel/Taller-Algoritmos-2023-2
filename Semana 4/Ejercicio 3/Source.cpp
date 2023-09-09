//#include"ArrCaracter.h"
#include"ArrAvion.h"
int main() {
	Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
	Console::CursorVisible = false;
	srand(time(0));
	int n = rand() % 3 + 3;
	ArrAvion* obj = new ArrAvion(n);
	//ArrCaracter* obj = new ArrCaracter();
	//
	//while (true)
	//{
	//	char tecla;
	//	if (_kbhit())
	//	{
	//		tecla = getch();
	//		if (tecla == '1')
	//			obj->agregar(new Caracter(1,0));
	//		else if (tecla == '2')
	//			obj->agregar(new Caracter(0, 1));
	//		else if (tecla == '3')
	//			obj->agregar(new Caracter(1, 1));
	//	}
	//	obj->mostrar_todo();
	//	_sleep(100);
	//}

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

