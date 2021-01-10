# distutils: language = c++
# distutils: sources = SudokuGrid.cpp

"""Cython interface file for wrapping the object. """

from libcpp.vector cimport vector

# C++ interface to cython.
cdef extern from "SudokuGrid.hpp" namespace "solver":
    cdef cppclass SudokuGrid:
        SudokuGrid(vector[vector[int]]) except +
        void solve()
        vector[vector[int]] get_grid()

# Creating a cython wrapper class.
cdef class PySudokuGrid:
    cdef SudokuGrid * thisptr  # Hold a C++ instance which we're wrapping.

    def __cinit__(self, vector[vector[int]] gridToSolve):
        self.thisptr = new SudokuGrid(gridToSolve)

    def __dealloc__(self):
        del self.thisptr

    def solve(self):
        self.thisptr.solve()

    def get_grid(self):
        return self.thisptr.get_grid()
