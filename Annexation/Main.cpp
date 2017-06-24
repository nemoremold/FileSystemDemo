//
//  Main.cpp
//  Annexation
//
//
//  0.1.0.170620_base   basic construction of the system
//  0.2.0.170620_base   basic implementation of the system in C#
//  0.2.1.170621_base   some alternatives applied on file operation
//  0.3.0.170621_base   reconstructed system with C++
//  0.3.1.170622_base   removed pointer operation of entity classes
//  0.3.2.170622_base   reconstructed entity classes' hierachy
//  0.3.3.170622_base   changed linked list mapping method to hash mapping
//  0.3.4.170623_alpha  many internal bugs fixed and basic system implemented, alpha version reached
//  0.3.5.170624_alpha  patches on file editing
//  1.0.0.170624_beta   initial gui added, beta version reached
//
//
//  Created by Emoin Lam on 22/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//

#include "AnnexationForm.h"
#include "FileSystem.h"
#include <cstdio>
#include <iostream>
using namespace Annexation;
using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Annexation::AnnexationForm form;
	Application::Run(%form);
}