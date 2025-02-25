#include "Clicker.h"

#include <stdlib.h>

void Clicker::ClickerLoop(void *ptr) {
    Clicker *clicker = (Clicker *)ptr;

    POINT point = { 0 };

    PerfCounter::Ticks bias = 0ll;

    PerfCounter::Ticks millis = clicker->_counter.Now();
    PerfCounter::Ticks millis_bias = clicker->_counter.Now();

    while (clicker->GetFlag("ClickerState")) {
        if (clicker->_counter.Now() - millis >= clicker->_duration - bias) {
            millis = clicker->_counter.Now();

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
            //printf("Clicker loop - %d ; %d ; %d\n", (int)clicker->_cps, clicker->_button_id, (int)(1000000000ull / PerfCounter::TicksTo(clicker->_counter.Now() - millis_bias, PerfCounter::Nanoseconds)));
            
            PerfCounter::Ticks control_duration = clicker->_counter.Now() - millis_bias;
            if (control_duration > clicker->_duration) {
                bias += (PerfCounter::Ticks)(0.97 * (double)control_duration - (double)clicker->_duration);
            }
            else if (control_duration < clicker->_duration) {
                bias -= (PerfCounter::Ticks)(0.97 * (double)clicker->_duration - (double)control_duration);
            }
            millis_bias = clicker->_counter.Now();
        }
        std::this_thread::sleep_for(std::chrono::nanoseconds(1));
    }
}

Clicker::Clicker(UI *ui) : _ui(ui) {
    AddFlag("ClickerState");
    AddFlag("KbClickerMode");
}

Clicker::~Clicker() {
    this->Stop();
}

void Clicker::Start() {
    /* Get cps */
    char cps_str[5] = { 0 };
    _ui->_cps_edit.GetWndText(cps_str, sizeof(cps_str));
    _cps = atoi(cps_str);

    _duration = (PerfCounter::Ticks)(1.0 / (double)_cps * (double)PerfCounter::Frequency);

    /* Get button */
    if ((_button_id = _ui->_buttons_list.GetItemId()) >= 2) {
        SetFlag("KbClickerMode", true);
    }
    else {
        SetFlag("KbClickerMode", false);
    }

    SetFlag("ClickerState", true);
    _clicker_thread = new std::thread(ClickerLoop, (void *)this);
}

void Clicker::Stop() {
    SetFlag("ClickerState", false);

    if (_clicker_thread) {
        _clicker_thread->join();
        delete _clicker_thread;
        _clicker_thread = nullptr;
    }
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
