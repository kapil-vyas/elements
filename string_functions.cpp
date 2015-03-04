#include <iostream>
using std::cout;
typedef char * ArrayString;

int length(ArrayString input) {
  int count = 0;
  while( input[count] != 0 ) {
    count++;
  }
  return count+1; // Plus 1 for null terminating char
}

bool equal(ArrayString input, ArrayString compare) {
  int length_input = length(input);
  int length_compare = length(compare);
  if( length_input != length_compare ) return false;
  for(int i = 0; i < length_input; i++ ) {
    if( input[i] != compare[i] )
      return false;
  }
  return true;
}

void append(ArrayString& inputString, char charToAppend) {
  int oldLength = length(inputString); 
  int newLength = oldLength+1;
  ArrayString temp = new char[newLength];
  for(int i = 0; i < oldLength; i++)
    temp[i] = inputString[i];
  delete [] inputString;
  temp[newLength-2] = charToAppend;
  temp[newLength-1] = 0; 
  inputString = temp;
}

void testAppend() {
  ArrayString arrayString1 = new char[6];
  arrayString1[0] = 'H';
  arrayString1[1] = 'e';
  arrayString1[2] = 'l';
  arrayString1[3] = 'l';
  arrayString1[4] = 'o';
  arrayString1[5] = 0;
  append(arrayString1, 'w');

  char arrayTest1[7] = {'H', 'e', 'l', 'l', 'o', 'w', 0};
  if( equal(arrayString1, arrayTest1)) {
    cout << "Append Test 1 passed\n";
  }
  else {
    cout << "Append Test 1 failed\n";
  }

  ArrayString arrayString2 = new char[4];
  arrayString2[0] = 'P';
  arrayString2[1] = 'i';
  arrayString2[2] = 'n';
  arrayString2[3] = 0;
  append(arrayString2, 'e');
  char arrayTest2[5] = {'P', 'i', 'n', 'e', 0};
  if( equal(arrayString2, arrayTest2)) { 
    cout << "Append Test 2 passed\n"; 
  }
  else {
    cout << "Append Test 2 failed\n";
  }

  ArrayString emptyString = new char[1];
  emptyString[0] = 0;
  append(emptyString, 'z');
  
  char arrayTest3[2] = {'z', 0};
  if( equal(emptyString, arrayTest3)) {
    cout << "Append Test 3 passed\n";
  }
  else {
    cout <<"Append Test 3 failed\n";
  }

  // clean up
  delete [] arrayString1;
  delete [] arrayString2;
  delete [] emptyString;
}

void concatenate(ArrayString& source, ArrayString stringToAppend) {
  int sourceLength = length(source);
  int stringToAppendLength = length(stringToAppend);
  int newLength = sourceLength+stringToAppendLength-1;
  ArrayString temp = new char[newLength]; 
  for(int i = 0; i < sourceLength-1; i++) {
    temp[i] = source[i];
  }
  for(int i = 0; i < stringToAppendLength-1; i++) {
    temp[i+sourceLength-1] = stringToAppend[i];
  }
  temp[newLength-1] = 0;
  delete [] source;
  source = temp;
}

void testConcatenate() {
  ArrayString source = new char[6];
  source[0] = 'H';
  source[1] = 'e';
  source[2] = 'l';
  source[3] = 'l';
  source[4] = 'o';
  source[5] = 0;

  ArrayString append = new char[5];
  append[0] = 'w';
  append[1] = 'e';
  append[2] = 'e';
  append[3] = 'n';
  append[4] = 0;
  concatenate(source, append);

  char arrayTest1[10] = {'H','e','l','l','o','w','e','e','n',0};
  if( equal(source, arrayTest1)) {
    cout << "Concatenate Test 1 passed\n";
  }
  else {
    cout << "Concatenate Test 1 failed\n";
  }
}

char characterAt(ArrayString arrayString, int position) {
  return arrayString[position];
}

void testCharacterAt() {
  ArrayString arrayString1 = new char[6];
  arrayString1[0] = 'H';
  arrayString1[1] = 'e';
  arrayString1[2] = 'l';
  arrayString1[3] = 'l';
  arrayString1[4] = 'o';
  arrayString1[5] = 0;

  if( characterAt(arrayString1, 0) == 'H' )
      cout << "CharacterAt Test1 passed\n"; 
  else 
      cout << "CharacterAt Test1 failed\n"; 
}

int main() {
  testCharacterAt();
  testAppend();
  testConcatenate();
  return 0;
}
