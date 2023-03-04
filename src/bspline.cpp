#include "bspline.h"
#include <iostream>
#include <fstream>

int main()
{
    ofstream  location_out;
    ofstream  location_updated_out;
//    location_out.open("location_out.txt",std::ios::out | std::ios::app);
//    location_updated_out.open("location_updated_out.txt",std::ios::out | std::ios::app);
    location_out.open("location_out.txt",std::ios::out);
    location_updated_out.open("location_updated_out.txt",std::ios::out );
    if(!location_out.is_open()){
        return 0;
    }
    if(!location_updated_out.is_open()){
        return 0;
    }
    double c_1[] = {-1.0, 1.0, 3.0, 3.0, 3.0, 3.0, 5.0, 6.0, 8.0, 9.0};
    double c_2[] = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0, 3.0, 3.0, 3.5, 5.0};
    int num = sizeof(c_1) / sizeof(c_1[0]);
    for(auto i = 0; i < 10; i++){
        location_out << c_1[i] <<  " " ;
    }
    location_out  << endl;
    for(auto i = 0; i < 10; i++){
        location_out << c_2[i] <<  " " ;
    }
    location_out  << endl;

    vector<double> x_set, y_set;
    for(int i=0;i<num;i++){
        x_set.push_back(c_1[i]);
        y_set.push_back(c_2[i]);
    }
    Points points;
    points = B_Spline(x_set,y_set);
    
    cout << "the point size is :" << points.points_x.size();
    for(int i=0;i<points.points_x.size();i++){
        location_updated_out << points.points_x[i] << " ";
    }

    location_updated_out  << endl;
    for(int i=0;i<points.points_y.size();i++){
        location_updated_out << points.points_y[i] << " ";
    }

    location_out.close();
    location_updated_out.close();
}
