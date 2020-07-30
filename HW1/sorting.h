/*
 * Title: Algorithm Efficiency and Sorting
 * Author: İlknur Baş
 * ID: 21601847
 * Section: 2
 * Assignment: 1
 * Description: header file of sorting functions
 */

#ifndef sorting_h
#define sorting_h
#include <iostream>


using namespace std;

class sorting{
public:
    void insertionSort(int *arr, int size, int &compCount, int &moveCount);
    void quickSort(int *arr, int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, int size, int &compCount, int &moveCount);

    
    //helper
    void quickSort(int *arr, int first, int last,int &compCount, int &moveCount);
    void partition (int *arr, int first, int last,int &pivotIndex, int &compCount, int &moveCount);
    void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
    
    //these are given
    void displayArray(int *arr, int len);
    void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int N);
    void createAlreadySortedArrays(int *&arr1, int *&arr2, int *&arr3, int N);
    void createNearlySortedArrays(int *&arr1, int *&arr2, int *&arr3, int N, int K);
    double averageDistance(int *arr, int N, int K);
    void attemptOneSwap(int *arr, int N, int K, int currIndex);
    
    void performanceAnalysis();
    void performanceAnalysis2();
    void performanceAnalysis3();
    void performanceAnalysis4();
    void performanceAnalysis5();
    
};


#endif /* sorting_h */
