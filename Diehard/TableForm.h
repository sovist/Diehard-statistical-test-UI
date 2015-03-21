#pragma once
#include "..//code_files/include/Dtest.h"

namespace Diehard 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;

	using namespace System::Globalization;
	using namespace System::Resources;
	using namespace System::Reflection;
	//using namespace System::Windows::Controls::Primitives;

	public enum class TestRezult { Failed, Weak, Passed };
	/// <summary>
	/// Summary for TableForm
	/// </summary>
	public ref class TableForm : public System::Windows::Forms::Form
	{
	private: String^ _ganeretorName;
             String^ _culture;
	public:
		TableForm(String^ ganeretorName, String^ culture)
		{
			InitializeComponent();
			_culture = culture;
			Create(dataGridView1);
			_isMaxHeight = false;
			_ganeretorName = ganeretorName;
			//AddLineInTable("dgg", 9.88888, TestRezult::Failed);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TableForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;





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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TableForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(389, 249);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TableForm::dataGridView1_MouseDown);
			// 
			// TableForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(401, 261);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"TableForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"TableForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: Dtest *_dtest;
			 Test *_test; 
			 TestRezult _testRez;
			 bool _isMaxHeight;
			 delegate System::Void delegateAddLineInTable();
			 System::Void AddLineInTable() { AddLineInTable(_dtest, _test, _testRez); }
	public:
		System::Void AddLineInTable(Dtest *dtest, Test *test, TestRezult testRez)
		{
			_testRez = testRez;
			_dtest = dtest;
			_test = test;

			if (!dataGridView1->InvokeRequired)
			{
				//спочатку збільшити висоту таблиці, а потім додавати нову строку, щоб VScrollBar не проскакува.
				int rowHeight = 18;
				if(!_isMaxHeight)
					if(Height > 520)
					{
						dataGridView1->Width = dataGridView1->Width + 17;//Для VScrollBar
						Width = dataGridView1->Width;
						_isMaxHeight = true;
					}
					else
					{
						dataGridView1->Height += rowHeight;
						Height = dataGridView1->Height;
					}

				DataGridViewRow^ row;
				dataGridView1->Rows->Add(gcnew String(dtest->name), "");
				dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[1]->Value = test->ntuple;
				dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[2]->Value = Math::Round(test->ks_pvalue, 8);
				dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[3]->Value = GetResourceManagerFildName(testRez.ToString());
				row = dataGridView1->Rows[dataGridView1->Rows->Count - 1];
				row->Height = rowHeight;
				
				Color color;
				switch (testRez)
				{
				case TestRezult::Failed:
					color = Color::LightPink;
					break;

				case TestRezult::Weak:
					color = Color::Gold;
					break;

				case TestRezult::Passed:
					color = Color::LightGreen;
					break;
				}
				for (int i = 0; i < dataGridView1->Columns->Count; i++)
					dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[i]->Style->BackColor = color;

				for each (Control^ control in dataGridView1->Controls)
					if (control->GetType() == VScrollBar::typeid)
						dataGridView1->FirstDisplayedScrollingRowIndex = dataGridView1->RowCount - 1;
			}
			else
				this->Invoke(gcnew delegateAddLineInTable(this, &Diehard::TableForm::AddLineInTable));//виклик AddLineInTable()
			    //параметри не вдалося передати в AddLineInTable, тому використав глобальні змінні, через які знову викликаю AddLineInTable(void)
		}

	private: 
		System::Void Create(DataGridView^ dataGridView)
		{		
			dataGridView->Rows->Clear();
			dataGridView->Columns->Clear();
			DataGridViewColumn^ column;
			dataGridView->AllowUserToAddRows = true;
			dataGridView->RowHeadersVisible = false;

			dataGridView->Columns->Add("", GetResourceManagerFildName("TestName"));
			column = dataGridView->Columns[0];
			column->Width = 200;
			column->SortMode = DataGridViewColumnSortMode::NotSortable;

			dataGridView->Columns->Add("", "ntup");
			column = dataGridView->Columns[1];
			column->Width = 30;
			column->SortMode = DataGridViewColumnSortMode::NotSortable;

			dataGridView->Columns->Add("", "P - value");
			column = dataGridView->Columns[2];
			column->Width = 75;
			column->SortMode = DataGridViewColumnSortMode::NotSortable;

			dataGridView->Columns->Add("", GetResourceManagerFildName("Assessment"));
			column = dataGridView->Columns[3];
			column->Width = 75;
			column->SortMode = DataGridViewColumnSortMode::NotSortable;

			dataGridView->ColumnHeadersHeight = 22;

			dataGridView->RowsDefaultCellStyle->SelectionForeColor = Color::Black;
			dataGridView->RowsDefaultCellStyle->SelectionBackColor = Color::AliceBlue;

			//dataGridView.DefaultCellStyle.Font = new Font("Microsoft Sans Serif", 8F, GraphicsUnit.Point);
			dataGridView->ReadOnly = true;
			dataGridView->AllowUserToAddRows = false;
			dataGridView->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			dataGridView->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;

			dataGridView->Height = 22 * ((int)dataGridView->RowCount) + dataGridView->ColumnHeadersHeight;

			dataGridView->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			
			int width = 0;
			for(int i = 0; i < dataGridView->Columns->Count; i++)
				width += dataGridView->Columns[i]->Width;

			dataGridView->Width = width + 3;
			Width = dataGridView->Width;
			Height = dataGridView->Height;
		}

private: 
	System::Void dataGridView1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 System::Windows::Forms::ContextMenu^ contextMenu = gcnew System::Windows::Forms::ContextMenu();
			 contextMenu->MenuItems->Add(0, gcnew MenuItem(GetResourceManagerFildName("SaveAs"), gcnew EventHandler(this, &Diehard::TableForm::dataGridView1_Mouse)));

			 if( e->Button == System::Windows::Forms::MouseButtons::Right )
			 {
				 dataGridView1->ContextMenu = contextMenu;
				 dataGridView1->ContextMenu->Show(dataGridView1, e->Location);
			 }
		 }
private: 
	System::Void dataGridView1_Mouse(System::Object^  sender, System::EventArgs^  e) 
	{
		String^ SaveFileExtension = ".txt";
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = String::Format("Файли параметрів (*{0})|*{0}", SaveFileExtension);
		saveFileDialog->DefaultExt = SaveFileExtension;
		saveFileDialog->AddExtension = true;

		if(saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ header = String::Format("Generator is <{0}>", _ganeretorName);
			String^ format = "{0,-32}{1,5}{2,15}{3,15}";

			   header += "\n\n" + String::Format(format, 
				   dataGridView1->Columns[0]->HeaderText,
				   dataGridView1->Columns[1]->HeaderText,
				   dataGridView1->Columns[2]->HeaderText,
				   dataGridView1->Columns[3]->HeaderText);
            header += "\n-------------------------------------------------------------------\n";
			for (int j = 0; j < dataGridView1->RowCount; j++)
			{
				header += "\n" + String::Format(format, 
						dataGridView1->Rows[j]->Cells[0]->Value,
						dataGridView1->Rows[j]->Cells[1]->Value,
						dataGridView1->Rows[j]->Cells[2]->Value,
						dataGridView1->Rows[j]->Cells[3]->Value);
			}
			File::WriteAllLines(saveFileDialog->FileName, header->Split(gcnew array<wchar_t>{'\n'}));
		}
	}

	private: 
		String^ GetResourceManagerFildName(String^ stringName)
		{
			return (gcnew ResourceManager("Diehard." + _culture, TableForm::typeid->Assembly))->GetString(stringName);
		}
};
}
