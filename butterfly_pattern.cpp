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
// #234567 TOP layer
// 1##4567 SEC layer
// 12###67 THI layer
// 123#### BOT layer
//
// Full Pattern
// *laying bricks based on above layer scheme*
//  TOP - TOP REVERSED
//  SEC - SEC REVERSED
//  THI - THI REVERSED
//  BOT - BOT REVERSED
//  BOT - BOT REVERSED
//  THI - THI REVERSED
//  SEC - SEC REVERSED
//  TOP - TOP REVERSED
//
//         i Spaces # for count of i's
// 0,6   = 1 0      1 x
// 1,,4  = 2 1      2
// 2,,,2 = 3 2      3
// 3,,,, = 4 3      4
//           i>j    j>=i
//

const int TOP = 1;
const int SEC = 2;
const int THI = 3;
const int BOT = 4;

void layer(int layer) {
  int count = 1;
  int j = 1;
  while( j <= 7 ) {
    if( layer > j )
      cout << " ";
    if( j >= layer && count <= layer ) {
      cout << "#";
      count++;
    }
    if( count > layer )
      cout << " ";
    j++;
  }
}
//  1234567 7654321
//1 #234567 765432# TOP layer
//2 1##4567 7654##1 SEC layer
//3 12###67 76###21 THI layer
//4 123#### ####321 BOT layer
void reverse_layer(int layer) {
  int count = 8-layer;
  int j = 7;
  while( j >= 1 ) {
    if( layer > j )
      cout << " ";
    if( j >= layer && count <= layer ) {
      cout << "#";
    }
    if( count > layer ) {
      cout << " ";
      count--;
    }
    j--;
  }
}

int main() {
  for(int i = 1; i <= 4; i++ ) {
    layer(i);  
    reverse_layer(i);  
    cout << "\n";
  }
  for(int i = 4; i >= 1; i-- ) {
    layer(i);  
    reverse_layer(i);  
    cout << "\n";
  }
  expected_output();
  return 0;
}
