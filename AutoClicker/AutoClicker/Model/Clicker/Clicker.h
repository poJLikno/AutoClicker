#ifndef CLICKER_H
#define CLICKER_H

#include <chrono>
#include <thread>

#include "PerfCounter.h"
#include "../FlagsManager/FlagsManager.h"
#include "../../UI/UI.h"

class Clicker : public FlagsManager {
protected:
    DWORD _cps = 0;
    PerfCounter::Ticks _duration = 0ll;
    int _button_id = 0;
    DWORD _target_key_code = 65ul;/* A */

    PerfCounter::Counter _counter = PerfCounter::Counter();

    std::thread *_clicker_thread = nullptr;;

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
