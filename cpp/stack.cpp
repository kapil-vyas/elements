//
//  main.cpp
//  elements
//
//  Created by Kapil Vyas on 6/12/15.
//  Copyright (c) 2015 Kapil Vyas. All rights reserved.
//

#include <iostream>
#include <string>
using std::cout;
using std::cin;

using std::cout;
using std::endl;
using std::string;

class Stack {
public:
  Stack(int value) {
    // Allocate array
    array = new int[value];
    size = 0; 
    length = value;
  }
  
  ~Stack() {
    // Deallocate:
    delete [] array;
  }
  
  void print() {
    // Print array:
    cout << "Stack: \n";
    cout << " Size: " << size << " ";
    cout << "[ ";
    for( int i = 0; i < size; i++ ) {
      cout << array[i] << " ";
    }
    cout << "]";
    cout << "\n";
  }
 
  int peek() {
    return array[size]; 
  }

  bool isEmpty() {
    if(size) return false;
    return true;
  }

  int pop() {
    if(size > 0)
      return array[size--];
    return -1;
  }
  
  int push(int value) {
    if(size < length)
      array[size++] = value;
    return size;
  }
  
private:
    int * array;
    int size;
    int length;
};

int main(int argc, const char * argv[]) {
  Stack stack(5);
  if( stack.isEmpty() ) cout << "Empty stack\n";
  else cout << "Non-empty stack\n";
  stack.print();
  stack.push(1);
  stack.print();
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.push(6);
  stack.print();
  if( stack.isEmpty() ) cout << "Empty stack\n";
  else cout << "Non-empty stack\n";
  stack.pop();
  stack.pop();
  stack.print();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.print();
  if( stack.isEmpty() ) cout << "Empty stack\n";
  else cout << "Non-empty stack\n";
  return 0;
}

