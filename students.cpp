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

void add_sorted(P_NODE& head, STUDENT student) {
  P_NODE new_node = new NODE;
  new_node->student = student;

  if( head == NULL ) {
    head = new_node;
    head->p_next = NULL;
    return;
  }

  P_NODE prev_node = NULL;
  P_NODE curr_node = head;

  while(curr_node->student.student_id < new_node->student.student_id) {
    prev_node = curr_node;
    if(curr_node->p_next == NULL) {
      curr_node->p_next = new_node;
      new_node->p_next = NULL;
      return;
    }
    curr_node = curr_node->p_next;
  }
  prev_node->p_next = new_node;
  new_node->p_next = curr_node;
}

double average(P_NODE& collection) {
  double sum = 0;
  double count = 0;
  P_NODE current = collection;
  while(current != NULL) {
    sum += current->student.grade;
    count++;
    current = current->p_next;
  }
  if(count == 0) return 0;
  return sum/count;
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

  double avge = average(collection);
  cout << "Average: " << avge << "\n";
}

void test_add_sorted(P_NODE& collection) {
  print(collection);

  STUDENT student1 = {1, 87};
  add_sorted(collection, student1);
  print(collection);

  STUDENT student2 = {3, 98};
  add_sorted(collection, student2);
  print(collection);
 
  STUDENT student3 = {2, 74};
  add_sorted(collection, student3);
  print(collection);

  STUDENT student4 = {4, 94};
  add_sorted(collection, student4);
  print(collection);

  double avge = average(collection);
  cout << "Average: " << avge << "\n";
}
int main(int argc, char *argv[]) {
  P_NODE collection1 = NULL;
  cout << "Unsorted Test" << "\n";
  test_add(collection1);

  P_NODE collection2 = NULL;
  cout << "Sorted Test" << "\n";
  test_add_sorted(collection2);
  return 0;
}
