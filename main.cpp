#include <iostream>
using namespace std;

#include "lcs.h"
#include "quicksort.h"
#include "heapsort.h"

void test_lcs(){
    string a = "bcbcdddbc";
    string b = "bcbcbc";
    int **res = new int*[2];
    int size;
    lcs(a,b,res,size);
    cout << "&&&&" << endl;
    printArr(res,2,size);
}

void test_quick_sort(){
    int arr[]= {5,1,2,4,7,3,9,8};
    int size = sizeof(arr)/ sizeof(arr[0]);
    quick_sort(arr,0, size-1,MAX);
    printArr(arr,size);
}

void test_heap_sort(){
    int arr[]= {5,1,2,4,7,3,9,8};
    int size = sizeof(arr)/ sizeof(arr[0]);
    heap_sort(arr, size, MAX);
    printArr(arr,size);
}

int main() {
    test_heap_sort();
    return 0;
}