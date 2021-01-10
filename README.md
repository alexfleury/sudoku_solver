# sudoku_solver

Solving a sudoku puzzle with python and a c++ shared library. The python script is used to inferface with the user. The c++ code use the brute-forecesearch method to solve an incomplete sudoku grid (more information [here](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms#Backtracking "Backtracking on Wikipedia")).

Files required:
1. SudokuGrid.hpp;
2. SudokuGrid.cpp;
3. sudoku_solver.pyx.

### Installation

The shared library can be generated with the command:

```bash
python setup.py build_ext --inplace
```

An example of usage is in test.py. This repository is still under development.

### TO DO

* GUI in python;
* More comments in c++ files;
* Generate test files.
