#pragma once
#include "FileSystem.h"
#include <Windows.h>

namespace Annexation {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for AnnexationForm
	/// </summary>
	public ref class AnnexationForm : public System::Windows::Forms::Form {
	public:
		FileSystem* fileSystem;
	private: System::Windows::Forms::Label^  fileNAMELABEL;
	private: System::Windows::Forms::Panel^  divideLine4;
	public:


	private: System::Windows::Forms::Panel^  filetype;
	private: System::Windows::Forms::Label^  fileTYPELABEL;
	private: System::Windows::Forms::Panel^  divideLine5;

	private: System::Windows::Forms::Panel^  filesize;
	private: System::Windows::Forms::Label^  fileSIZELABEL;
	private: System::Windows::Forms::Panel^  divideLine6;














	public:
		Thread^ UIController;

		AnnexationForm() {
			fileSystem = new FileSystem;
			willExitSystem = false;
			fileSystem->initializeFileSystem();
			InitializeComponent();
			reset();
			UIController = gcnew Thread(gcnew ThreadStart(this, &AnnexationForm::UIControl));
			UIController->Start();
		}

		void relayout() {
			//this->ContentSplitContainer->Panel2->Controls->Clear();
			/*int length = panels->GetLength;
			for (int i = 0; i < length; ++i) {
			panels[i]->Controls->Clear();
			}*/

			int fileCount = fileSystem->getFileCount();
			this->panels = (gcnew array<System::Windows::Forms::Panel^>(fileCount));
			this->fileNameLabels = (gcnew array<System::Windows::Forms::Label^>(fileCount));
			this->fileTypeLabels = (gcnew array<System::Windows::Forms::Label^>(fileCount));
			this->fileSizeLabels = (gcnew array<System::Windows::Forms::Label^>(fileCount));
			this->pictureBoxes = (gcnew array<System::Windows::Forms::PictureBox^>(fileCount));
			for (int i = 0; i < fileCount; ++i) {
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AnnexationForm::typeid));
				this->panels[i] = (gcnew System::Windows::Forms::Panel());
				this->fileNameLabels[i] = (gcnew System::Windows::Forms::Label());
				this->fileTypeLabels[i] = (gcnew System::Windows::Forms::Label());
				this->fileSizeLabels[i] = (gcnew System::Windows::Forms::Label());
				this->pictureBoxes[i] = (gcnew System::Windows::Forms::PictureBox());
				//
				// layout suspend
				//
				this->panels[i]->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxes[i]))->BeginInit();
				this->ContentSplitContainer->Panel2->Controls->Add(this->panels[i]);
				//
				// panel
				//
				this->panels[i]->BackColor = System::Drawing::SystemColors::ControlLightLight;
				this->panels[i]->Controls->Add(this->fileSizeLabels[i]);
				this->panels[i]->Controls->Add(this->fileTypeLabels[i]);
				this->panels[i]->Controls->Add(this->fileNameLabels[i]);
				this->panels[i]->Controls->Add(this->pictureBoxes[i]);
				this->panels[i]->Location = System::Drawing::Point(22, 36 + i * 26);
				this->panels[i]->Margin = System::Windows::Forms::Padding(0);
				this->panels[i]->Name = L"panel" + i.ToString();
				this->panels[i]->Size = System::Drawing::Size(633, 26);
				this->panels[i]->TabIndex = 6;
				this->panels[i]->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AnnexationForm::OnMouseClick);
				//this->panels[i]->MouseCaptureChanged += gcnew System::EventHandler(this, &AnnexationForm::OnMouseCaptureChanged);
				this->panels[i]->MouseEnter += gcnew System::EventHandler(this, &AnnexationForm::OnMouseEnter);
				this->panels[i]->MouseLeave += gcnew System::EventHandler(this, &AnnexationForm::OnMouseLeave);
				
				//
				// pictureBox
				//
				if (fileSystem->getFileTypeOfDirectoryId(i) == "FILE") {
					this->pictureBoxes[i]->Image = Image::FromFile("fileicon_middle.ico");
				}
				else {
					this->pictureBoxes[i]->Image = Image::FromFile("foldericon_middle.ico");
				}
				this->pictureBoxes[i]->Location = System::Drawing::Point(1, -1);
				this->pictureBoxes[i]->Name = L"pictureBoxes" + i.ToString();
				this->pictureBoxes[i]->Size = System::Drawing::Size(24, 24);
				this->pictureBoxes[i]->TabIndex = 0;
				this->pictureBoxes[i]->TabStop = false;
				// 
				// fileNameLabel
				// 
				this->fileNameLabels[i]->AutoSize = true;
				this->fileNameLabels[i]->CausesValidation = false;
				this->fileNameLabels[i]->Enabled = false;
				this->fileNameLabels[i]->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(134)));
				this->fileNameLabels[i]->Location = System::Drawing::Point(25, 4);
				this->fileNameLabels[i]->Name = L"fileNameLabels" + i.ToString();
				this->fileNameLabels[i]->Size = System::Drawing::Size(53, 20);
				this->fileNameLabels[i]->TabIndex = 1;
				this->fileNameLabels[i]->Text = fileSystem->getNameOfDirectoryId(i);
				// 
				// fileTypeLabel
				// 
				this->fileTypeLabels[i]->AutoSize = true;
				this->fileTypeLabels[i]->CausesValidation = false;
				this->fileTypeLabels[i]->Enabled = false;
				this->fileTypeLabels[i]->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(134)));
				this->fileTypeLabels[i]->Location = System::Drawing::Point(246, 4);
				this->fileTypeLabels[i]->Name = L"fileTypeLabels" + i.ToString();
				this->fileTypeLabels[i]->Size = System::Drawing::Size(55, 15);
				this->fileTypeLabels[i]->TabIndex = 2;
				this->fileTypeLabels[i]->Text = fileSystem->getFileTypeOfDirectoryId(i);
				// 
				// fileSizeLabel
				// 
				this->fileSizeLabels[i]->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
				this->fileSizeLabels[i]->AutoSize = false;
				this->fileSizeLabels[i]->CausesValidation = false;
				this->fileSizeLabels[i]->Enabled = false;
				this->fileSizeLabels[i]->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(134)));
				this->fileSizeLabels[i]->Location = System::Drawing::Point(429, 4);
				this->fileSizeLabels[i]->Name = L"fileSizeLabels" + i.ToString();
				this->fileSizeLabels[i]->Size = System::Drawing::Size(204, 15);
				this->fileSizeLabels[i]->TextAlign = System::Drawing::ContentAlignment::TopRight;
				this->fileSizeLabels[i]->TabIndex = 3;
				this->fileSizeLabels[i]->Text = fileSystem->Parse(fileSystem->getFileSizeOfDirectoryId(i)) + " B";
				//
				// resume layout
				//
				this->panels[i]->ResumeLayout(false);
				this->panels[i]->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxes[i]))->EndInit();
			}
		}

		void reset() {
			newFileName = 1;
			newFolderName = 1;
			diskUsedPercentageInNumber = fileSystem->getCurrentDiskSize() / (BLOCK_BEGIN_INDEX_IN_MEMORY + MAX_FILE_SIZE);
			this->diskSizeValue->Text = fileSystem->Parse(fileSystem->getCurrentDiskSize());
			this->diskSizeValue->Text += " B";
			this->diskUsedBar->Value = diskUsedPercentageInNumber;
			this->path->Text = fileSystem->getPath();

			relayout();
		}

		void UIControl() {
			while (!willExitSystem) {
				if (fileSystem->getCurrentINodeIndex() == 0) {
					backButton->Enabled = false;
				}
				else {
					backButton->Enabled = true;
				}
				UIController->Sleep(100);
			}

		}


	private:
		bool willExitSystem;
		int newFolderName;
		int newFileName;
		System::Int32 diskUsedPercentageInNumber;
		array<System::Windows::Forms::Panel^>^ panels;
		array<System::Windows::Forms::Label^>^ fileNameLabels;
		array<System::Windows::Forms::Label^>^ fileTypeLabels;
		array<System::Windows::Forms::Label^>^ fileSizeLabels;
		array<System::Windows::Forms::PictureBox^>^ pictureBoxes;

	private: System::Windows::Forms::Panel^  fileName;

	private: System::Windows::Forms::Label^  diskSizeValue;


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
	private: System::Windows::Forms::Label^  fileSizeMark;
	private: System::Windows::Forms::ProgressBar^  diskUsedBar;
	private: System::Windows::Forms::Label^  diskUsedPercentage;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AnnexationForm::typeid));
			this->topPanel = (gcnew System::Windows::Forms::Panel());
			this->OPERATE = (gcnew System::Windows::Forms::Label());
			this->ORGANIZE = (gcnew System::Windows::Forms::Label());
			this->NEW = (gcnew System::Windows::Forms::Label());
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
			this->divideLine3 = (gcnew System::Windows::Forms::Panel());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->buttomPanel = (gcnew System::Windows::Forms::Panel());
			this->diskSizeValue = (gcnew System::Windows::Forms::Label());
			this->diskUsedPercentage = (gcnew System::Windows::Forms::Label());
			this->diskUsedBar = (gcnew System::Windows::Forms::ProgressBar());
			this->fileSizeMark = (gcnew System::Windows::Forms::Label());
			this->pathPanel = (gcnew System::Windows::Forms::Panel());
			this->path = (gcnew System::Windows::Forms::TextBox());
			this->refreshButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->ContentSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->divideLine6 = (gcnew System::Windows::Forms::Panel());
			this->divideLine5 = (gcnew System::Windows::Forms::Panel());
			this->filesize = (gcnew System::Windows::Forms::Panel());
			this->fileSIZELABEL = (gcnew System::Windows::Forms::Label());
			this->divideLine4 = (gcnew System::Windows::Forms::Panel());
			this->filetype = (gcnew System::Windows::Forms::Panel());
			this->fileTYPELABEL = (gcnew System::Windows::Forms::Label());
			this->fileName = (gcnew System::Windows::Forms::Panel());
			this->fileNAMELABEL = (gcnew System::Windows::Forms::Label());
			this->topPanel->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->buttonLayoutPanel->SuspendLayout();
			this->mainPanel->SuspendLayout();
			this->buttomPanel->SuspendLayout();
			this->pathPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ContentSplitContainer))->BeginInit();
			this->ContentSplitContainer->Panel2->SuspendLayout();
			this->ContentSplitContainer->SuspendLayout();
			this->filesize->SuspendLayout();
			this->filetype->SuspendLayout();
			this->fileName->SuspendLayout();
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
			// OPERATE
			// 
			this->OPERATE->AutoSize = true;
			this->OPERATE->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OPERATE->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->OPERATE->Location = System::Drawing::Point(356, 135);
			this->OPERATE->Margin = System::Windows::Forms::Padding(0);
			this->OPERATE->Name = L"OPERATE";
			this->OPERATE->Size = System::Drawing::Size(87, 18);
			this->OPERATE->TabIndex = 11;
			this->OPERATE->Text = L"OPERATE";
			// 
			// ORGANIZE
			// 
			this->ORGANIZE->AutoSize = true;
			this->ORGANIZE->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ORGANIZE->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->ORGANIZE->Location = System::Drawing::Point(189, 135);
			this->ORGANIZE->Margin = System::Windows::Forms::Padding(0);
			this->ORGANIZE->Name = L"ORGANIZE";
			this->ORGANIZE->Size = System::Drawing::Size(97, 18);
			this->ORGANIZE->TabIndex = 10;
			this->ORGANIZE->Text = L"ORGANIZE";
			// 
			// NEW
			// 
			this->NEW->AutoSize = true;
			this->NEW->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NEW->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->NEW->Location = System::Drawing::Point(54, 135);
			this->NEW->Margin = System::Windows::Forms::Padding(0);
			this->NEW->Name = L"NEW";
			this->NEW->Size = System::Drawing::Size(49, 18);
			this->NEW->TabIndex = 9;
			this->NEW->Text = L"NEW";
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
			this->fileSystemToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->fileSystemToolStripMenuItem->Name = L"fileSystemToolStripMenuItem";
			this->fileSystemToolStripMenuItem->Size = System::Drawing::Size(99, 24);
			this->fileSystemToolStripMenuItem->Text = L"FileSystem";
			// 
			// formatToolStripMenuItem
			// 
			this->formatToolStripMenuItem->Name = L"formatToolStripMenuItem";
			this->formatToolStripMenuItem->Size = System::Drawing::Size(133, 26);
			this->formatToolStripMenuItem->Text = L"format";
			this->formatToolStripMenuItem->Click += gcnew System::EventHandler(this, &AnnexationForm::formatToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(133, 26);
			this->exitToolStripMenuItem->Text = L"exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &AnnexationForm::exitToolStripMenuItem_Click);
			// 
			// homepageToolStripMenuItem
			// 
			this->homepageToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->homepageToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
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
			this->createFolder->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->createFolder->Location = System::Drawing::Point(0, 5);
			this->createFolder->Margin = System::Windows::Forms::Padding(0, 5, 0, 5);
			this->createFolder->Name = L"createFolder";
			this->createFolder->Size = System::Drawing::Size(75, 100);
			this->createFolder->TabIndex = 0;
			this->createFolder->Text = L"new folder";
			this->createFolder->UseVisualStyleBackColor = false;
			this->createFolder->Click += gcnew System::EventHandler(this, &AnnexationForm::createFolder_Click);
			// 
			// createFile
			// 
			this->createFile->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->createFile->FlatAppearance->BorderSize = 0;
			this->createFile->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->createFile->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->createFile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->createFile->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->createFile->Location = System::Drawing::Point(76, 5);
			this->createFile->Margin = System::Windows::Forms::Padding(1, 5, 5, 5);
			this->createFile->Name = L"createFile";
			this->createFile->Size = System::Drawing::Size(75, 100);
			this->createFile->TabIndex = 3;
			this->createFile->Text = L"new  file";
			this->createFile->UseVisualStyleBackColor = true;
			this->createFile->Click += gcnew System::EventHandler(this, &AnnexationForm::createFile_Click);
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
			this->remove->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->remove->Location = System::Drawing::Point(162, 5);
			this->remove->Margin = System::Windows::Forms::Padding(5, 5, 0, 5);
			this->remove->Name = L"remove";
			this->remove->Size = System::Drawing::Size(75, 100);
			this->remove->TabIndex = 1;
			this->remove->Text = L"delete";
			this->remove->UseVisualStyleBackColor = true;
			// 
			// rename
			// 
			this->rename->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->rename->FlatAppearance->BorderSize = 0;
			this->rename->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->rename->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->rename->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rename->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rename->Location = System::Drawing::Point(238, 5);
			this->rename->Margin = System::Windows::Forms::Padding(1, 5, 5, 5);
			this->rename->Name = L"rename";
			this->rename->Size = System::Drawing::Size(75, 100);
			this->rename->TabIndex = 2;
			this->rename->Text = L"new name";
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
			this->open->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
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
			this->closeFile->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->closeFile->Location = System::Drawing::Point(400, 5);
			this->closeFile->Margin = System::Windows::Forms::Padding(1, 5, 5, 5);
			this->closeFile->Name = L"closeFile";
			this->closeFile->Size = System::Drawing::Size(75, 100);
			this->closeFile->TabIndex = 5;
			this->closeFile->Text = L"close file";
			this->closeFile->UseVisualStyleBackColor = false;
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
			this->buttomPanel->Controls->Add(this->diskSizeValue);
			this->buttomPanel->Controls->Add(this->diskUsedPercentage);
			this->buttomPanel->Controls->Add(this->diskUsedBar);
			this->buttomPanel->Controls->Add(this->fileSizeMark);
			this->buttomPanel->Location = System::Drawing::Point(0, 480);
			this->buttomPanel->Name = L"buttomPanel";
			this->buttomPanel->Size = System::Drawing::Size(1080, 21);
			this->buttomPanel->TabIndex = 2;
			// 
			// diskSizeValue
			// 
			this->diskSizeValue->AutoSize = true;
			this->diskSizeValue->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->diskSizeValue->Location = System::Drawing::Point(90, 1);
			this->diskSizeValue->Name = L"diskSizeValue";
			this->diskSizeValue->Size = System::Drawing::Size(89, 20);
			this->diskSizeValue->TabIndex = 3;
			this->diskSizeValue->Text = L"defaultSize";
			// 
			// diskUsedPercentage
			// 
			this->diskUsedPercentage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->diskUsedPercentage->AutoSize = true;
			this->diskUsedPercentage->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->diskUsedPercentage->Location = System::Drawing::Point(877, 1);
			this->diskUsedPercentage->Margin = System::Windows::Forms::Padding(3, 0, 8, 0);
			this->diskUsedPercentage->Name = L"diskUsedPercentage";
			this->diskUsedPercentage->Size = System::Drawing::Size(90, 20);
			this->diskUsedPercentage->TabIndex = 2;
			this->diskUsedPercentage->Text = L"DISK USED:";
			// 
			// diskUsedBar
			// 
			this->diskUsedBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->diskUsedBar->Location = System::Drawing::Point(977, 6);
			this->diskUsedBar->Margin = System::Windows::Forms::Padding(5);
			this->diskUsedBar->Name = L"diskUsedBar";
			this->diskUsedBar->Size = System::Drawing::Size(100, 12);
			this->diskUsedBar->Step = 1;
			this->diskUsedBar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->diskUsedBar->TabIndex = 1;
			// 
			// fileSizeMark
			// 
			this->fileSizeMark->AutoSize = true;
			this->fileSizeMark->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->fileSizeMark->Location = System::Drawing::Point(0, 1);
			this->fileSizeMark->Name = L"fileSizeMark";
			this->fileSizeMark->Size = System::Drawing::Size(81, 20);
			this->fileSizeMark->TabIndex = 0;
			this->fileSizeMark->Text = L"DISK SIZE:";
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
			this->refreshButton->FlatAppearance->BorderSize = 0;
			this->refreshButton->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->refreshButton->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->refreshButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->refreshButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->refreshButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->refreshButton->Location = System::Drawing::Point(970, 4);
			this->refreshButton->Margin = System::Windows::Forms::Padding(1, 0, 5, 0);
			this->refreshButton->MinimumSize = System::Drawing::Size(105, 29);
			this->refreshButton->Name = L"refreshButton";
			this->refreshButton->Size = System::Drawing::Size(105, 29);
			this->refreshButton->TabIndex = 2;
			this->refreshButton->Text = L"REFRESH";
			this->refreshButton->UseVisualStyleBackColor = false;
			this->refreshButton->Click += gcnew System::EventHandler(this, &AnnexationForm::refreshButton_Click);
			// 
			// backButton
			// 
			this->backButton->BackColor = System::Drawing::SystemColors::Control;
			this->backButton->FlatAppearance->BorderSize = 0;
			this->backButton->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->backButton->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->backButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->backButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->backButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->backButton->Location = System::Drawing::Point(5, 4);
			this->backButton->Margin = System::Windows::Forms::Padding(5, 0, 1, 0);
			this->backButton->MinimumSize = System::Drawing::Size(105, 29);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(105, 29);
			this->backButton->TabIndex = 1;
			this->backButton->Text = L"BACK";
			this->backButton->UseVisualStyleBackColor = false;
			this->backButton->Click += gcnew System::EventHandler(this, &AnnexationForm::backButton_Click);
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
			this->ContentSplitContainer->Panel2->AutoScroll = true;
			this->ContentSplitContainer->Panel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ContentSplitContainer->Panel2->Controls->Add(this->divideLine6);
			this->ContentSplitContainer->Panel2->Controls->Add(this->divideLine5);
			this->ContentSplitContainer->Panel2->Controls->Add(this->filesize);
			this->ContentSplitContainer->Panel2->Controls->Add(this->divideLine4);
			this->ContentSplitContainer->Panel2->Controls->Add(this->filetype);
			this->ContentSplitContainer->Panel2->Controls->Add(this->fileName);
			this->ContentSplitContainer->Size = System::Drawing::Size(1082, 466);
			this->ContentSplitContainer->SplitterDistance = 150;
			this->ContentSplitContainer->SplitterWidth = 1;
			this->ContentSplitContainer->TabIndex = 1;
			// 
			// divideLine6
			// 
			this->divideLine6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->divideLine6->Location = System::Drawing::Point(872, 6);
			this->divideLine6->Name = L"divideLine6";
			this->divideLine6->Size = System::Drawing::Size(1, 30);
			this->divideLine6->TabIndex = 5;
			// 
			// divideLine5
			// 
			this->divideLine5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->divideLine5->Location = System::Drawing::Point(602, 6);
			this->divideLine5->Name = L"divideLine5";
			this->divideLine5->Size = System::Drawing::Size(1, 30);
			this->divideLine5->TabIndex = 4;
			// 
			// filesize
			// 
			this->filesize->Controls->Add(this->fileSIZELABEL);
			this->filesize->Location = System::Drawing::Point(602, 6);
			this->filesize->Name = L"filesize";
			this->filesize->Size = System::Drawing::Size(272, 30);
			this->filesize->TabIndex = 3;
			this->filesize->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AnnexationForm::OnMouseDown);
			this->filesize->MouseEnter += gcnew System::EventHandler(this, &AnnexationForm::OnMouseEnter);
			this->filesize->MouseLeave += gcnew System::EventHandler(this, &AnnexationForm::OnMouseLeave);
			this->filesize->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &AnnexationForm::OnMouseUp);
			// 
			// fileSIZELABEL
			// 
			this->fileSIZELABEL->AutoSize = true;
			this->fileSIZELABEL->CausesValidation = false;
			this->fileSIZELABEL->Enabled = false;
			this->fileSIZELABEL->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->fileSIZELABEL->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->fileSIZELABEL->Location = System::Drawing::Point(5, 3);
			this->fileSIZELABEL->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->fileSIZELABEL->Name = L"fileSIZELABEL";
			this->fileSIZELABEL->Size = System::Drawing::Size(58, 20);
			this->fileSIZELABEL->TabIndex = 0;
			this->fileSIZELABEL->Text = L"filesize";
			// 
			// divideLine4
			// 
			this->divideLine4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->divideLine4->Location = System::Drawing::Point(352, 6);
			this->divideLine4->Margin = System::Windows::Forms::Padding(0);
			this->divideLine4->Name = L"divideLine4";
			this->divideLine4->Size = System::Drawing::Size(1, 30);
			this->divideLine4->TabIndex = 1;
			// 
			// filetype
			// 
			this->filetype->Controls->Add(this->fileTYPELABEL);
			this->filetype->Location = System::Drawing::Point(352, 6);
			this->filetype->Name = L"filetype";
			this->filetype->Size = System::Drawing::Size(250, 30);
			this->filetype->TabIndex = 2;
			this->filetype->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AnnexationForm::OnMouseDown);
			this->filetype->MouseEnter += gcnew System::EventHandler(this, &AnnexationForm::OnMouseEnter);
			this->filetype->MouseLeave += gcnew System::EventHandler(this, &AnnexationForm::OnMouseLeave);
			this->filetype->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &AnnexationForm::OnMouseUp);
			// 
			// fileTYPELABEL
			// 
			this->fileTYPELABEL->AutoSize = true;
			this->fileTYPELABEL->CausesValidation = false;
			this->fileTYPELABEL->Enabled = false;
			this->fileTYPELABEL->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->fileTYPELABEL->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->fileTYPELABEL->Location = System::Drawing::Point(5, 3);
			this->fileTYPELABEL->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->fileTYPELABEL->Name = L"fileTYPELABEL";
			this->fileTYPELABEL->Size = System::Drawing::Size(64, 20);
			this->fileTYPELABEL->TabIndex = 3;
			this->fileTYPELABEL->Text = L"filetype";
			// 
			// fileName
			// 
			this->fileName->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->fileName->Controls->Add(this->fileNAMELABEL);
			this->fileName->Location = System::Drawing::Point(2, 6);
			this->fileName->Margin = System::Windows::Forms::Padding(0);
			this->fileName->Name = L"fileName";
			this->fileName->Size = System::Drawing::Size(350, 30);
			this->fileName->TabIndex = 0;
			this->fileName->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AnnexationForm::OnMouseDown);
			this->fileName->MouseEnter += gcnew System::EventHandler(this, &AnnexationForm::OnMouseEnter);
			this->fileName->MouseLeave += gcnew System::EventHandler(this, &AnnexationForm::OnMouseLeave);
			this->fileName->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &AnnexationForm::OnMouseUp);
			// 
			// fileNAMELABEL
			// 
			this->fileNAMELABEL->AutoSize = true;
			this->fileNAMELABEL->CausesValidation = false;
			this->fileNAMELABEL->Enabled = false;
			this->fileNAMELABEL->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->fileNAMELABEL->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->fileNAMELABEL->Location = System::Drawing::Point(5, 3);
			this->fileNAMELABEL->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->fileNAMELABEL->Name = L"fileNAMELABEL";
			this->fileNAMELABEL->Size = System::Drawing::Size(71, 20);
			this->fileNAMELABEL->TabIndex = 0;
			this->fileNAMELABEL->Text = L"filename";
			// 
			// AnnexationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1080, 660);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->topPanel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(523, 500);
			this->Name = L"AnnexationForm";
			this->Text = L"Annexation File System v1.0.2.170624_beta";
			this->topPanel->ResumeLayout(false);
			this->topPanel->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->buttonLayoutPanel->ResumeLayout(false);
			this->mainPanel->ResumeLayout(false);
			this->buttomPanel->ResumeLayout(false);
			this->buttomPanel->PerformLayout();
			this->pathPanel->ResumeLayout(false);
			this->pathPanel->PerformLayout();
			this->ContentSplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ContentSplitContainer))->EndInit();
			this->ContentSplitContainer->ResumeLayout(false);
			this->filesize->ResumeLayout(false);
			this->filesize->PerformLayout();
			this->filetype->ResumeLayout(false);
			this->filetype->PerformLayout();
			this->fileName->ResumeLayout(false);
			this->fileName->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void formatToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fileSystem->formatFileSystem();
	reset();
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	willExitSystem = true;
	UIController->Abort();
	fileSystem->exitFileSystem();
	System::Environment::Exit(0);
	this->Close();
}
private: System::Void refreshButton_Click(System::Object^  sender, System::EventArgs^  e) {
	fileSystem->enterDirectory(fileSystem->getCurrentINodeIndex(), ".");
	reset();
}
private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e) {
	fileSystem->enterDirectory(fileSystem->getCurrentINodeIndex(), "..");
	reset();
}
private: System::Void createFolder_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string defaultName = "new folder";
	std::string name = "new folder";
	while (!fileSystem->checkNameExistance(name)) {
		++newFolderName;
		name = defaultName + (char)('0' + newFolderName);
	}
	fileSystem->makeFile(fileSystem->getCurrentINodeIndex(), name, DIRECTORY);
	reset();
}
private: System::Void createFile_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string defaultName = "new file";
	std::string name = "new file";
	while (!fileSystem->checkNameExistance(name)) {
		++newFileName;
		name = defaultName + (char)('0' + newFileName);
	}
	fileSystem->makeFile(fileSystem->getCurrentINodeIndex(), name, FILE);
	reset();
}

		 void OnMouseLeave(System::Object ^sender, System::EventArgs ^e);
		 void OnMouseEnter(System::Object ^sender, System::EventArgs ^e);
		 void OnMouseDown(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e);
		 void OnMouseUp(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e);
		 void OnMouseClick(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e);
		 //void OnMouseCaptureChanged(System::Object ^sender, System::EventArgs ^e);
};
}

