/*
 * Title: Algorithm Efficiency and Sorting
 * Author: İlknur Baş
 * ID: 21601847
 * Section: 2
 * Assignment: 1
 * Description: implementations of sorting functions
 */
#include <iostream>
#include <string.h>
#include "sorting.h"
#include <stdlib.h>  //rand
#include <string>
#include <iostream>   
#include <iomanip>   //setw
#include <time.h>    //clock_t
#include <stdio.h>
#include <unistd.h>
using namespace std;
#include <chrono>

///////////////////////////////////////////////////QUICK SORT////////////////////////////////////////////
void sorting:: quickSort(int *arr, int size, int &compCount, int &moveCount){
    compCount = 0;
    moveCount = 0;
    quickSort(arr, 0, size - 1, compCount, moveCount);

}

void sorting::quickSort(int *arr, int first, int last,int &compCount, int &moveCount) {
    // Precondition: theArray[first..last] is an array.
    // Postcondition: theArray[first..last] is sorted.
    int pivotIndex;
    if (first < last) {
        // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex,compCount,moveCount);
        // sort regions S1 and S2
        quickSort(arr, first, pivotIndex-1,compCount,moveCount);
        quickSort(arr, pivotIndex+1, last,compCount,moveCount);
    }
}

void sorting:: partition (int *arr, int first, int last,int &pivotIndex, int &compCount, int &moveCount) {
    // Precondition: theArray[first..last] is an array; first <= last.
    // Postcondition: Partitions theArray[first..last] such that:
    //   S1 = theArray[first..pivotIndex-1] < pivot
    //   theArray[pivotIndex] == pivot
    //   S2 = theArray[pivotIndex+1..last] >= pivot
    
    //for sorting purposes
    int temp;
    //pivot is the first element of the array
    int pivot = arr[first];
    moveCount++; //!!
    
    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown
    
    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot
        
        // move item from unknown to proper region
         if (arr[firstUnknown] < pivot) {      // belongs to S1
             ++lastS1;
             //swap
             temp=arr[firstUnknown];
             arr[firstUnknown] =arr[lastS1];
             arr[lastS1]=temp;
             //swap has 3 moves
             moveCount = moveCount + 3;
         }
        //comparison part is: if (arr[firstUnknown] < pivot)
         compCount++;
    }
    // place pivot in proper position and mark its location
    temp =arr[first];
    arr[first]=arr[lastS1];
    arr[lastS1]=temp;
    moveCount = moveCount + 3;
    pivotIndex = lastS1;
}


///////////////////////////////////////////////MERGE SORT////////////////////////////////////////////
void sorting::mergeSort(int *arr, int size, int &compCount, int &moveCount){
    compCount = 0;
    moveCount = 0;
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

void sorting::mergeSort(int *arr, int first, int last, int &compCount, int &moveCount){
    if (first < last) {
        int mid = (first + last)/2;  // index of midpoint //munib int mid = first + (last - first) / 2; // Get midpoint
        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid+1, last, compCount, moveCount);
        // merge the two halves
        merge(arr, first, mid, last, compCount, moveCount);
    }
}// end mergesort

//const int MAX_SIZE = 3000;

void sorting::merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount) {
    int tempArray[last+1]; // temporary array
    
    int first1 = first;     // beginning of first subarray
    int last1 = mid;         // end of first subarray
    int first2 = mid + 1;    // beginning of second subarray
    int last2 = last;        // end of second subarray
    int index = first1; // next available location in tempArray
    
    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        //compCount++; buraya mı
        if (arr[first1] < arr[first2]) {
            tempArray[index] = arr[first1];
            ++first1;
            moveCount++;
        }
        else {
            tempArray[index] = arr[first2];
            ++first2;
            moveCount++;
        }
        compCount++;
    }
    
    // finish off the first subarray, if necessary
    for ( ; first1 <= last1; ++first1, ++index){
        tempArray[index] = arr[first1];
        moveCount++;
    }
    
    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index){
        tempArray[index] = arr[first2];
        moveCount++;
    }
    
    // copy the result back into the original array
    for (index = first; index <= last; ++index){
        arr[index] = tempArray[index];
        moveCount++;
    }
    
}

