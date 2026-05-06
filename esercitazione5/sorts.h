#pragma once

#include <vector>
#include <utility>
#include <cstddef>

template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
    for (std::size_t i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

template<typename T>
void bubble_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return;
    }

    for (std::size_t i = 0; i < vec.size() - 1; i++) {
        for (std::size_t j = vec.size() - 1; j > i; j--) {
            if (vec[j] < vec[j - 1]) {
                std::swap(vec[j], vec[j - 1]);
            }
        }
    }
}

template<typename T>
void insertion_sort(std::vector<T>& vec)
{
    for (std::size_t j = 1; j < vec.size(); j++) {
        T key = vec[j];
        int i = static_cast<int>(j) - 1;

        while (i >= 0 && vec[static_cast<std::size_t>(i)] > key) {
            vec[static_cast<std::size_t>(i + 1)] = vec[static_cast<std::size_t>(i)];
            i--;
        }

        vec[static_cast<std::size_t>(i + 1)] = key;
    }
}

template<typename T>
void selection_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return;
    }

    for (std::size_t i = 0; i < vec.size() - 1; i++) {
        std::size_t min_index = i;

        for (std::size_t j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }

        std::swap(vec[i], vec[min_index]);
    }
}


template<typename T>
void merge(std::vector<T>& vec, std::size_t left, std::size_t mid, std::size_t right)
{
    std::vector<T> left_vec(vec.begin() + static_cast<long>(left),
                            vec.begin() + static_cast<long>(mid + 1));
    std::vector<T> right_vec(vec.begin() + static_cast<long>(mid + 1),
                             vec.begin() + static_cast<long>(right + 1));

    std::size_t i = 0;
    std::size_t j = 0;
    std::size_t k = left;

    while (i < left_vec.size() && j < right_vec.size()) {
        if (!(right_vec[j] < left_vec[i])) {
            vec[k] = left_vec[i];
            i++;
        } else {
            vec[k] = right_vec[j];
            j++;
        }
        k++;
    }

    while (i < left_vec.size()) {
        vec[k] = left_vec[i];
        i++;
        k++;
    }

    while (j < right_vec.size()) {
        vec[k] = right_vec[j];
        j++;
        k++;
    }
}

template<typename T>
void merge_sort(std::vector<T>& vec, std::size_t left, std::size_t right)
{
    if (left < right) {
        const std::size_t mid = left + (right - left) / 2;
        merge_sort(vec, left, mid);
        merge_sort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

template<typename T>
void merge_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return;
    }
    merge_sort(vec, 0, vec.size() - 1);
}

template<typename T>
std::size_t partition(std::vector<T>& vec, std::size_t left, std::size_t right)
{
    const T pivot = vec[right];
    std::size_t i = left;

    for (std::size_t j = left; j < right; j++) {
        if (!(pivot < vec[j])) {
            std::swap(vec[i], vec[j]);
            i++;
        }
    }

    std::swap(vec[i], vec[right]);
    return i;
}

template<typename T>
void quick_sort(std::vector<T>& vec, std::size_t left, std::size_t right)
{
    if (left < right) {
        const std::size_t q = partition(vec, left, right);

        if (q > 0) {
            quick_sort(vec, left, q - 1);
        }
        quick_sort(vec, q + 1, right);
    }
}

template<typename T>
void quick_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return;
    }
    quick_sort(vec, 0, vec.size() - 1);
}


template<typename T>
void quick_sort_hybrid(std::vector<T>& vec, std::size_t left, std::size_t right,
                       std::size_t threshold)
{
    if (left >= right) {
        return;
    }

    if (right - left + 1 <= threshold) {
        std::vector<T> tmp(vec.begin() + static_cast<long>(left),
                           vec.begin() + static_cast<long>(right + 1));
        insertion_sort(tmp);

        for (std::size_t i = 0; i < tmp.size(); i++) {
            vec[left + i] = tmp[i];
        }
        return;
    }

    const std::size_t q = partition(vec, left, right);

    if (q > 0) {
        quick_sort_hybrid(vec, left, q - 1, threshold);
    }
    quick_sort_hybrid(vec, q + 1, right, threshold);
}

template<typename T>
void quick_sort_hybrid(std::vector<T>& vec, std::size_t threshold = 64)
{
    if (vec.size() < 2) {
        return;
    }
    quick_sort_hybrid(vec, 0, vec.size() - 1, threshold);
}
