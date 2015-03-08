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

bool delete_record(P_NODE& head, int student_id) {
  if( head == NULL ) {
    return false;
  }

  P_NODE prev_node = NULL;
  P_NODE curr_node = head;

  while(curr_node != NULL) {
    if(curr_node->student.student_id == student_id) {
      if(prev_node == NULL) { 
        delete curr_node;
        curr_node = NULL;
        head = NULL;
        return true;
      }
      prev_node->p_next = curr_node->p_next; 
      delete curr_node;
      curr_node = NULL; 
      return true;
    }
    prev_node = curr_node;
    curr_node = curr_node->p_next;
  }
  return false;
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

void test_delete_record(P_NODE& collection) {
  bool is_deleted = false;
  print(collection);
  is_deleted = delete_record(collection, 1);
  if(is_deleted) cout << "Record was deleted\n";
  else cout << "Record was not deleted as it could not be found\n";
  print(collection);

  STUDENT student1 = {1, 87};
  add_sorted(collection, student1);
  print(collection);

  is_deleted = delete_record(collection, 1);
  if(is_deleted) cout << "Record was deleted\n";
  else cout << "Record was not deleted as it could not be found\n";
  print(collection);

  STUDENT student2 = {3, 98};
  add_sorted(collection, student2);
  print(collection);
 
  STUDENT student3 = {2, 74};
  add_sorted(collection, student3);
  print(collection);

  /*
  is_deleted = delete_record(collection, 3);
  if(is_deleted) cout << "Record was deleted\n";
  else cout << "Record was not deleted as it could not be found\n";
  print(collection);

  STUDENT student4 = {4, 94};
  add_sorted(collection, student4);
  print(collection);
  */
}

int main(int argc, char *argv[]) {

  P_NODE collection1 = NULL;
  cout << "\nUnsorted Test" << "\n";
  test_add(collection1);

  P_NODE collection2 = NULL;
  cout << "\nSorted Test" << "\n";
  test_add_sorted(collection2);

  P_NODE collection3 = NULL;
  cout << "\nDelete Record Test" << "\n";
  test_delete_record(collection3);
  return 0;
}
