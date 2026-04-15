#include <iostream>
#include <vector>
#include <algorithm>

#include "randfiller.h"
#include "timecounter.h"
#include "sorts.h"

int main()
{
    randfiller rf;
    timecounter tc;

    std::cout << "N bubble_sort insertion_sort selection_sort std::sort\n";

    for (int n = 4; n <= 8192; n *= 2) {
        std::vector<int> original(n);
        rf.fill(original, -10000, 10000);

        std::vector<int> v_bubble = original;
        std::vector<int> v_insertion = original;
        std::vector<int> v_selection = original;
        std::vector<int> v_std = original;

        tc.tic();
        bubble_sort(v_bubble);
        double t_bubble = tc.toc();

        tc.tic();
        insertion_sort(v_insertion);
        double t_insertion = tc.toc();

        tc.tic();
        selection_sort(v_selection);
        double t_selection = tc.toc();

        tc.tic();
        std::sort(v_std.begin(), v_std.end());
        double t_std = tc.toc();

        std::cout << n << " "
                  << t_bubble << " "
                  << t_insertion << " "
                  << t_selection << " "
                  << t_std << "\n";
    }

    return 0;
}