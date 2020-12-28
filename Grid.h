// File name: Grid.h
// Author: Sneh Patel
// Description:  Based on the Maze class developed by Vanderbilt University CS2201 Instructor for project 7
//
//    A grid has a start location, which is the smallest integer in the grid.
//    The initial grid is read from a file. It will keep track of the smallest integer input.
//    The user can get a location from the maze, and keep track of which locations
//    have been visited. Locations are represented by x-y coordinates or Point objects.
//    The origin (0,0) is the lower left corner of the graph; the x-coordinate moves
//    left to right across the x axis; the y-coordinate moves bottom to top up the y axis.
//    The set() method is private, as the grid should not be changed once it has been
//    read from the file.

// Last Changed:  12/28/2020
#ifndef SODOKUSOLVER_GRID_H
#define SODOKUSOLVER_GRID_H



#include <string>
#include <fstream>
#include <iostream>
#include "Point.h"
#include <stack>

//Default values of the rows/cols is set to 5.
const int MAX_ROWS = 9;
const int MAX_COLS = 9;

class Grid {

public:
    // Constructor
    //Pre:Accepts file name as a parameter
    //Post:Reads the file and initializes Grid
    Grid (std::string filename);

    //printGrid
    //Pre: A grid exists and contains values
    //Post: Prints the values in the grid values in the format they were inputted
    void printGrid() const;

    //Pre: A grid exists and max rows/cols is defined
    //Post: Returns the max number of rows
    int getNumRows() const;
    int getNumCols() const;

    //get
    //Pre: Grid is defined and has a valid element at given index
    //Post: Returns a value at the given coordinates from the Grid matrix.
    int get (int x, int y) const;
    int get (Point location) const;

    //getStartLocation
    //Pre: Starting point exists
    //Post: Returns the starting Point, set to default as (0,0)
    Point getStartLocation() const;

    //checkRange
    //Pre: Parameters are valid integers/points.
    //Post: Returns whether or not the corresponding point in the grid is valid.
    bool checkRange(int x, int y) const;

    bool checkRange(Point temp) const;

private:

    // Grid matrix storage buffer.  Using static arrays -- Big 3 not required!
    int gridMatrix[MAX_COLS][MAX_ROWS];

    // Start location for the grid
    Point startLocation;

    //set
    // Pre: Given coordinates are valid
    // Post: Set an item in the grid matrix at the given coordinates.
    // Post: Throws std::range_error if the coordinates are not within the maze bounds
    // These are private since no one outside the class should be changing the grid
    void set (int new_item, int x, int y);
    void set (int new_item, Point location);

};

#endif //SODOKUSOLVER_GRID_H