///////////////////////////////////////////////INSERTION SORT////////////////////////////////////////////
void sorting::insertionSort(int *arr, int size, int &compCount, int &moveCount){
    compCount = 0;
    moveCount = 0;
     for (int unsorted = 1; unsorted < size; ++unsorted) {
         int nextItem = arr[unsorted];
         int loc = unsorted;
         moveCount++;
         
         for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc){
             arr[loc] = arr[loc-1];
             moveCount++;
             
         }
         compCount++; //arr[loc-1] > nextItem
         arr[loc] = nextItem;
         moveCount++;
     }
}

//////////////////////////////////////////////////////////////////////////////////
void sorting::displayArray(int *arr, int len){
    for (int i = 0; i < len; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

void sorting::createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int N){
    if (N <= 0){
        arr1 = arr2 = arr3 = NULL;
        return;
    }
    arr1 = new int [N];
    arr2 = new int [N];
    arr3 = new int [N];
    
    //srand( time(NULL) ); ????
    srand((int) time(NULL));
    for (int i = 0; i < N; i ++){
        arr1[i] = rand() % (2 * N);
        arr2[i] = arr3[i] = arr1[i];
    }
}

void sorting::createAlreadySortedArrays(int *&arr1, int *&arr2, int *&arr3, int N){
    if (N <= 0){
        arr1 = arr2 = arr3 = NULL;
        return;
    }
    arr1 = new int [N];
    arr2 = new int [N];
    arr3 = new int [N];
    
    for (int i = 0; i < N; i ++)
        arr1[i] = arr2[i] = arr3[i] = i;
}


void sorting:: performanceAnalysis(){ //for random
    cout << "------------------------------------" << endl;
    cout << "Question 2c - Time analysis of Insertion Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        createRandomArrays(arr1, arr2, arr3, i);
        
        int compCount = 0;
        int moveCount = 0;
        string result1= "";
     
        
     
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        //Code block
        insertionSort(arr1, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()  <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
    cout << "------------------------------------" << endl;
    cout << "Question 2c - Time analysis of Merge Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
   
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        createRandomArrays(arr1, arr2, arr3, i);
        
        int compCount = 0;
        int moveCount = 0;
        
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        
        //Store the starting time
        startTime = std::chrono::system_clock::now();
         mergeSort(arr2, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()   <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }

    cout << "------------------------------------" << endl;
    cout << "Question 2c - Time analysis of Quick Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        createRandomArrays(arr1, arr2, arr3, i);
        
        int compCount = 0;
        int moveCount = 0;
        
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        quickSort(arr3, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()   <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
}

void sorting:: performanceAnalysis2(){ //for sorted
    cout << "------------------------------------" << endl;
    cout << "Question 2c - Time analysis of Insertion Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        createAlreadySortedArrays(arr1, arr2, arr3, i);
        
        int compCount = 0;
        int moveCount = 0;
        
       
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
         insertionSort(arr1, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()   <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
    cout << "------------------------------------" << endl;
    cout << "Question 2c - Time analysis of Merge Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        createAlreadySortedArrays(arr1, arr2, arr3, i);
        
        int compCount = 0;
        int moveCount = 0;
        
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
          mergeSort(arr2, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()  <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
    
    cout << "------------------------------------" << endl;
    cout << "Question 2c - Time analysis of Quick Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        createAlreadySortedArrays(arr1, arr2, arr3, i);
        
        int compCount = 0;
        int moveCount = 0;
        
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        quickSort(arr3, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()   <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
}

void sorting::attemptOneSwap(int *arr, int N, int K, int currIndex){
    int minIndex, maxIndex, swapIndex;
    
    arr[currIndex] - K >= 0 ? minIndex = arr[currIndex] - K : minIndex = 0;
    arr[currIndex] + K <  N ? maxIndex = arr[currIndex] + K : maxIndex = N - 1;
    swapIndex = rand() % (maxIndex - minIndex + 1) + minIndex;
    
    if (arr[swapIndex] - K <= currIndex && currIndex <= arr[swapIndex] + K){
        int temp = arr[swapIndex];
        arr[swapIndex] = arr[currIndex];
        arr[currIndex] = temp;
    }
}
double sorting::averageDistance(int *arr, int N, int K){
    double avgDist = 0.0;
    
    for (int i = 0; i < N; i++){
        int diff = abs(arr[i] - i);
        if (diff > K)
            cout << "Error (please inform the instructor)" << endl;
        avgDist += diff;
    }
    if (N == 0)
        return 0;
    return avgDist / N;
}
void sorting::createNearlySortedArrays(int *&arr1, int *&arr2, int *&arr3, int N, int K){
    if (N <= 0){
        arr1 = arr2 = arr3 = NULL;
        return;
    }
    int minIndex, maxIndex;
    arr1 = new int [N];
    arr2 = new int [N];
    arr3 = new int [N];
    
     srand((int) time(NULL));
  //  srand( time(NULL) );
    for (int i = 0; i < N; i ++)
        arr1[i] = i;
    
    int iterNo = 0;
    while (iterNo < 10) {
        for (int i = 0; i < N; i ++)
            attemptOneSwap(arr1, N, K, i);
        for (int i = N - 1; i >= 0; i--)
            attemptOneSwap(arr1, N, K, i);
        double d = averageDistance(arr1, N, K);
        //cout << "distance:"<<d << endl;
        if (d > K / 2)
            break;
        iterNo++;
    }
    for (int i = 0; i < N; i ++)
        arr2[i] = arr3[i] = arr1[i];
}

void sorting::performanceAnalysis3(){
    cout << "------------------------------------" << endl;
    cout << "Question 3 - Time analysis of Insertion Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        int K=15;
       createNearlySortedArrays(arr1, arr2, arr3, i, K);
        int compCount = 0;
        int moveCount = 0;
      
        
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        insertionSort(arr1, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()  <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
    cout << "------------------------------------" << endl;
    cout << "Question 3 - Time analysis of Merge Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        int K=15;
        createNearlySortedArrays(arr1, arr2, arr3, i, K);
        
        int compCount = 0;
        int moveCount = 0;
        
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
       mergeSort(arr2, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()  <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
    
    cout << "------------------------------------" << endl;
    cout << "Question 3 - Time analysis of Quick Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        int K=15;
        createNearlySortedArrays(arr1, arr2, arr3, i, K);
        
        int compCount = 0;
        int moveCount = 0;
       
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        quickSort(arr3, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()   <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
}

void sorting::performanceAnalysis4(){
    cout << "------------------------------------" << endl;
    cout << "Question 3 - Time analysis of Insertion Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        createNearlySortedArrays(arr1, arr2, arr3, i, (i-15));
        
        
        int compCount = 0;
        int moveCount = 0;
      
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        insertionSort(arr1, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()   <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
    cout << "------------------------------------" << endl;
    cout << "Question 3 - Time analysis of Merge Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        createNearlySortedArrays(arr1, arr2, arr3, i, (i-15));
        
        int compCount = 0;
        int moveCount = 0;
      
        
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        mergeSort(arr2, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()  <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
    
    cout << "------------------------------------" << endl;
    cout << "Question 3 - Time analysis of Quick Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        createNearlySortedArrays(arr1, arr2, arr3, i, (i-15));
        
        int compCount = 0;
        int moveCount = 0;
       
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        quickSort(arr3, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()  <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
}

void sorting::performanceAnalysis5(){
    cout << "------------------------------------" << endl;
    cout << "Question 3 - Time analysis of Insertion Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        //int K=4000;
        createNearlySortedArrays(arr1, arr2, arr3, i, (i/2));
        
        
        int compCount = 0;
        int moveCount = 0;
        string result1= "";
        
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        insertionSort(arr1, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()   <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
    cout << "------------------------------------" << endl;
    cout << "Question 3 - Time analysis of Merge Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        
        createNearlySortedArrays(arr1, arr2, arr3, i, (i/2));
        
        int compCount = 0;
        int moveCount = 0;
       
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        mergeSort(arr2, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()  <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
    
    cout << "------------------------------------" << endl;
    cout << "Question 3 - Time analysis of Quick Sort" << endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    for (int i = 5000; i <=35000; i=i+5000) {
        int *arr1  ;
        int *arr2  ;
        int *arr3  ;
        

        createNearlySortedArrays(arr1, arr2, arr3, i, (i/2));
        
        int compCount = 0;
        int moveCount = 0;
       
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, std::milli >elapsedTime;
        //Store the starting time
        startTime = std::chrono::system_clock::now();
        quickSort(arr3, i, compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        std::cout << i << setw(18) << elapsedTime.count()  <<  setw(15) << compCount << setw(15) << moveCount <<std::endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
}
