#include <iostream>
using std::cout;
typedef char * ArrayString;

// length function returns the length of the input string and
// not the size of the input string
// Say, input = char[5];       --> size is 5
// input = {'a','b','c','d',0} --> size is 5, but length is 4
int length(const ArrayString input) {
  int count = 0;
  while( input[count] != 0 ) {
    count++;
  }
  return count; 
}

bool equal(const ArrayString input, const ArrayString compare) {
  int length_input = length(input)+1; // To account for NULL char
  int length_compare = length(compare)+1;
  if( length_input != length_compare ) return false;
  for(int i = 0; i < length_input; i++ ) {
    if( input[i] != compare[i] )
      return false;
  }
  return true;
}

int find(const ArrayString input, const ArrayString token) {
  int tokenlen = length(token);
  int len = length(input);
  int matches = 0;

  int end_state = tokenlen-1;
  int curr_state = 0;
  bool prev_match = false;

  for( int i = 0; i < len; i++ ) {
    if( prev_match && token[curr_state] != input[i] ) {
      curr_state = 0;
    }
    if( token[curr_state] == input[i] ) {
      if( curr_state == end_state ) {
        matches++;
        curr_state = 0;
      }
      else {
        curr_state++;
      }
      prev_match = true;
    }
  }
  return matches;
}

int * match_index(const ArrayString input, const ArrayString token) {
  int count = find(input, token);
  if( count == 0 )
    return NULL;
  int * match_indexes = new int[count];

  int tokenlen = length(token);
  int len = length(input);
  int index = 0;

  int end_state = tokenlen-1;
  int curr_state = 0;
  bool prev_match = false;

  for( int i = 0; i < len; i++ ) {
    if( prev_match && token[curr_state] != input[i] ) {
      curr_state = 0;
    }
    if( token[curr_state] == input[i] ) {
      if( curr_state == end_state ) {
        match_indexes[index] = i-tokenlen+1;
        index++;
        curr_state = 0;
      }
      else {
        curr_state++;
      }
      prev_match = true;
    }
  }
  return match_indexes;
}

int replace(ArrayString& input, ArrayString token, ArrayString replace_token) {
  int count = find(input, token);
  int inputlen = length(input);
  int tokenlen = length(token);
  int replace_tokenlen = length(replace_token);
  int newlen = inputlen+count*(replace_tokenlen-tokenlen);

  ArrayString temp = new char[newlen+1];
  int k = 0;
  int * match_index_array = match_index(input, token);

  int i = 0;
  while( i < inputlen ) {
    if( i == match_index_array[k] ) {
      i += tokenlen;
      for( int j = 0; j < replace_tokenlen-1; j++ ) {
        temp[k] = replace_token[j];
        cout << " " << temp[k] << "\n";
        k++;
      }
    }
    else {
      temp[k] = input[i];
      cout << " " << temp[k] << "\n";
      k++;
      i++;
    }
  }
  temp[newlen] = 0;
  //delete [] input;
  input = temp;
  return newlen;
}

ArrayString substring(const ArrayString input, int pos, int substrlen) {
  ArrayString substr;
  if( substrlen < 0 || substrlen > length(input)-(pos - 1) ||
      pos < 0 || pos > length(input) ) {
    substr = new char[1];
    substr[0] = 0;
    return substr;
  }

  substr = new char[substrlen+1];
  for(int i = 0; i < substrlen; i++) {
    substr[i] = input[i+pos-1];
  }
  substr[substrlen] = 0;
  return substr;
}

void append(ArrayString& inputString, char charToAppend) {
  int oldLength = length(inputString)+1; 
  int newLength = oldLength+1;
  ArrayString temp = new char[newLength];
  for(int i = 0; i < oldLength; i++)
    temp[i] = inputString[i];
  delete [] inputString;
  temp[newLength-2] = charToAppend;
  temp[newLength-1] = 0; 
  inputString = temp;
}

void concatenate(ArrayString& source, const ArrayString stringToAppend) {
  int sourceLength = length(source);
  int stringToAppendLength = length(stringToAppend);
  int newLength = sourceLength+stringToAppendLength;
  ArrayString temp = new char[newLength+1]; // To account for Null char
  for(int i = 0; i < sourceLength-1; i++) {
    temp[i] = source[i];
  }
  for(int i = 0; i < stringToAppendLength-1; i++) {
    temp[i+sourceLength-1] = stringToAppend[i];
  }
  temp[newLength-1] = 0;
  delete [] source;
  source = temp;
}

char characterAt(ArrayString arrayString, int position) {
  return arrayString[position];
}
