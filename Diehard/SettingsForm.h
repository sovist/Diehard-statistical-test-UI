#pragma once
#include "..//code_files/include/Dtest.h"
namespace Diehard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	private:
		int высота_шапки;
		int ширина_границы_слева;
		int ширина_границы_справа;
		int высота_границы_снизу;
		String^ _culture;
	public:
		SettingsForm()
		{
			InitializeComponent();			
			Create(dataGridView1);
			System::Drawing::Rectangle rectAll = this->RectangleToClient(this->Bounds);
			System::Drawing::Rectangle rectClient = this->ClientRectangle;
			высота_шапки = rectClient.Top - rectAll.Top;
		    ширина_границы_слева = rectClient.Left - rectAll.Left;
			ширина_границы_справа = rectAll.Right - rectClient.Right;
			высота_границы_снизу = rectAll.Bottom - rectClient.Bottom;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SettingsForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(393, 243);
			this->dataGridView1->TabIndex = 0;
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(497, 330);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"SettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Diehard test settings";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: bool flag;
	public:
		System::Void AddLineInTable(Dtest* dtest)
		{
			System::Drawing::Rectangle rectAll = this->RectangleToClient(this->Bounds);
			System::Drawing::Rectangle rectClient = this->ClientRectangle;
			высота_шапки = rectClient.Top - rectAll.Top;
			ширина_границы_слева = rectClient.Left - rectAll.Left;
			ширина_границы_справа = rectAll.Right - rectClient.Right;
			высота_границы_снизу = rectAll.Bottom - rectClient.Bottom;

				dataGridView1->Rows->Add(gcnew String(dtest->name), "");
				dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[0]->ReadOnly = true;
				dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[1]->Value = dtest->nkps;
				dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[2]->Value = dtest->psamples_std;
				dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[3]->Value = dtest->tsamples_std;
				DataGridViewRow^ row = dataGridView1->Rows[dataGridView1->Rows->Count - 1];
				row->Height = 20;

				if((dataGridView1->Rows->Count - 1) % 2 == 0)
					for (int i = 0; i < dataGridView1->ColumnCount; i++)					
					  dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[i]->Style->BackColor = Color::AntiqueWhite;

				if(!flag)
				{
					if(Height > 500)
					{
						dataGridView1->Width = dataGridView1->Width + 17;
						Width = dataGridView1->Width + ширина_границы_справа + ширина_границы_слева;
						flag = true;
					}
					else
					{
						dataGridView1->Height += row->Height;
						Height = dataGridView1->Height + высота_шапки + высота_границы_снизу;
					}
				}

				/*for each (Control^ control in dataGridView1->Controls)
					if (control->GetType() == VScrollBar::typeid)
						dataGridView1->FirstDisplayedScrollingRowIndex = dataGridView1->RowCount - 1;
						*/
			}		
		
	private: 
		System::Void Create(DataGridView^ dataGridView)
		{		
			System::Drawing::Rectangle rectAll = this->RectangleToClient(this->Bounds);
			System::Drawing::Rectangle rectClient = this->ClientRectangle;
			высота_шапки = rectClient.Top - rectAll.Top;
			ширина_границы_слева = rectClient.Left - rectAll.Left;
			ширина_границы_справа = rectAll.Right - rectClient.Right;
			высота_границы_снизу = rectAll.Bottom - rectClient.Bottom;


			dataGridView->Rows->Clear();
			dataGridView->Columns->Clear();
			DataGridViewColumn^ column;
			dataGridView->AllowUserToAddRows = true;
			dataGridView->RowHeadersVisible = false;

			dataGridView->Columns->Add("", "Test name");
			column = dataGridView->Columns[0];
			column->Width = 200;
			column->SortMode = DataGridViewColumnSortMode::NotSortable;

			dataGridView->Columns->Add("", "ntup");
			column = dataGridView->Columns[1];
			column->Width = 30;
			column->SortMode = DataGridViewColumnSortMode::NotSortable;

			dataGridView->Columns->Add("", "psamples");
			column = dataGridView->Columns[2];
			column->Width = 65;
			column->SortMode = DataGridViewColumnSortMode::NotSortable;

			dataGridView->Columns->Add("", "tsamples");
			column = dataGridView->Columns[3];
			column->Width = 65;
			column->SortMode = DataGridViewColumnSortMode::NotSortable;

			dataGridView->ColumnHeadersHeight = 21;

			dataGridView->RowsDefaultCellStyle->SelectionForeColor = Color::Black;
			dataGridView->RowsDefaultCellStyle->SelectionBackColor = Color::AliceBlue;

			//dataGridView.DefaultCellStyle.Font = new Font("Microsoft Sans Serif", 8F, GraphicsUnit.Point);
			dataGridView->ReadOnly = false;
			dataGridView->AllowUserToAddRows = false;
			dataGridView->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			dataGridView->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			dataGridView->Height = 22 * ((int)dataGridView->RowCount) + 23;
			//dataGridView->Width = column_Width * ((int)dataGridView.ColumnCount) + 3;

			dataGridView->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

			int width = 0;
			for(int i = 0; i < dataGridView->Columns->Count; i++)
				width += dataGridView->Columns[i]->Width;

			dataGridView->Width = width + 3;
			Width = dataGridView->Width + ширина_границы_слева + ширина_границы_справа;
			Height = dataGridView->Height;
		}
	};
}
