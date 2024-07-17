#ifndef MODEL_H
#define MODEL_H

#include "../UI/UI.h"
#include "FlagsManager/FlagsManager.h"
#include "Clicker/Clicker.h"

class Model : public FlagsManager {
private:
    UI *_ui = nullptr;


    DWORD _hotkey = 76ul;/* L */

public:
    Clicker clicker;

    Model(UI *ui);
    ~Model() = default;

    UI *GetUI();

    /* Controller methods */
    const DWORD &GetHotkey();
    void SetNewHotkey(const DWORD &key);
};

#endif
