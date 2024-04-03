#include <iostream>
#include <string>
using std::cout;
using std::string;

void print_array(string text, int * array, int length) {
  cout << text << "\n";
  for( int i = 0; i < length; i++ ) 
    cout << array[i] << " ";
  cout << "\n";
}

void insertion_sort(int * array, int length) {
  // Basic idea: move [j] to temp and keep sliding elements to the right
  // creates empty slot in left, move temp to empty slot      
  // Demo:
  // [2][4][1] 
  //        ^
  // [ ][2][4]
  // [1][2][4]
  // With for and while

  for( int i = 1; i < length; i++ ) {
    int j = i;
    int temp = array[j];
    while( temp < array[j-1] && j > 0 ) {
      array[j] = array[j-1];
      j--;
    }
    array[j] = temp;
  }
}

void insertion_sort_for(int * array, int length) {
  // Basic idea: move [j-1] to temp and float temp to left on each loop iteration
  // creates empty slot in right, move temp to empty slot at end of each inner loop
  // Demo:
  // [2][4][5][1] 
  //           ^
  // [2][4][1][ ]
  // [2][4][1][5] ...1st loop
  // [2][1][4][5] ...2nd loop
  // [1][2][4][5] ...3rd loop
  // With for and while
  // With two for

  for( int i = 1; i < length; i++ ) {
    for( int j = i; array[j-1] > array[j] && j >= 1; j-- ) {
      int temp = array[j-1];
      array[j-1] = array[j];
      array[j] = temp;
    }
  }
}

int main() {
  int array[5] = {2, 4, 3, 1, 5};
  int array_length = 5;

  print_array("Before:", array, array_length);
  insertion_sort_for(array, 5); 
  print_array("After:", array, array_length);
  
  int arr[8] = {8, 7, 6, 5, 4, 3, 2, 1};
  int arr_length = 8;
  print_array("Before:", arr, arr_length);
  insertion_sort(arr, 8); 
  print_array("After:", arr, arr_length);
  return 0;
}
