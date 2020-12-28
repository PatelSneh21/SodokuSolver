// File name: Point.h
// Author: Sneh Patel
// Description: Based on the Point class developed by Vanderbilt University CS2201 Instructor for project 7.
// Represents a point via x & y coordinates.

#ifndef SODOKUSOLVER_POINT_H
#define SODOKUSOLVER_POINT_H
#include <iostream>


class Point
{
public:
    int x;
    int y;

    // Class Constructor
    // post: Initializes x and y to zero
    Point();

    // Class Constructor
    // post: Initializes x and y
    Point(int x,int y);


    // Equality operators
    bool operator== (const Point& rhs) const;
    bool operator!= (const Point& rhs) const;

};

// insertion operator for output
std::ostream& operator<< (std::ostream& os, const Point &p);



#endif //SODOKUSOLVER_POINT_H
