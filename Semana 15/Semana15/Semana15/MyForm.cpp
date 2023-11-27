#include "MyForm.h"
using namespace Semana15;
int main()
{
	srand(time(0));
	MyForm^ form = gcnew MyForm();
	form->ShowDialog();
	return 0;
}
