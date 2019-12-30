//
// Created by wocan23 on 2019/12/30.
//

#ifndef ALGORITHM_REPEAT_FIND_H
#define ALGORITHM_REPEAT_FIND_H

/**
 * 找到数组中唯一重复的数字(异或),只有连续时候管用
 * @param arr
 * @param size
 * @return
 */
int find_repeat_num(int arr[], int size){
    int res = 0;
    for(int i = 0; i < size; ++i){
        res = res ^ arr[i];
        cout << i << ": " <<  res << endl;
    }
    return res;
}

/**
 * 找到唯一重复数字(重复次数超过半数)
 * @param arr
 * @param size
 * @return
 */
int find_most_repeat(int arr[], int size){
    int res = arr[0];
    int count = 0;
    for(int i = 1; i < size; ++i){
        if(res == arr[i]){
            count++;
        }else{
            count--;
        };
        if(count <= 0){
            res = arr[i];
        }
    }
    return res;

}
#endif //ALGORITHM_REPEAT_FIND_H
