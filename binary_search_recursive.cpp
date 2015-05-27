#include <iostream>

bool assertEqual(int result, int expected) {
    return result == expected;
}

int binarySearch(int * array, int start, int end, int needle) {
	if(start > end) {
		return -1;
  }
	int mid = (start + end)/2;
	if(array[mid] == needle) {
		return mid;
  }
	if(needle < array[mid]) {
		end = mid-1;
  }
	else {
		start = mid+1;
  }
	return binarySearch(array, start, end, needle);
}

int main() {
  int length = 25;
  int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  int start = 0;
  int end = length - 1;

  if (assertEqual(binarySearch(primes, start, end, 73), 20)) {
    printf("Test 1 passed\n");
  }
  else {
    printf("Test 1 failed\n");
  }
  if (assertEqual(binarySearch(primes, start, end, 41), 12)) {
      printf("Test 2 passed\n");
  }
  else {
    printf("Test 2 failed\n");
  }
  if (assertEqual(binarySearch(primes, start, end, 97), 24)) {
      printf("Test 3 passed\n");
  }
  else {
    printf("Test 3 failed\n");
  }
  return 0;
}


