#include <iostream>
#include "string_functions.cpp"
using std::cout;

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

void testSubstring() {
  ArrayString arrayString1 = new char[6];
  arrayString1[0] = 'H';
  arrayString1[1] = 'e';
  arrayString1[2] = 'l';
  arrayString1[3] = 'l';
  arrayString1[4] = 'o';
  arrayString1[5] = 0;
  
  ArrayString substr1 = substring(arrayString1, 2, 3);

  char arrayTest1[4] = {'e', 'l', 'l', 0};
  if( equal( substr1, arrayTest1 ) ) {
    cout << "Substring Test 1 passed\n";
  }
  else {
    cout << "Substring Test 1 failed\n";
  }
  
  ArrayString substr2 = substring(arrayString1, 5, 1);
  char arrayTest2[2] = {'o', 0};
  if( equal( substr2, arrayTest2 ) ) {
    cout << "Substring Test 2 passed\n";
  }
  else {
    cout << "Substring Test 2 failed\n";
  }

  ArrayString substr3 = substring(arrayString1, 6, 1);
  char arrayTest3[1] = {0};
  if( equal( substr3, arrayTest3 ) ) {
    cout << "Substring Test 3 passed\n";
  }
  else {
    cout << "Substring Test 3 failed\n";
  }
}

int main() {
  testCharacterAt();
  cout << "\n";
  testAppend();
  cout << "\n";
  testConcatenate();
  cout << "\n";
  testSubstring();
  return 0;
}
