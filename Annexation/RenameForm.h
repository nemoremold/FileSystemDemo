#pragma once

namespace Annexation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::Collections::Generic;

	/// <summary>
	/// MyForm 摘要
	/// </summary>
	public ref class RenameForm : public System::Windows::Forms::Form
	{
	public:

		RenameForm(void) {
			InitializeComponent();
		}
		RenameForm(System::String^ Param) {
			InitializeComponent();
			set(Param);
		}

		System::String^ get() {
			return newNameBox->Text;
		}

		void set(System::String^ value) {
			newNameBox->Text = value;
		}


	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~RenameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  newNameBox;
	private: System::Windows::Forms::Label^  prompt;
	protected:

	private: System::Windows::Forms::Button^  confirmButton;
	private: System::Windows::Forms::Button^  cancelButton;

	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->newNameBox = (gcnew System::Windows::Forms::TextBox());
			this->prompt = (gcnew System::Windows::Forms::Label());
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// newNameBox
			// 
			this->newNameBox->Location = System::Drawing::Point(17, 43);
			this->newNameBox->Name = L"newNameBox";
			this->newNameBox->Size = System::Drawing::Size(302, 25);
			this->newNameBox->TabIndex = 0;
			this->newNameBox->TextChanged += gcnew System::EventHandler(this, &RenameForm::OnTextChanged);
			// 
			// prompt
			// 
			this->prompt->AutoSize = true;
			this->prompt->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->prompt->Location = System::Drawing::Point(9, 13);
			this->prompt->Name = L"prompt";
			this->prompt->Size = System::Drawing::Size(319, 19);
			this->prompt->TabIndex = 1;
			this->prompt->Text = L"Enter new file name in the textbox below";
			// 
			// confirmButton
			// 
			this->confirmButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->confirmButton->FlatAppearance->BorderSize = 0;
			this->confirmButton->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->confirmButton->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->confirmButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->confirmButton->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmButton->Location = System::Drawing::Point(17, 80);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(140, 53);
			this->confirmButton->TabIndex = 2;
			this->confirmButton->Text = L"CONFIRM";
			this->confirmButton->UseVisualStyleBackColor = true;
			// 
			// cancelButton
			// 
			this->cancelButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->FlatAppearance->BorderSize = 0;
			this->cancelButton->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->cancelButton->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->cancelButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(179, 80);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(140, 53);
			this->cancelButton->TabIndex = 3;
			this->cancelButton->Text = L"CANCEL";
			this->cancelButton->UseVisualStyleBackColor = false;
			this->cancelButton->Click += gcnew System::EventHandler(this, &RenameForm::cancelButton_Click);
			// 
			// RenameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(334, 144);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->prompt);
			this->Controls->Add(this->newNameBox);
			this->Name = L"RenameForm";
			this->Text = L"Rename";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
			 void OnTextChanged(System::Object ^sender, System::EventArgs ^e);
};
}


void Annexation::RenameForm::OnTextChanged(System::Object ^sender, System::EventArgs ^e) {
	System::Windows::Forms::TextBox^ temp = (TextBox^)sender;
	if (temp->Text == "") {
		confirmButton->Enabled = false;
	}
	else {
		confirmButton->Enabled = true;
	}
	//throw gcnew System::NotImplementedException();
}
