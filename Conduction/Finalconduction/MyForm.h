#pragma once

# include "MyForm2.h"

//# include "afxwin.h"
# include <cstring>
#include <fstream>
#include <iostream>
namespace Finalconduction {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		int cb1 = 0, cb2 = 0, cb3 = 0, option = -1, number_division = -1, material_index = -1, bc1 = -1, bc2 = -1, isnonuniform = -1, count = -1;
		//String ^material, ^bc1,^bc2;
		double nonuniform_coefficient = -1, convergence_criterion = -1, heat_per_volume = -1, Length = -1, Initial_temp = -1;
	private: System::Windows::Forms::Label^  label8;
	public:
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  textBox6;

	public:

		MyForm()
		{
			InitializeComponent();



			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(156, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Material";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Aluminium", L"Copper", L"Mild Steel" });
			this->comboBox1->Location = System::Drawing::Point(259, 39);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			this->comboBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox1_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(84, 151);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Boundary Condition1";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Insulated", L"Constant Temperature", L"Convection",
					L"Constant Heat Flux"
			});
			this->comboBox2->Location = System::Drawing::Point(259, 146);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 3;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			this->comboBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox2_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(86, 183);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(130, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Boundary condition2";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Insulated", L"Constant temperature", L"Convection",
					L"Constant heatflux"
			});
			this->comboBox3->Location = System::Drawing::Point(259, 178);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 5;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox3_SelectedIndexChanged);
			this->comboBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox3_KeyPress);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(259, 76);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(97, 76);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Number of division";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(259, 316);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(79, 205);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(139, 16);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Convergence criterion";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(259, 205);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(121, 20);
			this->textBox2->TabIndex = 10;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox2_KeyPress);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(22, 231);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(194, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"heat generation per unit volume";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(259, 231);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(121, 20);
			this->textBox3->TabIndex = 12;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox3_KeyPress);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(75, 124);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(143, 16);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Non-uniform coefficient";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(259, 120);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(121, 20);
			this->textBox4->TabIndex = 15;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox4_KeyPress);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(168, 261);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(48, 16);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Length";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(103, 291);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(113, 16);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Initial temperature";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(259, 261);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(121, 20);
			this->textBox5->TabIndex = 19;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox5_KeyPress);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(259, 290);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(121, 20);
			this->textBox6->TabIndex = 20;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox6_KeyPress);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(78, 104);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(83, 17);
			this->checkBox1->TabIndex = 21;
			this->checkBox1->Text = L"Non-uniform";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(416, 351);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


	//	if (material_index == -1 && number_division == -1 && bc1 == -1 && bc2 == -1 && convergence_criterion == -1 && heat_per_volume == -1 && Length == -1 && Initial_temp == -1)
	//	{
			ofstream outfile;
			//outfile.open("User_Input.txt", ios::trunc | ios::out);//delete at end
			outfile.open("User_Input.txt", ios::trunc | ios::out);
			outfile << "1" << '\n';
			outfile << material_index << '\n';
			outfile << number_division << '\n';
			if (isnonuniform == 1)
			{
				outfile << nonuniform_coefficient << '\n';

			}

			else
			{
				outfile << -1 << '\n';
			}
			outfile << bc1 << '\n';
			outfile << bc2 << '\n';
			outfile << convergence_criterion << '\n';
			outfile << heat_per_volume << '\n';
			outfile << Length << '\n';
			outfile << Initial_temp << '\n';





			outfile.close();



			//ComboBox *combo = (CComboBox*)GetDlgItem(IDC_COMBO1);
			//int index = combo->GetCurSel();
			//CString s;
			//combo->GetLBText(index, s);
		this->Hide();


			MyForm2^ f2 = gcnew MyForm2();
			f2->ShowDialog();

		//}
	//	else
	//	{
	//		MessageBox::Show("Please enter all the inputs");
	//	}



	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox1->SelectedIndex == 0)
		{
			material_index = 0;

		}


		else if (comboBox1->SelectedIndex == 1)
		{
			material_index = 1;



		}

		else if (comboBox1->SelectedIndex == 2)
		{
			material_index = 2;

		}

		else
		{

			MessageBox::Show("pleaser choose one material");
		}





	}
	private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (count == -1)
		{
			isnonuniform = -1; nonuniform_coefficient = -1;
			textBox4->Text = "Not required";
			textBox4->ReadOnly = true;

		}
		else
		{
			isnonuniform = 1;
			nonuniform_coefficient = Int32::Parse(textBox4->Text);


		}



	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		option = comboBox2->SelectedIndex;
		if (comboBox2->SelectedIndex == 0)
		{
			bc1 = 0;
		}
		else if (comboBox2->SelectedIndex == 1)
		{
			bc1 = 1;
		}
		else if (comboBox2->SelectedIndex == 2)
		{
			bc1 = 2;
		}
		else if (comboBox2->SelectedIndex == 3)
		{
			bc1 = 3;
		}





	}
	private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox3->SelectedIndex == 0)
		{
			bc2 = 0;
		}
		else if (comboBox3->SelectedIndex == 1)
		{
			bc2 = 1;
		}
		else if (comboBox3->SelectedIndex == 2)
		{
			bc2 = 2;
		}
		else if (comboBox3->SelectedIndex == 3)
		{
			bc2 = 3;
		}



	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {


		if (this->textBox1->Text->Length != 0)
		{
			if (textBox1->Text != "-")
			{
				number_division = Int32::Parse(textBox1->Text);
			}

		}





	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {





		if (this->textBox2->Text->Length != 0)
		{
			if (textBox2->Text != "-")
			{
				convergence_criterion = Double::Parse(textBox2->Text);
			}

		}

	}
	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {


		if (this->textBox3->Text->Length != 0)
		{
			if (textBox3->Text != "-")
			{
				heat_per_volume = Double::Parse(textBox3->Text);
			}

		}

	}

	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {


		if (this->textBox5->Text->Length != 0)
		{
			if (textBox5->Text != "-")
			{
				Length = Double::Parse(textBox5->Text);
			}

		}


	}
	private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		//Initial_temp = Double::Parse(textBox6->Text);
		if (this->textBox6->Text->Length != 0)
		{
			if (textBox6->Text != "-")
			{
				Initial_temp = Double::Parse(textBox6->Text);
			}

		}

	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		count++;
	}
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		if (e->KeyChar == '.') {
			if (this->textBox1->Text->Contains(".") && !this->textBox1->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox4_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBox4->Text->Contains(".") && !this->textBox4->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == '.') {
			if (this->textBox2->Text->Contains(".") && !this->textBox2->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox3_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBox3->Text->Contains(".") && !this->textBox3->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox5_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBox5->Text->Contains(".") && !this->textBox5->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox6_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBox6->Text->Contains(".") && !this->textBox6->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void comboBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		e->Handled = true;

	}
	private: System::Void comboBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		e->Handled = true;

	}
	private: System::Void comboBox3_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		e->Handled = true;

	}
	};
}
