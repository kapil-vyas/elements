#include <iostream>
using std::cout;
using std::cin;

int main() {
  int size;
  cout << "Size: ";
  cin >> size;

  // Allocate array
  int * array = new int[size];
  
  // Fill array:
  cout << "Enter elements separated by a space and press enter: ";
  for( int i = 0; i < size; i++ ) {
    cin >> array[i];
  }

  // Print array:
  cout << "Array: \n";
  for( int i = 0; i < size; i++ ) {
    cout << " [" << i << "]=" << array[i];
  }
  cout << "\n";

  // Deallocate:
  delete [] array;

  return 0;
}

