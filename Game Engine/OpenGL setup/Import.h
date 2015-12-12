#pragma once

namespace OpenGLsetup {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Import
	/// </summary>
	public ref class Import : public System::Windows::Forms::Form
	{
	public:
		Import(void)
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
		~Import()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  FilePathLabel;
	protected: 
	private: System::Windows::Forms::TextBox^  FilePathTextBox;
	private: System::Windows::Forms::Button^  LoadButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  ScaleX;
	private: System::Windows::Forms::TextBox^  ScaleY;
	private: System::Windows::Forms::TextBox^  ScaleZ;
	private: System::Windows::Forms::Label^  ScaleLabel;
	private: System::Windows::Forms::Label^  PositionLabel;
	private: System::Windows::Forms::TextBox^  PosZ;
	private: System::Windows::Forms::TextBox^  PosY;
	private: System::Windows::Forms::TextBox^  PosX;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  RotationLabel;
	private: System::Windows::Forms::TextBox^  RotZ;
	private: System::Windows::Forms::TextBox^  RotY;
	private: System::Windows::Forms::TextBox^  RotX;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Button^  ImportButton;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;

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
			this->FilePathLabel = (gcnew System::Windows::Forms::Label());
			this->FilePathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LoadButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ScaleX = (gcnew System::Windows::Forms::TextBox());
			this->ScaleY = (gcnew System::Windows::Forms::TextBox());
			this->ScaleZ = (gcnew System::Windows::Forms::TextBox());
			this->ScaleLabel = (gcnew System::Windows::Forms::Label());
			this->PositionLabel = (gcnew System::Windows::Forms::Label());
			this->PosZ = (gcnew System::Windows::Forms::TextBox());
			this->PosY = (gcnew System::Windows::Forms::TextBox());
			this->PosX = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->RotationLabel = (gcnew System::Windows::Forms::Label());
			this->RotZ = (gcnew System::Windows::Forms::TextBox());
			this->RotY = (gcnew System::Windows::Forms::TextBox());
			this->RotX = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->ImportButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// FilePathLabel
			// 
			this->FilePathLabel->AutoSize = true;
			this->FilePathLabel->Location = System::Drawing::Point(13, 13);
			this->FilePathLabel->Name = L"FilePathLabel";
			this->FilePathLabel->Size = System::Drawing::Size(48, 13);
			this->FilePathLabel->TabIndex = 0;
			this->FilePathLabel->Text = L"File Path";
			// 
			// FilePathTextBox
			// 
			this->FilePathTextBox->Location = System::Drawing::Point(67, 10);
			this->FilePathTextBox->Name = L"FilePathTextBox";
			this->FilePathTextBox->Size = System::Drawing::Size(250, 20);
			this->FilePathTextBox->TabIndex = 1;
			// 
			// LoadButton
			// 
			this->LoadButton->Location = System::Drawing::Point(323, 8);
			this->LoadButton->Name = L"LoadButton";
			this->LoadButton->Size = System::Drawing::Size(75, 23);
			this->LoadButton->TabIndex = 2;
			this->LoadButton->Text = L"Load";
			this->LoadButton->UseVisualStyleBackColor = true;
			this->LoadButton->Click += gcnew System::EventHandler(this, &Import::LoadButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(12, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"x";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(12, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(12, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"z";
			// 
			// ScaleX
			// 
			this->ScaleX->Location = System::Drawing::Point(31, 72);
			this->ScaleX->Name = L"ScaleX";
			this->ScaleX->Size = System::Drawing::Size(60, 20);
			this->ScaleX->TabIndex = 6;
			// 
			// ScaleY
			// 
			this->ScaleY->Location = System::Drawing::Point(31, 97);
			this->ScaleY->Name = L"ScaleY";
			this->ScaleY->Size = System::Drawing::Size(60, 20);
			this->ScaleY->TabIndex = 7;
			// 
			// ScaleZ
			// 
			this->ScaleZ->Location = System::Drawing::Point(31, 122);
			this->ScaleZ->Name = L"ScaleZ";
			this->ScaleZ->Size = System::Drawing::Size(60, 20);
			this->ScaleZ->TabIndex = 8;
			// 
			// ScaleLabel
			// 
			this->ScaleLabel->AutoSize = true;
			this->ScaleLabel->Location = System::Drawing::Point(31, 53);
			this->ScaleLabel->Name = L"ScaleLabel";
			this->ScaleLabel->Size = System::Drawing::Size(34, 13);
			this->ScaleLabel->TabIndex = 9;
			this->ScaleLabel->Text = L"Scale";
			// 
			// PositionLabel
			// 
			this->PositionLabel->AutoSize = true;
			this->PositionLabel->Location = System::Drawing::Point(138, 53);
			this->PositionLabel->Name = L"PositionLabel";
			this->PositionLabel->Size = System::Drawing::Size(44, 13);
			this->PositionLabel->TabIndex = 16;
			this->PositionLabel->Text = L"Position";
			// 
			// PosZ
			// 
			this->PosZ->Location = System::Drawing::Point(138, 122);
			this->PosZ->Name = L"PosZ";
			this->PosZ->Size = System::Drawing::Size(60, 20);
			this->PosZ->TabIndex = 15;
			// 
			// PosY
			// 
			this->PosY->Location = System::Drawing::Point(138, 97);
			this->PosY->Name = L"PosY";
			this->PosY->Size = System::Drawing::Size(60, 20);
			this->PosY->TabIndex = 14;
			// 
			// PosX
			// 
			this->PosX->Location = System::Drawing::Point(138, 72);
			this->PosX->Name = L"PosX";
			this->PosX->Size = System::Drawing::Size(60, 20);
			this->PosX->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(120, 125);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(12, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"z";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(120, 100);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(12, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"y";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(120, 75);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(12, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"x";
			// 
			// RotationLabel
			// 
			this->RotationLabel->AutoSize = true;
			this->RotationLabel->Location = System::Drawing::Point(245, 53);
			this->RotationLabel->Name = L"RotationLabel";
			this->RotationLabel->Size = System::Drawing::Size(47, 13);
			this->RotationLabel->TabIndex = 23;
			this->RotationLabel->Text = L"Rotation";
			// 
			// RotZ
			// 
			this->RotZ->Location = System::Drawing::Point(245, 122);
			this->RotZ->Name = L"RotZ";
			this->RotZ->Size = System::Drawing::Size(60, 20);
			this->RotZ->TabIndex = 22;
			// 
			// RotY
			// 
			this->RotY->Location = System::Drawing::Point(245, 97);
			this->RotY->Name = L"RotY";
			this->RotY->Size = System::Drawing::Size(60, 20);
			this->RotY->TabIndex = 21;
			// 
			// RotX
			// 
			this->RotX->Location = System::Drawing::Point(245, 72);
			this->RotX->Name = L"RotX";
			this->RotX->Size = System::Drawing::Size(60, 20);
			this->RotX->TabIndex = 20;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(227, 125);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(12, 13);
			this->label10->TabIndex = 19;
			this->label10->Text = L"z";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(227, 100);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(12, 13);
			this->label11->TabIndex = 18;
			this->label11->Text = L"y";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(227, 75);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(12, 13);
			this->label12->TabIndex = 17;
			this->label12->Text = L"x";
			// 
			// ImportButton
			// 
			this->ImportButton->Location = System::Drawing::Point(323, 119);
			this->ImportButton->Name = L"ImportButton";
			this->ImportButton->Size = System::Drawing::Size(75, 23);
			this->ImportButton->TabIndex = 24;
			this->ImportButton->Text = L"Import";
			this->ImportButton->UseVisualStyleBackColor = true;
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			// 
			// Import
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 161);
			this->Controls->Add(this->ImportButton);
			this->Controls->Add(this->RotationLabel);
			this->Controls->Add(this->RotZ);
			this->Controls->Add(this->RotY);
			this->Controls->Add(this->RotX);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->PositionLabel);
			this->Controls->Add(this->PosZ);
			this->Controls->Add(this->PosY);
			this->Controls->Add(this->PosX);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->ScaleLabel);
			this->Controls->Add(this->ScaleZ);
			this->Controls->Add(this->ScaleY);
			this->Controls->Add(this->ScaleX);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LoadButton);
			this->Controls->Add(this->FilePathTextBox);
			this->Controls->Add(this->FilePathLabel);
			this->Name = L"Import";
			this->Text = L"Import";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LoadButton_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 System::Windows::Forms::DialogResult objectFilePath = openFileDialog->ShowDialog();

			 }
};
}
