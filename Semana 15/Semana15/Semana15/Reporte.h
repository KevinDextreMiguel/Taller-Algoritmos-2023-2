#pragma once

namespace Semana15 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Reporte
	/// </summary>
	public ref class Reporte : public System::Windows::Forms::Form
	{
	public:
		Reporte(int v,int p)
		{
			InitializeComponent();
			puntos = p;
			vida = v;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Reporte()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelPuntos;
	protected:

	protected:

	private: System::Windows::Forms::Label^ labelVida;
	private: System::Windows::Forms::Label^ label4;


	private:
		int puntos, vida;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelPuntos = (gcnew System::Windows::Forms::Label());
			this->labelVida = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelPuntos
			// 
			this->labelPuntos->AutoSize = true;
			this->labelPuntos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPuntos->Location = System::Drawing::Point(240, 228);
			this->labelPuntos->Name = L"labelPuntos";
			this->labelPuntos->Size = System::Drawing::Size(267, 31);
			this->labelPuntos->TabIndex = 1;
			this->labelPuntos->Text = L"Cantidad de Puntos: ";
			// 
			// labelVida
			// 
			this->labelVida->AutoSize = true;
			this->labelVida->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelVida->Location = System::Drawing::Point(240, 130);
			this->labelVida->Name = L"labelVida";
			this->labelVida->Size = System::Drawing::Size(246, 31);
			this->labelVida->TabIndex = 2;
			this->labelVida->Text = L"Cantidad de vidas: ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Blue;
			this->label4->Location = System::Drawing::Point(279, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(111, 31);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Reporte";
			// 
			// Reporte
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(758, 542);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->labelVida);
			this->Controls->Add(this->labelPuntos);
			this->Name = L"Reporte";
			this->Text = L"Reporte";
			this->Load += gcnew System::EventHandler(this, &Reporte::Reporte_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Reporte_Load(System::Object^ sender, System::EventArgs^ e) {
		labelVida->Text += vida;
		labelPuntos->Text += puntos;	
	}
};
}
