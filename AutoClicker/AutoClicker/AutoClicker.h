#ifndef AUTOCLICKER_H
#define AUTOCLICKER_H

#include "Controller/Controller.h"

class AutoClicker {
private:
    /* App version */
    const char *_version = "AutoClicker v2.6";

    /* UI */
    UI _ui = UI(_version);

    /* Model */
    Model _model = Model(&_ui);

    /* Controller */
    Controller _controller = Controller(&_model);

public:
    AutoClicker() = default;
    ~AutoClicker() = default;

    int RunApp();
};

#endif
