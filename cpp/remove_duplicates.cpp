#include <iostream>
#include <cstring>
using namespace::std;

void remove_duplicates(char * array) {
  int len = strlen(array);
  if( len < 2) return;

  int marker = 1; // all elements are non-duplicate before marker
  for(int i = 0; i < len; i++) {
    int j = 0;
    while(j < marker) {
      if(array[j] == array[i]) {
        break;
      }
      j++;
    }
    if(j == marker) {
      array[marker] = array[i];
      marker++;
    }
  }
  array[marker] = '\0';
}
int main() {
  char array1[10] = {'b', 'a', 'd', 'd', 'b', 'd', 'c', 'b', 'a', '\0'};
  remove_duplicates(array1);
  char exp_output1[5] = {'b', 'a', 'd', 'c', '\0'};
  if(strcmp(array1, exp_output1) == 0) {
    cout << "Test 1 passed\n";
  }

  char array2[10] = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'd', 'e', '\0'};
  remove_duplicates(array2);
  char exp_output2[6] = {'a', 'b', 'c', 'd', 'e', '\0'};

  if(strcmp(array2, exp_output2) == 0) {
    cout << "Test 2 passed\n";
  }

  char array3[2] = {'a', '\0'};
  remove_duplicates(array3);
  char exp_output3[2] = {'a', '\0'};

  if(strcmp(array3, exp_output3) == 0) {
    cout << "Test 3 passed\n";
  }
  
  char array4[1] = {'\0'};
  remove_duplicates(array4);
  char exp_output4[1] = {'\0'};

  if(strcmp(array4, exp_output4) == 0) {
    cout << "Test 4 passed\n";
  }
  return 0;
}
