#include <iostream>
using std::cout;

void expected_output() {
   cout << "#            #\n";
   cout << " ##        ## \n";
   cout << "  ###    ###  \n";
   cout << "   ########   \n";
   cout << "   ########   \n";
   cout << "  ###    ###  \n";
   cout << " ##        ## \n";
   cout << "#            #\n";
}

int main() {
  cout << "Key: \n  s -> count of space characters\n  # -> count of # characters\n";
  cout << "s" << " " << "#" << " " << "s" << " " << "s" << " " << "#" << " " << "s\n";
  for(int i = 1; i <= 4; i++ ) {
      cout << i-1 << " " << i << " " << (4-i)*2 << " " << (4-i)*2 << " " << i << " " << i-1;
    cout << "\n";
  }
  for(int i = 4; i >= 1; i-- ) {
      cout << i-1 << " " << i << " " << (4-i)*2 << " " << (4-i)*2 << " " << i << " " << i-1;
    cout << "\n";
  }
  expected_output();
  return 0;
}
