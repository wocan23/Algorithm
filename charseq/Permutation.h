//
// Created by wocan23 on 2019/10/12.
//

#include <iostream>
using namespace std;
#include <vector>

/**
 * 问题：输入一字符串(要求不存在重复字符)，打印出该字符串中字符中字符的所有排列。
   例如：输入”abc”，输出结果为abc, acb, bac, bca, cab和cba。

   递归思路：看成两步：

1、首先求所有可能出现在第一个位置的字符，可以把第一个字符和后面的字符一次交换；
2、固定第一个字符后，求后面字符的全排列，过程类似第一个字符的取法，即递归调用
 也可以这么理解，f(abc) = [a+f(bc)] U [b+f(ac)] U [c+f(ba)]
 */

vector<string> permutation(string source, string pre){
    vector<string> res;
    int size = source.size();
    if(size == 1){
        res.push_back(pre+source);
        return res;
    }
    for(int i = 0; i < size; ++i){
        // 取头
        string begin = source.substr(i,1);
        string other = source.substr(0,i) + source.substr(i+1);
        vector<string> subRes = permutation(other,pre+begin);
        res.insert(res.end(),subRes.begin(),subRes.end());
    }
    return res;
}