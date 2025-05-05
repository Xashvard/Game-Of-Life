#pragma once
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>

using Grid = std::vector<std::vector<bool>>;

void printGrid(const Grid& grid);
int countAliveNeighbors(const Grid& grid, int x, int y);
Grid updateGrid(const Grid& current, int birthNum, int surviveMin, int surviveMax);
void initializeGrid(Grid& grid, int& rows, int& cols);
void waitForEnter();
int checkinputfornumber(int input);

#endif // CATIFY_H
