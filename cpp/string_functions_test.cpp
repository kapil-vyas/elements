#include <iostream>
#include <string>
#include <cstring>
#include "string_functions.cpp"
using std::cout;
using std::string;
using std::strcpy;

void testFind() {
  ArrayString arrayString1 = new char[9];
  string temp = "abcbabdc";
  strcpy(arrayString1, temp.c_str());

  ArrayString token = new char[4];
  temp = "abc";
  strcpy(token, temp.c_str());

  int count1 = find(arrayString1, token);
  if( count1 == 1 ) cout << "Find Test 1 passed\n";

  ArrayString token2 = new char[3];
  temp = "ab";
  strcpy(token2, temp.c_str());

  int count2 = find(arrayString1, token2);
  if( count2 == 2 ) cout << "Find Test 2 passed\n";
  
  ArrayString arrayString2 = new char[13];
  temp = "abcbcabcdcbc";
  strcpy(arrayString2, temp.c_str());

  ArrayString token3 = new char[3];
  temp = "bc";
  strcpy(token3, temp.c_str());

  int count3 = find(arrayString2, token3);
  if( count3 == 4 ) cout << "Find Test 3 passed\n";

  ArrayString token4 = new char[2];
  temp = "y";
  strcpy(token4, temp.c_str());

  int count4 = find(arrayString2, token4);
  if( count4 == 0 ) cout << "Find Test 4 passed\n";
}

void testMatchIndex() {
  ArrayString arrayString1 = new char[9];
  string temp = "abcbabdc";
  strcpy(arrayString1, temp.c_str());

  ArrayString token = new char[4];
  temp = "abc";
  strcpy(token, temp.c_str());

  int * match_index_list1 = match_index(arrayString1, token);
  if( match_index_list1[0] == 0 ) cout << "Match Index Test 1 passed\n";
  else cout << "Match Index Test 1 failed\n";

  ArrayString token2 = new char[3];
  temp = "ab";
  strcpy(token2, temp.c_str());

  int * match_index_list2 = match_index(arrayString1, token2);
  if( match_index_list2[0] == 0 && match_index_list2[1] == 4) cout << "Match Index Test 2 passed\n";
  else cout << "Match Index Test 2 failed\n";
  
  ArrayString arrayString2 = new char[13];
  temp = "abcbcabcdcbc";
  strcpy(arrayString2, temp.c_str());

  ArrayString token3 = new char[3];
  temp = "bc";
  strcpy(token3, temp.c_str());

  int * match_index_list3 = match_index(arrayString2, token3);
  if( match_index_list3[0] == 1 && 
      match_index_list3[1] == 3 && 
      match_index_list3[2] == 6 &&
      match_index_list3[3] == 10 ) 
    cout << "Match Index Test 3 passed\n";
  else cout << "Match Index Test 3 failed\n";

  ArrayString token4 = new char[2];
  temp = "y";
  strcpy(token4, temp.c_str());

  int * match_index_list4 = match_index(arrayString2, token4);
  if( match_index_list4 == NULL ) cout << "Match Index Test 4 passed\n";
}

void testReplace() {
  ArrayString arrayString1 = new char[9];
  string temp = "abcbabcc";
  strcpy(arrayString1, temp.c_str());

  ArrayString token = new char[4];
  temp = "abc";
  strcpy(token, temp.c_str());

  ArrayString repl_token = new char[3];
  temp = "xy";
  strcpy(repl_token, temp.c_str());
  cout << "Input: " << arrayString1 << " Find: " << token << " Replace: " << repl_token << "\n";

  int newlen = replace(arrayString1, token, repl_token);
  cout << "Output: " << arrayString1 << "\n";

  char result[7] = {'x','y','b','x','y','c',0};
  if( equal(arrayString1, result ) ) 
    cout << "Replace Test 1 passed\n";
  else 
    cout << "Replace Test 1 failed\n";

  ArrayString arrayString2 = new char[9];
  temp = "abcbabcc";
  strcpy(arrayString2, temp.c_str());

  ArrayString token2 = new char[3];
  temp = "bc";
  strcpy(token2, temp.c_str());

  ArrayString repl_token2 = new char[4];
  temp = "xyz";
  strcpy(repl_token2, temp.c_str());
  cout << "Input: " << arrayString2 << " Find: " << token2 << " Replace: " << repl_token2 << "\n";

  int newlen2 = replace(arrayString2, token2, repl_token2);
  cout << "Output: " << arrayString2 << "\n";

  char result2[11] = {'a','x','y','z','b','a','x','y','z','c',0};
  if( equal(arrayString2, result ) ) 
    cout << "Replace Test 2 passed\n";
  else 
    cout << "Replace Test 2 failed\n";

  /*
  ArrayString arrayString2 = new char[13];
  temp = "abcbcabcdcbc";
  strcpy(arrayString2, temp.c_str());

  ArrayString token3 = new char[3];
  temp = "bc";
  strcpy(token3, temp.c_str());

  int * match_index_list3 = match_index(arrayString2, token3);
  if( match_index_list3[0] == 1 && 
      match_index_list3[1] == 3 && 
      match_index_list3[2] == 6 &&
      match_index_list3[3] == 10 ) 
    cout << "Match Index Test 3 passed\n";
  else cout << "Match Index Test 3 failed\n";

  ArrayString token4 = new char[2];
  temp = "y";
  strcpy(token4, temp.c_str());

  int * match_index_list4 = match_index(arrayString2, token4);
  if( match_index_list4 == NULL ) cout << "Match Index Test 4 passed\n";
  */
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
  cout << "\n";
  testFind();
  cout << "\n";
  testMatchIndex();
  cout << "\n";
  testReplace();
  
  return 0;
}
