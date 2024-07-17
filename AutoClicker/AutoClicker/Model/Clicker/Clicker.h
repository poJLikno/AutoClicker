#ifndef CLICKER_H
#define CLICKER_H

#include <chrono>
#include <thread>

#include "PerfCounter.h"
#include "../FlagsManager/FlagsManager.h"
#include "../../UI/UI.h"

class Clicker : public FlagsManager {
protected:
    bool _clicker_exist = true;
    DWORD _cps = 0;
    unsigned long long _duration_ns = 0ull;
    int _button_id = 0;
    DWORD _target_key_code = 65ul;/* A */

    std::thread _clicker_thread = std::thread(ClickerLoop, (void *)this);

    UI *_ui = nullptr;

    static void ClickerLoop(void *ptr);

public:
    Clicker(UI *ui);
    ~Clicker();

    void Start();
    void Stop();
    void Switch();

    void SetTargetKey(const DWORD &key);
};

#endif
