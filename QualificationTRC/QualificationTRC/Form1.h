#pragma once
#include <iostream>
#include <fstream>



namespace QualificationTRC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  projectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lblMenuNew;
	private: System::Windows::Forms::ToolStripMenuItem^  lblMenuLoad;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  lblDialog;
	private: System::Windows::Forms::ComboBox^  lblSelectBox;
	private: System::Windows::Forms::Button^  lblButLoad;
	private: System::Windows::Forms::Button^  lblButStart;
	private: System::Windows::Forms::Button^  lblButStop;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  lblIC8;

	private: System::Windows::Forms::TextBox^  lblIC7;

	private: System::Windows::Forms::TextBox^  lblIC6;

	private: System::Windows::Forms::TextBox^  lblIC5;

	private: System::Windows::Forms::TextBox^  lblIC4;
	private: System::Windows::Forms::TextBox^  lblIC3;
	private: System::Windows::Forms::TextBox^  lblIC2;
	private: System::Windows::Forms::TextBox^  lblIC1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  lblBeaconIC8;
	private: System::Windows::Forms::TextBox^  lblBeaconIC7;
	private: System::Windows::Forms::TextBox^  lblBeaconIC6;
	private: System::Windows::Forms::TextBox^  lblBeaconIC5;
	private: System::Windows::Forms::TextBox^  lblBeaconIC4;
	private: System::Windows::Forms::TextBox^  lblBeaconIC3;
	private: System::Windows::Forms::TextBox^  lblBeaconIC2;
	private: System::Windows::Forms::TextBox^  lblBeaconIC1;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Button^  lblButGenerateReport;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Button^  lblCheckIC;
	private: System::Windows::Forms::CheckBox^  lblDispRes;


		 //Globals
		String^ sWorkingFile;
		bool bDispRes;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->projectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblMenuNew = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblMenuLoad = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblDialog = (gcnew System::Windows::Forms::TextBox());
			this->lblSelectBox = (gcnew System::Windows::Forms::ComboBox());
			this->lblButLoad = (gcnew System::Windows::Forms::Button());
			this->lblButStart = (gcnew System::Windows::Forms::Button());
			this->lblButStop = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lblCheckIC = (gcnew System::Windows::Forms::Button());
			this->lblBeaconIC8 = (gcnew System::Windows::Forms::TextBox());
			this->lblBeaconIC7 = (gcnew System::Windows::Forms::TextBox());
			this->lblBeaconIC6 = (gcnew System::Windows::Forms::TextBox());
			this->lblBeaconIC5 = (gcnew System::Windows::Forms::TextBox());
			this->lblBeaconIC4 = (gcnew System::Windows::Forms::TextBox());
			this->lblBeaconIC3 = (gcnew System::Windows::Forms::TextBox());
			this->lblBeaconIC2 = (gcnew System::Windows::Forms::TextBox());
			this->lblBeaconIC1 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lblIC8 = (gcnew System::Windows::Forms::TextBox());
			this->lblIC7 = (gcnew System::Windows::Forms::TextBox());
			this->lblIC6 = (gcnew System::Windows::Forms::TextBox());
			this->lblIC5 = (gcnew System::Windows::Forms::TextBox());
			this->lblIC4 = (gcnew System::Windows::Forms::TextBox());
			this->lblIC3 = (gcnew System::Windows::Forms::TextBox());
			this->lblIC2 = (gcnew System::Windows::Forms::TextBox());
			this->lblIC1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->lblButGenerateReport = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->lblDispRes = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->projectToolStripMenuItem, 
				this->exitToolStripMenuItem, this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(846, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// projectToolStripMenuItem
			// 
			this->projectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->lblMenuNew, 
				this->lblMenuLoad});
			this->projectToolStripMenuItem->Name = L"projectToolStripMenuItem";
			this->projectToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->projectToolStripMenuItem->Text = L"&Project";
			// 
			// lblMenuNew
			// 
			this->lblMenuNew->Name = L"lblMenuNew";
			this->lblMenuNew->Size = System::Drawing::Size(100, 22);
			this->lblMenuNew->Text = L"&New";
			this->lblMenuNew->Click += gcnew System::EventHandler(this, &Form1::lblMenuNew_Click);
			// 
			// lblMenuLoad
			// 
			this->lblMenuLoad->Name = L"lblMenuLoad";
			this->lblMenuLoad->Size = System::Drawing::Size(100, 22);
			this->lblMenuLoad->Text = L"&Load";
			this->lblMenuLoad->Click += gcnew System::EventHandler(this, &Form1::lblMenuLoad_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->exitToolStripMenuItem->Text = L"&Exit";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"&Help";
			// 
			// lblDialog
			// 
			this->lblDialog->Location = System::Drawing::Point(12, 42);
			this->lblDialog->Multiline = true;
			this->lblDialog->Name = L"lblDialog";
			this->lblDialog->ReadOnly = true;
			this->lblDialog->Size = System::Drawing::Size(199, 342);
			this->lblDialog->TabIndex = 0;
			this->lblDialog->Text = resources->GetString(L"lblDialog.Text");
			this->lblDialog->TextChanged += gcnew System::EventHandler(this, &Form1::lblDialog_TextChanged);
			// 
			// lblSelectBox
			// 
			this->lblSelectBox->FormattingEnabled = true;
			this->lblSelectBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"1: Normal Climb Engine Operating", L"2: Engine Acceleration", 
				L"3: Engine Deceleration", L"4: Pitch Controller Position vs Force", L"5: Roll Controller Position vs Force", L"6: Rudder Pedal Positon vs Force  "});
			this->lblSelectBox->Location = System::Drawing::Point(266, 27);
			this->lblSelectBox->Name = L"lblSelectBox";
			this->lblSelectBox->Size = System::Drawing::Size(314, 21);
			this->lblSelectBox->TabIndex = 1;
			this->lblSelectBox->Text = L" - Test Select -";
			// 
			// lblButLoad
			// 
			this->lblButLoad->Location = System::Drawing::Point(267, 80);
			this->lblButLoad->Name = L"lblButLoad";
			this->lblButLoad->Size = System::Drawing::Size(75, 23);
			this->lblButLoad->TabIndex = 2;
			this->lblButLoad->Text = L"Load";
			this->lblButLoad->UseVisualStyleBackColor = true;
			this->lblButLoad->Click += gcnew System::EventHandler(this, &Form1::lblButLoad_Click);
			// 
			// lblButStart
			// 
			this->lblButStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblButStart->Location = System::Drawing::Point(383, 80);
			this->lblButStart->Name = L"lblButStart";
			this->lblButStart->Size = System::Drawing::Size(75, 23);
			this->lblButStart->TabIndex = 3;
			this->lblButStart->Text = L"Start";
			this->lblButStart->UseVisualStyleBackColor = true;
			// 
			// lblButStop
			// 
			this->lblButStop->BackColor = System::Drawing::SystemColors::Control;
			this->lblButStop->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->lblButStop->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->lblButStop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblButStop->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblButStop->Location = System::Drawing::Point(499, 80);
			this->lblButStop->Name = L"lblButStop";
			this->lblButStop->Size = System::Drawing::Size(75, 23);
			this->lblButStop->TabIndex = 4;
			this->lblButStop->Text = L"Stop";
			this->lblButStop->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lblCheckIC);
			this->groupBox1->Controls->Add(this->lblBeaconIC8);
			this->groupBox1->Controls->Add(this->lblBeaconIC7);
			this->groupBox1->Controls->Add(this->lblBeaconIC6);
			this->groupBox1->Controls->Add(this->lblBeaconIC5);
			this->groupBox1->Controls->Add(this->lblBeaconIC4);
			this->groupBox1->Controls->Add(this->lblBeaconIC3);
			this->groupBox1->Controls->Add(this->lblBeaconIC2);
			this->groupBox1->Controls->Add(this->lblBeaconIC1);
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->lblIC8);
			this->groupBox1->Controls->Add(this->lblIC7);
			this->groupBox1->Controls->Add(this->lblIC6);
			this->groupBox1->Controls->Add(this->lblIC5);
			this->groupBox1->Controls->Add(this->lblIC4);
			this->groupBox1->Controls->Add(this->lblIC3);
			this->groupBox1->Controls->Add(this->lblIC2);
			this->groupBox1->Controls->Add(this->lblIC1);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(266, 109);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(308, 275);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Initial Conditions";
			// 
			// lblCheckIC
			// 
			this->lblCheckIC->Location = System::Drawing::Point(187, 241);
			this->lblCheckIC->Name = L"lblCheckIC";
			this->lblCheckIC->Size = System::Drawing::Size(75, 23);
			this->lblCheckIC->TabIndex = 10;
			this->lblCheckIC->Text = L"Check";
			this->lblCheckIC->UseVisualStyleBackColor = true;
			// 
			// lblBeaconIC8
			// 
			this->lblBeaconIC8->Location = System::Drawing::Point(176, 212);
			this->lblBeaconIC8->Name = L"lblBeaconIC8";
			this->lblBeaconIC8->ReadOnly = true;
			this->lblBeaconIC8->Size = System::Drawing::Size(15, 20);
			this->lblBeaconIC8->TabIndex = 26;
			// 
			// lblBeaconIC7
			// 
			this->lblBeaconIC7->Location = System::Drawing::Point(176, 184);
			this->lblBeaconIC7->Name = L"lblBeaconIC7";
			this->lblBeaconIC7->ReadOnly = true;
			this->lblBeaconIC7->Size = System::Drawing::Size(15, 20);
			this->lblBeaconIC7->TabIndex = 25;
			// 
			// lblBeaconIC6
			// 
			this->lblBeaconIC6->Location = System::Drawing::Point(176, 157);
			this->lblBeaconIC6->Name = L"lblBeaconIC6";
			this->lblBeaconIC6->ReadOnly = true;
			this->lblBeaconIC6->Size = System::Drawing::Size(15, 20);
			this->lblBeaconIC6->TabIndex = 24;
			// 
			// lblBeaconIC5
			// 
			this->lblBeaconIC5->Location = System::Drawing::Point(176, 128);
			this->lblBeaconIC5->Name = L"lblBeaconIC5";
			this->lblBeaconIC5->ReadOnly = true;
			this->lblBeaconIC5->Size = System::Drawing::Size(15, 20);
			this->lblBeaconIC5->TabIndex = 23;
			// 
			// lblBeaconIC4
			// 
			this->lblBeaconIC4->Location = System::Drawing::Point(176, 102);
			this->lblBeaconIC4->Name = L"lblBeaconIC4";
			this->lblBeaconIC4->ReadOnly = true;
			this->lblBeaconIC4->Size = System::Drawing::Size(15, 20);
			this->lblBeaconIC4->TabIndex = 22;
			// 
			// lblBeaconIC3
			// 
			this->lblBeaconIC3->Location = System::Drawing::Point(176, 75);
			this->lblBeaconIC3->Name = L"lblBeaconIC3";
			this->lblBeaconIC3->ReadOnly = true;
			this->lblBeaconIC3->Size = System::Drawing::Size(15, 20);
			this->lblBeaconIC3->TabIndex = 21;
			// 
			// lblBeaconIC2
			// 
			this->lblBeaconIC2->Location = System::Drawing::Point(176, 46);
			this->lblBeaconIC2->Name = L"lblBeaconIC2";
			this->lblBeaconIC2->ReadOnly = true;
			this->lblBeaconIC2->Size = System::Drawing::Size(15, 20);
			this->lblBeaconIC2->TabIndex = 20;
			// 
			// lblBeaconIC1
			// 
			this->lblBeaconIC1->Location = System::Drawing::Point(176, 18);
			this->lblBeaconIC1->Name = L"lblBeaconIC1";
			this->lblBeaconIC1->ReadOnly = true;
			this->lblBeaconIC1->Size = System::Drawing::Size(15, 20);
			this->lblBeaconIC1->TabIndex = 19;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(257, 128);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(40, 14);
			this->label16->TabIndex = 18;
			this->label16->Text = L"(deg)";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(262, 209);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(31, 14);
			this->label15->TabIndex = 17;
			this->label15->Text = L"(%)";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(262, 182);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(31, 14);
			this->label14->TabIndex = 17;
			this->label14->Text = L"(%)";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(262, 155);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(31, 14);
			this->label13->TabIndex = 17;
			this->label13->Text = L"(%)";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(266, 74);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(22, 14);
			this->label12->TabIndex = 17;
			this->label12->Text = L"(-)";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(262, 47);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(31, 14);
			this->label11->TabIndex = 17;
			this->label11->Text = L"(%)";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(257, 101);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(40, 14);
			this->label10->TabIndex = 17;
			this->label10->Text = L"(deg)";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(262, 20);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(31, 14);
			this->label9->TabIndex = 16;
			this->label9->Text = L"(%)";
			this->label9->Click += gcnew System::EventHandler(this, &Form1::label9_Click);
			// 
			// lblIC8
			// 
			this->lblIC8->Location = System::Drawing::Point(192, 212);
			this->lblIC8->Name = L"lblIC8";
			this->lblIC8->Size = System::Drawing::Size(64, 20);
			this->lblIC8->TabIndex = 15;
			// 
			// lblIC7
			// 
			this->lblIC7->Location = System::Drawing::Point(192, 184);
			this->lblIC7->Name = L"lblIC7";
			this->lblIC7->Size = System::Drawing::Size(64, 20);
			this->lblIC7->TabIndex = 14;
			// 
			// lblIC6
			// 
			this->lblIC6->Location = System::Drawing::Point(192, 157);
			this->lblIC6->Name = L"lblIC6";
			this->lblIC6->Size = System::Drawing::Size(64, 20);
			this->lblIC6->TabIndex = 13;
			this->lblIC6->TextChanged += gcnew System::EventHandler(this, &Form1::textBox6_TextChanged);
			// 
			// lblIC5
			// 
			this->lblIC5->Location = System::Drawing::Point(192, 128);
			this->lblIC5->Name = L"lblIC5";
			this->lblIC5->Size = System::Drawing::Size(64, 20);
			this->lblIC5->TabIndex = 12;
			this->lblIC5->TextChanged += gcnew System::EventHandler(this, &Form1::textBox5_TextChanged);
			// 
			// lblIC4
			// 
			this->lblIC4->Location = System::Drawing::Point(192, 102);
			this->lblIC4->Name = L"lblIC4";
			this->lblIC4->Size = System::Drawing::Size(64, 20);
			this->lblIC4->TabIndex = 11;
			// 
			// lblIC3
			// 
			this->lblIC3->Location = System::Drawing::Point(192, 75);
			this->lblIC3->Name = L"lblIC3";
			this->lblIC3->Size = System::Drawing::Size(64, 20);
			this->lblIC3->TabIndex = 10;
			// 
			// lblIC2
			// 
			this->lblIC2->Location = System::Drawing::Point(192, 46);
			this->lblIC2->Name = L"lblIC2";
			this->lblIC2->Size = System::Drawing::Size(64, 20);
			this->lblIC2->TabIndex = 9;
			// 
			// lblIC1
			// 
			this->lblIC1->Location = System::Drawing::Point(192, 18);
			this->lblIC1->Name = L"lblIC1";
			this->lblIC1->Size = System::Drawing::Size(64, 20);
			this->lblIC1->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(6, 214);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(135, 14);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Ruder Pedal Position";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(6, 186);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(149, 14);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Roll Controller Position";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(6, 159);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(157, 14);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Pitch Controller Position";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(6, 130);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(145, 14);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Flap Indicator Position";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(7, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 14);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Flap Lever Position";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(6, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(123, 14);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Trimwheel Position";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(7, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 14);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Mixture Setting";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(7, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 14);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Throttle Setting";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 390);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(562, 19);
			this->progressBar1->TabIndex = 6;
			// 
			// lblButGenerateReport
			// 
			this->lblButGenerateReport->BackColor = System::Drawing::Color::Transparent;
			this->lblButGenerateReport->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->lblButGenerateReport->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->lblButGenerateReport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblButGenerateReport->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblButGenerateReport->Location = System::Drawing::Point(644, 42);
			this->lblButGenerateReport->Name = L"lblButGenerateReport";
			this->lblButGenerateReport->Size = System::Drawing::Size(174, 45);
			this->lblButGenerateReport->TabIndex = 7;
			this->lblButGenerateReport->Text = L"Generate Report";
			this->lblButGenerateReport->UseVisualStyleBackColor = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(644, 154);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(174, 178);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(618, 348);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(227, 25);
			this->label17->TabIndex = 9;
			this->label17->Text = L"Simulator Qualification";
			// 
			// lblDispRes
			// 
			this->lblDispRes->AutoSize = true;
			this->lblDispRes->Location = System::Drawing::Point(482, 54);
			this->lblDispRes->Name = L"lblDispRes";
			this->lblDispRes->Size = System::Drawing::Size(98, 17);
			this->lblDispRes->TabIndex = 10;
			this->lblDispRes->Text = L"Display Results";
			this->lblDispRes->UseVisualStyleBackColor = true;
			this->lblDispRes->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(846, 411);
			this->Controls->Add(this->lblDispRes);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblButGenerateReport);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lblButStop);
			this->Controls->Add(this->lblButStart);
			this->Controls->Add(this->lblButLoad);
			this->Controls->Add(this->lblSelectBox);
			this->Controls->Add(this->lblDialog);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"TRC Simulators - Simulator Qualification";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			// Freeze Buttons
			lblButStart->Enabled = false;
			lblButStop->Enabled = false;
			lblButGenerateReport->Enabled = false;
			
		 }
