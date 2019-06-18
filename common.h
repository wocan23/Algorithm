//
// Created by wocan23 on 2019/6/18.
//

#ifndef ALGORITHM_COMMON_H
#define ALGORITHM_COMMON_H

#include <iostream>
using namespace std;

int Max(int &a,int &b,int &c){
    return max(max(a,b),c);
}

void printArr(int (arr)[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }
}
void printArr(int **arr, int length1,int length2){
    for(int i = 0; i < length1; i++){
        for(int j = 0; j < length2; j++){
            cout << arr[i][j] << endl;
        }
        cout << endl;
    }
}

#endif //ALGORITHM_COMMON_H
