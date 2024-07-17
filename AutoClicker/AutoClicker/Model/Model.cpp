#include "Model.h"

Model::Model(UI *ui) : _ui(ui), clicker(Clicker(_ui)) {
    AddFlag("SetNewHotkey");
    AddFlag("SetTargetKey");
}

UI *Model::GetUI() {
    return _ui;
}

const DWORD &Model::GetHotkey() {
    return _hotkey;
}

void Model::SetNewHotkey(const DWORD &key) {
    char buffer[21] = {};

    if (isprint((int)key)) {
        snprintf(buffer, sizeof(buffer), "Hotkey: %c (%d)", (char)key, (int)key);
    }
    else {
        snprintf(buffer, sizeof(buffer), "Hotkey: %d", (int)key);
    }

    _ui->_hotkey_label.SetWndText(buffer);
    _ui->_change_hotkey_button.SetWndText("Change hotkey");

    _hotkey = key;
}

