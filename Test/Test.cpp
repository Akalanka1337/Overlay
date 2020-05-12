// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <iostream>
#include "D3DOverlay.h"

using X2295::D3DOverlay;

auto Render(FLOAT aWidth, FLOAT aHeight)->VOID
{
	static bool vIsEnableEsp = FALSE;

	ImGui::Begin("Misc");
	ImGui::Text(xorstr_("Application average %.3f ms/frame (%.1f FPS)"), 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::Checkbox(xorstr_("Enable Esp"), &vIsEnableEsp);
	ImGui::End();
	D3DOverlay::DrawCrossHair(15, ImColor(255, 0, 0));
}

int main()
{
	system("start notepad"); //For test
	Sleep(1000); //Wait for notepad startup
	auto vTargetWindow = FindWindow(xorstr_(_T("Notepad")), xorstr_(_T("Untitled - Notepad"))); //Find target window
	if (IsWindow(vTargetWindow)) //Validate window
	{
		if (D3DOverlay::InitOverlay(xorstr_(_T("xxxxx")), xorstr_(_T("xxxxxxxxxx")))) // Init overlay
		{
			D3DOverlay::SetUserRender(Render); //User custom render
			while (D3DOverlay::MsgLoop() && D3DOverlay::AttachWindow(vTargetWindow)) {}; //Sleep?
			D3DOverlay::UninitOverlay(); //Cleanup overlay
		}
	}
	return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file