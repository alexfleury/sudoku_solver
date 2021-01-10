#ifndef SUDOKUGRID_H_INCLUDED
#define SUDOKUGRID_H_INCLUDED

#include <vector>
#include <iostream>

/*!
  SudokuGrid.hpp
  Defines function to solve a sudoku grid by brute-force (backtracking).
  https://en.wikipedia.org/wiki/Sudoku_solving_algorithms

  @author Alexandre Fleury
  @version Apr 2018
 */

namespace solver{

  class SudokuGrid{

    public:
    // Public methods.
    SudokuGrid(std::vector<std::vector<int> >gridToSolve);
    ~SudokuGrid();
    void solve();
    std::vector<std::vector<int> >get_grid();

    private:
    // Attribute.
    std::vector<std::vector<int> >grid;

    // Private methods. Thos should not be used by the user.
    void checkEmpty(unsigned int *emptyRows, unsigned int *emptyCols);
    bool cellIsValid(unsigned int row, unsigned int col);
    unsigned int identifySubCell(unsigned int index);
    bool isValueAlreadyInArray(unsigned int val, unsigned int *arr,
    unsigned int size);
  };
}
#endif // ifndef SUDOKUGRID_H_INCLUDED
