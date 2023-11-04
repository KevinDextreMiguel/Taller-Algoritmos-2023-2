#include "MyForm1.h"
using namespace Semana12T;
int main()
{
	MyForm^ form = gcnew MyForm();
	form->ShowDialog();
	//Application::Run(form);
	return 0;
}
