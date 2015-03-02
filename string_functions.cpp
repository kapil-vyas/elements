#include <iostream>
using std::cout;
typedef char * ArrayString;

// Return new length of output string
int append(ArrayString inputString, int length, ArrayString & outputString, char charToAppend) {
  outputString = new char[length+1];
  for(int i = 0; i < length; i++)
    outputString[i] = inputString[i];
  outputString[length] = charToAppend;
  return length+1;
}

// Append destination string to source string
int concatenate(ArrayString source, ArrayString destination) {
  return 0;
}

// Returns the char at position n
bool characterAt(ArrayString arrayString, int length, int position, char & charAtPosition) {
  if( position < 0 || position >= length ) {
    return false;
  }
  charAtPosition = arrayString[charAtPosition];
  return true;
}

void testAppend() {
  char arrayString[5] = {'H', 'e', 'l', 'l', 'o'}; 
  int length = 5;
  ArrayString pArrayString = arrayString;
  ArrayString outputString;
  int newLength = append(pArrayString, length, outputString, 'w');
  for(int i = 0; i < newLength; i++)
    cout << outputString[i];
  cout << "\n";
}

void testCharacterAt() {
  char arrayString[5] = {'H', 'e', 'l', 'l', 'o'}; 
  int length = 5;
  ArrayString pArrayString = arrayString;
  char charAtPosition;

  if( characterAt(pArrayString, length, 0, charAtPosition) ) {
    if( charAtPosition == 'H' ) {
      cout << "Test1 passed\n"; 
    }
    else {
      cout << "Test1 failed\n";
    }
  }

  if( characterAt(pArrayString, length, 6, charAtPosition) ) {
      cout << "Test1 failed\n"; 
  }
  else {
      cout << "Test1 passed\n";
  }
}

int main() {
  testCharacterAt();
  testAppend();
  return 0;
}
