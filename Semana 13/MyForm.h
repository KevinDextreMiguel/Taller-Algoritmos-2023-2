#pragma once
#include"Jugar.h"
namespace Semana13 {

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
			g = CreateGraphics();
			Fondo = gcnew Bitmap("imagenes/Fondo.png");
			Personaje = gcnew Bitmap("imagenes/Personaje.png");
			Fantasma = gcnew Bitmap("imagenes/Fantasma.jpg");

			anchoForm = g->VisibleClipBounds.Width;
			altoForm = g->VisibleClipBounds.Height;

			int anchoPersonaje = Personaje->Width / 3;
			int altoPersonaje = Personaje->Height /4 ;
			int anchoFantasma = Fantasma->Width / 5;
			int altoFantasma = Fantasma->Height / 1;

			ObjJugar = new Jugar(anchoForm, altoForm, anchoPersonaje, altoPersonaje, anchoFantasma, altoFantasma);
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
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Jugar* ObjJugar;
		Bitmap^ Fondo;
		Bitmap^ Personaje;
		Bitmap^ Fantasma;
		Graphics^ g;
		int anchoForm, altoForm;
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
			this->ClientSize = System::Drawing::Size(889, 608);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		BufferedGraphicsContext^ ctx = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = ctx->Allocate(g, Rectangle(1, 1, anchoForm, altoForm));

		buffer->Graphics->DrawImage(Fondo, 0, 0, anchoForm, altoForm);

		ObjJugar->Dibujar(buffer->Graphics, Personaje);
		ObjJugar->MoverFantasmaYDibujar(buffer->Graphics, Fantasma);

		if (!ObjJugar->colision())
		{
			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
			Close();
			return;
		}
		if (!ObjJugar->Colision_Pacman_Pacdots())
		{
			timer1->Enabled = false;
			MessageBox::Show("Ganaste");
			Close();
			return;
		}
		ObjJugar->PosicionBunus();
		ObjJugar->DuplicarVelocidad();
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		ObjJugar->MoverPacman(g, e->KeyCode);
	}
};
}