void Annexation::AnnexationForm::OnMouseEnter(System::Object ^sender, System::EventArgs ^e)
{
	System::Windows::Forms::Panel^ temp = (Panel^)sender;
	temp->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
	//throw gcnew System::NotImplementedException();
}

void Annexation::AnnexationForm::OnMouseLeave(System::Object ^sender, System::EventArgs ^e)
{
	System::Windows::Forms::Panel^ temp = (Panel^)sender;
	temp->BackColor = System::Drawing::SystemColors::ControlLightLight;
	//throw gcnew System::NotImplementedException();
}


void Annexation::AnnexationForm::OnMouseDown(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e)
{
	System::Windows::Forms::Panel^ temp = (Panel^)sender;
	temp->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
	//throw gcnew System::NotImplementedException();
}


void Annexation::AnnexationForm::OnMouseUp(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e)
{
	System::Windows::Forms::Panel^ temp = (Panel^)sender;
	temp->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
	//throw gcnew System::NotImplementedException();
}


void Annexation::AnnexationForm::OnMouseClick(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e)
{
	System::Windows::Forms::Panel^ temp = (Panel^)sender;
	temp->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
	//throw gcnew System::NotImplementedException();
}


/*void Annexation::AnnexationForm::OnMouseCaptureChanged(System::Object ^sender, System::EventArgs ^e)
{
	System::Windows::Forms::Panel^ temp = (Panel^)sender;
	temp->BackColor = System::Drawing::SystemColors::ControlDarkDark;
	//throw gcnew System::NotImplementedException();
}*/
