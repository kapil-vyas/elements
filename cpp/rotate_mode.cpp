#include <iostream>
#include "definitions.h"
using std::cout;

int switch_mode(int mode) {
  if( mode == UPPER) return LOWER;
  if( mode == LOWER) return PUNCT;
  if( mode == PUNCT) return UPPER;
  return UPPER;
}

int get_mode(int mode) {
  if( mode == UPPER) return 27;
  if( mode == LOWER) return 27;
  if( mode == PUNCT) return 9;
  return 27;
}

void print_mode(int mode) {
  if( mode == UPPER) cout << "UPPER\n";
  if( mode == LOWER) cout << "LOWER\n";
  if( mode == PUNCT) cout << "PUNCT\n";
}

int main() {
  int current_mode = UPPER;
  current_mode = switch_mode(current_mode);
  print_mode(current_mode);
  current_mode = switch_mode(current_mode);
  print_mode(current_mode);
  current_mode = switch_mode(current_mode);
  print_mode(current_mode);
  return 0;
}
