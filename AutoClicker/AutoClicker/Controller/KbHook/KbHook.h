#ifndef KB_HOOK_H
#define KB_HOOK_H

#include <string>
#include <windows.h>

class KbHook {
protected:
    HHOOK _kb_handle = { 0 };

    KbHook() = default;

public:
    virtual ~KbHook();
    
    void SetKbCallback(HOOKPROC callback);
};

#endif