private: System::Void lblMenuNew_Click(System::Object^  sender, System::EventArgs^  e) {
			
			
			//SaveFileDialog
			SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
			saveFileDialog1->Filter = "Project File|*.txt";
			saveFileDialog1->Title = "Save the project file...";
			saveFileDialog1->ShowDialog();
			

			String^ sfileName = saveFileDialog1->FileName;
			if(saveFileDialog1->FileName != "")
			{
				
				StreamWriter^ NewProjFile = gcnew StreamWriter(sfileName);
				NewProjFile->WriteLine(sfileName);//filename
				NewProjFile->WriteLine(DateTime::Now);//Date of Creation
				//List of Tests Still to Perform
				NewProjFile->WriteLine("Tests to perform:");
				NewProjFile->WriteLine("1: Normal Climb Engine Operating");
				
				
				//Close File and assig to working file
				sWorkingFile = sfileName;
				NewProjFile->Close();
				loadProject(sfileName);
			}
			
		 }
private: System::Void lblDialog_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void lblMenuLoad_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 
			//OpenFileDialog
			OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->Title = "Open the project file...";
			openFileDialog1->ShowDialog();
			
			String^ sFileName =  openFileDialog1->FileName;
			loadProject(sFileName);
			
			

		 }
private: System::Void lblButLoad_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			int iLoadTest = lblSelectBox->SelectedIndex;
			
			loadInitialConditions(iLoadTest);
			
			
					
		 }

