#include <windows.h>
#include "MyForm.h"

using namespace System;
using namespace Project1;

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
	return 0;
}
