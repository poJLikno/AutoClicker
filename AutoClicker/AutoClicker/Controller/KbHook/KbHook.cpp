#include "KbHook.h"

KbHook::~KbHook() {
    UnhookWindowsHookEx(_kb_handle);
}

void KbHook::SetKbCallback(HOOKPROC callback) {
    if ((_kb_handle = SetWindowsHookEx(WH_KEYBOARD_LL, callback, NULL, NULL)) == NULL) {
        throw std::string("Couldn't create hook");
    }
}
