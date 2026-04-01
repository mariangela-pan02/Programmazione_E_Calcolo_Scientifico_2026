#include <iostream>
#include "rational.hpp"

int main()
{
    int n1, d1, n2, d2;

    std::cout << "Primo numero razionale\n";
    std::cout << "Inserisci numeratore: ";
    std::cin >> n1;
    std::cout << "Inserisci denominatore: ";
    std::cin >> d1;

    std::cout << "\nSecondo numero razionale\n";
    std::cout << "Inserisci numeratore: ";
    std::cin >> n2;
    std::cout << "Inserisci denominatore: ";
    std::cin >> d2;

    rational<int> r1(n1, d1);
    rational<int> r2(n2, d2);

    std::cout << "\nI due numeri sono:\n";
    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 = " << r2 << "\n";

    std::cout << "\nOperazioni:\n";
    std::cout << "r1 + r2 = " << (r1 + r2) << "\n";
    std::cout << "r1 - r2 = " << (r1 - r2) << "\n";
    std::cout << "r1 * r2 = " << (r1 * r2) << "\n";
    std::cout << "r1 / r2 = " << (r1 / r2) << "\n";

    return 0;
}