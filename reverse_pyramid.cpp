#include <iostream>
#include "stdlib.h"
using std::cout;

// Program generates reverse-pyramid pattern
// Note j is from -4 to +4         
// Algorithm:
//  if j=0 ignore, 
//  if i+1-|j|>0 print #, 
//  if i+1-|j|<=0 print space
// Analysis:
//            i  i+1-|j|  j=[432101234]
// 1 ######## 4    5-|j|  :  123454321
// 2  ######  3    4-|j|  :  012343210 
// 3   ####   2    3-|j|  :  -0123210-
// 4    ##    1    2-|j|  :  --01210--

int main() {
  for( int i = 4; i >= 1; i-- ) {
    for( int j = -4; j <= 4; j++ ) {
      if( j == 0 )
        continue;
      int result = i+1-abs(j);
      if( result > 0 ) 
        cout << "#";
      else 
        cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
