#include <iostream>
#include <cstring>
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

void printString(string text, const ArrayString input, int length) {
  cout << text;
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

void reverseString(ArrayString& array, int size) {
  for(int i = 0; i < (size-1)/2; i++) {
    cout << "> " << array[i] << " < " << array[size-1-i] << "\n";
    int temp = array[i];
    array[i] = array[size-1-i];
    array[size-1-i] = temp;
  }
}

int main() {
  ArrayString array1 = createString("abcd", 4);
  printString("Array 1 Before: ", array1, 4);
  reverseString(array1, 4);
  printString("Array 1 After: ", array1, 4);
  ArrayString array1_expected = createString("dcba", 4);
  if(equal(array1, array1_expected)) {
    cout << "Test 1 Passed\n";
  }
  else {
    cout << "Test 1 Failed\n";
  }
  ArrayString array2 = createString("abcde", 5);
  printString("Array 2 Before: ", array2, 5);
  reverseString(array2, 5);
  printString("Array 2 After: ", array2, 5);
  ArrayString array2_expected = createString("edcba", 5);
  if(equal(array2, array2_expected)) {
    cout << "Test 2 Passed\n";
  }
  else {
    cout << "Test 2 Failed\n";
  }
  return 0;
}
