#pragma once
#include"Jugar.h"
namespace Semana12T {

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
			tiempo = clock();
			bmpHeroe = gcnew Bitmap("imagenes/Heroe.png");
			bmpEnemigo = gcnew Bitmap("imagenes/Enemigo.png");
			bmpFondo = gcnew Bitmap("imagenes/Fondo.png");
			objJugar = new Jugar(bmpHeroe->Width / 4, bmpHeroe->Height / 4);
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
		Bitmap^ bmpHeroe;
		Bitmap^ bmpEnemigo;
		Bitmap^ bmpFondo;
		Jugar* objJugar;
		clock_t tiempo;
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
			this->ClientSize = System::Drawing::Size(973, 561);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);
		int ancho = g->VisibleClipBounds.Width;
		int alto = g->VisibleClipBounds.Height;
		bf->Graphics->DrawImage(bmpFondo, 0, 0,ancho,alto);

		objJugar->moverTodo(g);
		objJugar->dibujarTodo(bf->Graphics, bmpHeroe, bmpEnemigo);
		objJugar->colision();
		objJugar->eliminarFueraFormulario(g);

		if ((clock() - tiempo) / CLOCKS_PER_SEC >= 3)
		{
			objJugar->generarEnemigo(bmpEnemigo->Width / 4, bmpEnemigo->Height / 4);
			tiempo = clock();
		}
		bf->Render(g);
		delete g, espacio, bf;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Graphics^ g = CreateGraphics();
		objJugar->mover_Heroe(g, e->KeyCode);
		delete g;	
	}
	private: System::Void MyForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		objJugar->generarBala();
	}
	};
}
