#include <iostream>
#include "point.h"
using std::cout;

int main() {
  Point p0;         // invokes default constructor
  cout << "p0 = " << p0.toString() << "\n";
  Point p1(5, -2);  // invokes default constructor
  cout << "p1 = " << p1.toString() << "\n";
  Point p2=p1;      // onvokes copy constructor
  cout << "p2 = " << p2.toString() << "\n";
  p0 = p1;          // invokes assignment operator
  cout << "p0 = " << p0.toString() << "\n";
  cout << "p0.x() = " << p0.x() << "\n";
  cout << "p0.y() = " << p0.y() << "\n";
  return 0;
}
