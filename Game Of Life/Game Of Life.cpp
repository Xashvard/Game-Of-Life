#include <iostream>
#include <vector>
#include "Grid.h"

using namespace std;


int main() {
    Grid grid;
    int birthNum=0, surviveMin=0, surviveMax=0;
    int rows, cols;

    cout << "========================================\n";
    cout << "|                                      |\n";
    cout << "|             GAME OF LIFE             |\n";
    cout << "|                                      |\n";
    cout << "========================================\n";

    cout << "\nWelcome to the game of life\n";
    cout << "\nIn this version of the game you can set your own rules\n";

    waitForEnter();

    cout << "Customize your Game of Life rules!" << endl;
    cout << "How many neighbors are needed for a dead cell to be born? ";
    birthNum = checkinputfornumber(birthNum);
    cout << "Minimum number of neighbors for a live cell to survive? ";
    surviveMin = checkinputfornumber(surviveMin);
    cout << "Maximum number of neighbors for a live cell to survive? ";
    surviveMax = checkinputfornumber(surviveMax);

    initializeGrid(grid, rows, cols);

    cin.ignore(); 
    while (true) {
        printGrid(grid);
        waitForEnter();
        grid = updateGrid(grid, birthNum, surviveMin, surviveMax);
    }

    return 0;
}
