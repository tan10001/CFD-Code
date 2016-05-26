#include "Conduction_options.h"
#include "MyForm.h"
#include "MyForm2.h"
#include "conduction.h"
#include "Conduction_Inputs.h"


#include <iostream>
//#include "afxwin.h"



using namespace System;
using namespace System::Windows::Forms;




[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Finalconduction::Conduction_options form;
	Application::Run(%form);
	
}
