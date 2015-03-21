#include "MainForm.h"
//#include <windows.h>

using namespace Diehard;

[STAThreadAttribute]//for openFileDialog in Debug Mode

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)//only WinForms
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					   _In_opt_ HINSTANCE hPrevInstance,
					   _In_ LPTSTR    lpCmdLine,
					   _In_ int       nCmdShow)
//int main()//console windows with WinForms
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	MainForm::_newCulture = CultureInfo::CurrentCulture->Name;

	if (!(MainForm::_newCulture == "en-US" || MainForm::_newCulture == "ru-RU" || MainForm::_newCulture == "uk-UA"))
		MainForm::_newCulture = "en-US";

	while (MainForm::_newCulture != "")//зміна мови
	{  
		MainForm::_form = gcnew MainForm(MainForm::_newCulture);
		MainForm::_newCulture = "";
		Application::Run(MainForm::_form);
	}

	//Application::Run(gcnew MainForm());
	return 0;
}