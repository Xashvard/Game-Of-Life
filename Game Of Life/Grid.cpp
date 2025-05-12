
#include "Grid.h"
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;



void initializeGrid(Grid& grid, int& rows, int& cols) {
    cout << "\nDecide the size of your grid\n";
    cout << "Enter number of rows: ";
    rows = checkinputfornumber(rows);
    cout << "Enter number of columns: ";
    cols = checkinputfornumber(cols);

    grid = Grid(rows, vector<bool>(cols, false));
    cout << "Enter live cell coordinates as 'row col' (0-based). Type -1 -1 to stop:\n";
    int r, c;
    while (true) {
        cout << "Cell (Enter: row column): ";
        cin >> r >> c;


        if (cin.fail()) {
            cout << "Invalid input. Please enter two numbers.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (r == -1 && c == -1) break;

        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            grid[r][c] = true;
        }
        else {
            cout << "Invalid coordinates. Try again.\n";
        }
    }

}

void printGrid(const Grid& grid) {
    system("cls");
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << (grid[i][j] ? "O" : ".") << " ";
        cout << "\n";
    }
}

int countAliveNeighbors(const Grid& grid, int row, int col) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int r = row + dr, c = col + dc;
            if (r >= 0 && r < rows && c >= 0 && c < cols)
                count += grid[r][c];
        }
    }
    return count;
}

Grid updateGrid(const Grid& grid, int birthNum, int surviveMin, int surviveMax) {
    Grid newGrid = grid;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int alive = countAliveNeighbors(grid, i, j);
            if (grid[i][j]) {
                newGrid[i][j] = (alive >= surviveMin && alive <= surviveMax);
            }
            else {
                newGrid[i][j] = (alive == birthNum);
            }
        }
    }
    return newGrid;
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");
}

int checkinputfornumber(int input) {
    while (true) {
        if (cin >> input)
            break;
        else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return input;
}
