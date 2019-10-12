//
// Created by wocan23 on 2019/6/20.
//

#ifndef ALGORITHM_HEAPSORT_H
#define ALGORITHM_HEAPSORT_H

#include "../common.h"

void swap(int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// 堆调整
void heapify(int arr[], int start, int end, SORT_TYPE type = MIN){
    int dad = start;
    int son = start * 2 + 1;
    while(son <= end){
        // 比较两个子节点，取出最大/小得子节点
        if(son + 1 <= end && ((type == MIN && arr[son] < arr[son+1]) || (type == MAX && arr[son] > arr[son+1]))){
            son++;
        }
        // 符合条件退出，不符合条件交换
        if((type == MIN && arr[dad] > arr[son]) || (type == MAX && arr[dad] < arr[son])){
            return;
        } else{
            swap(arr,dad,son);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len, SORT_TYPE type = MIN){
    // 从最后一个父节点开始调整，调整到根节点
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(arr, i, len - 1, type);
    // 将第一个和第i个交换，根为最大/最小，再将去除最后前i-1个作为新的堆，进行调整
    for (int i = len - 1; i > 0; i--) {
        swap(arr, 0, i);
        heapify(arr, 0, i - 1, type);
    }
}


#endif //ALGORITHM_HEAPSORT_H
