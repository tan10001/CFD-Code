#pragma once
#include "MyForm.h"  //will cause error
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>

namespace Finalconduction {

	using namespace System::IO;
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
		//extern int option;
		int count1 = 0, count2 = 0, is_one_d = 0;
	public:int material = -1, no_of_divisions = -1, bc1 = -1, bc2 = -1;
	public: double beta = -1, converge = -1, heatpervol = -1, heatflux_1 = -1, heatflux_2 = -1, convec_coefficient_1 = -1, convec_coefficient_2 = -1, temp1 = -1, temp2 = -1, Tempinfinty_1 = -1, Tempinfinty_2 = -1, Length = -1, Initial_temp = -1;
			MyForm2(void)
			{
				ifstream in;
				in.open("User_Input.txt");
				std::string name;
				int n;
				double d;
				in >> n;
				is_one_d = n;
				in >> n;
				material = n;
				in >> n;
				no_of_divisions = n;
				in >> d;
				beta = d;
				in >> n;
				bc1 = n;
				in >> n;
				bc2 = n;
				in >> d;
				converge = d;
				in >> d;
				heatpervol = d;
				in >> d;
				Length = d;
				in >> d;
				Initial_temp = d;





				//std::cout << "Please, enter your full name: ";
				//getline(in, name);
				//int bar = System::Convert::ToInt32(count1);

				//int c1 = stoi(count1);
				//int c2 = stoi(count2);
				InitializeComponent();
				//if (comboBox1->SelectedIndex == 0)
				//
				//TODO: Add the constructor code here
				//
			}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labela;
	private: System::Windows::Forms::Label^  labelc;
	private: System::Windows::Forms::Label^  labele;
	protected:



	private: System::Windows::Forms::TextBox^  textBoxa;
	private: System::Windows::Forms::TextBox^  textBoxc;
	private: System::Windows::Forms::TextBox^  textBoxe;
	private: System::Windows::Forms::Label^  labelg;



	protected:

	protected:






	private: System::Windows::Forms::TextBox^  textBoxg;

	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Label^  label52;
	private: System::Windows::Forms::TextBox^  textBoxb;
	private: System::Windows::Forms::Label^  labelb;


	private: System::Windows::Forms::TextBox^  textBoxd;
	private: System::Windows::Forms::Label^  labeld;
	private: System::Windows::Forms::Label^  labelf;



	private: System::Windows::Forms::TextBox^  textBoxf;
	private: System::Windows::Forms::Label^  labelh;


