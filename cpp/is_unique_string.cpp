#include <iostream>
#include <string>
#include <cstring>
using namespace::std;

void print(bool value) {
  if( value )
    cout << "Unique\n";
  else
    cout << "Not Unique\n";
}

void print_array(char * array) {
  cout << array << "\n";
}

bool is_unique_without_datastr(char * input, int length) {
  // without data structure
  // sort the array
  int start = 0;
  int end = length - 1;
  for( int i = start+1; i <= end; i++ ) {
    for( int j = i; j > start && input[j-1] > input[j]; j-- ) {
      int temp = input[j-1];
      input[j-1] = input[j];
      input[j] = temp;
    }
  }
  print_array(input);
  
  // check for consecutive occurences of a character
  int curr_char = input[0];
  for( int i = 1; i < length; i++ ) {
    if( curr_char == input[i] )
      return false;
    else {
      curr_char = input[i];
    }
  }
  return true;
}

bool is_unique(char * input) {
  int length = strlen(input);
  int ascii_array[128] = {0};

  for( int i = 0; i < length; i++ ) {
    ascii_array[int(input[i])]++;
    cout << input[i] << ":" << ascii_array[int(input[i])] << "\n";
    if( ascii_array[input[i]] > 1 ) 
      return false;
  }
  return true;
}

int main() {
  char input1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
  print(is_unique(input1));
  char input2[6] = {'H', 'e', 'l', 'i', 'o', '\0'};
  print(is_unique(input2));
  char input3[2] = {'H', '\0'};
  print(is_unique(input3));
  char input4[1] = {'\0'};
  print(is_unique(input4));
  char input5[5] = {'L', 'a', 'l', 'l', '\0'};
  print(is_unique(input5));
  return 0;
}
