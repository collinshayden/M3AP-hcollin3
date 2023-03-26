/**
 * Clayton Cafiero
 * CS 124
 * 24-Dec-2020
 */

#ifndef SORT_H
#define SORT_H

#include <vector>
#include <cmath>
#include "Plant.h"


/* ************************** Bubble Sort ********************************** */

/**
 * Bubble sort
 */
template<typename Comparable>
void bubbleSort(std::vector<Comparable>& v, int &read, int &write) {
    int numPasses = 0;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (int i = 0; i < (v.size() - numPasses - 1); ++i) {
            read += 2;//two reads in the if statement below
            if (v[i] > v[i + 1]) {
                // The two elements are out of order. Swap them.
                Comparable temp = v[i];//one read, one write
                v[i] = v[i + 1];//two reads, one write
                v[i + 1] = temp;//one read, one write
                read += 4; write += 3;
                haveSwapped = true;
            }
        }
    }
}

/* ************************** Selection Sort ******************************* */

/**
 * Selection sort
 */
template<typename Comparable>
void selectionSort(std::vector<Comparable>& v, int &read, int &write) {
    for (int swapIndex = 0; swapIndex < v.size(); ++swapIndex) {
        int minIndex = swapIndex;
        for (int i = swapIndex + 1; i < v.size(); ++i) {
            read += 2;
            if (v[i] < v[minIndex]) {
                minIndex = i;
            }
        }
        Comparable temp = v[minIndex];
        v[minIndex] = v[swapIndex];
        v[swapIndex] = temp;
        read += 4; write += 3;
    }
}

/* ************************** Insertion Sort ******************************* */

/**
 * Insertion sort. Treat the 0 index item as being sorted
 * from the start. Outer loop begins at index 1.
 */
template<typename Comparable>
void insertionSort(std::vector<Comparable>& v, int &read, int &write) {
    for (int i = 1; i < v.size(); ++i) {
        Comparable value = v[i];  // the value we're going to insert
        read += 1; write += 1;
        int j = i - 1;
        while (j >= 0 && v[j] > value) {
            v[j + 1] = v[j];  // shift the larger item right
            --j;  // move left
            read += 3; write += 1;
        }
        v[j + 1] = value;  // insert
        read += 1; write += 1;
    }
}

/* ************************** Merge Sort *********************************** */

/**
 * Merge two sections within a vector; called by mergeSort()
 */
template<typename Comparable>
void merge(std::vector<Comparable>& v,
           int start, int middle, int end,
           std::vector<Comparable>& temp, int &read, int &write) {

    int i = start;       // index into the left half
    int j = middle + 1;  // index into the right half
    int k = 0;           // index into temp

    while (i <= middle && j <= end) {
        read += 2;
        if (v[i] <= v[j]) {
            temp[k] = v[i];  // Take the element from the left half
            read += 1; write += 1;
            ++k;
            ++i;
        } else {
            temp[k] = v[j];  // Take the element from the right half
            read += 1; write += 1;
            ++k;
            ++j;
        }
    }

    while (i <= middle) {  // There are still elements in the left half
        temp[k] = v[i];
        read += 1; write += 1;
        ++k;
        ++i;
    }

    while (j <= end) {  // There are still elements in the right half
        temp[k] = v[j];
        read += 1; write += 1;
        ++k;
        ++j;
    }

    // Copy everything back to input vector
    for (int i = 0; i <= (end - start); ++i) {
        v[start + i] = temp[i];
        read += 1; write += 1;
    }
}

/**
 * Merge sort, recursive
 */
template<typename Comparable>
void mergeSort(std::vector<Comparable>& v,
               int start, int end,
               std::vector<Comparable>& temp,
               int &read, int &write) {
    if (end <= start) {
        // Base case for recursion.
        // 0 or 1 element vector is sorted by definition.
        return;
    } else {
        // Recursive cases: 2 or more elements.
        int middle = (start + end) / 2;
        mergeSort(v, start, middle, temp, read, write);
        mergeSort(v, middle + 1, end, temp, read, write);
        merge(v, start, middle, end, temp, read, write);
    }
}

/**
 * Merge sort. This creates the temporary vector needed in
 * recursive calls and then makes the first recursive call.
 */
template<typename Comparable>
void mergeSort(std::vector<Comparable>& v, int &read, int &write) {
    std::vector<int> temp(v.size());
    mergeSort(v, 0, v.size() - 1, temp, read, write);
}


/* ************************** Heap Sort ************************************ */

/**
 * Helper function for percolateDown
 */
inline int leftChild(int i) {
    return 2 * i + 1;
}

/**
 * Percolate down; used by heapSort() and heapify()
 */
template<typename Comparable>
void percolateDown(std::vector<Comparable>& v, int start, int end, int &read, int &write) {
    int root = start;
    while (leftChild(root) <= end) {
        int child = leftChild(root);
        read += 2;
        if (child + 1 <= end && v[child] < v[child + 1]){
            ++child;
        }
        read += 2;
        if (v[root] < v[child]) {
            Comparable temp = v[root];
            v[root] = v[child];
            v[child] = temp;
            root = child;
            read += 4; write += 3;
        } else {
            return;
        }
    }
}

/**
 * heapify; used by heapSort()
 */
template<typename Comparable>
void heapify(std::vector<Comparable>& v, int size, int &read, int &write) {
    int start = (size - 2) / 2;
    while (start >= 0) {
        percolateDown(v, start, size - 1, read, write);
        --start;
    }
}

