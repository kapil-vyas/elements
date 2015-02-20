#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::cin;
using std::string;
using std::strcpy;

bool is_unique(char * input, int length) {
  int ascii_array[128];
  // Initialize to zero count:
  for( int i = 0; i < 128; i++ ) {
    ascii_array[i] = 0;
  }

  for( int i = 0; i < length; i++ ) {
    ascii_array[int(input[i])]++;
    cout << input[i] << ":" << ascii_array[int(input[i])] << "\n";
  }

  for( int i = 0; i < 128; i++ ) {
    if( ascii_array[i] > 1 ) 
      return false;
  }
  return true;
}

void print(bool value) {
  if( value )
    cout << "Unique\n";
  else
    cout << "Not Unique\n";
}

void test() {
  char input2[5] = {'H', 'e', 'l', 'i', 'o'};
  print(is_unique(input2 , 5));
  char input3[1] = {'H'};
  print(is_unique(input3 , 1));
  char input4[0] = {};
  print(is_unique(input4 , 0));
  char input5[4] = {'L', 'a', 'l', 'l'};
  print(is_unique(input5 , 4));
}
int main() {
  test();
  string input;
  cin >> input;

  char * cstr = new char[input.length()+1];
  std::strcpy(cstr, input.c_str());
  print(is_unique(cstr, input.length()));

  delete[] cstr;
  return 0;
}
