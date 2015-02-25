#include <iostream>
using std::cout;

const int R = 0; // Upper
const int D = 1; // Down
const int L = 1; // Left
const int U = 1; // Up

int * rotate_matrix(int * matrix, int n) {
  for( int i = 0; i < n/2; i++ ) {
    i = 0;
    int j = 0;
    int state = R;
    while( i == 0 || j == 0 ) {
      if( state == R ) j++;
      if( j > n ) {
        state = D;
        j--; // fix index
        i++;
      }
      if( state == D ) i++;
      if( i > n ) {
        state = L;
        i--; // fix index
        j--;
      }
      if( state == L ) j--;
      if( j > 0 ) {
        state = U;
        j++; // fix index
        i--;
      }
      if( state == U ) i--;
    }
  }
  return matrix;
}

int main() {
  int matrix[2][2] = { {1, 2}, {3, 4} };
  int length = 2;
  for( int i = 0; i < length; i++ ) {
    for( int j = 0; j < length; j++ ) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
