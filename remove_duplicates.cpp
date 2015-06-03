#include <iostream>
#include <cstring>
using namespace::std;

void remove_duplicates(char * array) {
  int len = strlen(array);
  if( len < 2) return;

  int marker = 0; // all elements are non-duplicate before marker
  for(int i = 0; i < len; i++) {
    int j = 0;
    while(j < marker) {
      if(array[j] == array[i]) {
        break;
      }
      j++;
    }
    if(j == marker) {
      marker++;
    }
  }
  array[marker] = '\0';
}
int main() {
  char array[10] = {'b', 'a', 'd', 'd', 'b', 'd', 'c', 'b', 'a', '\0'};
  cout << "Before: " << array << "\n";
  remove_duplicates(array);
  cout << "After: " << array << "\n";
  return 0;
}
