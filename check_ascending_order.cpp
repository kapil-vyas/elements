#include <iostream>
using std::cin;
using std::cout;

int main() {
  int number;
  int next_number = -1;
  bool ascending = true;
  cout << "Enter -1 to Stop Program\n";
  
  while(true) {
    cout << "Enter number: ";
    cin >> number;
    if( number == -1 ) {
      break;
    }

    cout << "Enter number: ";
    cin >> next_number;
    if( next_number == -1 ) {
      break;
    }
    if( number <= next_number ) {
      ascending = true;
    }
    else {
      ascending = false;
    } 
    number = next_number;
  } 
  if( number == -1 && next_number == -1 ) {
    cout << "Program Stopped\n";
    return 0;
  }
  if( ascending )
    cout << "Ascending\n";
  else 
    cout << "Not Ascending\n";
  return 0;
}
