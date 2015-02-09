#include <iostream>
#include <stdlib.h>
#include "math.h"
using std::cin;
using std::cout;

int main() {
  for(int i=3;i>=-3;i--) {
    for(int j=1;j<=4-abs(i);j++) {
      cout << ">";
    }
    cout << "\n";
  }
  /*
	for(int i=-3;i<=3;i++) {
    cout << 4-abs(i) << "\n";
	}
  */
  /*
  for(int i=-3;i<=3;i++) {
    cout << abs(i)+1 << "\n";
	}
  */
	return 0;
}

