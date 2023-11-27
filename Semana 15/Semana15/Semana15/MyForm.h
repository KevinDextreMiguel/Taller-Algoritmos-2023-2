#pragma once
#include"Jugar.h"
#include"Reporte.h"
namespace Semana15 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			CmabiarImageb = true;
			tiempo = clock();

			g = CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(g, ClientRectangle);
			Fondo = gcnew Bitmap("imagenes/fondo.png");
			Animal = gcnew Bitmap("imagenes/animal.png");
			Tanque = gcnew Bitmap("imagenes/tanque.png");
			obj = new Jugar(Tanque->Width / 3, Tanque->Height / 4);
			for (int i = 0; i < 5; i++)
				obj->AgregarAnimal(Animal->Width / 3, Animal->Height / 4, Width, Height);

			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Graphics^ g;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ buffer;
		Bitmap^ Fondo;
		Bitmap^ Animal;
		Bitmap^ Tanque;
		Bitmap^ Heroe;
		Jugar* obj;
		clock_t tiempo;
		clock_t TiempoCambiar;

		bool CmabiarImageb;
		bool paraTiempo;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
		   /// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1064, 747);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->DrawImage(Fondo, 0, 0, Width, Height);
		

		obj->Colision();
		obj->dibujarTodos(buffer->Graphics, Tanque, Animal);
		obj->MoverTodos(g);

		if ((clock() - tiempo) / CLOCKS_PER_SEC >= 3)
		{
			obj->AgregarFuego();
			tiempo = clock();
		}

		if (obj->GetVida() == 0 || obj->GetPuntos() == 20)
		{
			timer1->Enabled = false;
			Reporte^ formR = gcnew Reporte(obj->GetVida(), obj->GetPuntos());
			formR->ShowDialog();

		}
		if ((clock() - TiempoCambiar) / CLOCKS_PER_SEC <= 5 && paraTiempo)
		{
			//if (paraTiempo)
			//{
				Tanque = gcnew Bitmap("imagenes/Heroe.png");
				obj->getTanque()->Setancho(Tanque->Width / 4);
				obj->getTanque()->Setancho(Tanque->Height / 4);
			//

				if ((clock() - TiempoCambiar) / CLOCKS_PER_SEC >= 5)paraTiempo = false;
		}
		else
		{
			Tanque = gcnew Bitmap("imagenes/tanque.png");
			obj->getTanque()->Setancho(Tanque->Width / 3);
			obj->getTanque()->Setancho(Tanque->Height / 4);
			TiempoCambiar = clock();
		}

		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		obj->MoverTanque(g, e->KeyCode);

		if (e->KeyCode == Keys::Space)
			obj->AgregarAgua();
		if (e->KeyCode == Keys::B)
		{
			if (CmabiarImageb) {
				Tanque = gcnew Bitmap("imagenes/Heroe.png");
				obj->getTanque()->Setancho(Tanque->Width / 4);
				obj->getTanque()->Setancho(Tanque->Height / 4);
			}
			else
			{
				Tanque = gcnew Bitmap("imagenes/tanque.png");
				obj->getTanque()->Setancho(Tanque->Width / 3);//objTanque
				obj->getTanque()->Setancho(Tanque->Height / 4);
			}
			CmabiarImageb= !CmabiarImageb;
		}
		//hacer con tiempo
		if (e->KeyCode == Keys::A)
		{
			paraTiempo = true;
			TiempoCambiar = clock();
		}
	}
	};
}
