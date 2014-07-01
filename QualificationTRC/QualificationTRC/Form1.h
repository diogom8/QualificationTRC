//------------------------------------------------------------------------------
//Copyright (c) TRC Simulators.  All rights reserved.
//Developed by Diogo Monteiro. 26/05/2014  
//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h> //To convert System String to std::string
#include <string>
//#include "chplot.h" - 30 day free trial library(c:silib:include)
#include <sstream>


#define GNUPLOT_NAME "pgnuplot -persist"



//MACRO TO CONVERT INT TO STRING
#define intTOstr( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace System::IO;

//SimConnect Stuff
#include <windows.h>
#include "SimConnect.h"
//#include <strsafe.h>






//Globals
HANDLE  hSimConnect = NULL; //Server Identifier for SimConnect
bool bQuitTest = false;
bool bTestStarted = false;
double check = 0;
double dInitTime;
char fCheckIC = 0x00;
double InitialConditions[8];

//bool Start_TEST_1(void);
//Test Files
#include "TestFiles/TEST_LOAD.h"
#include "TestFiles/TEST_START.h"
#include "InitialConditions/TEST_IC.h"





namespace QualificationTRC {

	/*using namespace System;
	using namespace System::Runtime::InteropServices;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;*/
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
	private: System::Windows::Forms::TextBox^  lblDialogProjectName;

	private: System::Windows::Forms::ComboBox^  lblSelectBox;
	private: System::Windows::Forms::Button^  lblButLoad;
	private: System::Windows::Forms::Button^  lblButStart;
	private: System::Windows::Forms::Button^  lblButReset;

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
	String^ sProjectFile;
		
