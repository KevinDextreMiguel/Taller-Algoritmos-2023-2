#pragma once
#include"FormJugar.h"
namespace Project1 {

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
	private: System::Windows::Forms::Button^ buttonJugor;
	protected:
	private: System::Windows::Forms::Button^ buttonSalir;

	private:
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
			this->buttonJugor = (gcnew System::Windows::Forms::Button());
			this->buttonSalir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonJugor
			// 
			this->buttonJugor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->buttonJugor->Location = System::Drawing::Point(193, 136);
			this->buttonJugor->Name = L"buttonJugor";
			this->buttonJugor->Size = System::Drawing::Size(94, 58);
			this->buttonJugor->TabIndex = 0;
			this->buttonJugor->Text = L"Jugar";
			this->buttonJugor->UseVisualStyleBackColor = false;
			this->buttonJugor->Click += gcnew System::EventHandler(this, &MyFormPrincipal::buttonJugor_Click);
			// 
			// buttonSalir
			// 
			this->buttonSalir->BackColor = System::Drawing::Color::Red;
			this->buttonSalir->Location = System::Drawing::Point(277, 259);
			this->buttonSalir->Name = L"buttonSalir";
			this->buttonSalir->Size = System::Drawing::Size(102, 54);
			this->buttonSalir->TabIndex = 1;
			this->buttonSalir->Text = L"Salir";
			this->buttonSalir->UseVisualStyleBackColor = false;
			this->buttonSalir->Click += gcnew System::EventHandler(this, &MyFormPrincipal::buttonSalir_Click);
			// 
			// MyFormPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(430, 338);
			this->Controls->Add(this->buttonSalir);
			this->Controls->Add(this->buttonJugor);
			this->Name = L"MyFormPrincipal";
			this->Text = L"MyFormPrincipal";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonJugor_Click(System::Object^ sender, System::EventArgs^ e) {
		FormJugar^ form= gcnew FormJugar();
		form->ShowDialog();
	}
	private: System::Void buttonSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
