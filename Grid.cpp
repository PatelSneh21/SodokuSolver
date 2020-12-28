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
#include "Grid.h"
#include <stdexcept>
#include <cstdlib>
#include "Grid.h"

//Constructor
//Pre:Accepts file name as a parameter
//Post:Reads the file and initializes start and end location and Grid Matrix and visited matrix
Grid::Grid(std::string filename) {

    std::string str;
    std::ifstream file(filename.c_str());
    // Do error checking here
    if (!file) {
        std::cout << "Unable to open file. Press enter to exit program.";
        getline(std::cin, str);  // consume existing line
        std::cin.get();  // get the key press
        exit(1);
    }

    //Arbitrarily, we will start at the top left of the grid.
    startLocation = Point(0,0);

    int curr;
    int rows = 4;
    int cols = 4;
    std::stack<int> vals;

    //Create a stack of all values so we can load into 9x9 grid correctly
    while (file >> curr) {
        vals.push(curr);
    }

    if (vals.size() != 25) {
        std::cout << "File did not contain the correct number of values." << std::endl;
        std::cout << "Unpredictable results may occur." << std::endl;
    }

    while (rows != -1 && !(vals.empty())) {
        if (cols == -1) {
            cols = 4;
            rows--;
        }
        set(vals.top(), rows, cols);
        vals.pop();
        cols--;
    }

    file.close();

}

//printGrid
//Pre: A grid exists and contains values
//Post: Prints the values in the grid values in the format they were inputted
void Grid::printGrid() const
{
    for (size_t x = 0; x < MAX_ROWS; ++x) {
        for (size_t y = 0; y < MAX_COLS; ++y) {
            std::cout << gridMatrix[x][y] << " ";
        }
        std::cout << "" << std::endl;
    }
}

//getNumRows
//Pre: A grid exists and max rows is defined
//Post: Returns the max number of rows
int Grid::getNumRows() const
{
    return MAX_ROWS;
}

//getNumCols
//Pre: A grid exists and max cols is defined
//Post: Returns the max number of cols
int Grid::getNumCols() const
{
    return MAX_COLS;
}


//get
//Pre: Grid is defined and has a valid element at given index
//Post: Returns a value at the given coordinates from the maze matrix.
int Grid::get(int x, int y) const
{
    return gridMatrix[x][y];

}

//get
//Pre: Grid is defined and has a valid element at given index
//Post: Returns a value at the given coordinates from the maze matrix.
int Grid::get(Point location) const
{
    return get(location.x, location.y);
}


//getStartLocation
//Pre: Starting point exists
//Post: Returns the starting Point, set to default as (0,0)
Point Grid::getStartLocation() const
{
    return startLocation;
}


//checkRange
//Pre: Parameters are valid integers/points.
//Post: Returns whether or not the corresponding point in the grid is valid.
bool Grid::checkRange(int x, int y) const
{
    if(y < 0 || y >= MAX_ROWS || x < 0 || x >= MAX_COLS)
    {
        return false;
    }

    else {
        return true;
    }
}

//checkRange
//Pre: Parameters are valid integers/points.
//Post: Returns whether or not the corresponding point in the grid is valid.
bool Grid::checkRange(Point temp) const {
    return checkRange(temp.x, temp.y);
}


//set
// Pre: Given coordinates are valid
// Post: Set an item in the grid matrix at the given coordinates.
// Post: Throws std::range_error if the coordinates are not within the maze bounds
// These are private since no one outside the class should be changing the grid
void Grid::set(int new_item, int x, int y)
{
    if (checkRange(x, y)) {
        gridMatrix[x][y] = new_item;
    }
    else {
        throw std::range_error("Point out of bounds");
    }
}

//set
// Pre: Given coordinates are valid
// Post: Set an item in the grid matrix at the given coordinates.
// Post: Throws std::range_error if the coordinates are not within the maze bounds
// These are private since no one outside the class should be changing the grid
void Grid::set(int new_item, Point location)
{
    set(new_item, location.x, location.y);
}
