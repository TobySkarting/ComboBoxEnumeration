#include <Windows.h>
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;


System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	HWND hWndMain = FindWindow(NULL, "MyForm");
	HWND hGroupBox = FindWindowEx(hWndMain, NULL, NULL, NULL);
	
	ComboBox ^cb = gcnew ComboBox;
	LPSTR lpComboBoxClassName = new CHAR[200];
	GetClassName(static_cast<HWND>(cb->Handle.ToPointer()), lpComboBoxClassName, 200);
	textBox1->Text = gcnew String(lpComboBoxClassName);

	listBox1->Items->Clear(); 
	LPSTR lpStr = new CHAR[200];
	HWND hComboBox = FindWindowEx(hGroupBox, NULL, lpComboBoxClassName, NULL);
	while (hComboBox)
	{
		HWND hComboEdit = FindWindowEx(hComboBox, NULL, NULL, NULL);

		GetWindowText(hComboEdit, lpStr, 200);
		listBox1->Items->Add(gcnew String(lpStr) + " - " + reinterpret_cast<unsigned int>(hComboBox).ToString("X"));
		
		hComboBox = FindWindowEx(hGroupBox, hComboBox, lpComboBoxClassName, NULL);
	}
	delete[] lpStr;

}
