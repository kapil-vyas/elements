#include <iostream>
using std::cin;
using std::cout;

bool isdigit(char c) {
  //cout << in << " Is digit\n";
  if(c>=48 && c<=57) 
    return true;
  else
    return false;
}

int atoi(char c) {
  return int(c)-48;
}

int doubledigit(int in) {
  in *= 2;
  if( in > 9 ) {
    int ones = in % 10;
    int tens = in / 10;
    return ones+tens;
  }
  return in;
}

int main() {
  char in;
  int sum_odd = 0;
  int sum_even = 0;
  int counter = 0;

  do {
    cin.get(in);
    
    if(isdigit(in)) {
      counter += 1;
      int digit = atoi(in);

      // Odd case:
      if( counter%2 == 0) {
        int twice = doubledigit(digit);
        sum_odd += twice;
      }
      else {
        sum_odd += digit;
      }
      
      // Even case:
      if( counter%2 != 0) {
        int twice = doubledigit(digit);
        sum_even += twice;
      }
      else {
        sum_even += digit;
      }
    }
  } while(in != '\n');

  if(counter%2 == 0) {
    if(sum_even%10 == 0)
      cout << "Valid\n";
    else
      cout << "Invalid\n";
  }

  if(counter%2 != 0) {
    if(sum_odd%10 == 0)
      cout << "Valid\n";
    else
      cout << "Invalid\n";
  }
	return 0;
}

