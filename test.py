import time
import numpy as np
from sudoku_solver import PySudokuGrid

start_time = time.time()

gridToSolve = np.array([[0, 0, 0, 0, 0, 0, 0, 0, 0],
                        [0, 0, 0, 0, 0, 3, 0, 8, 5],
                        [0, 0, 1, 0, 2, 0, 0, 0, 0],
                        [0, 0, 0, 5, 0, 7, 0, 0, 0],
                        [0, 0, 4, 0, 0, 0, 1, 0, 0],
                        [0, 9, 0, 0, 0, 0, 0, 0, 0],
                        [5, 0, 0, 0, 0, 0, 0, 7, 3],
                        [0, 0, 2, 0, 1, 0, 0, 0, 0],
                        [0, 0, 0, 0, 4, 0, 0, 0, 9]])

puzzle = PySudokuGrid(gridToSolve)
print(np.array(puzzle.get_grid()))
puzzle.solve()
print(np.array(puzzle.get_grid()))
print("--- %s seconds ---" % (time.time() - start_time))
