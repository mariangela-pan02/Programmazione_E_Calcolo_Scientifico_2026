#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "randfiller.h"
#include "timecounter.h"
#include "sorts.h"

void bubble_sort_wrapper(std::vector<int>& v)
{
    bubble_sort(v);
}

void insertion_sort_wrapper(std::vector<int>& v)
{
    insertion_sort(v);
}

void selection_sort_wrapper(std::vector<int>& v)
{
    selection_sort(v);
}

void merge_sort_wrapper(std::vector<int>& v)
{
    merge_sort(v);
}

void quick_sort_wrapper(std::vector<int>& v)
{
    quick_sort(v);
}

void std_sort_wrapper(std::vector<int>& v)
{
    std::sort(v.begin(), v.end());
}

void quick_sort_hybrid_64(std::vector<int>& v)
{
    quick_sort_hybrid(v, 64);
}

template<typename SortFunction>
double average_time(int n, int repetitions, randfiller& rf, SortFunction sort_function)
{
    std::vector<std::vector<int>> data(static_cast<std::size_t>(repetitions),
                                       std::vector<int>(static_cast<std::size_t>(n)));

    for (auto& v : data) {
        rf.fill(v, -10000, 10000);
    }

    timecounter tc;
    tc.tic();

    for (auto& v : data) {
        sort_function(v);
    }

    const double total_time = tc.toc();
    return total_time / repetitions;
}

int main()
{
    randfiller rf;
    const int repetitions = 100;

    std::cout << "N bubble_sort insertion_sort selection_sort merge_sort quick_sort "
              << "quick_sort_hybrid std_sort\n";

    for (int n = 4; n <= 1024; n *= 2) {
        const double t_bubble = average_time(n, repetitions, rf, bubble_sort_wrapper);
        const double t_insertion = average_time(n, repetitions, rf, insertion_sort_wrapper);
        const double t_selection = average_time(n, repetitions, rf, selection_sort_wrapper);
        const double t_merge = average_time(n, repetitions, rf, merge_sort_wrapper);
        const double t_quick = average_time(n, repetitions, rf, quick_sort_wrapper);
        const double t_quick_hybrid = average_time(n, repetitions, rf, quick_sort_hybrid_64);
        const double t_std = average_time(n, repetitions, rf, std_sort_wrapper);

        std::cout << n << " "
                  << t_bubble << " "
                  << t_insertion << " "
                  << t_selection << " "
                  << t_merge << " "
                  << t_quick << " "
                  << t_quick_hybrid << " "
                  << t_std << "\n";
    }

    return EXIT_SUCCESS;
}
