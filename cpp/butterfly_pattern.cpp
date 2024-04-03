#include <iostream>
using std::cout;

void expected_output() {
   cout << "#            #\n";
   cout << " ##        ## \n";
   cout << "  ###    ###  \n";
   cout << "   ########   \n";
   cout << "   ########   \n";
   cout << "  ###    ###  \n";
   cout << " ##        ## \n";
   cout << "#            #\n";
}

//Key: 
//  s -> count of space characters
//    # -> count of # characters
//  s # s s # s
//  0 1 6 6 1 0
//  1 2 4 4 2 1
//  2 3 2 2 3 2
//  3 4 0 0 4 3
//  3 4 0 0 4 3
//  2 3 2 2 3 2
//  1 2 4 4 2 1
//  0 1 6 6 1 0

void pattern(int i) {
  for( int a = 1; a <= i-1; a++ )
    cout << " ";
  for( int b = 1; b <= i; b++ )
    cout << "#";
  for( int c = 1; c <= (4-i)*4; c++ )
    cout << " ";
  for( int d = 1; d <= i; d++ )
    cout << "#";
  for( int e = 1; e <= i-1; e++ )
    cout << " ";
}
  
int main() {
  for(int i = 1; i <= 4; i++ ) {
    pattern(i);
    cout << "\n";
  }
  for(int i = 4; i >= 1; i-- ) {
    pattern(i);
    cout << "\n";
  }
  expected_output();
  return 0;
}
