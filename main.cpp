#include <iostream>

int main() {
    std::string choice;
    std::string filename;

    std::cout << "Solving a Sudoku puzzle using recursive backtracking\n" << std::endl;

    do {
        std::cout << "Please enter name of file containing the puzzle";
        std::cin >> filename;

        Solver newGrid(filename);
        std::cout << "\nGiven this board:" << std::endl;
        newGrid.printGrid();

        std:: cout << "\nThe solved board would be: ";
        newGrid.solve();

        std::cout << "\nDo you want to solve another grid? (Y|N)" << std::endl;
        std::cin >> choice;

    }   while(choice.at(0)=='Y' || choice.at(0)=='y');
    return 0;
}
