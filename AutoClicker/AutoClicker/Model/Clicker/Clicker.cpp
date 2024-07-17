#include "Clicker.h"

#include <stdlib.h>

void Clicker::ClickerLoop(void *ptr) {
    Clicker *clicker = (Clicker *)ptr;

    PerfCounter::Counter counter;
    PerfCounter::Ticks millis = counter.Now();

    //PerfCounter::Ticks millis_log = counter.Now();

    POINT point = { 0 };

    while (clicker->_clicker_exist) {
        if (clicker->GetFlag("ClickerState")) {
            if (PerfCounter::TicksTo(counter.Now() - millis, PerfCounter::Nanoseconds) >= (long long)clicker->_duration_ns) {
                millis = counter.Now();

                if (clicker->GetFlag("KbClickerMode")) {
                    keybd_event((unsigned char)clicker->_target_key_code, (unsigned char)MapVirtualKeyW((unsigned int)clicker->_target_key_code, 0), 0, 0);
                    keybd_event((unsigned char)clicker->_target_key_code, (unsigned char)MapVirtualKeyW((unsigned int)clicker->_target_key_code, 0), KEYEVENTF_KEYUP, 0);
                }
                else if (clicker->_button_id == 0) {
                    GetCursorPos(&point);
                    mouse_event(MOUSEEVENTF_LEFTDOWN, point.x, point.y, 0, 0);
                    mouse_event(MOUSEEVENTF_LEFTUP, point.x, point.y, 0, 0);
                }
                else if (clicker->_button_id == 1) {
                    GetCursorPos(&point);
                    mouse_event(MOUSEEVENTF_RIGHTDOWN, point.x, point.y, 0, 0);
                    mouse_event(MOUSEEVENTF_RIGHTUP, point.x, point.y, 0, 0);
                }

                /* Logs */
                //printf("Clicker loop - %d ; %d ; %d\n", (int)clicker->_cps, clicker->_button_id, (int)(1000000000ull / PerfCounter::TicksTo(counter.Now() - millis_log, PerfCounter::Nanoseconds)));
                //millis_log = counter.Now();
            }
        }
        else {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
}

Clicker::Clicker(UI *ui) : _ui(ui) {
    AddFlag("ClickerState");
    AddFlag("KbClickerMode");

    _clicker_thread.detach();
}

Clicker::~Clicker() {
    _clicker_exist = false;
}

void Clicker::Start() {
    /* Get cps */
    char cps_str[5] = { 0 };
    _ui->_cps_edit.GetWndText(cps_str, sizeof(cps_str));
    _cps = atoi(cps_str);

    _duration_ns = _cps ? 1000000000ull / _cps : 1000000000ull;

    /* Get button */
    if ((_button_id = _ui->_buttons_list.GetItemId()) >= 2) {
        SetFlag("KbClickerMode", true);
    }
    else {
        SetFlag("KbClickerMode", false);
    }

    SetFlag("ClickerState", true);
}

void Clicker::Stop() {
    SetFlag("ClickerState", false);
}

void Clicker::Switch() {
    if (GetFlag("ClickerState")) {
        Stop();
    }
    else {
        Start();
    }
}

void Clicker::SetTargetKey(const DWORD &key) {
    char buffer[21] = {};

    if (isprint((int)key)) {
        snprintf(buffer, sizeof(buffer), "Key: %c (%d)", (char)key, (int)key);
    }
    else {
        snprintf(buffer, sizeof(buffer), "Key: %d", (int)key);
    }

    _ui->_kb_target_key_label.SetWndText(buffer);
    _ui->_change_kb_target_key_button.SetWndText("Set key");

    _target_key_code = key;
}
