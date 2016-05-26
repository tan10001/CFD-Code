#pragma once
# include <fstream>
namespace Finalconduction {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Conduction_Inputs
	/// </summary>
	public ref class Conduction_Inputs : public System::Windows::Forms::Form
	{
	public:	public: double beta = -1, converge = -1, heatpervol = -1, heatflux_1 = -1, heatflux_2 = -1, heatflux_3 = -1, heatflux_4 = -1, convec_coefficient_1 = -1, convec_coefficient_2 = -1, convec_coefficient_3 = -1, convec_coefficient_4 = -1, temp1 = -1, temp2 = -1, temp3 = -1, temp4 = -1, Tempinfinty_1 = -1, Tempinfinty_2 = -1, Tempinfinty_3 = -1, Tempinfinty_4 = -1, Length1 = -1, Length2 = -1, Initial_temp = -1;
	public:int count1 = 0, count2 = 0, is_one_d = 0;
	public:int material = -1, no_of_divisions_x = -1, no_of_divisions_y = -1,bc1 = -1, bc2 = -1, bc3 = -1, bc4 = -1;
		   Conduction_Inputs(void)
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
			   no_of_divisions_x = n;
			   in >> n;
			   no_of_divisions_y = n;
			   in >> d;
			   beta = d;
			   in >> n;
			   bc1 = n;
			   in >> n;
			   bc2 = n;
			   in >> n;
			   bc3 = n;
			   in >> n;
			   bc4 = n;
			   converge = d;
			   in >> d;
			   heatpervol = d;
			   in >> d;
			   Length1 = d;
			   in >> d;
			   Length2 = d;
			   in >> d;
			   Initial_temp = d;


			   InitializeComponent();
			   //
			   //TODO: Add the constructor code here
			   //
		   }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Conduction_Inputs()
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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(75, 29);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Temperature1";
			this->label1->Click += gcnew System::EventHandler(this, &Conduction_Inputs::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(75, 75);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Temperature2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(423, 23);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Temperature3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(427, 75);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 18);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Temperature4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(113, 118);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 18);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Tinfinty1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(110, 185);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(65, 18);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Tinfinity2";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(458, 118);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(65, 18);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Tinfinity3";
			this->label7->Click += gcnew System::EventHandler(this, &Conduction_Inputs::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(458, 185);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 18);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Tinfinity4";
			this->label8->Click += gcnew System::EventHandler(this, &Conduction_Inputs::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(20, 246);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(162, 18);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Convection coefficient1";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(13, 316);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(162, 18);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Convection coefficient2";
			this->label10->Click += gcnew System::EventHandler(this, &Conduction_Inputs::label10_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(365, 246);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(162, 18);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Convection coefficient3";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(365, 310);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(162, 18);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Convection coefficient4";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(199, 28);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(148, 24);
			this->textBox1->TabIndex = 12;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(199, 75);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(148, 24);
			this->textBox2->TabIndex = 13;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox2_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox2_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(545, 23);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(148, 24);
			this->textBox3->TabIndex = 14;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox3_TextChanged);
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox3_KeyPress);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(545, 75);
			this->textBox4->Margin = System::Windows::Forms::Padding(4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(148, 24);
			this->textBox4->TabIndex = 15;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox4_TextChanged);
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox4_KeyPress);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(199, 118);
			this->textBox5->Margin = System::Windows::Forms::Padding(4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(148, 24);
			this->textBox5->TabIndex = 16;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox5_TextChanged);
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox5_KeyPress);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(199, 185);
			this->textBox6->Margin = System::Windows::Forms::Padding(4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(148, 24);
			this->textBox6->TabIndex = 17;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox6_TextChanged);
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox6_KeyPress);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(545, 118);
			this->textBox7->Margin = System::Windows::Forms::Padding(4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(148, 24);
			this->textBox7->TabIndex = 18;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox7_TextChanged);
			this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox7_KeyPress);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(545, 185);
			this->textBox8->Margin = System::Windows::Forms::Padding(4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(148, 24);
			this->textBox8->TabIndex = 19;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox8_TextChanged);
			this->textBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox8_KeyPress);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(199, 246);
			this->textBox9->Margin = System::Windows::Forms::Padding(4);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(148, 24);
			this->textBox9->TabIndex = 20;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox9_TextChanged);
			this->textBox9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox9_KeyPress);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(199, 316);
			this->textBox10->Margin = System::Windows::Forms::Padding(4);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(148, 24);
			this->textBox10->TabIndex = 21;
			this->textBox10->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox10_TextChanged);
			this->textBox10->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox10_KeyPress);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(545, 246);
			this->textBox11->Margin = System::Windows::Forms::Padding(4);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(148, 24);
			this->textBox11->TabIndex = 22;
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox11_TextChanged);
			this->textBox11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox11_KeyPress);
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(545, 310);
			this->textBox12->Margin = System::Windows::Forms::Padding(4);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(148, 24);
			this->textBox12->TabIndex = 23;
			this->textBox12->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox12_TextChanged_1);
			this->textBox12->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox12_KeyPress);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(106, 354);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(69, 18);
			this->label13->TabIndex = 24;
			this->label13->Text = L"Heatflux1";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(106, 418);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(69, 18);
			this->label14->TabIndex = 25;
			this->label14->Text = L"Heatflux2";
			this->label14->Click += gcnew System::EventHandler(this, &Conduction_Inputs::label14_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(454, 354);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(69, 18);
			this->label15->TabIndex = 26;
			this->label15->Text = L"Heatflux3";
			this->label15->Click += gcnew System::EventHandler(this, &Conduction_Inputs::label15_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(454, 418);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(69, 18);
			this->label16->TabIndex = 27;
			this->label16->Text = L"Heatflux4";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(199, 354);
			this->textBox13->Margin = System::Windows::Forms::Padding(4);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(148, 24);
			this->textBox13->TabIndex = 28;
			this->textBox13->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox13_TextChanged);
			this->textBox13->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox13_KeyPress);
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(199, 418);
			this->textBox14->Margin = System::Windows::Forms::Padding(4);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(148, 24);
			this->textBox14->TabIndex = 29;
			this->textBox14->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox14_TextChanged);
			this->textBox14->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox14_KeyPress);
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(545, 354);
			this->textBox15->Margin = System::Windows::Forms::Padding(4);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(148, 24);
			this->textBox15->TabIndex = 30;
			this->textBox15->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox15_TextChanged);
			this->textBox15->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox15_KeyPress);
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(545, 418);
			this->textBox16->Margin = System::Windows::Forms::Padding(4);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(148, 24);
			this->textBox16->TabIndex = 31;
			this->textBox16->TextChanged += gcnew System::EventHandler(this, &Conduction_Inputs::textBox16_TextChanged);
			this->textBox16->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Conduction_Inputs::textBox16_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(360, 465);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 32;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Conduction_Inputs::button1_Click);
			// 
			// Conduction_Inputs
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(779, 502);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox16);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
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
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Conduction_Inputs";
			this->Text = L"Conduction_Inputs";
			this->Load += gcnew System::EventHandler(this, &Conduction_Inputs::Conduction_Inputs_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Conduction_Inputs_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void textBox12_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox12_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {

		if (bc4 != 2)
		{
			textBox12->Text = "Not Required";
			textBox12->ReadOnly = true;
		}
		else
		{
			textBox12->ReadOnly = false;
			if (this->textBox12->Text->Length != 0)
			{
				if (textBox12->Text != "-")
				{
					convec_coefficient_4 = Double::Parse(textBox12->Text);
				}

			}
		}
	}
	private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc4 != 2)
		{
			textBox8->Text = "Not Required";
			textBox8->ReadOnly = true;
		}
		else
		{
			textBox8->ReadOnly = false;
			if (this->textBox8->Text->Length != 0)
			{
				if (textBox8->Text != "-")
				{
					Tempinfinty_4 = Double::Parse(textBox8->Text);
				}

			}

		}
	}
	private: System::Void label15_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label14_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc1 != 1)
		{
			textBox1->Text = "Not Required";
			textBox1->ReadOnly = true;
		}
		else
		{
			textBox1->ReadOnly = false;
			if (this->textBox1->Text->Length != 0)
			{
				if (textBox1->Text != "-")
				{
					temp1 = Double::Parse(textBox1->Text);
				}

			}

		}

	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc2 != 1)
		{
			textBox2->Text = "Not Required";
			textBox2->ReadOnly = true;
		}
		else
		{
			textBox2->ReadOnly = false;
			if (this->textBox2->Text->Length != 0)
			{
				if (textBox2->Text != "-")
				{
					temp2 = Double::Parse(textBox2->Text);
				}

			}


		}
	}
	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc3 != 1)
		{
			textBox3->Text = "Not Required";
			textBox3->ReadOnly = true;
		}
		else
		{
			textBox3->ReadOnly = false;

			if (this->textBox3->Text->Length != 0)
			{
				if (textBox3->Text != "-")
				{
					temp3 = Double::Parse(textBox3->Text);
				}

			}


		}


	}
	private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc4 != 1)
		{
			textBox4->Text = "Not Required";
			textBox4->ReadOnly = true;
		}
		else
		{
			textBox4->ReadOnly = false;

			if (this->textBox4->Text->Length != 0)
			{
				if (textBox4->Text != "-")
				{
					temp4 = Double::Parse(textBox4->Text);
				}

			}

		}



	}
	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc1 != 2)
		{
			textBox5->Text = "Not Required";
			textBox5->ReadOnly = true;
		}
		else
		{
			textBox5->ReadOnly = false;
			if (this->textBox5->Text->Length != 0)
			{
				if (textBox5->Text != "-")
				{
					Tempinfinty_1 = Double::Parse(textBox5->Text);
				}

			}



		}
	}
	private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc2 != 2)
		{
			textBox6->Text = "Not Required";
			textBox6->ReadOnly = true;
		}
		else
		{
			textBox6->ReadOnly = false;
			if (this->textBox6->Text->Length != 0)
			{
				if (textBox6->Text != "-")
				{
					Tempinfinty_2 = Double::Parse(textBox6->Text);
				}

			}


		}

	}
	private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc3 != 2)
		{
			textBox7->Text = "Not Required";
			textBox7->ReadOnly = true;
		}
		else
		{
			textBox7->ReadOnly = false;
			if (this->textBox7->Text->Length != 0)
			{
				if (textBox7->Text != "-")
				{
					Tempinfinty_3 = Double::Parse(textBox7->Text);
				}

			}

		}
	}
	private: System::Void textBox9_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc1 != 2)
		{
			textBox9->Text = "Not Required";
			textBox9->ReadOnly = true;
		}
		else
		{
			textBox9->ReadOnly = false;

			if (this->textBox9->Text->Length != 0)
			{
				if (textBox9->Text != "-")
				{
					convec_coefficient_1 = Double::Parse(textBox9->Text);
				}

			}

		}

	}
	private: System::Void textBox10_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc2 != 2)
		{
			textBox10->Text = "Not Required";
			textBox10->ReadOnly = true;
		}
		else
		{
			textBox10->ReadOnly = false;
			if (this->textBox10->Text->Length != 0)
			{
				if (textBox10->Text != "-")
				{
					convec_coefficient_2 = Double::Parse(textBox10->Text);
				}

			}
		}
	}
	private: System::Void textBox11_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc3 != 2)
		{
			textBox11->Text = "Not Required";
			textBox11->ReadOnly = true;
		}
		else
		{
			textBox11->ReadOnly = false;

			if (this->textBox11->Text->Length != 0)
			{
				if (textBox11->Text != "-")
				{
					convec_coefficient_3 = Double::Parse(textBox11->Text);
				}

			}
		}
	}
	private: System::Void textBox13_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc1 != 3)
		{
			textBox13->Text = "Not Required";
			textBox13->ReadOnly = true;
		}
		else
		{
			textBox13->ReadOnly = false;
			if (this->textBox13->Text->Length != 0)
			{
				if (textBox13->Text != "-")
				{
					heatflux_1 = Double::Parse(textBox13->Text);
				}

			}

		}
	}
	private: System::Void textBox14_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc2 != 3)
		{
			textBox14->Text = "Not Required";
			textBox14->ReadOnly = true;
		}
		else
		{
			textBox14->ReadOnly = false;

			if (this->textBox14->Text->Length != 0)
			{
				if (textBox14->Text != "-")
				{
					heatflux_2 = Double::Parse(textBox14->Text);
				}

			}
		}


	}
	private: System::Void textBox15_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (bc3 != 3)
		{
			textBox15->Text = "Not Required";
			textBox15->ReadOnly = true;
		}
		else
		{
			textBox15->ReadOnly = false;
			if (this->textBox15->Text->Length != 0)
			{
				if (textBox15->Text != "-")
				{
					heatflux_3 = Double::Parse(textBox15->Text);
				}

			}
		}
	}
	private: System::Void textBox16_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (bc4 != 3)
		{
			textBox16->Text = "Not Required";
			textBox16->ReadOnly = true;
		}
		else
		{
			textBox16->ReadOnly = false;

			if (this->textBox16->Text->Length != 0)
			{
				if (textBox16->Text != "-")
				{
					heatflux_4 = Double::Parse(textBox16->Text);
				}

			}
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		ofstream outfile;
		outfile.open("User_Input2.txt", ios::trunc | ios::out);

		outfile << temp1 << '\n';
		outfile << temp2 << '\n';
		outfile << temp3 << '\n';
		outfile << temp4 << '\n';

		outfile << Tempinfinty_1 << '\n';
		outfile << Tempinfinty_2 << '\n';
		outfile << Tempinfinty_3 << '\n';
		outfile << Tempinfinty_4 << '\n';

		outfile << convec_coefficient_1 << '\n';
		outfile << convec_coefficient_2 << '\n';
		outfile << convec_coefficient_3 << '\n';
		outfile << convec_coefficient_4 << '\n';

		outfile << heatflux_1 << '\n';
		outfile << heatflux_2 << '\n';
		outfile << heatflux_3 << '\n';
		outfile << heatflux_4 << '\n';

		Process::Start("Conduction.exe");



		outfile.close();


		Application::Exit();

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
	private: System::Void textBox9_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		if (e->KeyChar == '.') {
			if (this->textBox9->Text->Contains(".") && !this->textBox9->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox10_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		if (e->KeyChar == '.') {
			if (this->textBox10->Text->Contains(".") && !this->textBox10->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox11_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		if (e->KeyChar == '.') {
			if (this->textBox11->Text->Contains(".") && !this->textBox11->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox12_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if (e->KeyChar == '.') {
			if (this->textBox12->Text->Contains(".") && !this->textBox12->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}

	}
	private: System::Void textBox13_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		if (e->KeyChar == '.') {
			if (this->textBox13->Text->Contains(".") && !this->textBox13->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox14_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		if (e->KeyChar == '.') {
			if (this->textBox14->Text->Contains(".") && !this->textBox14->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox15_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		if (e->KeyChar == '.') {
			if (this->textBox15->Text->Contains(".") && !this->textBox15->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void textBox16_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		if (e->KeyChar == '.') {
			if (this->textBox16->Text->Contains(".") && !this->textBox16->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	};
}
