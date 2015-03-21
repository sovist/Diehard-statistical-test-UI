#pragma once

#include "..//code_files/include/libdieharder.h"
#include "../code_files/include/dieharder.h"
#include "TableForm.h"
#include "SettingsForm.h"
#include "FormAboutDiehard.h"

#using <mscorlib.dll>

#include <Windows.h>
#include <typeinfo> 
#include <string>
#include <tchar.h>
#include <cstddef> // for std::size_t
#include <shellapi.h>
#pragma comment(lib,"shell32.lib")
static HWND hBut;
namespace Diehard 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;
	using namespace System::IO;
	using namespace System::Globalization;
	using namespace System::Resources;
	using namespace System::Reflection;

	using std::string;
	using std::wstring;
	/// <summary>
	/// Summary for MainForm
	/// </summary>

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public: static MainForm^ _form; // ссилка на поточну форму, щоб її закривати
	public: static String^ _newCulture; // для відкриття нової форми з іншою мовою

	private: TableForm^ _tableForm;
	private: SettingsForm^ _settingForm;
	private: DateTime _startTime;
	private: System::Windows::Forms::ProgressBar^  progressBarProgress;
	private: bool showMessageErrLock;
	private: bool lockcomboBox_CheckedChanged;
			 Thread^ _ThreadDieHard;
			 Thread^ _ThreadTableForm;
			 Thread^ _ThreadProgress;
			 double _progressTestlInc;

	private: System::Windows::Forms::Label^  labelFileRewound;
	private: System::Windows::Forms::Label^  labelFileSize;
	private: System::Windows::Forms::TextBox^  textBoxSeed;
	private: System::Windows::Forms::Label^  labelSeed;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemHelp;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAboutDiehard;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButton1;
	private: System::Windows::Forms::ToolStripMenuItem^  UA;
	private: System::Windows::Forms::ToolStripMenuItem^  Rus;
	private: System::Windows::Forms::ToolStripMenuItem^  Eng;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolStripMenuItemViewHelp;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolTip^  toolTip1;
		
	public:
		MainForm(String^ culture)
		{
			InitializeComponent();

			_currentCulture = culture;
			AddGenerators(comboBoxEmbeddedGenerators);
			radioButtonEmbeddedGenerators->Checked = true;

			AddTests(groupBoxTests);
			lockcomboBox_CheckedChanged = false;
			showMessageErrLock = false;

			comboBoxReadFormat->SelectedIndex = 0;

			toolStripDropDownButton1->DropDownItems[0]->Text = (gcnew CultureInfo(L"uk-UA"))->NativeName;
			toolStripDropDownButton1->DropDownItems[1]->Text = (gcnew CultureInfo(L"ru-RU"))->NativeName;
			toolStripDropDownButton1->DropDownItems[2]->Text = (gcnew CultureInfo(L"en-US"))->NativeName;
			ChangeFormLanguage(culture);

			toolTip1->SetToolTip(buttonInputFile, GetResourceManagerFildName("toolTipbuttonInputFile"));
			toolTip1->SetToolTip(buttonTest, GetResourceManagerFildName("toolTipbuttonTest"));
			toolTip1->SetToolTip(buttonStop, GetResourceManagerFildName("toolTipbuttonStop"));
			toolTip1->SetToolTip(comboBoxEmbeddedGenerators, GetResourceManagerFildName("toolTipcomboBoxEmbeddedGenerators"));
			toolTip1->SetToolTip(progressBarProgress, GetResourceManagerFildName("toolTipprogressBarProgress"));
			toolTip1->SetToolTip(statusStrip1, GetResourceManagerFildName("toolTipstatusStrip1"));
			toolTip1->SetToolTip(radioButtonInputFile, GetResourceManagerFildName("toolTipradioButtonInputFile"));
			toolTip1->SetToolTip(radioButtonEmbeddedGenerators, GetResourceManagerFildName("toolTipradioButtonEmbeddedGenerators"));
			toolTip1->SetToolTip(labelFileRewound, GetResourceManagerFildName("toolTiplabelFileRewound"));
			toolTip1->SetToolTip(labelFileSize, GetResourceManagerFildName("toolTiplabelFileSize"));	
			toolTip1->SetToolTip(checkBoxSelAll, GetResourceManagerFildName("toolTipcheckBoxSelAll"));
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBoxGeneratorSelecting;
	private: System::Windows::Forms::ComboBox^  comboBoxReadFormat;

	private: System::Windows::Forms::Label^  labelReadFormat;
	private: System::Windows::Forms::Button^  buttonInputFile;
	private: System::Windows::Forms::TextBox^  textBoxInputFile;
	private: System::Windows::Forms::RadioButton^  radioButtonInputFile;
	private: System::Windows::Forms::ComboBox^  comboBoxEmbeddedGenerators;
	private: System::Windows::Forms::RadioButton^  radioButtonEmbeddedGenerators;
	private: System::Windows::Forms::GroupBox^  groupBoxTests;
	private: System::Windows::Forms::Button^  buttonTest;
	private: System::Windows::Forms::Button^  buttonStop;
	private: System::Windows::Forms::Button^  buttonSettings;
	private: System::ComponentModel::IContainer^  components;

	protected: 
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->groupBoxGeneratorSelecting = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxSeed = (gcnew System::Windows::Forms::TextBox());
			this->labelSeed = (gcnew System::Windows::Forms::Label());
			this->labelFileSize = (gcnew System::Windows::Forms::Label());
			this->labelFileRewound = (gcnew System::Windows::Forms::Label());
			this->comboBoxEmbeddedGenerators = (gcnew System::Windows::Forms::ComboBox());
			this->radioButtonEmbeddedGenerators = (gcnew System::Windows::Forms::RadioButton());
			this->comboBoxReadFormat = (gcnew System::Windows::Forms::ComboBox());
			this->labelReadFormat = (gcnew System::Windows::Forms::Label());
			this->buttonInputFile = (gcnew System::Windows::Forms::Button());
			this->textBoxInputFile = (gcnew System::Windows::Forms::TextBox());
			this->radioButtonInputFile = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxTests = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSettings = (gcnew System::Windows::Forms::Button());
			this->buttonTest = (gcnew System::Windows::Forms::Button());
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			this->progressBarProgress = (gcnew System::Windows::Forms::ProgressBar());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItemHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolStripMenuItemViewHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemAboutDiehard = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->UA = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Rus = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Eng = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->groupBoxGeneratorSelecting->SuspendLayout();
			this->groupBoxTests->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBoxGeneratorSelecting
			// 
			this->groupBoxGeneratorSelecting->Controls->Add(this->textBoxSeed);
			this->groupBoxGeneratorSelecting->Controls->Add(this->labelSeed);
			this->groupBoxGeneratorSelecting->Controls->Add(this->labelFileSize);
			this->groupBoxGeneratorSelecting->Controls->Add(this->labelFileRewound);
			this->groupBoxGeneratorSelecting->Controls->Add(this->comboBoxEmbeddedGenerators);
			this->groupBoxGeneratorSelecting->Controls->Add(this->radioButtonEmbeddedGenerators);
			this->groupBoxGeneratorSelecting->Controls->Add(this->comboBoxReadFormat);
			this->groupBoxGeneratorSelecting->Controls->Add(this->labelReadFormat);
			this->groupBoxGeneratorSelecting->Controls->Add(this->buttonInputFile);
			this->groupBoxGeneratorSelecting->Controls->Add(this->textBoxInputFile);
			this->groupBoxGeneratorSelecting->Controls->Add(this->radioButtonInputFile);
			resources->ApplyResources(this->groupBoxGeneratorSelecting, L"groupBoxGeneratorSelecting");
			this->groupBoxGeneratorSelecting->Name = L"groupBoxGeneratorSelecting";
			this->groupBoxGeneratorSelecting->TabStop = false;
			// 
			// textBoxSeed
			// 
			resources->ApplyResources(this->textBoxSeed, L"textBoxSeed");
			this->textBoxSeed->Name = L"textBoxSeed";
			// 
			// labelSeed
			// 
			resources->ApplyResources(this->labelSeed, L"labelSeed");
			this->labelSeed->Name = L"labelSeed";
			// 
			// labelFileSize
			// 
			resources->ApplyResources(this->labelFileSize, L"labelFileSize");
			this->labelFileSize->Name = L"labelFileSize";
			// 
			// labelFileRewound
			// 
			resources->ApplyResources(this->labelFileRewound, L"labelFileRewound");
			this->labelFileRewound->Name = L"labelFileRewound";
			// 
			// comboBoxEmbeddedGenerators
			// 
			this->comboBoxEmbeddedGenerators->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxEmbeddedGenerators->FormattingEnabled = true;
			resources->ApplyResources(this->comboBoxEmbeddedGenerators, L"comboBoxEmbeddedGenerators");
			this->comboBoxEmbeddedGenerators->Name = L"comboBoxEmbeddedGenerators";
			// 
			// radioButtonEmbeddedGenerators
			// 
			resources->ApplyResources(this->radioButtonEmbeddedGenerators, L"radioButtonEmbeddedGenerators");
			this->radioButtonEmbeddedGenerators->Name = L"radioButtonEmbeddedGenerators";
			this->radioButtonEmbeddedGenerators->UseVisualStyleBackColor = true;
			this->radioButtonEmbeddedGenerators->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButtonInputFile_CheckedChanged);
			// 
			// comboBoxReadFormat
			// 
			this->comboBoxReadFormat->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			resources->ApplyResources(this->comboBoxReadFormat, L"comboBoxReadFormat");
			this->comboBoxReadFormat->FormattingEnabled = true;
			this->comboBoxReadFormat->Items->AddRange(gcnew cli::array< System::Object^  >(2) {resources->GetString(L"comboBoxReadFormat.Items"), 
				resources->GetString(L"comboBoxReadFormat.Items1")});
			this->comboBoxReadFormat->Name = L"comboBoxReadFormat";
			// 
			// labelReadFormat
			// 
			resources->ApplyResources(this->labelReadFormat, L"labelReadFormat");
			this->labelReadFormat->Name = L"labelReadFormat";
			// 
			// buttonInputFile
			// 
			resources->ApplyResources(this->buttonInputFile, L"buttonInputFile");
			this->buttonInputFile->Name = L"buttonInputFile";
			this->buttonInputFile->UseVisualStyleBackColor = true;
			this->buttonInputFile->Click += gcnew System::EventHandler(this, &MainForm::buttonInputFile_Click);
			// 
			// textBoxInputFile
			// 
			resources->ApplyResources(this->textBoxInputFile, L"textBoxInputFile");
			this->textBoxInputFile->Name = L"textBoxInputFile";
			this->textBoxInputFile->ReadOnly = true;
			// 
			// radioButtonInputFile
			// 
			resources->ApplyResources(this->radioButtonInputFile, L"radioButtonInputFile");
			this->radioButtonInputFile->Name = L"radioButtonInputFile";
			this->radioButtonInputFile->UseVisualStyleBackColor = true;
			this->radioButtonInputFile->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButtonInputFile_CheckedChanged);
			// 
			// groupBoxTests
			// 
			this->groupBoxTests->Controls->Add(this->buttonSettings);
			resources->ApplyResources(this->groupBoxTests, L"groupBoxTests");
			this->groupBoxTests->Name = L"groupBoxTests";
			this->groupBoxTests->TabStop = false;
			// 
			// buttonSettings
			// 
			resources->ApplyResources(this->buttonSettings, L"buttonSettings");
			this->buttonSettings->Name = L"buttonSettings";
			this->buttonSettings->UseVisualStyleBackColor = true;
			this->buttonSettings->Click += gcnew System::EventHandler(this, &MainForm::buttonSettings_Click);
			// 
			// buttonTest
			// 
			resources->ApplyResources(this->buttonTest, L"buttonTest");
			this->buttonTest->Name = L"buttonTest";
			this->buttonTest->UseVisualStyleBackColor = true;
			this->buttonTest->Click += gcnew System::EventHandler(this, &MainForm::buttonTest_Click);
			// 
			// buttonStop
			// 
			resources->ApplyResources(this->buttonStop, L"buttonStop");
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->UseVisualStyleBackColor = true;
			this->buttonStop->Click += gcnew System::EventHandler(this, &MainForm::buttonStop_Click);
			// 
			// progressBarProgress
			// 
			resources->ApplyResources(this->progressBarProgress, L"progressBarProgress");
			this->progressBarProgress->Name = L"progressBarProgress";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripMenuItemHelp});
			resources->ApplyResources(this->menuStrip1, L"menuStrip1");
			this->menuStrip1->Name = L"menuStrip1";
			// 
			// toolStripMenuItemHelp
			// 
			this->toolStripMenuItemHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->ToolStripMenuItemViewHelp, 
				this->toolStripSeparator1, this->toolStripMenuItemAboutDiehard});
			this->toolStripMenuItemHelp->Name = L"toolStripMenuItemHelp";
			resources->ApplyResources(this->toolStripMenuItemHelp, L"toolStripMenuItemHelp");
			// 
			// ToolStripMenuItemViewHelp
			// 
			this->ToolStripMenuItemViewHelp->Name = L"ToolStripMenuItemViewHelp";
			resources->ApplyResources(this->ToolStripMenuItemViewHelp, L"ToolStripMenuItemViewHelp");
			this->ToolStripMenuItemViewHelp->Click += gcnew System::EventHandler(this, &MainForm::ToolStripMenuItemViewHelp_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			resources->ApplyResources(this->toolStripSeparator1, L"toolStripSeparator1");
			// 
			// toolStripMenuItemAboutDiehard
			// 
			this->toolStripMenuItemAboutDiehard->Name = L"toolStripMenuItemAboutDiehard";
			resources->ApplyResources(this->toolStripMenuItemAboutDiehard, L"toolStripMenuItemAboutDiehard");
			this->toolStripMenuItemAboutDiehard->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAboutDiehard_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripStatusLabel1, 
				this->toolStripDropDownButton1});
			resources->ApplyResources(this->statusStrip1, L"statusStrip1");
			this->statusStrip1->Name = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			resources->ApplyResources(this->toolStripStatusLabel1, L"toolStripStatusLabel1");
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->UA, 
				this->Rus, this->Eng});
			resources->ApplyResources(this->toolStripDropDownButton1, L"toolStripDropDownButton1");
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			// 
			// UA
			// 
			this->UA->Name = L"UA";
			resources->ApplyResources(this->UA, L"UA");
			this->UA->Click += gcnew System::EventHandler(this, &MainForm::UA_Click);
			// 
			// Rus
			// 
			this->Rus->Name = L"Rus";
			resources->ApplyResources(this->Rus, L"Rus");
			this->Rus->Click += gcnew System::EventHandler(this, &MainForm::Rus_Click);
			// 
			// Eng
			// 
			this->Eng->Name = L"Eng";
			resources->ApplyResources(this->Eng, L"Eng");
			this->Eng->Click += gcnew System::EventHandler(this, &MainForm::Eng_Click);
			// 
			// MainForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->progressBarProgress);
			this->Controls->Add(this->buttonStop);
			this->Controls->Add(this->buttonTest);
			this->Controls->Add(this->groupBoxTests);
			this->Controls->Add(this->groupBoxGeneratorSelecting);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->LocationChanged += gcnew System::EventHandler(this, &MainForm::MainForm_LocationChanged);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseClick);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			this->groupBoxGeneratorSelecting->ResumeLayout(false);
			this->groupBoxGeneratorSelecting->PerformLayout();
			this->groupBoxTests->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void AddGenerators(ComboBox^ comboBox)
		{
			dieharder_rng_types();

			for(int i = 0; i < MAXRNGS; i++)
				if(dh_rng_types[i] != 0 && (i < 200 || i > 202) && i != 207)
					comboBox->Items->Add(gcnew String(string(dh_rng_types[i]->name).c_str()));

			comboBox->SelectedIndex = 13;
		}

	private: CheckBox^ checkBoxSelAll;
			 void AddTests(GroupBox^ groupBox)
			 {				
				 dieharder_test_types();

				 int top = 15;
				 int left_ = 15;
				 int height = 19;
				 int numbersInColumn = 12;
				 int width = 220;
				 int j = 0, k = 0;

				 for(int i = 0; i < MAXTESTS; i++)
					 if(dh_test_types[i] != 0)
					 {
						 CheckBox^ checkBox = gcnew CheckBox();
						 checkBox->Name = gcnew String(string(dh_test_types[i]->sname).c_str());
						 checkBox->Text = gcnew String(string(dh_test_types[i]->name).c_str());
						 checkBox->Checked = true;
						 checkBox->Top = top + j++ * height;
						 checkBox->Left = left_ + width * k;
						 checkBox->Width = TextRenderer::MeasureText(checkBox->Text, checkBox->Font).Width + 50;
						 checkBox->CheckedChanged += gcnew EventHandler(this, &MainForm::comboBox_CheckedChanged);

						 groupBox->Controls->Add(checkBox);

						 if(j % numbersInColumn == 0)
						 {
							 j = 0;
							 k++;
						 }
					 }

					 checkBoxSelAll = gcnew CheckBox();
					 checkBoxSelAll->Name = "SelectAll";
					 checkBoxSelAll->Text = GetResourceManagerFildName("SelectAll");
					 checkBoxSelAll->Checked = true;
					 checkBoxSelAll->Top = top + (j + 4) * height;
					 checkBoxSelAll->Left = left_ + width * k++;
					 checkBoxSelAll->Width = TextRenderer::MeasureText(checkBoxSelAll->Text, checkBoxSelAll->Font).Width + 20;
					 checkBoxSelAll->CheckedChanged += gcnew EventHandler(this, &MainForm::comboBox_CheckedChanged);

					 groupBox->Controls->Add(checkBoxSelAll);
			 }

	private: 
		System::Void comboBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			if (lockcomboBox_CheckedChanged)
				return;

			if(((CheckBox^)sender)->Name == "SelectAll")
			{
				lockcomboBox_CheckedChanged = true;
				for each (Control^ control in groupBoxTests->Controls)
					if(control->GetType() == CheckBox::typeid)
						if(((CheckBox^)control)->Name!= "SelectAll")
							((CheckBox^)control)->Checked = ((CheckBox^)sender)->Checked;
				lockcomboBox_CheckedChanged = false;
				return;
			}

			int selNumbers = 0;
			for each (Control^ control in groupBoxTests->Controls)
				if(control->GetType() == CheckBox::typeid)
					if(((CheckBox^)control)->Name != "SelectAll" && ((CheckBox^)control)->Checked)
						selNumbers++;

			lockcomboBox_CheckedChanged = true;
			checkBoxSelAll->Checked = selNumbers == 31;
			lockcomboBox_CheckedChanged = false;
		}

	private: 
		System::Void radioButtonInputFile_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			textBoxInputFile->Enabled = radioButtonInputFile->Checked;
			buttonInputFile->Enabled = radioButtonInputFile->Checked;
			//labelReadFormat->Enabled = radioButtonInputFile->Checked;
			//comboBoxReadFormat->Enabled = radioButtonInputFile->Checked;
			labelFileRewound->Enabled = radioButtonInputFile->Checked;
			labelFileSize->Enabled = radioButtonInputFile->Checked;

			comboBoxEmbeddedGenerators->Enabled = !radioButtonInputFile->Checked;
			labelSeed->Enabled = !radioButtonInputFile->Checked;
			textBoxSeed->Enabled = !radioButtonInputFile->Checked;

			if(!radioButtonInputFile->Checked)
				textBoxSeed->Text = random_seed().ToString();
		}

	private: 
		System::Void buttonInputFile_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

			if(openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				textBoxInputFile->Text = openFileDialog->FileName;
				strncpy(filename, StringToCharPtr(openFileDialog->FileName), 1000);
				labelFileSize->Text = GetResourceManagerFildName("Size") + FileSizeInfo(openFileDialog->FileName);
			}
		}

		char* StringToCharPtr(String^ str)
		{
			return (char*)(void*)Marshal::StringToHGlobalAnsi(str);
		}

		wstring s2ws(const string& s)
		{
			int slength = (int)s.length() + 1;
			int len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 

			wchar_t* buf = new wchar_t[len];
			MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);

			wstring r(buf);
			delete[] buf;
			return r;
		}
	private: System::Void MainForm_Resize(System::Object^  sender, System::EventArgs^  e) 
			 {
				 MainForm_LocationChanged(gcnew Object(), gcnew EventArgs());
			 }
	private: 
		System::Void MainForm_LocationChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			if (_tableForm == nullptr)
				return;

			if (!_tableForm->Visible)
				return;

			int screenWidth;
			for each (Screen^ screen in Screen::AllScreens) 
				if(screen->Primary)
					screenWidth = screen->WorkingArea.Width;

			_tableForm->Top = Top /*+ 20*/;

			if(Left + Width + _tableForm->Width < screenWidth)		 
				_tableForm->Left = Left + Width;
			else
				_tableForm->Left = Left - _tableForm->Width;

			_tableForm->Focus();
		}

	private: System::Void MainForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			 {
				 if (_tableForm == nullptr)
					 return;

				 _tableForm->Focus();
			 }

	private:
		System::Void buttonTest_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			set_globals();
			if(textBoxInputFile->Text == String::Empty && radioButtonInputFile->Checked)
			{
				MessageBox::Show(GetResourceManagerFildName("SelectInputFile") + "\n", "Diehard", MessageBoxButtons::OK, MessageBoxIcon::Information); 
				return;
			}			
			try
			{
				Seed = Int64::Parse(textBoxSeed->Text);
			}
			catch (Exception^ e)
			{
				MessageBox::Show(e->Message, "Diehard", MessageBoxButtons::OK, MessageBoxIcon::Error); 
				return;
			}

			all = 1;
			first_file_input_raw_set = 1;
			fileRewound = 0;
			fromfile = radioButtonInputFile->Checked;
			String^ ganeratorName;
			if(radioButtonInputFile->Checked)
			{
				if(comboBoxReadFormat->SelectedIndex == 0) //Binary
					gnumbs[0] = 201; //Binary reader
				else //ACSII
					gnumbs[0] = 202; //ACSII reader

				ganeratorName = textBoxInputFile->Text;
			}
			else
			{
				for(int i = 0; i < MAXRNGS; i++)
					if(dh_rng_types[i] != 0)
						if(comboBoxEmbeddedGenerators->Text == gcnew String(dh_rng_types[i]->name))
						{
							gnumbs[0] = i;
							break;
						}
						ganeratorName = comboBoxEmbeddedGenerators->Text;
			}

			bool selTest = false;
			int progressMax = 0, numberSelTest = 0;
			for (int i = 0; i < MAXTESTS; i++)
			{
				if(dh_test_types[i] != 0)
				{
					SelTest[i] = TestIsChecked(gcnew String(dh_test_types[i]->name));
					if(SelTest[i])
					{
						progressMax += dh_test_types[i]->psamples_std;
						numberSelTest++;
					}
					if(!selTest)
						selTest = SelTest[i];
				}
				else
					SelTest[i] = 0;
			}

			if(!selTest)
			{
				MessageBox::Show(GetResourceManagerFildName("SelectTest"), "Diehard", MessageBoxButtons::OK, MessageBoxIcon::Information); 
				return;
			}

			statusStrip1->Enabled = false;
			groupBoxGeneratorSelecting->Enabled = false;
			groupBoxTests->Enabled = false;
			buttonTest->Enabled = false;
			buttonStop->Enabled = true;

			progressGeneral = 0;
			progressTest = 0;
			progressGeneralInc = Math::Floor(progressMax / numberSelTest);
			_progressTestlInc = progressGeneralInc;
			progressBarProgress->Maximum = progressMax;
			progressBarProgress->Value = 0;
			progressBarProgress->Visible = true;

			if(_tableForm != nullptr)
				_tableForm->Close();

			(_tableForm = gcnew TableForm(ganeratorName, _currentCulture))->Show();
			MainForm_LocationChanged(gcnew Object(), gcnew EventArgs());

			_ThreadTableForm = gcnew Thread(gcnew ThreadStart(this, &Diehard::MainForm::Proc));
			_ThreadTableForm->IsBackground = true;
			_ThreadTableForm->Start();

			_ThreadProgress = gcnew Thread(gcnew ThreadStart(this, &Diehard::MainForm::UpdateProgress));
			_ThreadProgress->IsBackground = true;
			_ThreadProgress->Start();

			_startTime = DateTime::Now;
			_ThreadDieHard = gcnew Thread(gcnew ThreadStart(this, &Diehard::MainForm::DieHard_Proc));
			_ThreadDieHard->IsBackground = true;
			_ThreadDieHard->Start();
		}
	private: 
		void DieHard_Proc()
		{	
			bool err = false;
			try
			{
				//verbose = 1;
				//tflag  = 1;
				tflag = tflag_default;
				mainDeahard(); 
			}

			catch(Exception^ e)
			{
				if(!showMessageErrLock)
					MessageBox::Show("Tests error!\n" + e->Message, "Diehard", MessageBoxButtons::OK, MessageBoxIcon::Error);  
			}
		}
	private: void Proc()
			 {	              
				 try
				 {
					 Globals::_tableForm = _tableForm;
				 }

				 catch(Exception^ e)
				 {
					 if(!showMessageErrLock)
						 MessageBox::Show("Tests error!\n" + e->Message, "Diehard", MessageBoxButtons::OK, MessageBoxIcon::Error);  
				 }
			 }

			 delegate void DelegateThreadTask();
	private: 
		void ThreadTask()
		{
			if (!progressBarProgress->InvokeRequired)
			{
				progressBarProgress->Value = progressGeneral + progressTest;
				labelFileRewound->Text = String::Format(GetResourceManagerFildName("FileRewound1") + "{0}" + GetResourceManagerFildName("FileRewound2"), fileRewound);

				if(dh_test_types[dtest_num] != 0 && dtest_num != -1)
					SetFont(gcnew String(dh_test_types[dtest_num]->name));

				Application::DoEvents();
			}
			else 
			{
				DelegateThreadTask^ myThreadDelegate = gcnew DelegateThreadTask(this, &Diehard::MainForm::ThreadTask);      
				this->Invoke(myThreadDelegate);			
			}
		}
	private: 
		void UpdateProgress()
		{	
			while(true)
			{
				ThreadTask();
				Thread::Sleep(100);

				if (!_ThreadDieHard->IsAlive)
				{	
					progressTest = 0;
					progressGeneral = progressBarProgress->Maximum; 
					ThreadTask();
					Thread::Sleep(900);//показати прогрес завершеним;
					TestDone();
					_ThreadProgress->Abort();   
				}
			}
		}

		delegate void DelegateTestDone();
	private: void TestDone()
			 {	
				 if(!progressBarProgress->InvokeRequired)
				 {
					 statusStrip1->Enabled = true;
					 groupBoxGeneratorSelecting->Enabled = true;
					 groupBoxTests->Enabled = true;
					 buttonTest->Enabled = true;
					 buttonStop->Enabled = false;
					 progressBarProgress->Visible = false;
					 SetFont("none");
					 MessageBox::Show(GetResourceManagerFildName("TestsIsDone") + "\n" + GetResourceManagerFildName("ElapsedTime") + " " + (DateTime::Now - _startTime).ToString()->Substring(0,11), "Diehard", MessageBoxButtons::OK, MessageBoxIcon::Information);
				 }
				 else
				 {
					 DelegateTestDone^ delegateTestDone = gcnew DelegateTestDone(this, &Diehard::MainForm::TestDone);
					 this->Invoke(delegateTestDone);
				 }
			 }

	private: void SetFont(String^ checkBoxText)
			 {
				 for each (Control^ control in groupBoxTests->Controls)
					 if(control->GetType() == CheckBox::typeid)
					 {
						 CheckBox^ box = ((CheckBox^)control);
						 if(box->Text != "Select all")
						 {	
							 int len = checkBoxText->Length > box->Text->Length ? box->Text->Length : checkBoxText->Length;
							 if(box->Text->Substring(0, len) == checkBoxText)
							 {
								 box->Font = gcnew System::Drawing::Font(box->Font->FontFamily, box->Font->Size, FontStyle::Italic + FontStyle::Underline);
								 if(progressTest!= 0)//не відображати 0%
									box->Text = checkBoxText + " " + (100 * progressTest / (_progressTestlInc + 0.001)).ToString("f0") + "%";
								 break;
							 }
							 else
							 {							 
								 if(box->Text[box->Text->Length - 1] == '%')//видалити - " 100%"
									 box->Text = box->Text->Substring(0, box->Text->LastIndexOf(' '));								 
								 box->Font = gcnew System::Drawing::Font(box->Font->FontFamily, box->Font->Size, FontStyle::Regular);
							 }
						 }
					 }
			 }

	private: 
		System::Void buttonStop_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			showMessageErrLock = true;

			if (_ThreadDieHard != nullptr)
				if (_ThreadDieHard->IsAlive)
					_ThreadDieHard->Abort();

			if (_ThreadTableForm != nullptr)
				if (_ThreadTableForm->IsAlive)
					_ThreadTableForm->Abort();

			if (_ThreadProgress != nullptr)
				if (_ThreadProgress->IsAlive)
					_ThreadProgress->Abort();

			if(inputFile != NULL)
				fclose(inputFile);

			TestDone();
			SetFont("none");
			showMessageErrLock = false;
		}
	private: System::Void buttonSettings_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (_settingForm != nullptr)								 
					 _settingForm->Close();

				 _settingForm = gcnew SettingsForm();
				 for (int i = 0; i < MAXTESTS; i++)
					 if(dh_test_types[i] != 0)
						 if(TestIsChecked(gcnew String(dh_test_types[i]->name)))
							 _settingForm->AddLineInTable(dh_test_types[i]);
				 _settingForm->Show();
				 _settingForm->Top = Top + 40;
				 _settingForm->Left = Left + 20;
			 }

			 bool TestIsChecked(String^ testName)
			 {
				 for each (Control^ control in groupBoxTests->Controls)
					 if (control->GetType() == CheckBox::typeid)
						 if(((CheckBox^ )control)->Text == testName)
							 return ((CheckBox^ )control)->Checked;
			 }

	public: 
		System::String^ FileSizeInfo(System::String^ fileName) 
		{
			System::IO::FileInfo^ fileInfo = gcnew System::IO::FileInfo(fileName);
			array<String^>^ degree = gcnew array<String^>{"", "K", "M", "G"};

			long long size = fileInfo->Length;
			int divider = 1024, index = 0;
			for ( ; size >= divider && index < degree->Length; index++)
				size /= divider;

			String^ fullSize  = fileInfo->Length.ToString("### ### ### ###")->TrimStart(' ');
			return " - " + size.ToString("f2") + " " + degree[index] + "b (" + fullSize + " bytes)";
		}

	private: 
		System::Void toolStripMenuItemAboutDiehard_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			FormAboutDiehard^ form = gcnew FormAboutDiehard(_currentCulture);
			form->Show();
			form->Top = Top + 40;
			form->Left = Left + 20;
		}

		private: 
			System::Void ToolStripMenuItemViewHelp_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				String^ helpFile = Environment::CurrentDirectory + "\\help\\dieharder_hlp_" + _currentCulture + ".chm";

				string stringHelpFile = string("hh.exe ") +  (char*)(void*)Marshal::StringToHGlobalAnsi(helpFile);

				WinExec(stringHelpFile.c_str(), SW_RESTORE);
			}

	private: 
		String^ GetResourceManagerFildName(String^ stringName)
		{
			return (gcnew ResourceManager("Diehard." + _currentCulture, MainForm::typeid->Assembly))->GetString(stringName);
		}

	private: String^ _currentCulture;
	private: void ChangeFormLanguage(String^ newLanguageString)
			 {
				 _currentCulture = newLanguageString;

				 ChangeCulture(newLanguageString, MainForm::Controls);
				 ChangeCulture(newLanguageString, groupBoxGeneratorSelecting->Controls);
				 ChangeCulture(newLanguageString, statusStrip1->Controls);

				 ComponentResourceManager^ resources = gcnew ComponentResourceManager(MainForm::GetType());
				 CultureInfo^ newCultureInfo = gcnew CultureInfo(newLanguageString);

				 resources->ApplyResources(toolStripStatusLabel1, toolStripStatusLabel1->Name, newCultureInfo);
				 resources->ApplyResources(toolStripMenuItemHelp, toolStripMenuItemHelp->Name, newCultureInfo);
				 resources->ApplyResources(toolStripMenuItemAboutDiehard, toolStripMenuItemAboutDiehard->Name, newCultureInfo);
				 resources->ApplyResources(ToolStripMenuItemViewHelp, ToolStripMenuItemViewHelp->Name, newCultureInfo);

				 if (checkBoxSelAll != nullptr)
				     checkBoxSelAll->Text = GetResourceManagerFildName("SelectAll");

				 toolStripDropDownButton1->Text = newCultureInfo->NativeName;

				 for each (ToolStripMenuItem^ languageButton in toolStripDropDownButton1->DropDownItems)
					 languageButton->Checked = (languageButton->Text == toolStripDropDownButton1->Text);
			 }

	private: 
		void ChangeCulture(String^ newLanguageString, Control::ControlCollection^ controls)
		{
			ComponentResourceManager^ resources = gcnew ComponentResourceManager(MainForm::GetType());

			CultureInfo^ newCultureInfo = gcnew CultureInfo(newLanguageString);

			for each (Control^ control in controls)
				resources->ApplyResources(control, control->Name, newCultureInfo);
		}

private: 
		System::Void UA_Click(System::Object^  sender, System::EventArgs^  e) 
		{
		  _newCulture = "uk-UA";
		  _form->Close();
		}

	private: 
		System::Void Rus_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			_newCulture = "ru-RU";
			_form->Close();
		}
	private: 
		System::Void Eng_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			_newCulture = "en-US";
			_form->Close();
		}
};
}