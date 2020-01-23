//
// Created by wocan23 on 2019/8/16.
//

#ifndef ALGORITHM_DBSCAN_H
#define ALGORITHM_DBSCAN_H

#define EARTH_RADIUS 6378245.0

#include <math.h>
#include <vector>
#include <set>
#include <stack>
#include <iostream>
#include <sys/time.h>

using namespace std;
/**
 * 迪卡尔距离
 * @param p1
 * @param p2
 * @return
 */


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

Point::Point() {
    this->nearCount = 0;
}

Point::Point(string id, double lng, double lat) {
    this->id = id;
    this->lng = lng;
    this->lat = lat;
    this->nearCount = 0;
}

double get_distance(int p1[2],int p2[2]){
    return pow((pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2)),-2);
}

double rad(double d) {
    return d * M_PI / 180.0;
}

void print_arr(vector<Point>& arr){
    for(int i = 0; i < arr.size(); ++i){
        cout << "id: " << arr[i].id << " lng:" << arr[i].lng <<" lat:" << arr[i].lat <<endl;
    }
}

/**
 * 获取gps距离，火星坐标
 * @param lng1
 * @param lat1
 * @param lng2
 * @param lat2
 * @return
 */
double get_gps_distance(double lng1, double lat1, double lng2, double lat2){
    double radLat1 = rad(lat1);
    double radLat2 = rad(lat2);
    double a = radLat1 - radLat2;
    double b = rad(lng1) - rad(lng1);
    double s = 2 * asin(sqrt(pow(sin(a / 2), 2)
                                       + cos(radLat1) * cos(radLat2)
                                         * pow(sin(b / 2), 2)));
    s = s * EARTH_RADIUS;
    s = round(s * 10000) / 10000;
    s = s*1000;
    return s;
}

double get_gps_distance(Point& p1, Point& p2){
    return get_gps_distance(p1.lng,p1.lat,p2.lng,p2.lat);
}

long get_current_timemills(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_usec/1000+tv.tv_sec*1000;
}

long get_current_time(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec;
}

void do_dbscan(Point points[],int size, double r, int num){

    cout <<"ct："<< get_current_time() << endl;
    // 所有访问集合
    set<string> visited_point_ids;
    // 去除噪音的点
    vector<Point> pre_cluster_points;
    // 遍历节点更新附近个数
    vector<Point> max_near_count_points;

    stack<int> stack1;
    cout << "near count" << endl;
    long t1 = get_current_time();
    // 计算附近点个数
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            double dist = get_gps_distance(points[i],points[j]);
//            cout << dist << endl;
            if(dist<r){
//                cout << ">r" << endl;
                points[i].nearCount++;
                points[j].nearCount++;
            }
        }
    }
    long t2 = get_current_time();
    cout << "near points cost: [" << (t2-t1)<< " ]s" << endl;
    // 标记符合条件的点，瞬间
    for(int i=0;i< size;i++){
        if(points[i].nearCount>=num) {
            points[i].pointType = 3;
            pre_cluster_points.push_back(points[i]);
        }
    }

    long t3 = get_current_time();
    cout << "cluster and pre count:"<< pre_cluster_points.size() << endl;
    cout << "get all pre point cost: [" << (t3-t2)<< " ]s" << endl;
    // 附近点索引号放入附近点集合，60s
    for(int i=0;i<pre_cluster_points.size();i++){
        for(int j=i+1;j<pre_cluster_points.size();j++){
            if(get_gps_distance(pre_cluster_points[i],pre_cluster_points[j])<r){
                pre_cluster_points[i].nearIndexes.push_back(j);
                pre_cluster_points[j].nearIndexes.push_back(i);
            }
        }
    }
    long t4 = get_current_time();
    cout << "nearIndexes point cost: [" << (t4-t3)<< " ]s" << endl;
    // 聚类：瞬间
    for(int i=0;i<pre_cluster_points.size();i++){
        stack<Point*> ps;
        if(pre_cluster_points[i].visited) continue;
        ps.push(&pre_cluster_points[i]);
        Point *v;
        Point *max = nullptr;
        while(!ps.empty()){
            v = ps.top();
            v->visited = true;
            if(max == nullptr){
                max = v;
            } else {
                if(max->nearCount<v->nearCount){
                    max = v;
                }
            }
            ps.pop();
            for(int j=0;j<v->nearIndexes.size();j++){
                if(pre_cluster_points[v->nearIndexes[j]].visited==1) continue;
                pre_cluster_points[v->nearIndexes[j]].visited = true;
                ps.push(&pre_cluster_points[v->nearIndexes[j]]);
            }
        }
        max_near_count_points.push_back(*max);
    }
    long t5 = get_current_time();
    cout << "central point cost: [" << (t5-t4)<< " ]s" << endl;
    print_arr(max_near_count_points);
}

#endif //ALGORITHM_DBSCAN_H
