#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char *argv[])
{

    if (argc < 2) {
        std::cerr << "Errore: nome file mancante.\n";
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file) {
        std::cerr << "Errore: impossibile aprire il file '" << argv[1] << "'.\n";
        return 1;
    }

    std::string citta;
    double t0, t6, t12, t18;

    while (file >> citta >> t0 >> t6 >> t12 >> t18) {
        double media = (t0 + t6 + t12 + t18) / 4.0;
        std::cout << citta << " " << media << "\n";
    }

    return 0;
}