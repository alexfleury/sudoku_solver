#include "SudokuGrid.hpp"

using namespace solver;

// Constructor.
SudokuGrid::SudokuGrid(std::vector<std::vector<int> >gridToSolve)
{
  grid = gridToSolve;
}

// Destructor.
SudokuGrid::~SudokuGrid(){}

// Main solving function.
void SudokuGrid::solve(){

  unsigned int emptyRows[81] = {0}, emptyCols[81] = {0};

  // Check empty cells, a.k.a where are 0s.
  SudokuGrid::checkEmpty(emptyRows, emptyCols);

  // Main loop across empty cells.
  for (unsigned int i = 0; i < 81; i++){
    if((emptyRows[i] == 0) && (emptyCols[i] == 0) && (i > 0)) break; // End?

    unsigned int row = emptyRows[i], col = emptyCols[i];

    // Increment cell value until a valid value is stored.
    do{
      grid[row][col]++;
    }while(SudokuGrid::cellIsValid(row, col) == false && grid[row][col] < 11);

    // If the value=10, restore to 0 and go back the previous cell.
    if(grid[row][col] == 10){
      grid[row][col] = 0;
      i -= 2;
    }
  }
}

// Getter for the only attributes.
std::vector<std::vector<int> > SudokuGrid::get_grid(){
  return grid;
}

// Check where the empty cells are. Stores the i,j position in a table.
void SudokuGrid::checkEmpty(unsigned int *emptyRows, unsigned int *emptyCols){
  unsigned int index = 0;

  for(unsigned int i = 0; i < 9; i++){
    for(unsigned int j = 0; j < 9; j++){

      // 0 -> empty cell.
      if(grid[i][j] == 0){
        emptyRows[index] = i;
        emptyCols[index] = j;
        index++;
      }
    }
  }
}

// Check if the number in table[row, col] can be place there.
bool SudokuGrid::cellIsValid(unsigned int row, unsigned int col){

  unsigned int numbersInRow[9], numbersInCol[9],  numbersInSubCell[9];

  // Get numbers already there in row and column.
  for(unsigned int i = 0; i < 9; i++){
    numbersInRow[i] = grid[row][i];
    numbersInCol[i] = grid[i][col];
  }

  unsigned int offsetRow = SudokuGrid::identifySubCell(row);
  unsigned int offsetCol = SudokuGrid::identifySubCell(col);

  // Get numbers already there in square.
  for(unsigned int i = 0, subId = 0; i < 3; i++){
    for(unsigned j = 0; j < 3; j++) {
      numbersInSubCell[subId] = grid[i + offsetRow][j + offsetCol];
      subId++;
    }
  }

  if(SudokuGrid::isValueAlreadyInArray(grid[row][col], // Number in row?
    numbersInRow, 9) == true){
    return false;
  }
  else if(SudokuGrid::isValueAlreadyInArray(grid[row][col], // Number in column?
    numbersInCol, 9) == true){
    return false;
  }
  else if(SudokuGrid::isValueAlreadyInArray(grid[row][col], // Number in square?
    numbersInSubCell, 9) == true){
    return false;
  }
  else{
    return true;
  }
}

// Identify in which square a value is.
unsigned int SudokuGrid::identifySubCell(unsigned int index){
  if(index < 3){
    return 0;
  }
  else if(index < 6){
    return 3;
  }
  else{
    return 6;
  }
}

// Check if a number is already in a C++ vector.
bool SudokuGrid::isValueAlreadyInArray(unsigned int val, unsigned int *arr,
                                       unsigned int size){
  unsigned int howMany = 0;

  for (unsigned int i = 0; i < size; i++){
    if(arr[i] == val) howMany++;
  }

  if(howMany == 1){
    return false;
  }
  else{
    return true;
  }
}
