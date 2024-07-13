#include "AutoClicker/AutoClicker.h"

int main(int argc, const char **argv) {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    AutoClicker autoclicker_app;

    return autoclicker_app.RunApp();
}



//
//#include <thread>
//#include <chrono>
//
//ComboBox *mouse_buttons;
//Label *cps_label;
//Edit *cps;
//Label *toggle_label;
//Button *change_button;
//
//bool flag = false;
//POINT point;
//
//int main(int argc, const char **argv) {
//	const char *version = "AutoClicker v2.4";
//
//	try
//	{
//		// Create window
//		Window window(version, "icon.ico", 200, 200, 262, 130);
//
//		// Create forms
//		mouse_buttons = new ComboBox(window.hWnd, 10, 10, 95, 0);
//		{
//			mouse_buttons->AddItem("Left button");
//			mouse_buttons->AddItem("Right button");
//			mouse_buttons->SelectItem(0);
//		}
//
//		cps_label = new Label(window.hWnd, "CPS:", 170, 12, 30, 20);
//		cps = new Edit(window.hWnd, 200, 10, 35, 22, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT | ES_NUMBER);
//
//		toggle_label = new Label(window.hWnd, "Toggle key: 76(L)", 12, 54, 85, 32);
//		change_button = new Button(window.hWnd, "Change toggle key", 100, 52, 130, 30);
//
//		// Set forms normal font
//		NormalFont normal_font;
//		{
//			normal_font.SetFont(mouse_buttons->hWnd);
//			normal_font.SetFont(cps_label->hWnd);
//			normal_font.SetFont(cps->hWnd);
//			normal_font.SetFont(toggle_label->hWnd);
//			normal_font.SetFont(change_button->hWnd);
//		}
//
//		cps->SetText("20");
//
//		std::chrono::time_point millis = std::chrono::high_resolution_clock::now();
//		char cps_str[5] = {};
//
//		// Clicker thread
//		std::thread clicker_thread([&]
//			{
//				while (true)
//				{
//					memset(cps_str, 0, sizeof(cps_str));
//					cps->GetText(cps_str, sizeof(cps_str));
//					if (std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - millis).count() >= (long long)(pow(10, 9) / atof(cps_str)))
//					{
//						millis = std::chrono::high_resolution_clock::now();
//						if (flag && !mouse_buttons->GetItemId())
//						{
//							GetCursorPos(&point);
//							mouse_event(MOUSEEVENTF_LEFTDOWN, point.x, point.y, 0, 0);
//							mouse_event(MOUSEEVENTF_LEFTUP, point.x, point.y, 0, 0);
//						}
//						else if (flag && mouse_buttons->GetItemId())
//						{
//							GetCursorPos(&point);
//							mouse_event(MOUSEEVENTF_RIGHTDOWN, point.x, point.y, 0, 0);
//							mouse_event(MOUSEEVENTF_RIGHTUP, point.x, point.y, 0, 0);
//						}
//					}
//
//					std::this_thread::sleep_for(std::chrono::nanoseconds(1));
//				}
//			});
//		clicker_thread.detach();
//
//		// Run main loop
//		window.RunMessageLoop();
//	}
//	catch (std::runtime_error e)
//	{
//		MessageBox(NULL, e.what(), "Error", MB_OK);
//	}
//
//	return 0;
//}
