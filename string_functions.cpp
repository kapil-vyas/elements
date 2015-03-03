#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::string;
using std::strcpy;
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
int concatenate(ArrayString source, int sourceLength, ArrayString dest, int destLength) {
  int totalLength = sourceLength+destLength;
  char * temp = new char[totalLength]; 
  for(int i = 0; i < sourceLength; i++) {
    temp[i] = source[i];
  }
  for(int i = 0; i < destLength; i++) {
    temp[sourceLength+i] = dest[i];
  }
  source = temp;
  cout << temp << "\n";
  return totalLength;
}

// Returns the char at position n
bool characterAt(ArrayString arrayString, int length, int position, char & charAtPosition) {
  if( position < 0 || position >= length ) {
    return false;
  }
  charAtPosition = arrayString[charAtPosition];
  return true;
}

void testConcatenate() {
  string sourceString = "Hello"; 
  string appendString = "Pin"; 
  char source[sourceString.length()+1];
  strcpy(source, sourceString.c_str());
  char append[appendString.length()+1];
  strcpy(append, appendString.c_str());

  int sourceLength = 5;
  int appendLength = 3;
  concatenate(source, sourceLength, append, appendLength);
  //cout << source << "\n";
}

void testAppend() {
  char arrayString1[5] = {'H', 'e', 'l', 'l', 'o'}; 
  int length = 5;
  ArrayString outputString;
  append(arrayString1, length, outputString, 'w');
  cout << outputString << "\n";

  char arrayString2[3] = {'P', 'i', 'n'}; 
  length = 3;
  append(arrayString2, length, outputString, 'e');
  cout << outputString << "\n";

  delete [] outputString;
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
  testConcatenate();
  return 0;
}
