#pragma once
#include "Conduction_Inputs.h"
#include <fstream>
# include <cstring>
#include <iostream>


namespace Finalconduction {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for conduction
	/// </summary>
	public ref class conduction : public System::Windows::Forms::Form
	{
	public:int count = 0, cb2 = 0, cb3 = 0, option = -1, number_division_y = -1, number_division_x = -1, material_index = -1, bc1 = -1, bc2 = -1, bc3 = -1, bc4 = -1, isnonuniform = -1;
	public:  double nonuniform_coefficient = -1, convergence_criterion = -1, heat_per_volume = -1, Length1 = -1, Length2 = -1, Initial_temp = -1;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBox8;
	public:
	private: System::Windows::Forms::CheckBox^  checkBox1;
	public:
		conduction(void)
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
		~conduction()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::Button^  button1;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(107, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Material";
			this->label1->Click += gcnew System::EventHandler(this, &conduction::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(107, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Number of DivisionX";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(107, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(161, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Non uniform coefficient";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(107, 105);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(141, 18);
			this->label4->TabIndex = 3;
			this->label4->Text = L"boundary condition1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(107, 133);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(141, 18);
			this->label5->TabIndex = 4;
			this->label5->Text = L"boundary condition2";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(107, 157);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(141, 18);
			this->label6->TabIndex = 5;
			this->label6->Text = L"boundary condition3";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(107, 187);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(141, 18);
			this->label7->TabIndex = 6;
			this->label7->Text = L"boundary condition4";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(107, 215);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(153, 18);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Convergence criterion";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(107, 247);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(184, 18);
			this->label9->TabIndex = 8;
			this->label9->Text = L"heat generation per unit vol";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(107, 273);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(60, 18);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Length1";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(110, 304);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(64, 18);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Length 2";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(110, 330);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(123, 18);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Initial temperature";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Aluminium", L"Copper", L"Mild Steel" });
			this->comboBox1->Location = System::Drawing::Point(343, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 21);
			this->comboBox1->TabIndex = 12;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &conduction::comboBox1_SelectedIndexChanged);
			this->comboBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::comboBox1_KeyPress);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(343, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 13;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &conduction::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(343, 85);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 14;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &conduction::textBox2_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::textBox2_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(343, 213);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 15;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &conduction::textBox3_TextChanged);
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::textBox3_KeyPress);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(343, 245);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 16;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &conduction::textBox4_TextChanged);
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::textBox4_KeyPress);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(343, 271);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 17;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &conduction::textBox5_TextChanged);
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::textBox5_KeyPress);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(343, 302);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 18;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &conduction::textBox6_TextChanged);
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::textBox6_KeyPress);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(343, 328);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 19;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &conduction::textBox7_TextChanged);
			this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::textBox7_KeyPress);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Insulated", L"Constant Temperature", L"Convection",
					L"Heat Flux"
			});
			this->comboBox2->Location = System::Drawing::Point(343, 106);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(100, 21);
			this->comboBox2->TabIndex = 20;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &conduction::comboBox2_SelectedIndexChanged);
			this->comboBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::comboBox2_KeyPress);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Insulated", L"Constant Temperature", L"Convection",
					L"Heat Flux"
			});
			this->comboBox3->Location = System::Drawing::Point(343, 134);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(100, 21);
			this->comboBox3->TabIndex = 21;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &conduction::comboBox3_SelectedIndexChanged);
			this->comboBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::comboBox3_KeyPress);
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Insulated", L"Constant Temperature", L"Convection",
					L"Heat Flux"
			});
			this->comboBox4->Location = System::Drawing::Point(343, 161);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(100, 21);
			this->comboBox4->TabIndex = 22;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &conduction::comboBox4_SelectedIndexChanged);
			this->comboBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::comboBox4_KeyPress);
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Insulated", L"Constant Temperature", L"Convection",
					L"Heat Flux"
			});
			this->comboBox5->Location = System::Drawing::Point(343, 187);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(100, 21);
			this->comboBox5->TabIndex = 23;
			this->comboBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &conduction::comboBox5_SelectedIndexChanged);
			this->comboBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::comboBox5_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(231, 365);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 24;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &conduction::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 75);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(81, 17);
			this->checkBox1->TabIndex = 25;
			this->checkBox1->Text = L"non-uniform";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &conduction::checkBox1_CheckedChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(105, 59);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(143, 18);
			this->label13->TabIndex = 26;
			this->label13->Text = L"Number of DIvisionY";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(343, 59);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 27;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &conduction::textBox8_TextChanged);
			this->textBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &conduction::textBox8_KeyPress);
			// 
			// conduction
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(572, 437);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"conduction";
			this->Text = L"conduction";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
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
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {


		if (this->textBox1->Text->Length != 0)
		{
			if (textBox1->Text != "-")
			{
				number_division_x = Int32::Parse(textBox1->Text);
			}

		}





	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {


		if (count == -1)
		{
			isnonuniform = -1; nonuniform_coefficient = -1;
			textBox2->Text = "Not required";
			textBox2->ReadOnly = true;

		}
		else
		{
			isnonuniform = 1;
			if (this->textBox1->Text->Length != 0)
			{
				if (textBox2->Text != "-")
				{
					nonuniform_coefficient = Double::Parse(textBox2->Text);
				}

			}





		}
	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
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
	private: System::Void comboBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox4->SelectedIndex == 0)
		{
			bc3 = 0;
		}
		else if (comboBox4->SelectedIndex == 1)
		{
			bc3 = 1;
		}
		else if (comboBox4->SelectedIndex == 2)
		{
			bc3 = 2;
		}
		else if (comboBox4->SelectedIndex == 3)
		{
			bc3 = 3;
		}


	}
	private: System::Void comboBox5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox5->SelectedIndex == 0)
		{
			bc4 = 0;
		}
		else if (comboBox5->SelectedIndex == 1)
		{
			bc4 = 1;
		}
		else if (comboBox5->SelectedIndex == 2)
		{
			bc4 = 2;
		}
		else if (comboBox5->SelectedIndex == 3)
		{
			bc4 = 3;
		}

	}
	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {




		if (this->textBox3->Text->Length != 0)
		{
			if (textBox3->Text != "-")
			{
				convergence_criterion = Double::Parse(textBox3->Text);
			}

		}




	}
	private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {





		if (this->textBox3->Text->Length != 0)
		{
			if (textBox3->Text != "-")
			{
				heat_per_volume = Double::Parse(textBox4->Text);
			}

		}



	}
	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {


		if (this->textBox5->Text->Length != 0)
		{
			if (textBox5->Text != "-")
			{
				Length1 = Double::Parse(textBox5->Text);
			}

		}


	}
	private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (this->textBox6->Text->Length != 0)
		{
			if (textBox6->Text != "-")
			{
				Length2 = Double::Parse(textBox6->Text);
			}

		}

	}
	private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (this->textBox7->Text->Length != 0)
		{
			if (textBox7->Text != "-")
			{
				Initial_temp = Double::Parse(textBox7->Text);
			}

		}

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		if (material_index != -1 && number_division_x != -1 && number_division_y != -1 && bc1 != -1 && bc2 != -1 && bc3 != -1 && bc4 != -1 && convergence_criterion != -1 && heat_per_volume != -1 && Length1 != -1 && Length2 != -1 && Initial_temp != -1)
		{

			ofstream outfile;

			//outfile.open("User_Input.txt", ios::trunc | ios::out);//delete at end
			outfile.open("User_Input.txt", ios::trunc | ios::out);
			outfile << "-1" << '\n';
			outfile << material_index << '\n';
			outfile << number_division_x << '\n';
			outfile << number_division_y << '\n';
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
			outfile << bc3 << '\n';
			outfile << bc4 << '\n';
			outfile << convergence_criterion << '\n';
			outfile << heat_per_volume << '\n';
			outfile << Length1 << '\n';
			outfile << Length2 << '\n';
			outfile << Initial_temp << '\n';





			outfile.close();





			this->Hide();


			Conduction_Inputs^ f3 = gcnew Conduction_Inputs();
			f3->ShowDialog();

		}

		else
		{
			MessageBox::Show("Please enter all the inputs");
		}
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
	private: System::Void textBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {



		if (e->KeyChar == '.') {
			if (this->textBox2->Text->Contains(".") && !this->textBox2->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox3_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		if (e->KeyChar == '.') {
			if (this->textBox3->Text->Contains(".") && !this->textBox3->SelectedText->Contains("."))
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
	private: System::Void textBox7_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		if (e->KeyChar == '.') {
			if (this->textBox7->Text->Contains(".") && !this->textBox7->SelectedText->Contains("."))
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
	private: System::Void comboBox4_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		e->Handled = true;
	}
	private: System::Void comboBox5_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		e->Handled = true;
	}
	private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {


		if (this->textBox8->Text->Length != 0)
		{
			if (textBox8->Text != "-")
			{
				number_division_y = Int32::Parse(textBox8->Text);
			}

		}


	}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	count++;
}
private: System::Void textBox8_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


	if (e->KeyChar == '.') {
		if (this->textBox8->Text->Contains(".") && !this->textBox8->SelectedText->Contains("."))
			e->Handled = true;
	}

	// Accept only digits ".", "-" and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
};
}
