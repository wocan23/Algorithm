//
// Created by wocan23 on 2019/6/18.
//

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

// arr = {5,1,2,4,7,3,9,8}
// 从大到小
void quick_sort_max(int arr[],int low, int high){
    // 递归结束条件
    if(low < high){
        int i = low,j = high, x = arr[i];
        // 第一个循环，将8->5
        // 第二个循环，将1->8
        // 此时7空着，将5补上
        // 持续以上，保证i左边的值，都小于x，i右边的值都大于x
        while (i < j){
            while(i < j && x >= arr[j]) { // 从右向左找第一个大于x的数
                j--;
            }
            if(i < j){
                arr[i++] = arr[j]; // 将小的数赋值给当前的i,即基数所占的位置
            }
            while(i < j && x < arr[i]) { // 从左向右找第一个小于x的数
                i++;
            }
            if(i < j){
                arr[j--] = arr[i]; // 将大的数赋值给j，
            }
        }
        // 最后将x赋值给arr[i]
        arr[i] = x; // 原基数赋值给当前的i,i左边的都比他大，右边的都比他小
        // 递归
        quick_sort_max(arr,low,i-1);
        quick_sort_max(arr,i+1,high);
    }
}

// arr = {5,1,2,4,7,3,9,8}
// 从小到大
void quick_sort_min(int arr[],int low, int high){
    // 递归结束条件
    if(low < high){
        int i = low,j = high, x = arr[i];
        // 第一个循环，将3->5
        // 第二个循环，将7->3
        // 此时7空着，将5补上
        // 持续以上，保证i左边的值，都小于x，i右边的值都大于x
        while (i < j){
            while(i < j && x <= arr[j]) { // 从右向左找第一个小于x的数
                j--;
            }
            if(i < j){
                arr[i++] = arr[j]; // 将小的数赋值给当前的i,即基数所占的位置
            }
            while(i < j && x > arr[i]) { // 从左向右找第一个大于x的数
                i++;
            }
            if(i < j){
                arr[j--] = arr[i]; // 将大的数赋值给j，
            }
        }
        // 最后将x赋值给arr[i]
        arr[i] = x; // 原基数赋值给当前的i,i左边的都比他大，右边的都比他小
        printArr(arr,8);
        cout << "---------" << endl;
        // 递归
        quick_sort_min(arr,low,i-1);
        quick_sort_min(arr,i+1,high);
    }
}

// arr = {5,1,2,4,7,3,9,8}

void quick_sort(int arr[],int low, int high, SORT_TYPE type = MIN){
    // 递归结束条件
    if(low < high){
        int i = low,j = high, x = arr[i];
        // 第一个循环，将3->5
        // 第二个循环，将7->3
        // 此时7空着，将5补上
        // 持续以上，保证i左边的值，都小于x，i右边的值都大于x
        while (i < j){
            while(i < j && (( type == MIN && x <= arr[j]) || (type == MAX && x >= arr[j]))) { // 从右向左找第一个小于x的数
                j--;
            }
            if(i < j){
                arr[i++] = arr[j]; // 将小的数赋值给当前的i,即基数所占的位置
            }
            while(i < j && (( type == MIN && x > arr[i]) || (type == MAX && x < arr[i]))) { // 从左向右找第一个大于x的数
                i++;
            }
            if(i < j){
                arr[j--] = arr[i]; // 将大的数赋值给j，
            }
        }
        // 最后将x赋值给arr[i]
        arr[i] = x; // 原基数赋值给当前的i,i左边的都比他大，右边的都比他小
        // 递归
        quick_sort(arr,low,i-1,type);
        quick_sort(arr,i+1,high,type);
    }
}

#endif //ALGORITHM_QUICKSORT_H
