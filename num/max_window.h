//
// Created by wocan23 on 2020/1/23.
//

#ifndef ALGORITHM_MAX_WINDOW_H
#define ALGORITHM_MAX_WINDOW_H

#include <deque>
using namespace std;
/**
 * 思路：双端队列，将arr中的元素加入res该队列中，
 * 若该队列的队尾元素小于等于要加入的元素，则不断的弹出，直到队尾元素大于该元素或者队列为空。
 * 此时将该元素的序号加入队列中。
 * 同时当 i-w == 队头的序号，则将队头元素弹出。
 *
 * int arr[] = {4,3,5,4,3,3,6,7};
 * 每次循环队列角标对应的值情况
 * 4                    0
 * 4 3                  0 1
 * 5                    2           符合条件输出  5
 * 5 4                  2 3         符合条件输出  5
 * 5 4 3                2 3 4       符合条件输出  5
 * 4 3 3                3 4 5       符合条件输出  4
 * 6                    6           符合条件输出  6
 * 7                    7           符合条件输出  7
 *
 **/
int* get_window_max(int arr[], int size, int win_len){
    if(win_len > size){
        return nullptr;
    }
    deque<int> deq;
    int *res = new int[size-win_len];
    for(int i = 0; i < size; ++i){
        // 出现最大值，则前面的都出列
        while (!deq.empty() && arr[deq.back()] <= arr[i]){
            deq.pop_back();
        }
        deq.push_back(i);
        if(deq.front() == i - win_len){
            deq.pop_front();
        }
        if(i >= win_len-1){
            res[i-win_len+1] = arr[deq.front()];
        }
    }
    return res;
}

#endif //ALGORITHM_MAX_WINDOW_H
