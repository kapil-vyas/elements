#include <iostream>
#include <cstring>
using namespace::std;

void printString(string text, const char * input) {
  cout << text << input << "\n";
}

void reverseString(char * array, int size) {
  for(int i = 0; i < (size-1)/2; i++) {
    cout << "> " << array[i] << " < " << array[size-2-i] << "\n";
    int temp = array[i];
    array[i] = array[size-2-i];
    array[size-2-i] = temp;
  }
}

int main() {
  // Test 1 
  char array1[5] = {'a', 'b', 'c', 'd', '\0'};
  printString("Array 1 Before: ", array1);
  reverseString(array1, 5);
  printString("Array 1 After: ", array1);
  char array1_expected[5] = {'d', 'c', 'b', 'a', '\0'};
  if(strcmp(array1, array1_expected) == 0) {
    cout << "Test 1 Passed\n";
  }
  else {
    cout << "Test 1 Failed\n";
  }

  // Test 2
  char array2[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
  printString("Array 2 Before: ", array2);
  reverseString(array2, 6);
  printString("Array 2 After: ", array2);
  char array2_expected[6] = {'e', 'd', 'c', 'b', 'a', '\0'};
  if(strcmp(array2, array2_expected) == 0) {
    cout << "Test 2 Passed\n";
  }
  else {
    cout << "Test 2 Failed\n";
  }
  return 0;
}
