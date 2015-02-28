#include <iostream>
using std::cout;
const int LEN=3;
const int ROWS=LEN;
const int COLS=LEN;
typedef int Array[ROWS][COLS];

const int R = 0; // Upper
const int D = 1; // Down
const int L = 2; // Left
const int U = 3; // Up

void print_state(int state) {
  if( state == 0 ) cout << "R";
  if( state == 1 ) cout << "D";
  if( state == 2 ) cout << "L";
  if( state == 3 ) cout << "U";
}

void print_index_chain(int state, int i, int j, Array matrix, int& prev_value) {
  if( i != -1 && j != -1 && i != LEN && j != LEN ) {
    cout << "State: ";
    print_state(state);
    cout << " Before: [" << i << "," << j << "]=" << matrix[i][j];
    int temp = prev_value;
    prev_value = matrix[i][j];
    matrix[i][j] = temp;
    cout << " Now: [" << i << "," << j << "]=" << matrix[i][j] << "\n";
  }
}

//    -10
//     00 01 02 03
//     10 11 12
// 2-1 20 21 22
//           32
//
void rotate_matrix(Array matrix) {
    int i = 0;
    int j = 0;
    int state = R;
    int prev_chain_value = matrix[i][j];

    do {
      // switch state
      if( j == LEN ) {
        state = D;
        j--; // fix index
      }
      if( i == LEN ) {
        state = L;
        i--; // fix index
      }
      if( j == -1 ) {
        state = U;
        j++; // fix index
      }
      if( i == -1 ) {
        state == R;
        i++; // fix index
      }

      if( state == R ) j++;
      if( state == D ) i++;
      if( state == L ) j--;
      if( state == U ) i--;

      print_index_chain(state, i, j, matrix, prev_chain_value);  
    } while( i != 0 || j != 0 );
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
  // Case 1:
  /*
  int matrix[2][2] = { {1, 2}, {3, 4} };
  print_matrix(matrix);
  rotate_matrix(matrix);
  print_matrix(matrix);
  */
  
  // Case 2:
  int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  print_matrix(matrix);
  rotate_matrix(matrix);
  print_matrix(matrix);
  return 0;
}