	private: System::Windows::Forms::ListBox^  lblListBoxTests;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  lblDialogProjectDate;
	private: System::Windows::Forms::Label^  label19;
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
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblDialogProjectName = (gcnew System::Windows::Forms::TextBox());
			this->lblSelectBox = (gcnew System::Windows::Forms::ComboBox());
			this->lblButLoad = (gcnew System::Windows::Forms::Button());
			this->lblButStart = (gcnew System::Windows::Forms::Button());
			this->lblButReset = (gcnew System::Windows::Forms::Button());
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
			this->lblListBoxTests = (gcnew System::Windows::Forms::ListBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->lblDialogProjectDate = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->projectToolStripMenuItem, 
				this->helpToolStripMenuItem, this->exitToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(846, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
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
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"&Help";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->exitToolStripMenuItem->Text = L"&Exit";
			// 
			// lblDialogProjectName
			// 
			this->lblDialogProjectName->Location = System::Drawing::Point(13, 25);
			this->lblDialogProjectName->Multiline = true;
			this->lblDialogProjectName->Name = L"lblDialogProjectName";
			this->lblDialogProjectName->ReadOnly = true;
			this->lblDialogProjectName->Size = System::Drawing::Size(199, 19);
			this->lblDialogProjectName->TabIndex = 0;
			this->lblDialogProjectName->TextChanged += gcnew System::EventHandler(this, &Form1::lblDialog_TextChanged);
			// 
			// lblSelectBox
			// 
			this->lblSelectBox->FormattingEnabled = true;
			this->lblSelectBox->Items->AddRange(gcnew cli::array< System::Object^  >(37) {L"1: Normal Climb Engine Operating (1.c1)", 
				L"2: Engine Acceleration (1.f1)", L"3: Engine Deceleration (1.f2)", L"4: Pitch Controller Position vs Force (2.a1) - Cruise", 
				L"5: Pitch Controller Position vs Force (2.a1) - Approach", L"6: Roll Controller Position vs Force (2.a2) - Cruise/Approach", 
				L"7: Roll Controller Position vs Force (2.a2) - Approach", L"8: Ruder Pedal Position vs Force (2.a3) - Cruise/Approach", L"9: Ruder Pedal Position vs Force (2.a3) - Approach", 
				L"10: Pitch Trim Indicator vs Surface Position Calibration (2.a6)", L"11: Alignment of Cockpit Throttle vs Selected Engine Parameter (2.a8)", 
				L"12: Power Change Dynamics (2.c1)", L"13: Flap Change Dynamics (2.c2)", L"14: Spoiler/Speedbrake Change Dynamics (2.c3)", L"15: Gear Change Dynamics (2.c4)", 
				L"16: Longitudinal Trim (2.c5) - Cruise", L"17: Longitudinal Trim (2.c5) - Approach", L"18: Longitudinal Manoeuvring Stability (2.c6) - Cruise", 
				L"19: Longitudinal Manoeuvring Stability (2.c6) - Approach", L"20: Longitudinal Static Stability (2.c6)", L"21: Stall Characteristics (2.c8) - Climb", 
				L"22: Stall Characteristics (2.c8) - Approach", L"23: Phugoid Dynamics (2.c9)", L"24: Short Period Dynamics (2.c10)", L"25: Minimum Control Speed (2.d1)", 
				L"26: Roll Response (Rate) (2.d2) - Cruise", L"27: Roll Response (Rate) (2.d2) - Approach", L"28: Step Input of Cockpit Roll Controller (2.d3)", 
				L"29: Spiral Stability (2.d4) - Cruise", L"30: Spiral Stability (2.d4) - Approach", L"31: Engine Inoperative Trim (2.d5) - Climb", 
				L"32: Engine Inoperative Trim (2.d5) - Approach", L"33: Rudder Response (2.d6)", L"34: Dutch Roll (2.d7) - Cruise", L"35: Dutch Roll (2.d7) - Approach", 
				L"36: Steady State Sideslip (2.d8)", L"37: System Response Time (4.a1)"});
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
			this->lblButStart->Click += gcnew System::EventHandler(this, &Form1::lblButStart_Click);
			// 
			// lblButReset
			// 
			this->lblButReset->BackColor = System::Drawing::SystemColors::Control;
			this->lblButReset->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->lblButReset->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->lblButReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblButReset->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblButReset->Location = System::Drawing::Point(499, 80);
			this->lblButReset->Name = L"lblButReset";
			this->lblButReset->Size = System::Drawing::Size(75, 23);
			this->lblButReset->TabIndex = 4;
			this->lblButReset->Text = L"Reset";
			this->lblButReset->UseVisualStyleBackColor = true;
			this->lblButReset->Click += gcnew System::EventHandler(this, &Form1::lblButReset_Click);
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
			this->lblCheckIC->Click += gcnew System::EventHandler(this, &Form1::lblCheckIC_Click);
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
			this->label16->Location = System::Drawing::Point(266, 128);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(22, 14);
			this->label16->TabIndex = 18;
			this->label16->Text = L"(-)";
			this->label16->Click += gcnew System::EventHandler(this, &Form1::label16_Click);
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
			this->lblIC8->BackColor = System::Drawing::SystemColors::Window;
			this->lblIC8->Location = System::Drawing::Point(192, 212);
			this->lblIC8->Name = L"lblIC8";
			this->lblIC8->ReadOnly = true;
			this->lblIC8->Size = System::Drawing::Size(64, 20);
			this->lblIC8->TabIndex = 15;
			this->lblIC8->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lblIC7
			// 
			this->lblIC7->BackColor = System::Drawing::SystemColors::Window;
			this->lblIC7->Location = System::Drawing::Point(192, 184);
			this->lblIC7->Name = L"lblIC7";
			this->lblIC7->ReadOnly = true;
			this->lblIC7->Size = System::Drawing::Size(64, 20);
			this->lblIC7->TabIndex = 14;
			this->lblIC7->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lblIC6
			// 
			this->lblIC6->BackColor = System::Drawing::SystemColors::Window;
			this->lblIC6->Location = System::Drawing::Point(192, 157);
			this->lblIC6->Name = L"lblIC6";
			this->lblIC6->ReadOnly = true;
			this->lblIC6->Size = System::Drawing::Size(64, 20);
			this->lblIC6->TabIndex = 13;
			this->lblIC6->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->lblIC6->TextChanged += gcnew System::EventHandler(this, &Form1::textBox6_TextChanged);
			// 
			// lblIC5
			// 
			this->lblIC5->BackColor = System::Drawing::SystemColors::Window;
			this->lblIC5->Location = System::Drawing::Point(192, 128);
			this->lblIC5->Name = L"lblIC5";
			this->lblIC5->ReadOnly = true;
			this->lblIC5->Size = System::Drawing::Size(64, 20);
			this->lblIC5->TabIndex = 12;
			this->lblIC5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->lblIC5->TextChanged += gcnew System::EventHandler(this, &Form1::textBox5_TextChanged);
			// 
			// lblIC4
			// 
			this->lblIC4->BackColor = System::Drawing::SystemColors::Window;
			this->lblIC4->Location = System::Drawing::Point(192, 102);
			this->lblIC4->Name = L"lblIC4";
			this->lblIC4->ReadOnly = true;
			this->lblIC4->Size = System::Drawing::Size(64, 20);
			this->lblIC4->TabIndex = 11;
			this->lblIC4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lblIC3
			// 
			this->lblIC3->BackColor = System::Drawing::SystemColors::Window;
			this->lblIC3->Location = System::Drawing::Point(192, 75);
			this->lblIC3->Name = L"lblIC3";
			this->lblIC3->ReadOnly = true;
			this->lblIC3->Size = System::Drawing::Size(64, 20);
			this->lblIC3->TabIndex = 10;
			this->lblIC3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lblIC2
			// 
			this->lblIC2->BackColor = System::Drawing::SystemColors::Window;
			this->lblIC2->Location = System::Drawing::Point(192, 46);
			this->lblIC2->Name = L"lblIC2";
			this->lblIC2->ReadOnly = true;
			this->lblIC2->Size = System::Drawing::Size(64, 20);
			this->lblIC2->TabIndex = 9;
			this->lblIC2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lblIC1
			// 
			this->lblIC1->BackColor = System::Drawing::SystemColors::Window;
			this->lblIC1->Location = System::Drawing::Point(192, 18);
			this->lblIC1->Name = L"lblIC1";
			this->lblIC1->ReadOnly = true;
			this->lblIC1->Size = System::Drawing::Size(64, 20);
			this->lblIC1->TabIndex = 8;
			this->lblIC1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
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
			this->lblButGenerateReport->Click += gcnew System::EventHandler(this, &Form1::lblButGenerateReport_Click);
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
			this->label17->Location = System::Drawing::Point(679, 348);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(105, 25);
			this->label17->TabIndex = 9;
			this->label17->Text = L"QTG Tool";
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
			// lblListBoxTests
			// 
			this->lblListBoxTests->FormattingEnabled = true;
			this->lblListBoxTests->HorizontalScrollbar = true;
			this->lblListBoxTests->Location = System::Drawing::Point(13, 127);
			this->lblListBoxTests->Name = L"lblListBoxTests";
			this->lblListBoxTests->Size = System::Drawing::Size(199, 212);
			this->lblListBoxTests->TabIndex = 11;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(10, 6);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(43, 13);
			this->label18->TabIndex = 12;
			this->label18->Text = L"Project:";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label20);
			this->panel1->Controls->Add(this->lblDialogProjectDate);
			this->panel1->Controls->Add(this->label19);
			this->panel1->Controls->Add(this->label18);
			this->panel1->Controls->Add(this->lblListBoxTests);
			this->panel1->Controls->Add(this->lblDialogProjectName);
			this->panel1->Location = System::Drawing::Point(11, 27);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(243, 356);
			this->panel1->TabIndex = 13;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(10, 107);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(87, 13);
			this->label20->TabIndex = 15;
			this->label20->Text = L"Tests to Perform:";
			this->label20->Click += gcnew System::EventHandler(this, &Form1::label20_Click);
			// 
			// lblDialogProjectDate
			// 
			this->lblDialogProjectDate->Location = System::Drawing::Point(13, 74);
			this->lblDialogProjectDate->Multiline = true;
			this->lblDialogProjectDate->Name = L"lblDialogProjectDate";
			this->lblDialogProjectDate->ReadOnly = true;
			this->lblDialogProjectDate->Size = System::Drawing::Size(199, 19);
			this->lblDialogProjectDate->TabIndex = 14;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(10, 58);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(87, 13);
			this->label19->TabIndex = 13;
			this->label19->Text = L"Date of Creation:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(846, 411);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->lblDispRes);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblButGenerateReport);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lblButReset);
			this->Controls->Add(this->lblButStart);
			this->Controls->Add(this->lblButLoad);
			this->Controls->Add(this->lblSelectBox);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"TRC Simulators - QTG Tool";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
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
			// Initialization of the form
			lblButStart->Enabled = false;
			lblButLoad->Enabled = false;
			lblSelectBox->Enabled = false;
			lblButReset->Enabled = false;
			lblCheckIC->Enabled = false;
			
			lblButGenerateReport->Enabled = true;
			
		 }
private: System::Void lblMenuNew_Click(System::Object^  sender, System::EventArgs^  e) {
			
			
			//SaveFileDialog
			SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
			saveFileDialog1->Filter = "Project File|*.proj";
			saveFileDialog1->Title = "Save the project file...";
			saveFileDialog1->OverwritePrompt = true;
			saveFileDialog1->ShowDialog();
			

			String^ sfileName = saveFileDialog1->FileName;

			/* CREATE DIRECTORY
			msclr::interop::marshal_context context;
			std::string str_aux = context.marshal_as<std::string>(sfileName);

			string key = "\\";
			unsigned found = str_aux.find_first_of(key);
			while(found != std::string::npos)
			{
				str_aux.replace (found,key.length(),"\\\\");
				found = str_aux.find_first_of("\\",found+2);
				
			}
			
			CreateDirectory((LPCTSTR)str_aux.c_str(), NULL);*/

			if(saveFileDialog1->FileName != "")
			{
				
				StreamWriter^ NewProjFile = gcnew StreamWriter(sfileName);
				NewProjFile->WriteLine(sfileName);//filename
				NewProjFile->WriteLine(DateTime::Now);//Date of Creation
				
				//List of Tests to Perform
				StreamReader^ sFile = File::OpenText("TestFiles\\TestsToPerform.txt");
				String^ str;
				
				while ((str = sFile->ReadLine()) != nullptr) 
				{
					NewProjFile->WriteLine(str); 
				
				
				}
				sFile->Close();
				
				
				
				//Close File and assig to working file
				sProjectFile = sfileName;
				NewProjFile->Close();
				loadProject(sfileName);
			}
			
		 }
private: System::Void lblDialog_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void lblMenuLoad_Click(System::Object^  sender, System::EventArgs^  e) {
			
			
			
			//OpenFileDialog
			OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->Filter = "Project File|*.proj";
			openFileDialog1->Title = "Open the project file...";
			openFileDialog1->ShowDialog();
			
			String^ sFileName =  openFileDialog1->FileName;
			if (File::Exists(sFileName) == true)
			{
				loadProject(sFileName);
			}
			

		 }
private: System::Void lblButLoad_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			int iTestNumber = lblSelectBox->SelectedIndex;
			iTestNumber++;
			
