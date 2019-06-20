//
// Created by wocan23 on 2019/6/20.
//

#ifndef ALGORITHM_HEAPSORT_H
#define ALGORITHM_HEAPSORT_H

void swap(int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapify(int arr[], int start, int end, SORT_TYPE type = MIN){
    int dad = start;
    int son = start * 2 + 1;
    while(son <= end){
        // 比较两个子节点
        if(son + 1 <= end && ((type == MIN && arr[son] < arr[son+1]) || (type == MAX && arr[son] > arr[son+1]))){
            son++;
        }
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
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(arr, i, len - 1, type);
    // 先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
    for (int i = len - 1; i > 0; i--) {
        swap(arr, 0, i);
        heapify(arr, 0, i - 1, type);
    }
}


#endif //ALGORITHM_HEAPSORT_H
