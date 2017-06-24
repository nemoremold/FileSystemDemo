#pragma once
#include "FileSystem.h"

namespace Annexation {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AnnexationForm
	/// </summary>
	public ref class AnnexationForm : public System::Windows::Forms::Form {
	public:
		FileSystem* fileSystem;

		AnnexationForm() {
			fileSystem = new FileSystem;
			fileSystem->formatFileSystem();
			//fileSystem->exitFileSystem();
			InitializeComponent();

			UIController();
		}

		void UIController() {
			//this->textBox1->Text = fileSystem->getPath();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AnnexationForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  topPanel;
	private: System::Windows::Forms::Panel^  mainPanel;
	private: System::Windows::Forms::Panel^  pathPanel;
	private: System::Windows::Forms::TextBox^  path;

	private: System::Windows::Forms::Button^  refreshButton;
	private: System::Windows::Forms::Button^  backButton;
	private: System::Windows::Forms::SplitContainer^  ContentSplitContainer;
	private: System::Windows::Forms::Panel^  buttomPanel;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileSystemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  formatToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  homepageToolStripMenuItem;
	private: System::Windows::Forms::FlowLayoutPanel^  buttonLayoutPanel;
	private: System::Windows::Forms::Button^  createFolder;
	private: System::Windows::Forms::Button^  remove;
	private: System::Windows::Forms::Button^  rename;


	private: System::Windows::Forms::Button^  createFile;
	private: System::Windows::Forms::Button^  open;
	private: System::Windows::Forms::Button^  closeFile;
	private: System::Windows::Forms::Panel^  divideLine1;
	private: System::Windows::Forms::Panel^  divideLine2;
	private: System::Windows::Forms::Panel^  divideLine3;
	private: System::Windows::Forms::Label^  OPERATE;
	private: System::Windows::Forms::Label^  ORGANIZE;
	private: System::Windows::Forms::Label^  NEW;











	protected:


	protected:

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
		void InitializeComponent(void) {
			this->topPanel = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileSystemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->formatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->homepageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->createFolder = (gcnew System::Windows::Forms::Button());
			this->createFile = (gcnew System::Windows::Forms::Button());
			this->divideLine1 = (gcnew System::Windows::Forms::Panel());
			this->remove = (gcnew System::Windows::Forms::Button());
			this->rename = (gcnew System::Windows::Forms::Button());
			this->divideLine2 = (gcnew System::Windows::Forms::Panel());
			this->open = (gcnew System::Windows::Forms::Button());
			this->closeFile = (gcnew System::Windows::Forms::Button());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->buttomPanel = (gcnew System::Windows::Forms::Panel());
			this->pathPanel = (gcnew System::Windows::Forms::Panel());
			this->path = (gcnew System::Windows::Forms::TextBox());
			this->refreshButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->ContentSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->divideLine3 = (gcnew System::Windows::Forms::Panel());
			this->NEW = (gcnew System::Windows::Forms::Label());
			this->ORGANIZE = (gcnew System::Windows::Forms::Label());
			this->OPERATE = (gcnew System::Windows::Forms::Label());
			this->topPanel->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->buttonLayoutPanel->SuspendLayout();
			this->mainPanel->SuspendLayout();
			this->pathPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ContentSplitContainer))->BeginInit();
			this->ContentSplitContainer->SuspendLayout();
			this->SuspendLayout();
			// 
			// topPanel
			// 
			this->topPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->topPanel->BackColor = System::Drawing::SystemColors::Control;
			this->topPanel->Controls->Add(this->OPERATE);
			this->topPanel->Controls->Add(this->ORGANIZE);
			this->topPanel->Controls->Add(this->NEW);
			this->topPanel->Controls->Add(this->menuStrip1);
			this->topPanel->Controls->Add(this->buttonLayoutPanel);
			this->topPanel->Location = System::Drawing::Point(0, 0);
			this->topPanel->Margin = System::Windows::Forms::Padding(0);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(1080, 155);
			this->topPanel->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileSystemToolStripMenuItem,
					this->homepageToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(0);
			this->menuStrip1->Size = System::Drawing::Size(1080, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileSystemToolStripMenuItem
			// 
			this->fileSystemToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->fileSystemToolStripMenuItem->CheckOnClick = true;
			this->fileSystemToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->formatToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileSystemToolStripMenuItem->Name = L"fileSystemToolStripMenuItem";
			this->fileSystemToolStripMenuItem->Size = System::Drawing::Size(99, 24);
			this->fileSystemToolStripMenuItem->Text = L"FileSystem";
			// 
			// formatToolStripMenuItem
			// 
			this->formatToolStripMenuItem->Name = L"formatToolStripMenuItem";
			this->formatToolStripMenuItem->Size = System::Drawing::Size(133, 26);
			this->formatToolStripMenuItem->Text = L"format";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(133, 26);
			this->exitToolStripMenuItem->Text = L"exit";
			// 
			// homepageToolStripMenuItem
			// 
			this->homepageToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->homepageToolStripMenuItem->Name = L"homepageToolStripMenuItem";
			this->homepageToolStripMenuItem->Size = System::Drawing::Size(103, 24);
			this->homepageToolStripMenuItem->Text = L"Homepage";
			// 
			// buttonLayoutPanel
			// 
			this->buttonLayoutPanel->Controls->Add(this->createFolder);
			this->buttonLayoutPanel->Controls->Add(this->createFile);
			this->buttonLayoutPanel->Controls->Add(this->divideLine1);
			this->buttonLayoutPanel->Controls->Add(this->remove);
			this->buttonLayoutPanel->Controls->Add(this->rename);
			this->buttonLayoutPanel->Controls->Add(this->divideLine2);
			this->buttonLayoutPanel->Controls->Add(this->open);
			this->buttonLayoutPanel->Controls->Add(this->closeFile);
			this->buttonLayoutPanel->Controls->Add(this->divideLine3);
			this->buttonLayoutPanel->Location = System::Drawing::Point(3, 27);
			this->buttonLayoutPanel->Name = L"buttonLayoutPanel";
			this->buttonLayoutPanel->Size = System::Drawing::Size(1074, 125);
			this->buttonLayoutPanel->TabIndex = 1;
			// 
			// createFolder
			// 
			this->createFolder->BackColor = System::Drawing::SystemColors::Control;
			this->createFolder->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->createFolder->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->createFolder->FlatAppearance->BorderSize = 0;
			this->createFolder->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->createFolder->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->createFolder->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->createFolder->Location = System::Drawing::Point(0, 5);
			this->createFolder->Margin = System::Windows::Forms::Padding(0, 5, 0, 5);
			this->createFolder->Name = L"createFolder";
			this->createFolder->Size = System::Drawing::Size(75, 100);
			this->createFolder->TabIndex = 0;
			this->createFolder->Text = L"new folder";
			this->createFolder->UseVisualStyleBackColor = false;
			// 
			// createFile
			// 
			this->createFile->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->createFile->FlatAppearance->BorderSize = 0;
			this->createFile->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->createFile->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->createFile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->createFile->Location = System::Drawing::Point(76, 5);
			this->createFile->Margin = System::Windows::Forms::Padding(1, 5, 5, 5);
			this->createFile->Name = L"createFile";
			this->createFile->Size = System::Drawing::Size(75, 100);
			this->createFile->TabIndex = 3;
			this->createFile->Text = L"new  file";
			this->createFile->UseVisualStyleBackColor = true;
			// 
			// divideLine1
			// 
			this->divideLine1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->divideLine1->Location = System::Drawing::Point(156, 4);
			this->divideLine1->Margin = System::Windows::Forms::Padding(0, 4, 0, 4);
			this->divideLine1->Name = L"divideLine1";
			this->divideLine1->Size = System::Drawing::Size(1, 117);
			this->divideLine1->TabIndex = 6;
			// 
			// remove
			// 
			this->remove->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->remove->FlatAppearance->BorderSize = 0;
			this->remove->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->remove->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->remove->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->remove->Location = System::Drawing::Point(162, 5);
			this->remove->Margin = System::Windows::Forms::Padding(5, 5, 0, 5);
			this->remove->Name = L"remove";
			this->remove->Size = System::Drawing::Size(75, 100);
			this->remove->TabIndex = 1;
			this->remove->Text = L"remove";
			this->remove->UseVisualStyleBackColor = true;
			// 
			// rename
			// 
			this->rename->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->rename->FlatAppearance->BorderSize = 0;
			this->rename->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->rename->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->rename->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rename->Location = System::Drawing::Point(238, 5);
			this->rename->Margin = System::Windows::Forms::Padding(1, 5, 5, 5);
			this->rename->Name = L"rename";
			this->rename->Size = System::Drawing::Size(75, 100);
			this->rename->TabIndex = 2;
			this->rename->Text = L"rename";
			this->rename->UseVisualStyleBackColor = true;
			// 
			// divideLine2
			// 
			this->divideLine2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->divideLine2->Location = System::Drawing::Point(318, 4);
			this->divideLine2->Margin = System::Windows::Forms::Padding(0, 4, 0, 4);
			this->divideLine2->Name = L"divideLine2";
			this->divideLine2->Size = System::Drawing::Size(1, 117);
			this->divideLine2->TabIndex = 7;
			// 
			// open
			// 
			this->open->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->open->FlatAppearance->BorderSize = 0;
			this->open->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->open->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->open->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->open->Location = System::Drawing::Point(324, 5);
			this->open->Margin = System::Windows::Forms::Padding(5, 5, 0, 5);
			this->open->Name = L"open";
			this->open->Size = System::Drawing::Size(75, 100);
			this->open->TabIndex = 4;
			this->open->Text = L"open";
			this->open->UseVisualStyleBackColor = true;
			// 
			// closeFile
			// 
			this->closeFile->BackColor = System::Drawing::SystemColors::Control;
			this->closeFile->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->closeFile->FlatAppearance->BorderSize = 0;
			this->closeFile->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->closeFile->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->closeFile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeFile->Location = System::Drawing::Point(400, 5);
			this->closeFile->Margin = System::Windows::Forms::Padding(1, 5, 5, 5);
			this->closeFile->Name = L"closeFile";
			this->closeFile->Size = System::Drawing::Size(75, 100);
			this->closeFile->TabIndex = 5;
			this->closeFile->Text = L"close file";
			this->closeFile->UseVisualStyleBackColor = false;
			// 
			// mainPanel
			// 
			this->mainPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mainPanel->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->mainPanel->Controls->Add(this->buttomPanel);
			this->mainPanel->Controls->Add(this->pathPanel);
			this->mainPanel->Controls->Add(this->ContentSplitContainer);
			this->mainPanel->Location = System::Drawing::Point(0, 160);
			this->mainPanel->Margin = System::Windows::Forms::Padding(0);
			this->mainPanel->MinimumSize = System::Drawing::Size(320, 200);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(1080, 500);
			this->mainPanel->TabIndex = 1;
			// 
			// buttomPanel
			// 
			this->buttomPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttomPanel->Location = System::Drawing::Point(0, 480);
			this->buttomPanel->Name = L"buttomPanel";
			this->buttomPanel->Size = System::Drawing::Size(1080, 21);
			this->buttomPanel->TabIndex = 2;
			// 
			// pathPanel
			// 
			this->pathPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pathPanel->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pathPanel->Controls->Add(this->path);
			this->pathPanel->Controls->Add(this->refreshButton);
			this->pathPanel->Controls->Add(this->backButton);
			this->pathPanel->Location = System::Drawing::Point(0, 0);
			this->pathPanel->Margin = System::Windows::Forms::Padding(0);
			this->pathPanel->Name = L"pathPanel";
			this->pathPanel->Size = System::Drawing::Size(1080, 40);
			this->pathPanel->TabIndex = 0;
			// 
			// path
			// 
			this->path->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->path->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->path->Location = System::Drawing::Point(112, 5);
			this->path->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->path->MinimumSize = System::Drawing::Size(100, 4);
			this->path->Name = L"path";
			this->path->ReadOnly = true;
			this->path->Size = System::Drawing::Size(858, 25);
			this->path->TabIndex = 3;
			// 
			// refreshButton
			// 
			this->refreshButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->refreshButton->BackColor = System::Drawing::SystemColors::Control;
			this->refreshButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->refreshButton->Location = System::Drawing::Point(970, 4);
			this->refreshButton->Margin = System::Windows::Forms::Padding(1, 0, 5, 0);
			this->refreshButton->MinimumSize = System::Drawing::Size(105, 29);
			this->refreshButton->Name = L"refreshButton";
			this->refreshButton->Size = System::Drawing::Size(105, 29);
			this->refreshButton->TabIndex = 2;
			this->refreshButton->Text = L"refresh";
			this->refreshButton->UseVisualStyleBackColor = false;
			// 
			// backButton
			// 
			this->backButton->BackColor = System::Drawing::SystemColors::Control;
			this->backButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->backButton->Location = System::Drawing::Point(5, 4);
			this->backButton->Margin = System::Windows::Forms::Padding(5, 0, 1, 0);
			this->backButton->MinimumSize = System::Drawing::Size(105, 29);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(105, 29);
			this->backButton->TabIndex = 1;
			this->backButton->Text = L"BACK";
			this->backButton->UseVisualStyleBackColor = false;
			// 
			// ContentSplitContainer
			// 
			this->ContentSplitContainer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ContentSplitContainer->BackColor = System::Drawing::SystemColors::Menu;
			this->ContentSplitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->ContentSplitContainer->Location = System::Drawing::Point(-1, 35);
			this->ContentSplitContainer->Margin = System::Windows::Forms::Padding(0);
			this->ContentSplitContainer->Name = L"ContentSplitContainer";
			// 
			// ContentSplitContainer.Panel1
			// 
			this->ContentSplitContainer->Panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			// 
			// ContentSplitContainer.Panel2
			// 
			this->ContentSplitContainer->Panel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ContentSplitContainer->Size = System::Drawing::Size(1082, 466);
			this->ContentSplitContainer->SplitterDistance = 150;
			this->ContentSplitContainer->SplitterWidth = 1;
			this->ContentSplitContainer->TabIndex = 1;
			// 
			// divideLine3
			// 
			this->divideLine3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->divideLine3->Location = System::Drawing::Point(480, 4);
			this->divideLine3->Margin = System::Windows::Forms::Padding(0, 4, 0, 4);
			this->divideLine3->Name = L"divideLine3";
			this->divideLine3->Size = System::Drawing::Size(1, 117);
			this->divideLine3->TabIndex = 8;
			// 
			// NEW
			// 
			this->NEW->AutoSize = true;
			this->NEW->Location = System::Drawing::Point(63, 135);
			this->NEW->Margin = System::Windows::Forms::Padding(0);
			this->NEW->Name = L"NEW";
			this->NEW->Size = System::Drawing::Size(31, 15);
			this->NEW->TabIndex = 9;
			this->NEW->Text = L"NEW";
			// 
			// ORGANIZE
			// 
			this->ORGANIZE->AutoSize = true;
			this->ORGANIZE->Location = System::Drawing::Point(202, 135);
			this->ORGANIZE->Margin = System::Windows::Forms::Padding(0);
			this->ORGANIZE->Name = L"ORGANIZE";
			this->ORGANIZE->Size = System::Drawing::Size(71, 15);
			this->ORGANIZE->TabIndex = 10;
			this->ORGANIZE->Text = L"ORGANIZE";
			// 
			// OPERATE
			// 
			this->OPERATE->AutoSize = true;
			this->OPERATE->Location = System::Drawing::Point(368, 135);
			this->OPERATE->Margin = System::Windows::Forms::Padding(0);
			this->OPERATE->Name = L"OPERATE";
			this->OPERATE->Size = System::Drawing::Size(63, 15);
			this->OPERATE->TabIndex = 11;
			this->OPERATE->Text = L"OPERATE";
			// 
			// AnnexationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1080, 660);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->topPanel);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(523, 500);
			this->Name = L"AnnexationForm";
			this->Text = L"AnnexationForm";
			this->topPanel->ResumeLayout(false);
			this->topPanel->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->buttonLayoutPanel->ResumeLayout(false);
			this->mainPanel->ResumeLayout(false);
			this->pathPanel->ResumeLayout(false);
			this->pathPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ContentSplitContainer))->EndInit();
			this->ContentSplitContainer->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
};
}
