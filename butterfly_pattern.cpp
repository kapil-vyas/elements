#include <iostream>
using std::cout;

// Representing as a 7x4 image
// Key: Space by numbers and # by commas:
// #234567 TOP layer
// 1##4567 SEC layer
// 12###67 THI layer
// 123#### BOT layer
const int TOP = 1;
const int SEC = 2;
const int THI = 3;
const int BOT = 4;

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

void layer(int layer) {
  int count = 1;
  int j = 1;
  while( j <= 7 ) {
    if( layer > j )
      cout << " ";
    else if( j >= layer && count <= layer ) {
      cout << "#";
      count++;
    }
    else 
      cout << " ";
    j++;
  }
}

void reverse_layer(int layer) {
  int count = 8-layer;
  int j = 7;
  while( j >= 1 ) {
    if( layer > j )
      cout << " ";
    else if( j >= layer && count <= layer ) {
      cout << "#";
    }
    else {
      cout << " ";
      count--;
    }
    j--;
  }
}

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
