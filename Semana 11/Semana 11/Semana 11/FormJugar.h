#pragma once
#include"Jugar.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormJugar
	/// </summary>
	public ref class FormJugar : public System::Windows::Forms::Form
	{
	public:
		FormJugar(void)
		{
			InitializeComponent();

			srand(time(0));
			tiempo = clock();
			g = CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, ClientRectangle);
			//							carpeta / nombre imagen
			bmpPersonaje = gcnew Bitmap("imagenes/Personaje.png");
			bmpFondo = gcnew Bitmap("imagenes/Fondo.png");
			objJugar = new Jugar(bmpPersonaje->Width/4, bmpPersonaje->Height/4);
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormJugar()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Jugar* objJugar;
		clock_t tiempo;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpPersonaje;
		Bitmap^ bmpFondo;
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
			this->timer1->Tick += gcnew System::EventHandler(this, &FormJugar::timer1_Tick);
			// 
			// FormJugar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1044, 483);
			this->Name = L"FormJugar";
			this->Text = L"FormJugar";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormJugar::FormJugar_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->DrawImage(bmpFondo, 0, 0, bmpFondo->Width*2, bmpFondo->Height*1.2);
		objJugar->moverTodos();
		objJugar->dibujarTodos(buffer->Graphics, bmpPersonaje);

		if ((clock() - tiempo) / CLOCKS_PER_SEC >= 1)
		{
			objJugar->GenerarBomba();
			tiempo=clock();
		}

		if (objJugar->colision())
		{
			timer1->Enabled = false;
			MessageBox::Show("Te elimianron");
		}

		buffer->Render(g);
	}

	private: System::Void FormJugar_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		objJugar->moverPersonaje(g, e->KeyCode);
	}
	};
}