/**
 * Heap sort
 */
template<typename Comparable>
void heapSort(std::vector<Comparable>& v, int &read, int &write) {
    int size = v.size();
    int end = size - 1;
    heapify(v, size, read, write);
    while (end > 0) {
        Comparable temp = v[end];
        v[end] = v[0];
        v[0] = temp;
        read += 4; write += 3;
        --end;
        percolateDown(v, 0, end, read, write);
    }
}

/* ************************** Quicksort (not stable) *********************** */

/**
 * Quicksort partition
 */
template<typename Comparable>
int partition(std::vector<Comparable>& v, int start, int end, int &read, int &write) {
    Comparable pivot = v[end];
    int i = start;
    for (int j = start; j <= end; ++j) {
        read += 1;
        if (v[j] < pivot) {
            // swap v[i] and v[j]
            Comparable temp = v[j];
            v[j] = v[i];
            v[i] = temp;
            read += 4; write += 3;
            ++i;
        }
    }
    // swap v[i] and v[end]
    Comparable temp = v[i];
    v[i] = v[end];
    v[end] = temp;
    read += 4; write += 3;
    return i;
}


/**
 * Quicksort
 */
template<typename Comparable>
void quicksort(std::vector<Comparable>& v,
               int start, int end, int &read, int &write) {
    if (end <= start) {
        return;  // base case for recursion; single element
    } else {
        // recursive case
        int p = partition(v, start, end, read, write);
        quicksort(v, start, p - 1, read, write);
        quicksort(v, p + 1, end, read, write);
    }
}

/**
 * Quicksort. This is to set up the first recursive call.
 */
template<typename Comparable>
void quicksort(std::vector<Comparable>& v, int &read, int &write) {
    quicksort(v, 0, v.size() - 1, read, write);
}

/* ************************** Quicksort (stable) *************************** */

/**
 * Quicksort stable, recursive. This implementation of Quicksort
 * is stable, but requires more space. Note we have the vectors
 * smaller, equal, and larger.
 */
template<typename Comparable>
void quicksortStable(std::vector<Comparable>& v, int &read, int &write) {
    // Recursive base case
    if (v.size() < 2) {
        return;
    }
    Comparable pivot = v[0];
    std::vector<Comparable> smaller, equal, larger;
    int i;  // OK to declare here. See where we copy values back to orig. vector
    for (i = 0; i < v.size(); ++i) {
        if (v[i] < pivot) {
            smaller.push_back(v[i]);
            read += 2; write += 1;
        } else if (v[i] > pivot) {
            larger.push_back(v[i]);
            read += 2; write += 1;
        } else {
            equal.push_back(v[i]);
            read += 1; write += 1;
        }
    }

    quicksortStable(smaller, read, write);
    quicksortStable(larger, read, write);

    // Copy everything back into vector
    for (i = 0; i < smaller.size(); ++i) {
        v[i] = smaller[i];
        read += 2; write += 1;
    }
    // Omit initialization of i and continue...
    for (; i < smaller.size() + equal.size(); ++i) {
        v[i] = equal[i - smaller.size()];
        read += 2; write += 1;
    }
    // Omit initialization of i and continue...
    for (; i < v.size(); ++i) {
        v[i] = larger[i - smaller.size() - equal.size()];
        read += 2; write += 1;
    }
}

/* ************************** Radix Sort *********************************** */

/**
 * Radix sort
 * Note: Not a templated function
 * This assumes a vector of non-negative integers
 */
void radixSort(std::vector<int>& v, int numDigits, int &read, int &write) {
    std::vector<std::vector<int> > buckets(10);
    for (int iteration = 0; iteration < numDigits; ++iteration) {
        // Copy items from vector into the appropriate buckets
        for (int i = 0; i < v.size(); ++i) {
            int digit = (v[i] / int(std::pow(10, iteration)) % 10);
            buckets[digit].push_back(v[i]);
            read += 3; write += 2;
        }
        // Copy everything from buckets back into vector in the appropriate order
        int i = 0;
        for (int bucket = 0; bucket < buckets.size(); ++bucket) {
            for (int item = 0; item < buckets[bucket].size(); ++item) {
                v[i] = buckets[bucket][item];
                read += 2; write += 1;
                ++i;
            }
            buckets[bucket].clear();
        }
//        printVector(v);
    }
}

/**
 * Assumes a vector of integers >= 0
 */
void radixSort(std::vector<int>& v, int &read, int &write) {
    int maxNum = 0;
    for (int num : v) {
        if (num > maxNum) {
            maxNum = num;
        }
    }
    int numDigits = int (std::log10(maxNum) + 1);
    radixSort(v, numDigits, read, write);
}


/* ************************** Two Sort ********************************** */

/**
 * Two sort
 */
void twoSort(std::vector<Plant>& v, int &read, int &write) {
    int numPasses = 0;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (int i = 0; i < (v.size() - numPasses - 1); ++i) {
            read += 2;//two reads in the if statement below
            if (v[i].getNetGenerationMwh() > v[i + 1].getNetGenerationMwh()) {
                // The two elements are out of order. Swap them.
                Plant temp = v[i];//one read, one write
                v[i] = v[i + 1];//two reads, one write
                v[i + 1] = temp;//one read, one write
                read += 4; write += 3;
                haveSwapped = true;
            }
        }
    }
}

#endif // SORT_H
