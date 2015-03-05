#include <iostream>
using std::cout;

struct student {
  int student_id;
  int grade;
};
typedef student STUDENT;

struct node {
  STUDENT student; 
  node * p_next;
};
typedef node * P_NODE;
typedef node NODE;

void add(P_NODE& collection, STUDENT student) {
  P_NODE new_student = new NODE;
  new_student->student = student;
  new_student->p_next = collection;
  collection = new_student;
}

void print(P_NODE& collection) {
  P_NODE current = collection;
  while(current != NULL) {
    cout << "[" << current->student.student_id << "," << current->student.grade << "]->";
    current = current->p_next;
  }
  cout << "NULL\n";
}

void test_add(P_NODE& collection) {
  print(collection);

  STUDENT student1 = {1, 87};
  add(collection, student1);
  print(collection);

  STUDENT student2 = {2, 98};
  add(collection, student2);
  print(collection);
  
  STUDENT student3 = {3, 74};
  add(collection, student3);
  print(collection);

  STUDENT student4 = {4, 94};
  add(collection, student4);
  print(collection);
}

int main(int argc, char *argv[]) {
  P_NODE collection = NULL;
  test_add(collection);
  return 0;
}
