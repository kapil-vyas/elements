#include <iostream>
using std::cout;
using std::string;
typedef char * ArrayString;
using std::strcpy;

ArrayString createString(string value, int length) {
  ArrayString array = new char[length];
  strcpy(array, value.c_str());
  return array;
}

// length function returns the length of the input string and
// not the size of the input string
// Say, input = char[5];       --> size is 5
// input = {'a','b','c','d',0} --> size is 5, but length is 4
int length(const ArrayString input) {
  int count = 0;
  while( input[count] != 0 ) {
    count++;
  }
  return count; 
}

void printString(const ArrayString input, int length) {
  for(int i = 0; i < length; i++) {
    cout << input[i];
  }
  cout << "\n";
}

bool equal(const ArrayString input, const ArrayString compare) {
  int length_input = length(input)+1; // To account for NULL char
  int length_compare = length(compare)+1;
  if( length_input != length_compare ) return false;
  for(int i = 0; i < length_input; i++ ) {
    if( input[i] != compare[i] )
      return false;
  }
  return true;
}

ArrayString reverseString(ArrayString input, int size) {
  int length = size-1;
  ArrayString array = new char[size];
  for(int i = 0; i < length; i++) {
    array[length-i] = input[i];
  }
  array[size] = '\0';
  return array;
}

int main() {
  ArrayString array = createString("abcd", 4);
  cout << "New string: ";
  printString(array, 5);
  ArrayString actualString = reverseString(array, 5);
  cout << "Actual string: ";
  printString(actualString, 5);
  cout << "Lenght 1: " << length(actualString);
  ArrayString expectedString = createString("dcba", 4);
  cout << "Expected string: ";
  printString(expectedString, 5);
  cout << "Lenght 2: " << length(expectedString);
  if(equal(actualString, expectedString)) {
    cout << "Test 1 Passed\n";
  }
  else {
    cout << "Test 1 Failed\n";
  }
  return 0;
}