	private: System::Windows::Forms::TextBox^  textBoxh;






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
			this->labela = (gcnew System::Windows::Forms::Label());
			this->labelc = (gcnew System::Windows::Forms::Label());
			this->labele = (gcnew System::Windows::Forms::Label());
			this->textBoxa = (gcnew System::Windows::Forms::TextBox());
			this->textBoxc = (gcnew System::Windows::Forms::TextBox());
			this->textBoxe = (gcnew System::Windows::Forms::TextBox());
			this->labelg = (gcnew System::Windows::Forms::Label());
			this->textBoxg = (gcnew System::Windows::Forms::TextBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->textBoxb = (gcnew System::Windows::Forms::TextBox());
			this->labelb = (gcnew System::Windows::Forms::Label());
			this->textBoxd = (gcnew System::Windows::Forms::TextBox());
			this->labeld = (gcnew System::Windows::Forms::Label());
			this->labelf = (gcnew System::Windows::Forms::Label());
			this->textBoxf = (gcnew System::Windows::Forms::TextBox());
			this->labelh = (gcnew System::Windows::Forms::Label());
			this->textBoxh = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// labela
			// 
			this->labela->AutoSize = true;
			this->labela->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labela->Location = System::Drawing::Point(36, 80);
			this->labela->Name = L"labela";
			this->labela->Size = System::Drawing::Size(93, 16);
			this->labela->TabIndex = 0;
			this->labela->Text = L"Temperature1";
			// 
			// labelc
			// 
			this->labelc->AutoSize = true;
			this->labelc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelc->Location = System::Drawing::Point(66, 135);
			this->labelc->Name = L"labelc";
			this->labelc->Size = System::Drawing::Size(63, 16);
			this->labelc->TabIndex = 1;
			this->labelc->Text = L"T infinity1";
			// 
			// labele
			// 
			this->labele->AutoSize = true;
			this->labele->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labele->Location = System::Drawing::Point(5, 193);
			this->labele->Name = L"labele";
			this->labele->Size = System::Drawing::Size(124, 16);
			this->labele->TabIndex = 2;
			this->labele->Text = L"Convec coefficient1";
			// 
			// textBoxa
			// 
			this->textBoxa->Location = System::Drawing::Point(152, 80);
			this->textBoxa->Name = L"textBoxa";
			this->textBoxa->Size = System::Drawing::Size(100, 20);
			this->textBoxa->TabIndex = 3;
			this->textBoxa->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBoxa_TextChanged);
			this->textBoxa->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm2::textBoxa_KeyPress);
			// 
			// textBoxc
			// 
			this->textBoxc->Location = System::Drawing::Point(152, 131);
			this->textBoxc->Name = L"textBoxc";
			this->textBoxc->Size = System::Drawing::Size(100, 20);
			this->textBoxc->TabIndex = 4;
			this->textBoxc->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBoxc_TextChanged);
			this->textBoxc->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm2::textBoxc_KeyPress);
			// 
			// textBoxe
			// 
			this->textBoxe->Location = System::Drawing::Point(152, 192);
			this->textBoxe->Name = L"textBoxe";
			this->textBoxe->Size = System::Drawing::Size(100, 20);
			this->textBoxe->TabIndex = 5;
			this->textBoxe->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBoxe_TextChanged);
			this->textBoxe->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm2::textBoxe_KeyPress);
			// 
			// labelg
			// 
			this->labelg->AutoSize = true;
			this->labelg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelg->Location = System::Drawing::Point(66, 246);
			this->labelg->Name = L"labelg";
			this->labelg->Size = System::Drawing::Size(63, 16);
			this->labelg->TabIndex = 6;
			this->labelg->Text = L"heat flux1";
			this->labelg->Click += gcnew System::EventHandler(this, &MyForm2::label42_Click);
			// 
			// textBoxg
			// 
			this->textBoxg->Location = System::Drawing::Point(152, 246);
			this->textBoxg->Name = L"textBoxg";
			this->textBoxg->Size = System::Drawing::Size(100, 20);
			this->textBoxg->TabIndex = 7;
			this->textBoxg->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBoxg_TextChanged);
			this->textBoxg->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm2::textBoxg_KeyPress);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(152, 310);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 23);
			this->button12->TabIndex = 8;
			this->button12->Text = L"OK";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm2::button12_Click);
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label52->Location = System::Drawing::Point(121, 22);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(148, 20);
			this->label52->TabIndex = 9;
			this->label52->Text = L"Input Parameters";
			// 
			// textBoxb
			// 
			this->textBoxb->Location = System::Drawing::Point(152, 105);
			this->textBoxb->Name = L"textBoxb";
			this->textBoxb->Size = System::Drawing::Size(100, 20);
			this->textBoxb->TabIndex = 10;
			this->textBoxb->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBoxb_TextChanged);
			this->textBoxb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm2::textBoxb_KeyPress);
			// 
			// labelb
			// 
			this->labelb->AutoSize = true;
			this->labelb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelb->Location = System::Drawing::Point(36, 105);
			this->labelb->Name = L"labelb";
			this->labelb->Size = System::Drawing::Size(93, 16);
			this->labelb->TabIndex = 11;
			this->labelb->Text = L"Temperature2";
			// 
			// textBoxd
			// 
			this->textBoxd->Location = System::Drawing::Point(152, 165);
			this->textBoxd->Name = L"textBoxd";
			this->textBoxd->Size = System::Drawing::Size(100, 20);
			this->textBoxd->TabIndex = 12;
			this->textBoxd->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBoxd_TextChanged);
			this->textBoxd->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm2::textBoxd_KeyPress);
			// 
			// labeld
			// 
			this->labeld->AutoSize = true;
			this->labeld->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labeld->Location = System::Drawing::Point(66, 165);
			this->labeld->Name = L"labeld";
			this->labeld->Size = System::Drawing::Size(63, 16);
			this->labeld->TabIndex = 13;
			this->labeld->Text = L"T infinity2";
			// 
			// labelf
			// 
			this->labelf->AutoSize = true;
			this->labelf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelf->Location = System::Drawing::Point(5, 220);
			this->labelf->Name = L"labelf";
			this->labelf->Size = System::Drawing::Size(124, 16);
			this->labelf->TabIndex = 14;
			this->labelf->Text = L"Convec coefficient2";
			this->labelf->Click += gcnew System::EventHandler(this, &MyForm2::label3_Click);
			// 
			// textBoxf
			// 
			this->textBoxf->Location = System::Drawing::Point(152, 216);
			this->textBoxf->Name = L"textBoxf";
			this->textBoxf->Size = System::Drawing::Size(100, 20);
			this->textBoxf->TabIndex = 15;
			this->textBoxf->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBoxf_TextChanged);
			this->textBoxf->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm2::textBoxf_KeyPress);
			// 
			// labelh
			// 
			this->labelh->AutoSize = true;
			this->labelh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelh->Location = System::Drawing::Point(66, 285);
			this->labelh->Name = L"labelh";
			this->labelh->Size = System::Drawing::Size(63, 16);
			this->labelh->TabIndex = 16;
			this->labelh->Text = L"heat flux2";
			// 
			// textBoxh
			// 
			this->textBoxh->Location = System::Drawing::Point(152, 281);
			this->textBoxh->Name = L"textBoxh";
			this->textBoxh->Size = System::Drawing::Size(100, 20);
			this->textBoxh->TabIndex = 17;
			this->textBoxh->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBoxh_TextChanged);
			this->textBoxh->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm2::textBoxh_KeyPress);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 364);
			this->Controls->Add(this->textBoxh);
			this->Controls->Add(this->labelh);
			this->Controls->Add(this->textBoxf);
			this->Controls->Add(this->labelf);
			this->Controls->Add(this->labeld);
			this->Controls->Add(this->textBoxd);
			this->Controls->Add(this->labelb);
			this->Controls->Add(this->textBoxb);
			this->Controls->Add(this->label52);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->textBoxg);
			this->Controls->Add(this->labelg);
			this->Controls->Add(this->textBoxe);
			this->Controls->Add(this->textBoxc);
			this->Controls->Add(this->textBoxa);
			this->Controls->Add(this->labele);
			this->Controls->Add(this->labelc);
			this->Controls->Add(this->labela);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {


		ofstream outfile;
		outfile.open("User_Input2.txt", ios::trunc | ios::out);
		//outfile << material << '\n';
		//outfile << no_of_divisions << '\n';
		//outfile << beta << '\n';
		outfile << temp1 << '\n';
		outfile << temp2 << '\n';
		outfile << Tempinfinty_1 << '\n';
		outfile << Tempinfinty_2 << '\n';
		outfile << convec_coefficient_1 << '\n';
		outfile << convec_coefficient_2 << '\n';

		outfile << heatflux_1 << '\n';
		outfile << heatflux_2 << '\n';
		//	outfile << Length << '\n';
		//	outfile << Initial_temp << '\n';

		Process::Start("Conduction.exe");


		outfile.close();

		Application::Exit();
	}


	private: System::Void textBoxa_TextChanged(System::Object^  sender, System::EventArgs^  e) {








		if (bc1 != 1)
		{
			textBoxa->Text = "Not Required";
			textBoxa->ReadOnly = true;
		}
		else
		{
			textBoxa->ReadOnly = false;
			if (this->textBoxa->Text->Length != 0)
			{
				if (textBoxa->Text != "-")
				{
					temp1 = Double::Parse(textBoxa->Text);
				}

			}


		}



	}
	private: System::Void label42_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBoxb_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc2 != 1)
		{
			textBoxb->Text = "Not Required";
			textBoxb->ReadOnly = true;
		}
		else
		{


			textBoxb->ReadOnly = false;
			if (this->textBoxb->Text->Length != 0)
			{
				if (textBoxb->Text != "-")
				{
					temp2 = Double::Parse(textBoxb->Text);
				}

			}




		}


	}
	private: System::Void textBoxc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc1 != 2)
		{
			textBoxc->Text = "Not Required";
			textBoxc->ReadOnly = true;
		}
		else
		{
			textBoxc->ReadOnly = false;
			if (this->textBoxc->Text->Length != 0)
			{
				if (textBoxc->Text != "-")
				{
					Tempinfinty_1 = Double::Parse(textBoxc->Text);
				}

			}


		}

	}
	private: System::Void textBoxd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc2 != 2)
		{
			textBoxd->Text = "Not Required";
			textBoxd->ReadOnly = true;
		}
		else
		{

			textBoxd->ReadOnly = false;
			if (this->textBoxd->Text->Length != 0)
			{
				if (textBoxd->Text != "-")
				{
					Tempinfinty_2 = Double::Parse(textBoxd->Text);
				}

			}


		}
	}
	private: System::Void textBoxe_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc1 != 2)
		{
			textBoxe->Text = "Not Required";
			textBoxe->ReadOnly = true;
		}
		else
		{
			textBoxe->ReadOnly = false;
			if (this->textBoxe->Text->Length != 0)
			{
				if (textBoxe->Text != "-")
				{
					convec_coefficient_1 = Double::Parse(textBoxe->Text);
				}

			}
		}
	}
	private: System::Void textBoxf_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc2 != 2)
		{
			textBoxf->Text = "Not Required";
			textBoxf->ReadOnly = true;
		}
		else
		{
			textBoxf->ReadOnly = false;
			if (this->textBoxf->Text->Length != 0)
			{
				if (textBoxf->Text != "-")
				{
					convec_coefficient_2 = Double::Parse(textBoxf->Text);
				}

			}

		}
	}
	private: System::Void textBoxg_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc1 != 3)
		{
			textBoxg->Text = "Not Required";
			textBoxg->ReadOnly = true;
		}
		else
		{
			textBoxg->ReadOnly = false;
			if (this->textBoxg->Text->Length != 0)
			{
				if (textBoxg->Text != "-")
				{
					heatflux_1 = Double::Parse(textBoxg->Text);
				}

			}

		}
	}
	private: System::Void textBoxh_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc2 != 3)
		{
			textBoxh->Text = "Not Required";
			textBoxh->ReadOnly = true;
		}
		else
		{
			textBoxh->ReadOnly = false;
			if (this->textBoxh->Text->Length != 0)
			{
				if (textBoxh->Text != "-")
				{
					heatflux_2 = Double::Parse(textBoxh->Text);
				}

			}

		}
	}
	private: System::Void textBoxa_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBoxa->Text->Contains(".") && !this->textBoxa->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBoxb_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBoxb->Text->Contains(".") && !this->textBoxb->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBoxc_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBoxc->Text->Contains(".") && !this->textBoxc->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBoxd_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == '.') {
			if (this->textBoxd->Text->Contains(".") && !this->textBoxd->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBoxe_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBoxe->Text->Contains(".") && !this->textBoxe->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBoxf_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBoxf->Text->Contains(".") && !this->textBoxf->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBoxg_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBoxg->Text->Contains(".") && !this->textBoxg->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBoxh_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBoxh->Text->Contains(".") && !this->textBoxh->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	};
}
