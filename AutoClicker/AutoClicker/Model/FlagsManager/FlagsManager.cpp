#include "FlagsManager.h"

void FlagsManager::AddFlag(const char *name, const bool &state) {
    _flags_names.push_back((char *)name);
    _flags.push_back(state);
}

bool FlagsManager::GetFlag(const char *name) {
    for (int i = 0; i < _flags_names.size(); ++i) {
        if (memcmp(name, _flags_names[i], strlen(name)) == 0) {
            return _flags[i];
        }
    }

    throw std::string("FlagsManager doesn't has this flag");
}

void FlagsManager::SetFlag(const char *name, const bool &state) {
    for (int i = 0; i < _flags_names.size(); ++i) {
        if (memcmp(name, _flags_names[i], strlen(name)) == 0) {
            _flags[i] = state;
            return;
        }
    }

    throw std::string("FlagsManager doesn't has this flag");
}

void FlagsManager::SwitchFlag(const char *name) {
    for (int i = 0; i < _flags_names.size(); ++i) {
        if (memcmp(name, _flags_names[i], strlen(name)) == 0) {
            _flags[i] = !_flags[i];
            return;
        }
    }

    throw std::string("FlagsManager doesn't has this flag");
}
