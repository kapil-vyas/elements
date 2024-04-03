#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;
using std::cout;

struct student {
  int id;
  string name;
  int grade;
};

int compareByGrade(const void * voidA, const void * voidB) {
  student * studentA = (student *)(voidA);
  student * studentB = (student *)(voidB);
  return studentA->grade - studentB->grade;
}

int compareByName(const void * voidA, const void * voidB) {
  student * studentA = (student *)(voidA);
  student * studentB = (student *)(voidB);
  return (studentA->name).compare(studentB->name);
}
int main() {
  const int SIZE = 4;
  student math_class[4] = { { 1, "Ire", 89}, { 2, "Cie", 67 }, { 3, "Abe", 59 }, { 4, "Dei", 25 } };

  qsort( math_class, SIZE, sizeof(student), compareByGrade);
  cout << "Sort by Grade:\n";
  for( int i = 0; i < SIZE; i++ ) {
    cout << math_class[i].id << ": " << math_class[i].name << " " << math_class[i].grade << "\n";
  }

  qsort( math_class, SIZE, sizeof(student), compareByName);
  cout << "Sort by Name:\n";
  for( int i = 0; i < SIZE; i++ ) {
    cout << math_class[i].id << ": " << math_class[i].name << " " << math_class[i].grade << "\n";
  }
  return 0;
}
