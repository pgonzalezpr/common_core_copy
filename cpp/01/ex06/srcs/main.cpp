#include "Harl.hpp"

int main(int argc, char *argv[]) {
    Harl    harl;

    if (argc != 2) {
        cout << ARGC_ERR << endl;
        return (1);
    }
    harl.complain(argv[1]);
    return (0);
}