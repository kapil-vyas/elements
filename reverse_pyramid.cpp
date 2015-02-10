#include <iostream>
using std::cout;

// Program generates reverse-pyramid pattern
// Key: 
// h = hash count
// s = total space count
// e = edge space count
// Width 8    h s e e i.2 4-i
// 1 ######## 8 0 0 0 4.2 4-4 0
// 2  ######  6 2 1 1 3.2 4-3 1
// 3   ####   4 4 2 2 2.2 4-2 2
// 4    ##    2 6 3 3 1.2 4-1 3

int main() {
  cout << "h" << " " << "e\n";
  for( int i = 4; i >= 1; i-- ) {
    for( int j = 1; j <= i*2; j++ ) {
      for( int k = 4-i; k < 4; k++ ) {
        cout << " ";
      }
      cout << "#";
    }
    cout << "\n";
  }
  return 0;
}
