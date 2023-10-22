#pragma once
#include"Jugar.h"
#include<time.h>
namespace TallerSemana10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyFormPrincipal
	/// </summary>
	public ref class MyFormPrincipal : public System::Windows::Forms::Form
	{
	public:
		MyFormPrincipal(void)
		{
			InitializeComponent();
			srand(time(0));
			g = CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, ClientRectangle);
			obj = new Jugar(g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyFormPrincipal()
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
		Jugar* obj;
		Graphics^ g;
		BufferedGraphicsContext^ space; 
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelContador;
	private: System::Windows::Forms::Label^ labelM3;
	private: System::Windows::Forms::Label^ labelM2;
	private: System::Windows::Forms::Label^ labelM1;

		   BufferedGraphics^ buffer;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelContador = (gcnew System::Windows::Forms::Label());
			this->labelM3 = (gcnew System::Windows::Forms::Label());
			this->labelM2 = (gcnew System::Windows::Forms::Label());
			this->labelM1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyFormPrincipal::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(1294, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"META";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(139, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Cantidad de Competiciones:";
			// 
			// labelContador
			// 
			this->labelContador->AutoSize = true;
			this->labelContador->Location = System::Drawing::Point(169, 9);
			this->labelContador->Name = L"labelContador";
			this->labelContador->Size = System::Drawing::Size(13, 13);
			this->labelContador->TabIndex = 2;
			this->labelContador->Text = L"0";
			// 
			// labelM3
			// 
			this->labelM3->AutoSize = true;
			this->labelM3->Location = System::Drawing::Point(12, 448);
			this->labelM3->Name = L"labelM3";
			this->labelM3->Size = System::Drawing::Size(139, 13);
			this->labelM3->TabIndex = 3;
			this->labelM3->Text = L"";
			// 
			// labelM2
			// 
			this->labelM2->AutoSize = true;
			this->labelM2->Location = System::Drawing::Point(12, 412);
			this->labelM2->Name = L"labelM2";
			this->labelM2->Size = System::Drawing::Size(139, 13);
			this->labelM2->TabIndex = 4;
			this->labelM2->Text = L"";
			// 
			// labelM1
			// 
			this->labelM1->AutoSize = true;
			this->labelM1->Location = System::Drawing::Point(12, 384);
			this->labelM1->Name = L"labelM1";
			this->labelM1->Size = System::Drawing::Size(139, 13);
			this->labelM1->TabIndex = 5;
			this->labelM1->Text = L"";
			// 
			// MyFormPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1424, 533);
			this->Controls->Add(this->labelM1);
			this->Controls->Add(this->labelM2);
			this->Controls->Add(this->labelM3);
			this->Controls->Add(this->labelContador);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyFormPrincipal";
			this->Text = L"MyFormPrincipal";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//borrar
		buffer->Graphics->Clear(Color::White);

		obj->moverTodo();
		obj->dibujarTodo(buffer->Graphics);
		obj->dibujarMeta(buffer->Graphics);
		obj->analizarMeta();
		this->labelContador->Text = "" + obj->getcantidadCompetencias();
		obj->ordenarVector();

		labelM1->Text = "1: " + gcnew String(obj->GetNombre(0).c_str())+" "+obj->getPuntos(0);
		labelM2->Text = "2: " + gcnew String(obj->GetNombre(1).c_str())+" "+obj->getPuntos(1);
		labelM3->Text = "3: " + gcnew String(obj->GetNombre(2).c_str())+" "+obj->getPuntos(2);
		buffer->Render(g);
		if (obj->getcantidadCompetencias() == 10)
		{		
			this->timer1->Enabled = false;
			MessageBox::Show("Ya hubo 10 competencias");
			this->Close();
		}

		
	}
	};
}
