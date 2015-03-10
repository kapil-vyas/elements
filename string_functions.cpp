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
  int sourceLength = length(source)+1;
  int stringToAppendLength = length(stringToAppend)+1;
  int newLength = sourceLength+stringToAppendLength-1;
  ArrayString temp = new char[newLength]; 
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
