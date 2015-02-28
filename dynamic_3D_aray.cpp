#include <iostream>
using std::cout;
using std::cin;

int main() {
  int dim1, dim2, dim3;
  cout << "Enter the three dimensions separated by a space and press enter:";
  cin >> dim1 >> dim2 >> dim3;

  // Allocate array
  int *** ipppArray = new int**[dim1];
  for( int i = 0; i < dim1; i++ ) {
    ipppArray[i] = new int*[dim2];
    for( int j = 0; j < dim2; j++ ) {
      ipppArray[i][j] = new int[dim3];
    }
  }
  
  // Fill array:
  cout << "Enter elements separated by a space and press enter: ";
  for( int i = 0; i < dim1; i++ ) {
    for( int j = 0; j < dim2; j++ ) {
      for( int k = 0; k < dim3; k++ ) {
        cin >> ipppArray[i][j][k];
      }
    }
  }

  // Print array:
  cout << "Array: \n";
  for( int i = 0; i < dim1; i++ ) {
    for( int j = 0; j < dim2; j++ ) {
      for( int k = 0; k < dim3; k++ ) {
       cout << " [" << i << "," << j << "," << k << "]=" << ipppArray[i][j][k];
      }
      cout << "\n";
    }
    cout << "\n";
  }

  // Deallocate:
  for( int i = 0; i < dim1; i++ ) {
    for( int j = 0; j < dim2; j++ ) {
      delete [] ipppArray[i][j];
    }
    delete [] ipppArray[i];
  }
  delete [] ipppArray;

  return 0;
}

