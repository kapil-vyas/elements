#include <iostream>
#include <string>
using std::cout;
using std::string;

void sort_simple(int * array, int length) {
  for( int i = 1; i < length; i++ ) {
    int j = i;
    int curr = array[j];
    while( curr < array[j-1] && j > 0) {
      array[j] = array[j-1];
      j--;
    }
    array[j] = curr;
  }
}

void print_array(string text, int * array, int length) {
  cout << text << "\n";
  for( int i = 0; i < length; i++ ) 
    cout << array[i] << " ";
  cout << "\n";
}

int main() {
  int array[5] = {2, 4, 3, 1, 5};
  int length = 5;

  print_array("Before:", array, length);
  sort_simple(array, 5); 
  print_array("After:", array, length);
  return 0;
}
