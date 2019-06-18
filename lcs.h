//
// Created by wocan23 on 2019/6/17.
//

#ifndef ALGORITHM_LCS_H
#define ALGORITHM_LCS_H
#include <iostream>
using namespace std;

#include "common.h"
//  匹配
//  A=a1a2……aN，表示A是由a1a2……aN这N个字符组成，Len(A)=N;
//
//  B=b1b2……bM，表示B是由b1b2……bM这M个字符组成，Len(B)=M.
//
//  定义LCS(i,j)=LCS(a1a2……ai,b1b2……bj)，其中0≤i≤N，0≤j≤M.
//
//  对于1≤i≤N，1≤j≤M，有公式:
//
//  若ai=bj，则LCS(i,j)=LCS(i-1,j-1)+1
//  若ai≠bj，则LCS(i,j)=Max(LCS(i-1,j-1),LCS(i-1,j),LCS(i,j-1))

//  回溯
//  若ai=bj，则回溯到左上角单元格
//  若ai≠bj，回溯到左上角、上边、左边中值最大的单元格，若有相同最大值的单元格，优先级按照左上角、上边、左边的顺序
//  若当前单元格是在矩阵的第一行，则回溯至左边的单元格
//  若当前单元格是在矩阵的第一列，则回溯至上边的单元格



void lcs(string &a, string &b, int* res[2], int& size){
    int aLen = a.length();
    int bLen = b.length();

    char acr[aLen];
    char bcr[bLen];

    strcpy(acr,a.c_str());
    strcpy(bcr,b.c_str());

    int lcv[aLen+1][bLen+1];
    memset(lcv,0, sizeof(lcv));
    cout << lcv[aLen][bLen] << endl;

    for(int i = 1; i <= aLen; i++){
        for(int j = 1; j <= bLen; j++){
            if(acr[i-1] == bcr[j-1]){
                lcv[i][j] = lcv[i-1][j-1] + 1;
            }else{
                lcv[i][j] = Max(lcv[i-1][j-1],lcv[i-1][j],lcv[i][j-1]);
            }
        }
    }

    // 获取长度
    int maxL = lcv[aLen][bLen];
    cout << maxL << endl;
    for(int i = 0; i <= aLen; i++){
        for( int j = 0; j <= bLen; j++){
            cout << lcv[i][j];
        }
        cout << "" << endl;
    }

    int ais[maxL];
    int bis[maxL];
    res[0] = new int[maxL];
    res[1] = new int[maxL];
    // 回溯求取对应的坐标
    int i = aLen;
    int j = bLen;
    int cur = maxL;
    while(i > 0 || j > 0){
        if(acr[i-1] == bcr[j-1]){
//            cout << acr[i-1]<<endl;
            ais[cur-1] = i-1;
            bis[cur-1] = j-1;
            res[0][cur-1] = i-1;
            res[1][cur-1] = j-1;
            i--;
            j--;
            cur--;
        }else{
            if( i == 1){
                j--;
                continue;
            }else if(j == 1){
                i--;
                continue;
            }
            int left = lcv[i - 1][j];
            int up = lcv[i][j-1];
            int lu = lcv[i-1][j-1];
            int max = Max(left,up,lu);
            if(lu == max){
                i--;
                j--;
            }else if(up == max){
                j--;
            }else{
                i--;
            }
        }
    }

    size = maxL;
}
#endif //ALGORITHM_LCS_H
