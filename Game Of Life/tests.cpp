#include <cassert>
#include "Grid.h"
#include <iostream>


void test_countAliveNeighbors() {
    Grid grid = {
        {false, true,  false},
        {true,  true,  false},
        {false, false, true}
    };

    assert(countAliveNeighbors(grid, 1, 1) == 3);
    assert(countAliveNeighbors(grid, 0, 0) == 3); 
    assert(countAliveNeighbors(grid, 2, 2) == 1); 
    std::cout << "test_countAliveNeighbors passed\n";
}

void test_updateGrid_birth_rule() {
    Grid grid = {
        {false, true,  false},
        {true,  false, true},
        {false, false, false}
    };

    Grid updated = updateGrid(grid, 3, 2, 3); 

    assert(updated[1][1] == true);

    std::cout << "test_updateGrid_birth_rule passed\n";
}

void test_updateGrid_survival_rule() {
    Grid grid = {
        {false, true,  false},
        {true,  true,  false},
        {false, false, false}
    };

    Grid updated = updateGrid(grid, 3, 2, 3); 


    assert(updated[1][1] == true);

    assert(updated[1][0] == true);

    assert(updated[0][1] == true);

    std::cout << "test_updateGrid_survival_rule passed\n";
}

void test_updateGrid_death_rule() {
    Grid grid = {
        {false, false, false},
        {true,  true,  true},
        {false, false, false}
    };

    Grid updated = updateGrid(grid, 3, 2, 2); 


    assert(updated[1][1] == true);

    assert(updated[1][0] == false);
    assert(updated[1][2] == false);

    std::cout << "test_updateGrid_death_rule passed\n";
}

int main() {
    test_countAliveNeighbors();
    test_updateGrid_birth_rule();
    test_updateGrid_survival_rule();
    test_updateGrid_death_rule();

    std::cout << "\nAll unit tests passed!\n";
    return 0;
}
