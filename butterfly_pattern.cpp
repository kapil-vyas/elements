#include <iostream>
using std::cout;

void expected_output() {
   cout << "#            #\n";
   cout << " ##        ## \n";
   cout << "  ###    ###  \n";
   cout << "   #######    \n";
   cout << "   #######    \n";
   cout << "  ###    ###  \n";
   cout << " ##        ## \n";
   cout << "#            #\n";
}
// Representing as a 7x4 image
// Key: Space by numbers and # by commas:
// #234567
// 1##4567
// 12###67
// 123####

//         i Spaces # for count of i's
// 0,6   = 1 0      1 x
// 1,,4  = 2 1      2
// 2,,:,2 = 3 2      3
// 3,,,, = 4 3      4
//           i>j    j>=i
//
int main() {
  for(int i = 1; i <= 4; i++ ) {
    int count = 1;
    for( int j = 1; j <= 7; j++ ) {
      if( i > j )
        cout << " ";
      if( j >= i && count <= i ) {
        cout << "#";
        count++;
      }
    }
    cout << "\n";
  }
  expected_output();
  return 0;
}
