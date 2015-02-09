#include <iostream>
#include "definitions.h"
using namespace::std;

void read_num(char in, int *prev_num) {
  int num = int(in-'0');
  *prev_num = ((*prev_num)*10) + num;
}

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

char get_mode_char(int mode, int num) {
  char punct_char_array[] = {
      '!',
      '?',
      ',',
      '.',
      char(32),
      ';',
      '\"',
      '\''};
  if( mode == UPPER) return char(int('A') + num - 1);
  if( mode == LOWER) return char(int('a') + num - 1);
  if( mode == PUNCT) return punct_char_array[num-1];
  return '0';
}

int main() {
  char c = cin.get();
  int prev_num = 0;
  int current_mode = UPPER;
  char curr_char;
  int mod_result;

  while( c != '\n' ) {
    if( c != ',') {
      read_num(c, &prev_num);
    }
    if( c == ',') {
      mod_result = prev_num % get_mode(current_mode);
      if( mod_result == 0 ) {
        current_mode = switch_mode(current_mode);
        print_mode(current_mode);
      }
      else {
        curr_char = get_mode_char(current_mode, mod_result);
        cout << "\t" << curr_char << "\t" << prev_num << "\n";
      }
      prev_num = 0;
    }
    c = cin.get();
  }
  mod_result = prev_num % get_mode(current_mode);
  curr_char = get_mode_char(current_mode, mod_result);
  cout << "\t" << curr_char << "\t" << prev_num << "\n";
  return 0;
}
