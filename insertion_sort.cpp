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
  // With for and while
  for( int i = 1; i < length; i++ ) {
    int j = i;
    int curr = array[j];
    while( curr < array[j-1] && j > 0 ) {
      array[j] = array[j-1];
      j--;
    }
    array[j] = curr;
  }
}

void insertion_sort_for(int * array, int length) {
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
