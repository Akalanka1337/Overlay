Overlay wrapper
====
An overlay wrapper with ImGui[Win32_Dx11]


### Usage

1. Install dependency Library with vcpkg


```
vcpkg install imgui imgui[example] xorstr
vcpkg integrate install
```

2. Add the following files to your project

>+ D3DOverlay.h
>+ D3DOverlay.cpp
>+ imgui_impl_dx11.cpp
>+ imgui_impl_win32.cpp

3. Add code to your source code

```cpp
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

```


4. Tested on win10 x64 [1809 17763.1158]