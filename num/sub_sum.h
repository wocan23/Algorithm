//
// Created by wocan23 on 2019/12/27.
//

#ifndef ALGORITHM_SUBSUM_H
#define ALGORITHM_SUBSUM_H

/**
 * 最大子段和，动态规划
 * C[i]=max[1≤k≤i]{∑(j=k) iA[j]} C[i]为从k到第i个连续值第求和，因为递归第时候要算C[i]和C[i-1]之间的关系，所以必须连续从后往前推
 * 那么有递推关系
 *   C[i]=max{C[i−1]+A[i], A[i]}i=2,...,n
 *   C[1]={A[1]  ifA[1]>00     ifA[1]<0 
 *
 *   OPT(A)=max(1≤i≤n){Ci}
 */


double maxSubSum(double arr[], int size){
 double tmpSum = 0;
 double maxSubSum = 0;
 for( int i = 0; i < size; ++i){
    tmpSum = (tmpSum + arr[i]) > maxSubSum ? tmpSum + arr[i] : arr[i];
    if( tmpSum > maxSubSum){
        maxSubSum = tmpSum;
    }
 }
 return maxSubSum;
}

#endif //ALGORITHM_SUBSUM_H