private: void loadInitialConditions(int iTestNumber)
		 {
			String^ sFileName = "test" + Convert::ToString(iTestNumber) + ".txt" + ".txt" ;
			if (File::Exists(sFileName) == true)
			{
				//Check if file is not corrupted (erroneous number of lines)
				int iLineCount = 0;
				StreamReader^ streamActualFile = File::OpenText(sFileName);
				while (streamActualFile->ReadLine() != nullptr)
				{
					iLineCount++;
				}
				streamActualFile->Close();
				if ( iLineCount == 8)
				{
					//Read test Initial Conditions(IC)
					StreamReader^ streamActualFile = File::OpenText(sFileName);
					//Write IC in textLabels
					lblIC1->Text = streamActualFile->ReadLine();
					lblIC2->Text = streamActualFile->ReadLine();
					lblIC3->Text = streamActualFile->ReadLine();
					lblIC4->Text = streamActualFile->ReadLine();
					lblIC5->Text = streamActualFile->ReadLine();
					lblIC6->Text = streamActualFile->ReadLine();
					lblIC7->Text = streamActualFile->ReadLine();
					lblIC8->Text = streamActualFile->ReadLine();
					streamActualFile->Close();
					//Change IC Beacons
					//lblBeaconIC1->BackColor = System::Drawing::Color::Gold;
				}
				else
				{
					MessageBox::Show("Test file corrupted!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
				
			}		
			else
			{
				MessageBox::Show("Test file not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
				 
		 }
private: void loadProject(String^ sFileName)
		 {
			StreamReader^ streamActualFile = File::OpenText(sFileName);
			String^ str;
			
			lblDialog->Text ="";
			while ((str = streamActualFile->ReadLine()) != nullptr) 
			{
				lblDialog->Text += str;
				lblDialog->Text += "\r\n";
				
			}
			//Close File and assign to working file
			streamActualFile->Close();
			sWorkingFile = sFileName;

		 }
private: System::Void checkBox1_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {

		 }
};
}

