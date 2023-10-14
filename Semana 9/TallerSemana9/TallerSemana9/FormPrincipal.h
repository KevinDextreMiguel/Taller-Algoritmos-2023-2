#pragma once
#include"MyForm.h"
namespace TallerSemana9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormPrincipal
	/// </summary>
	public ref class FormPrincipal : public System::Windows::Forms::Form
	{
	public:
		FormPrincipal(void)
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
		~FormPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonEmpezar;
	private: System::Windows::Forms::Button^ buttonActivar;
	protected:

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
			this->buttonEmpezar = (gcnew System::Windows::Forms::Button());
			this->buttonActivar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonEmpezar
			// 
			this->buttonEmpezar->BackColor = System::Drawing::Color::Lime;
			this->buttonEmpezar->Location = System::Drawing::Point(289, 218);
			this->buttonEmpezar->Name = L"buttonEmpezar";
			this->buttonEmpezar->Size = System::Drawing::Size(130, 98);
			this->buttonEmpezar->TabIndex = 0;
			this->buttonEmpezar->Text = L"Empezar a Jugar";
			this->buttonEmpezar->UseVisualStyleBackColor = false;
			this->buttonEmpezar->Visible = false;
			this->buttonEmpezar->Click += gcnew System::EventHandler(this, &FormPrincipal::buttonEmpezar_Click);
			// 
			// buttonActivar
			// 
			this->buttonActivar->BackColor = System::Drawing::Color::Red;
			this->buttonActivar->Location = System::Drawing::Point(159, 87);
			this->buttonActivar->Name = L"buttonActivar";
			this->buttonActivar->Size = System::Drawing::Size(130, 98);
			this->buttonActivar->TabIndex = 1;
			this->buttonActivar->Text = L"Activar button jugar";
			this->buttonActivar->UseVisualStyleBackColor = false;
			this->buttonActivar->Click += gcnew System::EventHandler(this, &FormPrincipal::buttonActivar_Click);
			// 
			// FormPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(493, 376);
			this->Controls->Add(this->buttonActivar);
			this->Controls->Add(this->buttonEmpezar);
			this->Name = L"FormPrincipal";
			this->Text = L"FormPrincipal";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonEmpezar_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ form = gcnew MyForm();
		form->ShowDialog();
	}
	private: System::Void buttonActivar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->buttonEmpezar->Visible = true;
	}
	};
}
