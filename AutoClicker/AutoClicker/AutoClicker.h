#ifndef AUTOCLICKER_H
#define AUTOCLICKER_H

#include "../resource.h"

#include "../WindowLib/Window.h"
#include "../WindowLib/NormalFont.h"

class AutoClicker {
private:
    const char *_version = "AutoClicker v2.5";

    NormalFont _normal_font = NormalFont();

    Window _autoclicker_wnd = Window("AutoClicker",
        WndPairValue{ CW_USEDEFAULT, CW_USEDEFAULT }, WndPairValue{ 262, 130 },
        IDI_ICON1, WS_OVERLAPPED | WS_SYSMENU);

    Label _cps_label = Label("CPS:", WndPairValue{ 170, 12 }, WndPairValue{ 30, 20 });
    Label _toggle_key_label = Label("Toggle key: 76(L)", WndPairValue{ 12, 54 }, WndPairValue{ 85, 32 });

    ComboBox _mouse_buttons_list = ComboBox(WndPairValue{ 10, 10 }, WndPairValue{ 95, 0 });

    Edit _cps_edit = Edit(WndPairValue{ 200, 10 }, WndPairValue{ 35, 22 });

    Button _change_key_button = Button("Change toggle key", WndPairValue{ 100, 52 }, WndPairValue{ 130, 30 });

public:
    AutoClicker();

    int RunApp();
};

#endif
