#ifndef UI_H
#define UI_H

#include "../../resource.h"

#define WINDOWLIB_NO_CONSOLE

#include "../../WindowLib/Window.h"
#include "../../WindowLib/NormalFont.h"

class UI {
public:
    /* Windows & controls */
    NormalFont _normal_font = NormalFont();

    Window _autoclicker_wnd = Window("AutoClicker",
        WndPairValue{ CW_USEDEFAULT, CW_USEDEFAULT }, WndPairValue{ 286/*270*/, 159/*120*/},
        IDI_ICON1, WS_OVERLAPPED | WS_SYSMENU);

    Label _cps_label = Label("CPS:", WndPairValue{ 193, 12 }, WndPairValue{ 30, 20 });
    Label _hotkey_label = Label("Hotkey: L (76)", WndPairValue{ 12, 84 }, WndPairValue{ 105, 20 });
    Label _kb_target_key_label = Label("Key: A (65)", WndPairValue{ 110, 12 }, WndPairValue{ 78, 20 });

    ComboBox _buttons_list = ComboBox(WndPairValue{ 10, 10 }, WndPairValue{ 95, 0 });

    Edit _cps_edit = Edit(WndPairValue{ 225, 10 }, WndPairValue{ 35, 22 });

    Button _change_kb_target_key_button = Button("Set key", WndPairValue{ 110, 38 }, WndPairValue{ 60, 25 });
    Button _change_hotkey_button = Button("Change hotkey", WndPairValue{ 130, 82 }, WndPairValue{ 130, 30 });

    UI(const char *version = "UI");
    ~UI() = default;
};

#endif
