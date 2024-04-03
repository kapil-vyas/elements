#include <iostream>
using std::cout;
using std::string;

void censorString(string& input, const string censor) {
  for(int pos = 0; pos < input.length(); pos++) {
    for(int j = 0; j < censor.length(); j++) {
      if(input[pos] == censor[j]) {
        input.erase(pos, 1);
      }
    }
  }
}


void censorString_impl2(string& input, const string censor) {
  for(int j = 0; j < censor.length(); j++) {
    int pos = 0;
    while((pos = input.find(censor[j], pos)) != string::npos) {
      input.replace(pos, 1, "");
      pos++;
    }
  }
}

void test1() {
  string input = "University of Texas at Arlington";
  string censor = "nt";
  cout << "Input:" << input << " Censor:" << censor << "\n";

  censorString(input, censor);
  string expected_output = "Uiversiy of Texas a Arligo";

  cout << "Output: " << input << "\n";
  if(input == expected_output) cout << "Test1 passed\n";
  else cout << "Test1 failed\n";
}

void test2() {
  string input = "Llamas like to laugh";
  string censor = "la";
  cout << "Input:" << input << " Censor:" << censor << "\n";

  censorString(input, censor);
  string expected_output = "Lms ike to ugh";

  cout << "Output: " << input << "\n";
  if(input == expected_output) cout << "Test2 passed\n";
  else cout << "Test2 failed\n";
}

int main() {
  test1();
  test2();
  return 0;
}
