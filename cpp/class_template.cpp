//
//  main.cpp
//  elements
//
//  Created by Kapil Vyas on 6/8/15.
//  Copyright (c) 2015 Kapil Vyas. All rights reserved.
//

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Student {
public:
    Student(string value) {
        setName(value);
    }
    
    void displayMessage() {
        cout << "Hello " << getName() << "!" << endl;
    }
    
    void setName(string value) {
        name = value;
    }
    
    string getName() {
        return name;
    }
private:
    string name;
};

int main(int argc, const char * argv[]) {
    Student student("John Doe");
    student.displayMessage();
    student.setName("James Dave");
    student.displayMessage();
    return 0;
}
