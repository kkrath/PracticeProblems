#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


#include<iostream>
#include<vector>
/*
 * Complete the 'largestSegment' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY radius
 *  2. INTEGER segments
 */
bool isAreaPossible(vector<double>& areas, int segments, double test_area){
    int count  = 0;
    for(auto area : areas){
        count  = count + (area / test_area);
        if(count >= segments)
            return true;
    }
    return false;
}

string largestSegment(vector<int> radius, int segments) {
    /* let's calculate the area of the circles first */
    double max_area = 0.0;
    double PI = 3.14159265359;
    vector<double> areas;
    for(auto r : radius){
        double area = PI * r * r;
        max_area = max(max_area, area);
        areas.push_back(area);
    }
    /* now we will apply binary search area on max_area to find a suitable
       area that fits to all circles and if that matches with the numner of
       segemnts, we will look for the max area we can get */
    double min_area = 0.0, mid_area = 0.0;
    while(max_area - min_area >= 1e-4){
        mid_area = (max_area - min_area) / 2;
        /* check if this intermediate area is common to all the circles
           if we can find an area greater;this which is common to all the circles */
        if(isAreaPossible(areas, segments, mid_area))
            min_area = mid_area;
        /* the area does not fit all the circles so we will move left to find a area
           smaller than the found area and see if that fits */
        else
            max_area = mid_area;
    }
    /* the maximum area that fits all the circles */
    return to_string(mid_area);
}


int main()
{
    
    vector<int> radius{3,4,3,3,3};


    string result = largestSegment(radius, 6);

}
