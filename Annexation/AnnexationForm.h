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
	private: System::Windows::Forms::Panel^  panel1;

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
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->pathPanel = (gcnew System::Windows::Forms::Panel());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->refreshButton = (gcnew System::Windows::Forms::Button());
			this->path = (gcnew System::Windows::Forms::TextBox());
			this->ContentSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
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
			this->topPanel->Location = System::Drawing::Point(0, 0);
			this->topPanel->Margin = System::Windows::Forms::Padding(0);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(1080, 145);
			this->topPanel->TabIndex = 0;
			// 
			// mainPanel
			// 
			this->mainPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mainPanel->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->mainPanel->Controls->Add(this->panel1);
			this->mainPanel->Controls->Add(this->pathPanel);
			this->mainPanel->Controls->Add(this->ContentSplitContainer);
			this->mainPanel->Location = System::Drawing::Point(0, 150);
			this->mainPanel->Margin = System::Windows::Forms::Padding(0);
			this->mainPanel->MinimumSize = System::Drawing::Size(320, 200);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(1080, 500);
			this->mainPanel->TabIndex = 1;
			// 
			// pathPanel
			// 
			this->pathPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pathPanel->Controls->Add(this->path);
			this->pathPanel->Controls->Add(this->refreshButton);
			this->pathPanel->Controls->Add(this->backButton);
			this->pathPanel->Location = System::Drawing::Point(0, 0);
			this->pathPanel->Margin = System::Windows::Forms::Padding(0);
			this->pathPanel->Name = L"pathPanel";
			this->pathPanel->Size = System::Drawing::Size(1080, 40);
			this->pathPanel->TabIndex = 0;
			// 
			// backButton
			// 
			this->backButton->Location = System::Drawing::Point(5, 4);
			this->backButton->Margin = System::Windows::Forms::Padding(5, 0, 1, 0);
			this->backButton->MinimumSize = System::Drawing::Size(105, 29);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(105, 29);
			this->backButton->TabIndex = 1;
			this->backButton->Text = L"BACK";
			this->backButton->UseVisualStyleBackColor = true;
			// 
			// refreshButton
			// 
			this->refreshButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->refreshButton->Location = System::Drawing::Point(970, 4);
			this->refreshButton->Margin = System::Windows::Forms::Padding(1, 0, 5, 0);
			this->refreshButton->MinimumSize = System::Drawing::Size(105, 29);
			this->refreshButton->Name = L"refreshButton";
			this->refreshButton->Size = System::Drawing::Size(105, 29);
			this->refreshButton->TabIndex = 2;
			this->refreshButton->Text = L"refresh";
			this->refreshButton->UseVisualStyleBackColor = true;
			// 
			// path
			// 
			this->path->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->path->Location = System::Drawing::Point(112, 5);
			this->path->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->path->MinimumSize = System::Drawing::Size(100, 4);
			this->path->Name = L"path";
			this->path->Size = System::Drawing::Size(858, 25);
			this->path->TabIndex = 3;
			// 
			// ContentSplitContainer
			// 
			this->ContentSplitContainer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ContentSplitContainer->BackColor = System::Drawing::Color::Silver;
			this->ContentSplitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->ContentSplitContainer->Location = System::Drawing::Point(-1, 35);
			this->ContentSplitContainer->Margin = System::Windows::Forms::Padding(0);
			this->ContentSplitContainer->Name = L"ContentSplitContainer";
			// 
			// ContentSplitContainer.Panel1
			// 
			this->ContentSplitContainer->Panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			// 
			// ContentSplitContainer.Panel2
			// 
			this->ContentSplitContainer->Panel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ContentSplitContainer->Size = System::Drawing::Size(1082, 466);
			this->ContentSplitContainer->SplitterDistance = 150;
			this->ContentSplitContainer->SplitterWidth = 1;
			this->ContentSplitContainer->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Location = System::Drawing::Point(0, 480);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1080, 21);
			this->panel1->TabIndex = 2;
			// 
			// AnnexationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1080, 650);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->topPanel);
			this->MinimumSize = System::Drawing::Size(400, 300);
			this->Name = L"AnnexationForm";
			this->Text = L"AnnexationForm";
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
