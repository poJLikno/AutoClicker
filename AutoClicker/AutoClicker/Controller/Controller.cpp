#include "Controller.h"

Controller *Controller::_this_controller = nullptr;

void Controller::ButtonsListOnChange(void *ptr) {
    _this_controller->_model->clicker.Stop();

    UI *ui = _this_controller->_model->GetUI();
    ComboBox *buttons_list = (ComboBox *)ptr;
    if (buttons_list->GetItemId() == 2) {
        ui->_kb_target_key_label.ShowWnd(true);
        ui->_change_kb_target_key_button.ShowWnd(true);
    }
    else {
        ui->_kb_target_key_label.ShowWnd(false);
        ui->_change_kb_target_key_button.ShowWnd(false);
    }

}

void Controller::ChangeHotkeyButtonOnClick(void *ptr) {
    _this_controller->_model->clicker.Stop();
    ((Button *)ptr)->SetWndText("Press new key...");
    _this_controller->_model->SetFlag("SetNewHotkey", true);
}

void Controller::ChangeKbTargetKeyButtonOnClick(void *ptr) {
    _this_controller->_model->clicker.Stop();
    ((Button *)ptr)->SetWndText("Press...");
    _this_controller->_model->SetFlag("SetTargetKey", true);
}

LRESULT __stdcall Controller::LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    HHOOK hkb = 0;
    if (nCode < 0) {
        return CallNextHookEx(hkb, nCode, wParam, lParam);
    }

    if (HC_ACTION == nCode) {
        if (wParam == WM_KEYDOWN) {
            KBDLLHOOKSTRUCT *pressed_key = (KBDLLHOOKSTRUCT *)lParam;
            if (_this_controller->_model->GetFlag("SetNewHotkey")) {
                _this_controller->_model->SetFlag("SetNewHotkey", false);

                _this_controller->_model->SetNewHotkey(pressed_key->vkCode);
            }
            else if (_this_controller->_model->GetFlag("SetTargetKey")) {
                _this_controller->_model->SetFlag("SetTargetKey", false);

                _this_controller->_model->clicker.SetTargetKey(pressed_key->vkCode);
            }
            else if (_this_controller->_model->GetHotkey() == pressed_key->vkCode) {
                _this_controller->_model->clicker.Switch();
            }
        }
        /*else if (wParam == WM_KEYUP)
        {
            KBDLLHOOKSTRUCT *p = (KBDLLHOOKSTRUCT *)lParam;
            char res[20] = {};
            snprintf(res, sizeof(res), "up%d", (int)p->vkCode);

        }*/
    }
    return CallNextHookEx(hkb, nCode, wParam, lParam);
}

Controller::Controller(Model *model) : _model(model) {
    if (_model == nullptr) {
        throw std::string("Controller doesn't has connected model");
    }

    _this_controller = this;

    UI *ui = _model->GetUI();

    ui->_buttons_list.AddCallback("MainCallback", ButtonsListOnChange);
    ui->_change_hotkey_button.AddCallback("MainCallback", ChangeHotkeyButtonOnClick);
    ui->_change_kb_target_key_button.AddCallback("MainCallback", ChangeKbTargetKeyButtonOnClick);

    SetKbCallback(LowLevelKeyboardProc);
}

Controller::~Controller() {
    _this_controller = nullptr;
    _model = nullptr;
}
