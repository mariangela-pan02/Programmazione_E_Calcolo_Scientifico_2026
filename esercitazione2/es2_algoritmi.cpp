#include <algorithm>
#include <cmath>
#include <iostream>

int main()
{
    static const int N = 10; 
    double arr[N] = {2.5, 7.0, -1.2, 4.8, 9.1, 3.3, 0.0, 5.5, -2.4, 6.7};

    double minimo = arr[0];
    double massimo = arr[0];
    double somma = 0.0;

    for (int i = 0; i < N; i++) {
        minimo = std::min(minimo, arr[i]);
        massimo = std::max(massimo, arr[i]);
        somma += arr[i];
    }

    double media = somma / N;

    double somma_quadrati = 0.0;
    for (int i = 0; i < N; i++) {
        double differenza = arr[i] - media;
        somma_quadrati += differenza * differenza;
    }

    double deviazione_standard = std::sqrt(somma_quadrati / N);

    std::cout << "Minimo: " << minimo << "\n";
    std::cout << "Massimo: " << massimo << "\n";
    std::cout << "Media: " << media << "\n";
    std::cout << "Deviazione standard: " << deviazione_standard << "\n";

    return 0;
}