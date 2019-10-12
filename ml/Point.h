//
// Created by wocan23 on 2019/8/20.
//

#ifndef ALGORITHM_POINT_H
#define ALGORITHM_POINT_H

#include <vector>
#include <string>
#include "PointStruct.h"
using namespace std;

class Point {
public:
    double lng;
    double lat;
    string id;

    int nearCount;
    int pointType;
    bool visited;
    vector<int> nearIndexes;

    Point();
    Point(string id, double lng, double lat);
};


#endif //ALGORITHM_POINT_H
