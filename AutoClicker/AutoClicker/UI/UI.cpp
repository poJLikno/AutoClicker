#include "UI.h"

UI::UI(const char *version) {
    /* Setup window */
    _autoclicker_wnd.SetWndText(version);
    _autoclicker_wnd.EnableControlsDialogMessages(true);

    /* Attach child controls to main window */
    _autoclicker_wnd.AttachChildControl(&_cps_label);
    _autoclicker_wnd.AttachChildControl(&_hotkey_label);
    _autoclicker_wnd.AttachChildControl(&_kb_target_key_label);
    _autoclicker_wnd.AttachChildControl(&_buttons_list);
    _autoclicker_wnd.AttachChildControl(&_cps_edit);
    _autoclicker_wnd.AttachChildControl(&_change_kb_target_key_button);
    _autoclicker_wnd.AttachChildControl(&_change_hotkey_button);

    /* Set normal font */
    _normal_font.SetFont(&_cps_label);
    _normal_font.SetFont(&_hotkey_label);
    _normal_font.SetFont(&_kb_target_key_label);
    _normal_font.SetFont(&_buttons_list);
    _normal_font.SetFont(&_cps_edit);
    _normal_font.SetFont(&_change_kb_target_key_button);
    _normal_font.SetFont(&_change_hotkey_button);

    /* Setup child controls */
    _buttons_list.AddItem("Left Button");
    _buttons_list.AddItem("Right Button");
    _buttons_list.AddItem("Keyboard key");
    _buttons_list.SelectItem(0);

    _cps_edit.SetWndStyle(WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | WS_BORDER | WS_CHILD | WS_TABSTOP | ES_NUMBER);
    _cps_edit.SetWndText("20");

    _kb_target_key_label.ShowWnd(false);
    _change_kb_target_key_button.ShowWnd(false);

    /* Show main window */
    _autoclicker_wnd.ShowWnd(true);
}
