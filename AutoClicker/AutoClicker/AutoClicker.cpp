#include "AutoClicker.h"

AutoClicker::AutoClicker() {
    /* Setup window */
    _autoclicker_wnd.SetWndText(_version);
    _autoclicker_wnd.EnableControlsDialogMessages(true);

    /* Attach child controls to main window */
    _autoclicker_wnd.AttachChildControl(&_cps_label);
    _autoclicker_wnd.AttachChildControl(&_toggle_key_label);
    _autoclicker_wnd.AttachChildControl(&_mouse_buttons_list);
    _autoclicker_wnd.AttachChildControl(&_cps_edit);
    _autoclicker_wnd.AttachChildControl(&_change_key_button);

    /* Set normal font */
    _normal_font.SetFont(&_cps_label);
    _normal_font.SetFont(&_toggle_key_label);
    _normal_font.SetFont(&_mouse_buttons_list);
    _normal_font.SetFont(&_cps_edit);
    _normal_font.SetFont(&_change_key_button);

    /* Setup child controls */
    _mouse_buttons_list.AddItem("Left Button");
    _mouse_buttons_list.AddItem("Right Button");
    _mouse_buttons_list.SelectItem(0);

    _cps_edit.SetWndText("20");

    /* Show main window */
    _autoclicker_wnd.ShowWnd(true);

}

int AutoClicker::RunApp() {
    return _autoclicker_wnd.Run();
}
