// Break streaming digits separated by commas into individual numbers
#include <iostream>
using std::cin;
using std::cout;

int main() {
  char digit = cin.get();
  while( digit != '\n') {
    int count = 0;
    int number = 0;
    if( digit != ',') {
      if( count > 1 )
        number = number*10+(int(digit-'0'));
      else {
        number = int(digit-'0');
        cout << "Count: " << count << "\n";
      }
      count++;
    }
    else {
      cout << "Number: " << number << "\n";
      count = 0;
    }
    digit = cin.get();
  }
	return 0;
}

