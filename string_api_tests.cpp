#include <iostream>
using std::cout;
using std::string;

void test1() {
  string input = "bacabca";
  int pos = 0;
  while((pos = input.find('a', pos)) != string::npos) {
    cout << pos << "\n";
    pos++;
  }
}

int main() {
  test1();
  return 0;
}
