#include <iostream>
using std::cout;
const int LEN=4;
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

void print_index_chain(int left_edge, int right_edge, int state, int i, int j, Array matrix, int& prev_value) {
  if( i != left_edge && j != left_edge && i != right_edge && j != right_edge ) {
    cout << "State: ";
    print_state(state);
    cout << " Before: [";
    cout << i << "," << j << "]=" << matrix[i][j];
    int temp = prev_value;
    prev_value = matrix[i][j];
    matrix[i][j] = temp;
    cout << " Now: [" << i << "," << j << "]=" << matrix[i][j] << "\n";
  }
}

// [3x3]
//    -10
//     00 01 02 03
//     10 11 12
// 2-1 20 21 22
//           32
//
// [4x4]
//    -10
//     00 01 02 03 04
//     10 11 12 13
//     20 21 22 23
// 3-1 30 31 32 33
//              43 
//
void rotate_matrix(Array matrix) {
  int bounds = LEN+1;
  for( int loop = 0; loop < LEN/2; loop++ ) {
    int i = loop;
    int j = loop;
    int state = R;
    int prev_chain_value = matrix[i][j];
    bounds -= 1;

    do {
      // switch state
      if( j == bounds ) {
        state = D;
        j--; // fix index
      }
      if( i == bounds ) {
        state = L;
        i--; // fix index
      }
      if( j == loop-1 ) {
        state = U;
        j++; // fix index
      }
      if( i == loop-1 ) {
        state == R;
        i++; // fix index
      }

      if( state == R ) j++;
      if( state == D ) i++;
      if( state == L ) j--;
      if( state == U ) i--;

      print_index_chain(loop-1, bounds, state, i, j, matrix, prev_chain_value);  
    } while( i != loop || j != loop );
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
  // Case 1:
  /*
  int matrix[1][1] = { {1} };
  print_matrix(matrix);
  rotate_matrix(matrix);
  print_matrix(matrix);
  */

  // Case 2:
  /*
  int matrix[2][2] = { {1, 2}, {3, 4} };
  print_matrix(matrix);
  rotate_matrix(matrix);
  print_matrix(matrix);
  */
  
  // Case 3:
  /*
  int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  print_matrix(matrix);
  rotate_matrix(matrix);
  print_matrix(matrix);
  */
  
  // Case 4:
  int matrix[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
  print_matrix(matrix);
  rotate_matrix(matrix);
  print_matrix(matrix);
  return 0;
}
