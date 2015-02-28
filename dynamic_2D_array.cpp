#include <iostream>
using std::cout;
using std::cin;

int main() {
  int rows, cols;
  cout << "Num of Rows: ";
  cin >> rows;
  cout << "Num of Cols: ";
  cin >> cols;

  // Allocate array
  int ** array = new int*[rows];
  for( int i = 0; i < rows; i++ ) {
    array[i] = new int[cols];
  }
  
  // Fill array:
  cout << "Enter elements separated by a space and press enter: ";
  for( int row = 0; row < rows; row++ ) {
    for( int col = 0; col < cols; col++ ) {
      cin >> array[row][col];
    }
  }

  // Print array:
  cout << "Array: \n";

  for( int row = 0; row < rows; row++ ) {
    for( int col = 0; col < cols; col++ ) {
      cout << " [" << row << "," << col << "]=" << array[row][col];
    }
  }
  cout << "\n";

  // Deallocate:
  for( int row = 0; row < rows; row++ ) {
    delete [] array[row];
  }
  delete [] array;

  return 0;
}

