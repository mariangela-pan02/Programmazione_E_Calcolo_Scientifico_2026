#include <cstdlib>
#include <string>
#include <vector>

#include "randfiller.h"
#include "sorts.h"

void bubble_sort_int(std::vector<int>& v)
{
    bubble_sort(v);
}

void insertion_sort_int(std::vector<int>& v)
{
    insertion_sort(v);
}

void selection_sort_int(std::vector<int>& v)
{
    selection_sort(v);
}

void merge_sort_int(std::vector<int>& v)
{
    merge_sort(v);
}

void quick_sort_int(std::vector<int>& v)
{
    quick_sort(v);
}

void quick_sort_hybrid_int(std::vector<int>& v)
{
    quick_sort_hybrid(v, 64);
}

void bubble_sort_string(std::vector<std::string>& v)
{
    bubble_sort(v);
}

void insertion_sort_string(std::vector<std::string>& v)
{
    insertion_sort(v);
}

void selection_sort_string(std::vector<std::string>& v)
{
    selection_sort(v);
}

void merge_sort_string(std::vector<std::string>& v)
{
    merge_sort(v);
}

void quick_sort_string(std::vector<std::string>& v)
{
    quick_sort(v);
}

void quick_sort_hybrid_string(std::vector<std::string>& v)
{
    quick_sort_hybrid(v, 64);
}

bool test_int_vectors(void (*sort_function)(std::vector<int>&))
{
    randfiller rf;

    for (int k = 0; k < 100; k++) {
        std::vector<int> size_vec(1);
        rf.fill(size_vec, 0, 200);

        std::vector<int> v(static_cast<std::size_t>(size_vec[0]));
        rf.fill(v, -100, 100);

        sort_function(v);

        if (!is_sorted(v)) {
            return false;
        }
    }

    return true;
}

bool test_strings(void (*sort_function)(std::vector<std::string>&))
{
    std::vector<std::string> words = {
        "grumo", "toritto", "bitetto", "binetto", "acquaviva",
        "adelfia", "bitonto", "cassano", "corato", "giovinazzo"
    };

    sort_function(words);
    return is_sorted(words);
}

bool run_tests(void (*sort_int)(std::vector<int>&),
               void (*sort_string)(std::vector<std::string>&))
{
    return test_int_vectors(sort_int) && test_strings(sort_string);
}

int main()
{
    if (!run_tests(bubble_sort_int, bubble_sort_string)) {
        return EXIT_FAILURE;
    }

    if (!run_tests(insertion_sort_int, insertion_sort_string)) {
        return EXIT_FAILURE;
    }

    if (!run_tests(selection_sort_int, selection_sort_string)) {
        return EXIT_FAILURE;
    }

    if (!run_tests(merge_sort_int, merge_sort_string)) {
        return EXIT_FAILURE;
    }

    if (!run_tests(quick_sort_int, quick_sort_string)) {
        return EXIT_FAILURE;
    }

    if (!run_tests(quick_sort_hybrid_int, quick_sort_hybrid_string)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
