#include <cstdlib>
#include <vector>
#include <string>

#include "randfiller.h"
#include "sorts.h"

int main()
{
    randfiller rf;

    // Test su 100 vettori di int con dimensione casuale
    for (int k = 0; k < 100; k++) {
        std::vector<int> size_vec(1);
        rf.fill(size_vec, 0, 200);

        std::vector<int> v(size_vec[0]);
        rf.fill(v, -100, 100);

        bubble_sort(v);

        if (!is_sorted(v)) {
            return EXIT_FAILURE;
        }
    }

    // Test su un vettore di stringhe
    std::vector<std::string> words = {
        "grumo", "toritto", "bitetto", "binetto", "acquaviva",
        "adelfia", "bitonto", "cassano", "corato", "giovinazzo"
    };

    bubble_sort(words);

    if (!is_sorted(words)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}