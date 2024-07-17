#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/Model.h"
#include "KbHook/KbHook.h"

class Controller : public KbHook {
private:
    static Controller *_this_controller;

    Model *_model = nullptr;

    static void ButtonsListOnChange(void *ptr);
    static void ChangeHotkeyButtonOnClick(void *ptr);
    static void ChangeKbTargetKeyButtonOnClick(void *ptr);

    static LRESULT __stdcall LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

public:
    Controller(Model *model);
    ~Controller();

};

#endif
