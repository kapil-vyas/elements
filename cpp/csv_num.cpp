// Break streaming digits separated by commas into individual numbers
#include <iostream>
using std::cin;
using std::cout;

int main() {
  char digit = cin.get();
  int prev_num = 0;
  int number = 0;

  while( digit != '\n') {
    if( digit != ',') {
        number = prev_num*10+(int(digit-'0'));
        prev_num = number;
    }
    else {
      cout << "Number: " << number << "\n";
      prev_num = 0;
    }
    digit = cin.get();
  }
  cout << "Number: " << number << "\n";
	return 0;
}
