#ifndef FLAGS_MANAGER_H
#define FLAGS_MANAGER_H

#include <string.h>
#include <string>
#include <vector>

class FlagsManager {
protected:
    std::vector<char *> _flags_names = std::vector<char *>();
    std::vector<bool> _flags = std::vector<bool>();

    FlagsManager() = default;

public:
    virtual ~FlagsManager() = default;

    void AddFlag(const char *name, const bool &state = false);

    bool GetFlag(const char *name);
    void SetFlag(const char *name, const bool &state);
    void SwitchFlag(const char *name);
};

#endif
