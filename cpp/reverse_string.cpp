#include <iostream>
#include <cstring>
using namespace::std;

void reverseString(char * array) {
  int size = strlen(array)+1;
  for(int i = 0; i < (size-1)/2; i++) {
    int temp = array[i];
    array[i] = array[size-2-i];
    array[size-2-i] = temp;
  }
}

int main() {
  // Test 1 
  char array1[5] = {'a', 'b', 'c', 'd', '\0'};
  reverseString(array1);
  char array1_expected[5] = {'d', 'c', 'b', 'a', '\0'};
  if(strcmp(array1, array1_expected) == 0) {
    cout << "Test 1 Passed\n";
  }
  else {
    cout << "Test 1 Failed\n";
  }

  // Test 2
  char array2[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
  reverseString(array2);
  char array2_expected[6] = {'e', 'd', 'c', 'b', 'a', '\0'};
  if(strcmp(array2, array2_expected) == 0) {
    cout << "Test 2 Passed\n";
  }
  else {
    cout << "Test 2 Failed\n";
  }
  return 0;
}
