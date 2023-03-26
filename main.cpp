//
// Created by Clayton Cafiero on 12/24/20.
//

#include <vector>
#include <iostream>
#include <random>
#include "sort.h"
#include "Plant.h"
#include "Plant.cpp"


template<typename Comparable>
void printVector(const std::vector<Comparable> &v) {
    for (Comparable item: v) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int main() {
    //loading data into vectors
    std::vector<Plant> data;
    loadFromFile("data/CS124_Data.csv", data);

    std::vector<Plant> data_100(data.begin(), data.begin() + 100);
    std::vector<Plant> data_200(data.begin(), data.begin() + 200);
    std::vector<Plant> data_300(data.begin(), data.begin() + 300);
    std::vector<Plant> data_400(data.begin(), data.begin() + 400);
    std::vector<Plant> data_500(data.begin(), data.begin() + 500);
    std::vector<Plant> data_600(data.begin(), data.begin() + 600);
    std::vector<Plant> data_700(data.begin(), data.begin() + 700);
    std::vector<Plant> data_800(data.begin(), data.begin() + 800);
    std::vector<Plant> data_900(data.begin(), data.begin() + 900);
    std::vector<Plant> data_1000(data.begin(), data.begin() + 1000);

    std::random_device rd;
    std::shuffle(data_100.begin(), data_100.end(), rd);
    std::shuffle(data_200.begin(), data_200.end(), rd);
    std::shuffle(data_300.begin(), data_300.end(), rd);
    std::shuffle(data_400.begin(), data_400.end(), rd);
    std::shuffle(data_500.begin(), data_500.end(), rd);
    std::shuffle(data_600.begin(), data_600.end(), rd);
    std::shuffle(data_700.begin(), data_700.end(), rd);
    std::shuffle(data_800.begin(), data_800.end(), rd);
    std::shuffle(data_900.begin(), data_900.end(), rd);
    std::shuffle(data_1000.begin(), data_1000.end(), rd);


    std::ofstream outFile("data/bubble.txt");
    if (outFile.is_open()) {
        std::vector<Plant> data_100_copy = std::vector<Plant>(data_100);
        std::vector<Plant> data_200_copy = std::vector<Plant>(data_200);
        std::vector<Plant> data_300_copy = std::vector<Plant>(data_300);
        std::vector<Plant> data_400_copy = std::vector<Plant>(data_400);
        std::vector<Plant> data_500_copy = std::vector<Plant>(data_500);
        std::vector<Plant> data_600_copy = std::vector<Plant>(data_600);
        std::vector<Plant> data_700_copy = std::vector<Plant>(data_700);
        std::vector<Plant> data_800_copy = std::vector<Plant>(data_800);
        std::vector<Plant> data_900_copy = std::vector<Plant>(data_900);
        std::vector<Plant> data_1000_copy = std::vector<Plant>(data_1000);

        int read = 0;
        int write = 0;
        bubbleSort(data_100_copy, read, write);
        outFile << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        bubbleSort(data_200_copy, read, write);
        outFile << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        bubbleSort(data_300_copy, read, write);
        outFile << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        bubbleSort(data_400_copy, read, write);
        outFile << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        bubbleSort(data_500_copy, read, write);
        outFile << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        bubbleSort(data_600_copy, read, write);
        outFile << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        bubbleSort(data_700_copy, read, write);
        outFile << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        bubbleSort(data_800_copy, read, write);
        outFile << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        bubbleSort(data_900_copy, read, write);
        outFile << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        bubbleSort(data_1000_copy, read, write);
        outFile << read << ',' << write << std::endl;
    }
    outFile.close();

    std::ofstream outFile2("data/selection.txt");
    if (outFile2.is_open()) {
        std::vector<Plant> data_100_copy = std::vector<Plant>(data_100);
        std::vector<Plant> data_200_copy = std::vector<Plant>(data_200);
        std::vector<Plant> data_300_copy = std::vector<Plant>(data_300);
        std::vector<Plant> data_400_copy = std::vector<Plant>(data_400);
        std::vector<Plant> data_500_copy = std::vector<Plant>(data_500);
        std::vector<Plant> data_600_copy = std::vector<Plant>(data_600);
        std::vector<Plant> data_700_copy = std::vector<Plant>(data_700);
        std::vector<Plant> data_800_copy = std::vector<Plant>(data_800);
        std::vector<Plant> data_900_copy = std::vector<Plant>(data_900);
        std::vector<Plant> data_1000_copy = std::vector<Plant>(data_1000);

        int read = 0;
        int write = 0;
        selectionSort(data_100_copy, read, write);
        outFile2 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        selectionSort(data_200_copy, read, write);
        outFile2 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        selectionSort(data_300_copy, read, write);
        outFile2 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        selectionSort(data_400_copy, read, write);
        outFile2 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        selectionSort(data_500_copy, read, write);
        outFile2 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        selectionSort(data_600_copy, read, write);
        outFile2 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        selectionSort(data_700_copy, read, write);
        outFile2 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        selectionSort(data_800_copy, read, write);
        outFile2 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        selectionSort(data_900_copy, read, write);
        outFile2 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        selectionSort(data_1000_copy, read, write);
        outFile2 << read << ',' << write << std::endl;
    }
    outFile2.close();

    std::ofstream outFile3("data/quick.txt");
    if (outFile3.is_open()) {
        std::vector<Plant> data_100_copy = std::vector<Plant>(data_100);
        std::vector<Plant> data_200_copy = std::vector<Plant>(data_200);
        std::vector<Plant> data_300_copy = std::vector<Plant>(data_300);
        std::vector<Plant> data_400_copy = std::vector<Plant>(data_400);
        std::vector<Plant> data_500_copy = std::vector<Plant>(data_500);
        std::vector<Plant> data_600_copy = std::vector<Plant>(data_600);
        std::vector<Plant> data_700_copy = std::vector<Plant>(data_700);
        std::vector<Plant> data_800_copy = std::vector<Plant>(data_800);
        std::vector<Plant> data_900_copy = std::vector<Plant>(data_900);
        std::vector<Plant> data_1000_copy = std::vector<Plant>(data_1000);

        int read = 0;
        int write = 0;
        quicksortStable(data_100_copy, read, write);
        outFile3 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        quicksortStable(data_200_copy, read, write);
        outFile3 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        quicksortStable(data_300_copy, read, write);
        outFile3 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        quicksortStable(data_400_copy, read, write);
        outFile3 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        quicksortStable(data_500_copy, read, write);
        outFile3 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        quicksortStable(data_600_copy, read, write);
        outFile3 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        quicksortStable(data_700_copy, read, write);
        outFile3 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        quicksortStable(data_800_copy, read, write);
        outFile3 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        quicksortStable(data_900_copy, read, write);
        outFile3 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        quicksortStable(data_1000_copy, read, write);
        outFile3 << read << ',' << write << std::endl;
    }
    outFile3.close();

    std::ofstream outFile4("data/heap.txt");
    if (outFile4.is_open()) {
        std::vector<Plant> data_100_copy = std::vector<Plant>(data_100);
        std::vector<Plant> data_200_copy = std::vector<Plant>(data_200);
        std::vector<Plant> data_300_copy = std::vector<Plant>(data_300);
        std::vector<Plant> data_400_copy = std::vector<Plant>(data_400);
        std::vector<Plant> data_500_copy = std::vector<Plant>(data_500);
        std::vector<Plant> data_600_copy = std::vector<Plant>(data_600);
        std::vector<Plant> data_700_copy = std::vector<Plant>(data_700);
        std::vector<Plant> data_800_copy = std::vector<Plant>(data_800);
        std::vector<Plant> data_900_copy = std::vector<Plant>(data_900);
        std::vector<Plant> data_1000_copy = std::vector<Plant>(data_1000);

        int read = 0;
        int write = 0;
        heapSort(data_100_copy, read, write);
        outFile4 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_200_copy, read, write);
        outFile4 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_300_copy, read, write);
        outFile4 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_400_copy, read, write);
        outFile4 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_500_copy, read, write);
        outFile4 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_600_copy, read, write);
        outFile4 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_700_copy, read, write);
        outFile4 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_800_copy, read, write);
        outFile4 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_900_copy, read, write);
        outFile4 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_1000_copy, read, write);
        outFile4 << read << ',' << write << std::endl;
    }
    outFile4.close();

    std::ofstream outFile5("data/twosort.txt");
    if (outFile5.is_open()) {
        std::vector<Plant> data_100_copy = std::vector<Plant>(data_100);
        std::vector<Plant> data_200_copy = std::vector<Plant>(data_200);
        std::vector<Plant> data_300_copy = std::vector<Plant>(data_300);
        std::vector<Plant> data_400_copy = std::vector<Plant>(data_400);
        std::vector<Plant> data_500_copy = std::vector<Plant>(data_500);
        std::vector<Plant> data_600_copy = std::vector<Plant>(data_600);
        std::vector<Plant> data_700_copy = std::vector<Plant>(data_700);
        std::vector<Plant> data_800_copy = std::vector<Plant>(data_800);
        std::vector<Plant> data_900_copy = std::vector<Plant>(data_900);
        std::vector<Plant> data_1000_copy = std::vector<Plant>(data_1000);

        int read = 0;
        int write = 0;
        heapSort(data_100_copy, read, write);
        twoSort(data_100_copy, read, write);
        outFile5 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_200_copy, read, write);
        twoSort(data_200_copy, read, write);
        outFile5 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_300_copy, read, write);
        twoSort(data_300_copy, read, write);
        outFile5 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_400_copy, read, write);
        twoSort(data_400_copy, read, write);
        outFile5 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_500_copy, read, write);
        twoSort(data_500_copy, read, write);
        outFile5 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_600_copy, read, write);
        twoSort(data_600_copy, read, write);
        outFile5 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_700_copy, read, write);
        twoSort(data_700_copy, read, write);
        outFile5 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_800_copy, read, write);
        twoSort(data_800_copy, read, write);
        outFile5 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_900_copy, read, write);
        twoSort(data_900_copy, read, write);
        outFile5 << read << ',' << write << std::endl;

        read = 0;
        write = 0;
        heapSort(data_1000_copy, read, write);
        twoSort(data_1000_copy, read, write);
        outFile5 << read << ',' << write << std::endl;
    }
    outFile5.close();


    return 0;
}