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
    Stack(int size) {
      // Allocate array
      int * array = new int[size];
    }

    ~Stack() {
      // Deallocate:
      delete [] array;
    }
    
    void print() {
      // Print array:
      cout << "Stack: \n";
      for( int i = 0; i < getSize(); i++ ) {
        cout << " [" << i << "]=" << array[i];
      }
      cout << "\n";
    }
   
    int peek() {
      return array[size-1]; 
    }

    bool isEmpty() {
      if(size) return false;
      return true;
    }

    int pop() {
      //TODO
      return 0;
    }
    
    void push(int value) {
        //TODO
    }

    int getSize() {
      return size;
    }

    void setSize(int value) {
      size = value;
    }

private:
    int * array;
    int size;
};

int main(int argc, const char * argv[]) {
  int size = 5;
  Stack stack(size);
  return 0;
}
