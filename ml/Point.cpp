//
// Created by wocan23 on 2019/8/20.
//

#include "Point.h"

Point::Point() {
    this->nearCount = 0;
}

Point::Point(string id, double lng, double lat) {
    this->id = id;
    this->lng = lng;
    this->lat = lat;
    this->nearCount = 0;
}