			if (SUCCEEDED(SimConnect_Open(&hSimConnect, "Open and Close", NULL, 0, 0, 0)))
			{
				if (LoadFlightFileSimConnect(iTestNumber) != true)
				{
					MessageBox::Show("Cannot load simulation test file!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
				else 
				{
					if (loadInitialConditions(iTestNumber) == true)
					{
						//Enable
						lblCheckIC->Enabled = true;
						lblButLoad->Enabled = false;
						lblSelectBox->Enabled = false;
			
					}
				}
			}
			else
				MessageBox::Show("Failed to connect to Prepar3D! Check if simulator is running	.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					
		 
			SimConnect_Close(hSimConnect);
		 
		 }
 
	 
		 

private: bool loadInitialConditions(int iTestNumber)
		 {
			String^ str;
			String^ sFileName = "InitialConditions/IC_TEST_" + Convert::ToString(iTestNumber) + ".txt" ;
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
					//Write IC in textLabels and assign to InitialConditions array
					str = streamActualFile->ReadLine(); InitialConditions[0] = Convert::ToDouble(str);
					lblIC1->Text = str;//1
					str = streamActualFile->ReadLine(); InitialConditions[1] = Convert::ToDouble(str);
					lblIC2->Text = str;//2
					str = streamActualFile->ReadLine(); InitialConditions[2] = Convert::ToDouble(str);
					lblIC3->Text = str;//3
					str = streamActualFile->ReadLine(); InitialConditions[3] = Convert::ToDouble(str);
					lblIC4->Text = str;//4
					str = streamActualFile->ReadLine(); InitialConditions[4] = Convert::ToDouble(str);
					lblIC5->Text = str;//5
					str = streamActualFile->ReadLine(); InitialConditions[5] = Convert::ToDouble(str);
					lblIC6->Text = str;//6
					str = streamActualFile->ReadLine(); InitialConditions[6] = Convert::ToDouble(str);
					lblIC7->Text = str;//7
					str = streamActualFile->ReadLine(); InitialConditions[7] = Convert::ToDouble(str);
					lblIC8->Text = str;//8
				
					streamActualFile->Close();
					
					return true;
					
					
				}
				else
				{
					//clear textLabels
					lblIC1->Text = "";
					lblIC2->Text = "";
					lblIC3->Text = "";
					lblIC4->Text = "";
					lblIC5->Text = "";
					lblIC6->Text = "";
					lblIC7->Text = "";
					lblIC8->Text = "";
					MessageBox::Show("Test file corrupted!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return false;
					
				}
				
			}		
			else
			{
				//clear textLabels
				lblIC1->Text = "";
				lblIC2->Text = "";
				lblIC3->Text = "";
				lblIC4->Text = "";
				lblIC5->Text = "";
				lblIC6->Text = "";
				lblIC7->Text = "";
				lblIC8->Text = "";
				MessageBox::Show("Test file not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return false;
			}
				 
		 }
private: void loadProject(String^ sFileName)
		 {
			StreamReader^ streamTestFile = File::OpenText(sFileName);
			String^ str;
			
			
			//Initialize Dialog and List box
			lblDialogProjectName->Text ="";
			lblDialogProjectDate->Text ="";
			lblListBoxTests->Items->Clear();
			

			//Read Project Name
			str = streamTestFile->ReadLine();
			//Manipulate to get project name out of directory
			msclr::interop::marshal_context context;
			std::string str_aux = context.marshal_as<std::string>(str);
			int i = str_aux.find_last_of("\\");
			str_aux=str_aux.erase (0,i+1);
			lblDialogProjectName->Text = gcnew String(str_aux.c_str());

						
			//Read Project Date
			str = streamTestFile->ReadLine();
			lblDialogProjectDate->Text = str;
			//Read test to perform
			while ((str = streamTestFile->ReadLine()) != nullptr) 
			{
				lblListBoxTests->Items->Add(str);
				
				
			}
			//Close File and assign to working file
			streamTestFile->Close();
			sProjectFile = sFileName;

			//Enable/Disable
			lblButStart->Enabled = false;
			lblButLoad->Enabled = true;
			lblCheckIC->Enabled = false;
			lblSelectBox->Enabled = true;
			lblButReset->Enabled = true;

		 }
private: System::Void checkBox1_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void lblButReset_Click(System::Object^  sender, System::EventArgs^  e) {
	
		lblButStart->Enabled = false;
		lblButLoad->Enabled = true;
		lblSelectBox->Enabled = true;
		lblCheckIC->Enabled = false;
			 
			 
		//If some error arises try including line HRESULT hr; and hr = SimConnect_Close(hSimConnect);

		
			 
		//SimConnect_Close(hSimConnect);

        //lblDialogProjectDate->Text="\nDisconnected from Prepar3D";
}
		 
private: System::Void label20_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		 }
private: System::Void lblButStart_Click(System::Object^  sender, System::EventArgs^  e) {
		
		int iTestNumber = lblSelectBox->SelectedIndex;
		iTestNumber++;

		/*StreamWriter^ myfile = gcnew StreamWriter("Plots/DATA_TESTE_1.txt");
		myfile->Close();
		
		check = 3;
		if(Start_TEST_1() == false)
		{
			 lblDialogProjectDate->Text="\nFaile to connect to Prepar3D!";
		}

		lblDialogProjectDate->Text = Convert::ToString(check);*/

		
		if(StartTestSimConnect(iTestNumber) == false)
		{
			 MessageBox::Show("Failed to connect to Prepar3D! Check if simulator is running	.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}

		
		 
		 
		 
		 
	}
private: System::Void lblButGenerateReport_Click(System::Object^  sender, System::EventArgs^  e) {

			
			FILE *pipe = _popen("pgnuplot -persist", "w");
			fprintf(pipe, "set term wxt\n");
			fprintf(pipe, "plot sin(x)\n");


			if (pipe != NULL)
			{
				lblDialogProjectDate->Text="Conseguiu";
			}
			else
				lblDialogProjectDate->Text="Não deu";
		
		 
		 _pclose(pipe);
		 
		 }

private: void Refresh_Simulator(int time){

			HRESULT hr;
			static enum EVENT_ID {
				 EVENT_PAUSE,
				 EVENT_UNPAUSE,
			};

			if (SUCCEEDED(SimConnect_Open(&hSimConnect, "Send Event PAUSE_UNPAUSE", NULL, 0, 0, 0)))
			{
				// Set the UNPAUSE STATE
				hr = SimConnect_MapClientEventToSimEvent(hSimConnect, EVENT_UNPAUSE, "PAUSE_OFF");
				SimConnect_TransmitClientEvent(hSimConnect, 0, EVENT_UNPAUSE, 0, SIMCONNECT_GROUP_PRIORITY_HIGHEST, SIMCONNECT_EVENT_FLAG_GROUPID_IS_PRIORITY);
				
				Sleep(time);//Enough Time!
				
				// Set the PAUSE STATE again
				hr = SimConnect_MapClientEventToSimEvent(hSimConnect, EVENT_PAUSE, "PAUSE_ON");
				SimConnect_TransmitClientEvent(hSimConnect, 0, EVENT_PAUSE, 0, SIMCONNECT_GROUP_PRIORITY_DEFAULT, SIMCONNECT_EVENT_FLAG_GROUPID_IS_PRIORITY);

			}
			else
			{
				MessageBox::Show("Cannot load simulation test file!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}




		 }
private: System::Void lblCheckIC_Click(System::Object^  sender, System::EventArgs^  e) {

		//Refresh Simulator 200ms (allow to load new inputs from user)
		Refresh_Simulator(200);
		
			 
		fCheckIC = 0;
		if(Start_CHECK_IC() == false)
		{
			 lblDialogProjectDate->Text="\nFaile to connect to Prepar3D!";
		}	
			
		//Throttle
		if((fCheckIC & 0x01) != 0)
			lblBeaconIC1->BackColor = System::Drawing::Color::Green;
		else
			lblBeaconIC1->BackColor = System::Drawing::Color::Red;

		//Mixture
		if((fCheckIC & 0x02) != 0)
			lblBeaconIC2->BackColor = System::Drawing::Color::Green;
		else
			lblBeaconIC2->BackColor = System::Drawing::Color::Red;

		//Trim
		if((fCheckIC & 0x04) != 0)
			lblBeaconIC3->BackColor = System::Drawing::Color::Green;
		else
			lblBeaconIC3->BackColor = System::Drawing::Color::Red;

		//Flaps
		if((fCheckIC & 0x08) != 0)
		{
			lblBeaconIC4->BackColor = System::Drawing::Color::Green;
			lblBeaconIC5->BackColor = System::Drawing::Color::Green;
		}
		else
		{
			lblBeaconIC4->BackColor = System::Drawing::Color::Red;
			lblBeaconIC5->BackColor = System::Drawing::Color::Red;
		}
			
		//Pitch Controller
		if((fCheckIC & 0x10) != 0)
			lblBeaconIC6->BackColor = System::Drawing::Color::Green;
		else
			lblBeaconIC6->BackColor = System::Drawing::Color::Red;

		//Roll Controller
		if((fCheckIC & 0x20) != 0)
			lblBeaconIC7->BackColor = System::Drawing::Color::Green;
		else
			lblBeaconIC7->BackColor = System::Drawing::Color::Red;

		//Rudder Controller
		if((fCheckIC & 0x40) != 0)
			lblBeaconIC8->BackColor = System::Drawing::Color::Green;
		else
			lblBeaconIC8->BackColor = System::Drawing::Color::Red;


		if((fCheckIC & 0xFF) == 0x7F)//All Initial Conditions are right
		{
			//Enable Start
			lblButStart->Enabled = true;
			lblCheckIC->Enabled = false;

		}
		else
		{
			//Disable Start
			lblButStart->Enabled = false;
			lblCheckIC->Enabled = true;
		}
	
		 
	}

		 
private: System::Void label16_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};



}

