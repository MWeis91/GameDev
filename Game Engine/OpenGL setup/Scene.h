#pragma once

namespace OpenGLsetup {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Scene
	/// </summary>
	public ref class Scene : public System::Windows::Forms::Form
	{
	public:
		Scene(void)
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
		~Scene()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  compileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  compileToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  runToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  prefabToolStripMenuItem;
	private: System::Windows::Forms::Label^  RotationLabel;
	private: System::Windows::Forms::TextBox^  RotZ;
	private: System::Windows::Forms::TextBox^  RotY;
	private: System::Windows::Forms::TextBox^  RotX;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  PositionLabel;
	private: System::Windows::Forms::TextBox^  PosZ;
	private: System::Windows::Forms::TextBox^  PosY;
	private: System::Windows::Forms::TextBox^  PosX;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  ScaleLabel;
	private: System::Windows::Forms::TextBox^  ScaleZ;
	private: System::Windows::Forms::TextBox^  ScaleY;
	private: System::Windows::Forms::TextBox^  ScaleX;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripMenuItem^  shapesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cubeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sphereToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  prismToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  planeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lightingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  coneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ambientToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cameraToolStripMenuItem;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::Label^  ObjectListLabel;
	private: System::Windows::Forms::Button^  UpdateButton;
	private: System::Windows::Forms::Button^  RunButton;
	private: System::Windows::Forms::Button^  ScriptButton;


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->compileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->compileToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->prefabToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->shapesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cubeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sphereToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->prismToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->planeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lightingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->coneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ambientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cameraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RotationLabel = (gcnew System::Windows::Forms::Label());
			this->RotZ = (gcnew System::Windows::Forms::TextBox());
			this->RotY = (gcnew System::Windows::Forms::TextBox());
			this->RotX = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->PositionLabel = (gcnew System::Windows::Forms::Label());
			this->PosZ = (gcnew System::Windows::Forms::TextBox());
			this->PosY = (gcnew System::Windows::Forms::TextBox());
			this->PosX = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ScaleLabel = (gcnew System::Windows::Forms::Label());
			this->ScaleZ = (gcnew System::Windows::Forms::TextBox());
			this->ScaleY = (gcnew System::Windows::Forms::TextBox());
			this->ScaleX = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->ObjectListLabel = (gcnew System::Windows::Forms::Label());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->RunButton = (gcnew System::Windows::Forms::Button());
			this->ScriptButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->fileToolStripMenuItem, 
				this->editToolStripMenuItem, this->compileToolStripMenuItem, this->prefabToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(684, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem1, 
				this->saveToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(152, 22);
			this->toolStripMenuItem1->Text = L"Open";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->undoToolStripMenuItem, 
				this->redoToolStripMenuItem, this->importToolStripMenuItem, this->exportToolStripMenuItem});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->undoToolStripMenuItem->Text = L"Undo";
			// 
			// redoToolStripMenuItem
			// 
			this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
			this->redoToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->redoToolStripMenuItem->Text = L"Redo";
			// 
			// importToolStripMenuItem
			// 
			this->importToolStripMenuItem->Name = L"importToolStripMenuItem";
			this->importToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->importToolStripMenuItem->Text = L"Import";
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exportToolStripMenuItem->Text = L"Export";
			// 
			// compileToolStripMenuItem
			// 
			this->compileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->compileToolStripMenuItem1, 
				this->runToolStripMenuItem});
			this->compileToolStripMenuItem->Name = L"compileToolStripMenuItem";
			this->compileToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->compileToolStripMenuItem->Text = L"Compile";
			// 
			// compileToolStripMenuItem1
			// 
			this->compileToolStripMenuItem1->Name = L"compileToolStripMenuItem1";
			this->compileToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
			this->compileToolStripMenuItem1->Text = L"Compile";
			// 
			// runToolStripMenuItem
			// 
			this->runToolStripMenuItem->Name = L"runToolStripMenuItem";
			this->runToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->runToolStripMenuItem->Text = L"Run";
			// 
			// prefabToolStripMenuItem
			// 
			this->prefabToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->shapesToolStripMenuItem, 
				this->lightingToolStripMenuItem, this->cameraToolStripMenuItem});
			this->prefabToolStripMenuItem->Name = L"prefabToolStripMenuItem";
			this->prefabToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->prefabToolStripMenuItem->Text = L"Prefab";
			// 
			// shapesToolStripMenuItem
			// 
			this->shapesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->cubeToolStripMenuItem, 
				this->sphereToolStripMenuItem, this->prismToolStripMenuItem, this->planeToolStripMenuItem});
			this->shapesToolStripMenuItem->Name = L"shapesToolStripMenuItem";
			this->shapesToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->shapesToolStripMenuItem->Text = L"Shapes";
			// 
			// cubeToolStripMenuItem
			// 
			this->cubeToolStripMenuItem->Name = L"cubeToolStripMenuItem";
			this->cubeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->cubeToolStripMenuItem->Text = L"Cube";
			// 
			// sphereToolStripMenuItem
			// 
			this->sphereToolStripMenuItem->Name = L"sphereToolStripMenuItem";
			this->sphereToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->sphereToolStripMenuItem->Text = L"Sphere";
			// 
			// prismToolStripMenuItem
			// 
			this->prismToolStripMenuItem->Name = L"prismToolStripMenuItem";
			this->prismToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->prismToolStripMenuItem->Text = L"Prism";
			// 
			// planeToolStripMenuItem
			// 
			this->planeToolStripMenuItem->Name = L"planeToolStripMenuItem";
			this->planeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->planeToolStripMenuItem->Text = L"Plane";
			// 
			// lightingToolStripMenuItem
			// 
			this->lightingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->coneToolStripMenuItem, 
				this->ambientToolStripMenuItem});
			this->lightingToolStripMenuItem->Name = L"lightingToolStripMenuItem";
			this->lightingToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->lightingToolStripMenuItem->Text = L"Lighting";
			// 
			// coneToolStripMenuItem
			// 
			this->coneToolStripMenuItem->Name = L"coneToolStripMenuItem";
			this->coneToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->coneToolStripMenuItem->Text = L"Cone";
			// 
			// ambientToolStripMenuItem
			// 
			this->ambientToolStripMenuItem->Name = L"ambientToolStripMenuItem";
			this->ambientToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->ambientToolStripMenuItem->Text = L"Ambient";
			// 
			// cameraToolStripMenuItem
			// 
			this->cameraToolStripMenuItem->Name = L"cameraToolStripMenuItem";
			this->cameraToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->cameraToolStripMenuItem->Text = L"Camera";
			// 
			// RotationLabel
			// 
			this->RotationLabel->AutoSize = true;
			this->RotationLabel->Location = System::Drawing::Point(612, 222);
			this->RotationLabel->Name = L"RotationLabel";
			this->RotationLabel->Size = System::Drawing::Size(47, 13);
			this->RotationLabel->TabIndex = 44;
			this->RotationLabel->Text = L"Rotation";
			// 
			// RotZ
			// 
			this->RotZ->Location = System::Drawing::Point(612, 291);
			this->RotZ->Name = L"RotZ";
			this->RotZ->Size = System::Drawing::Size(60, 20);
			this->RotZ->TabIndex = 9;
			// 
			// RotY
			// 
			this->RotY->Location = System::Drawing::Point(612, 266);
			this->RotY->Name = L"RotY";
			this->RotY->Size = System::Drawing::Size(60, 20);
			this->RotY->TabIndex = 8;
			// 
			// RotX
			// 
			this->RotX->Location = System::Drawing::Point(612, 241);
			this->RotX->Name = L"RotX";
			this->RotX->Size = System::Drawing::Size(60, 20);
			this->RotX->TabIndex = 7;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(594, 294);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(12, 13);
			this->label10->TabIndex = 40;
			this->label10->Text = L"z";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(594, 269);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(12, 13);
			this->label11->TabIndex = 39;
			this->label11->Text = L"y";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(594, 244);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(12, 13);
			this->label12->TabIndex = 38;
			this->label12->Text = L"x";
			// 
			// PositionLabel
			// 
			this->PositionLabel->AutoSize = true;
			this->PositionLabel->Location = System::Drawing::Point(612, 130);
			this->PositionLabel->Name = L"PositionLabel";
			this->PositionLabel->Size = System::Drawing::Size(44, 13);
			this->PositionLabel->TabIndex = 37;
			this->PositionLabel->Text = L"Position";
			// 
			// PosZ
			// 
			this->PosZ->Location = System::Drawing::Point(612, 199);
			this->PosZ->Name = L"PosZ";
			this->PosZ->Size = System::Drawing::Size(60, 20);
			this->PosZ->TabIndex = 6;
			// 
			// PosY
			// 
			this->PosY->Location = System::Drawing::Point(612, 174);
			this->PosY->Name = L"PosY";
			this->PosY->Size = System::Drawing::Size(60, 20);
			this->PosY->TabIndex = 5;
			// 
			// PosX
			// 
			this->PosX->Location = System::Drawing::Point(612, 149);
			this->PosX->Name = L"PosX";
			this->PosX->Size = System::Drawing::Size(60, 20);
			this->PosX->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(594, 202);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(12, 13);
			this->label6->TabIndex = 33;
			this->label6->Text = L"z";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(594, 177);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(12, 13);
			this->label7->TabIndex = 32;
			this->label7->Text = L"y";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(594, 152);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(12, 13);
			this->label8->TabIndex = 31;
			this->label8->Text = L"x";
			// 
			// ScaleLabel
			// 
			this->ScaleLabel->AutoSize = true;
			this->ScaleLabel->Location = System::Drawing::Point(612, 38);
			this->ScaleLabel->Name = L"ScaleLabel";
			this->ScaleLabel->Size = System::Drawing::Size(34, 13);
			this->ScaleLabel->TabIndex = 30;
			this->ScaleLabel->Text = L"Scale";
			// 
			// ScaleZ
			// 
			this->ScaleZ->Location = System::Drawing::Point(612, 107);
			this->ScaleZ->Name = L"ScaleZ";
			this->ScaleZ->Size = System::Drawing::Size(60, 20);
			this->ScaleZ->TabIndex = 3;
			// 
			// ScaleY
			// 
			this->ScaleY->Location = System::Drawing::Point(612, 82);
			this->ScaleY->Name = L"ScaleY";
			this->ScaleY->Size = System::Drawing::Size(60, 20);
			this->ScaleY->TabIndex = 2;
			// 
			// ScaleX
			// 
			this->ScaleX->Location = System::Drawing::Point(612, 57);
			this->ScaleX->Name = L"ScaleX";
			this->ScaleX->Size = System::Drawing::Size(60, 20);
			this->ScaleX->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(594, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(12, 13);
			this->label3->TabIndex = 26;
			this->label3->Text = L"z";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(594, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(12, 13);
			this->label2->TabIndex = 25;
			this->label2->Text = L"y";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(594, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(12, 13);
			this->label1->TabIndex = 24;
			this->label1->Text = L"x";
			// 
			// listView1
			// 
			this->listView1->Location = System::Drawing::Point(12, 57);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(576, 254);
			this->listView1->TabIndex = 46;
			this->listView1->TabStop = false;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// ObjectListLabel
			// 
			this->ObjectListLabel->AutoSize = true;
			this->ObjectListLabel->Location = System::Drawing::Point(300, 38);
			this->ObjectListLabel->Name = L"ObjectListLabel";
			this->ObjectListLabel->Size = System::Drawing::Size(57, 13);
			this->ObjectListLabel->TabIndex = 47;
			this->ObjectListLabel->Text = L"Object List";
			// 
			// UpdateButton
			// 
			this->UpdateButton->Location = System::Drawing::Point(516, 331);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(75, 23);
			this->UpdateButton->TabIndex = 11;
			this->UpdateButton->Text = L"Update";
			this->UpdateButton->UseVisualStyleBackColor = true;
			// 
			// RunButton
			// 
			this->RunButton->Location = System::Drawing::Point(597, 331);
			this->RunButton->Name = L"RunButton";
			this->RunButton->Size = System::Drawing::Size(75, 23);
			this->RunButton->TabIndex = 12;
			this->RunButton->Text = L"Run";
			this->RunButton->UseVisualStyleBackColor = true;
			// 
			// ScriptButton
			// 
			this->ScriptButton->Location = System::Drawing::Point(435, 331);
			this->ScriptButton->Name = L"ScriptButton";
			this->ScriptButton->Size = System::Drawing::Size(75, 23);
			this->ScriptButton->TabIndex = 10;
			this->ScriptButton->Text = L"Edit Script";
			this->ScriptButton->UseVisualStyleBackColor = true;
			// 
			// Scene
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 393);
			this->Controls->Add(this->ScriptButton);
			this->Controls->Add(this->RunButton);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->ObjectListLabel);
			this->Controls->Add(this->listView1);
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
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Scene";
			this->Text = L"Scene";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


};
}
