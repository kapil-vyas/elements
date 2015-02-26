#include <iostream>
using std::cout;
const int LEN=2;
const int ROWS=LEN;
const int COLS=LEN;
typedef int Array[ROWS][COLS];

const int R = 0; // Upper
const int D = 1; // Down
const int L = 1; // Left
const int U = 1; // Up

void rotate_matrix(Array matrix) {
  for( int i = 0; i < LEN/2; i++ ) {
    i = 0;
    int j = 1;
    int state = R;
    while( i != 0 || j != 0 ) {
      cout << i << " " << j << "\n";
      if( state == R ) j++;
      if( j == LEN ) {
        state = D;
        j--; // fix index
        i++;
        cout << i << " " << j << "\n";
      }
      if( state == D ) i++;
      if( i == LEN ) {
        state = L;
        i--; // fix index
        j--;
        cout << i << " " << j << "\n";
      }
      if( state == L ) j--;
      if( j > 0 ) {
        state = U;
        j++; // fix index
        i--;
        cout << i << " " << j << "\n";
      }
      if( state == U ) i--;
      if( j > 0 ) {
        state = U;
        i++; // fix index
        j++;
        cout << i << " " << j << "\n";
      }
      break;
    } 
    break;
  }
}

void print_matrix(const Array matrix) {
  for( int i = 0; i < ROWS; i++ ) {
    for( int j = 0; j < COLS; j++ ) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int matrix[2][2] = { {1, 2}, {3, 4} };
  print_matrix(matrix);
  rotate_matrix(matrix);
  print_matrix(matrix);
  return 0;
}
