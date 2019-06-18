#include <iostream>
using namespace std;

#include "lcs.h"

int main() {
    string a = "bcbcdddbc";
    string b = "bcbcbc";
    int **res = new int*[2];
    int size;
    lcs(a,b,res,size);
    cout << "&&&&" << endl;
    printArr(res,2,size);
    return 0;
}