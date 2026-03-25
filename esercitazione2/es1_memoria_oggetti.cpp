#include <iostream>

int main()
{
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f};
    int ai[3] = {0, 1, 2};

    int x = 1;
    float y = 1.1f;

    std::cout << "Indirizzi array ad:\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "&ad[" << i << "] = " << &ad[i] << "\n";
    }

    std::cout << "\nIndirizzi array af:\n";
    for (int i = 0; i < 8; i++) {
        std::cout << "&af[" << i << "] = " << &af[i] << "\n";
    }

    std::cout << "\nIndirizzi array ai:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "&ai[" << i << "] = " << &ai[i] << "\n";
    }

    std::cout << "\nIndirizzi variabili scalari:\n";
    std::cout << "&x = " << &x << "\n";
    std::cout << "&y = " << &y << "\n";

    (&y)[1] = 0;

    std::cout << "\nValore di x dopo (&y)[1] = 0:\n";
    std::cout << x << "\n";

    return 0;
}