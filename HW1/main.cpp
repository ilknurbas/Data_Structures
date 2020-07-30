/*
 * Title: Algorithm Efficiency and Sorting
 * Author: İlknur Baş
 * ID: 21601847
 * Section: 2
 * Assignment: 1
 * Description: main function
 */

#include <iostream>
#include "sorting.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    sorting s;
    int compCount = 0;
    int moveCount = 0;
    int arr[] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    int len = 16;
        
    cout << "Insertion sort: " <<endl;
    s.insertionSort(arr, len, compCount, moveCount);
    s.displayArray(arr, len);
    cout << "\nComparison Count: " << compCount << " Data Moves: "  << moveCount <<endl;
        
        
    cout << "\nQuick sort: " <<endl;
    s.quickSort(arr, len, compCount, moveCount );
    s.displayArray(arr, len);
     cout << "\nComparison Count: " << compCount << " Data Moves: "  << moveCount <<endl;
        
    cout << "\nMerge sort: " <<endl;
    s.mergeSort(arr, len, compCount, moveCount );
    s.displayArray(arr, len);
    cout << "\nComparison Count: " << compCount << " Data Moves: "  << moveCount <<endl;
    cout << endl;
    
    
    ///part 2c
    cout << "\nRandom array elements**** " <<endl;
    s.performanceAnalysis();
    cout << "\nAlready sorted array elements**** " <<endl;
    s.performanceAnalysis2();
    cout << "\nNearly sorted array elements k=15**** " <<endl;
     s.performanceAnalysis3();
    cout << "\nNearly sorted array elements k=size-15**** " <<endl;
    s.performanceAnalysis4();
    cout << "\nNearly sorted array elements k=size/2**** " <<endl;
    s.performanceAnalysis5();
    
    return 0;

}
