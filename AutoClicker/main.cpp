#include "AutoClicker/AutoClicker.h"

int main(int argc, const char **argv) {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    try {
        AutoClicker autoclicker_app;

        return autoclicker_app.RunApp();
    }
    catch (std::string &e) {
        std::cout << e << "\n";
    }

    return 0;
}
