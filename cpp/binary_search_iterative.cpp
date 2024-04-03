#include <iostream>

bool assertEqual(int result, int expected) {
    return result == expected;
}

/* Returns either the index of the location in the array,
  or -1 if the array did not contain the targetValue */
int binarySearch(int * array, int targetValue, int length) {
	int min = 0;
	int max = length - 1;
    int guess = 0;
    int totalGuesses = 0;
    
    while(min <= max) {
        guess = (min + max)/2;
        totalGuesses++;
        if(array[guess] == targetValue) {
            printf("\tTotal Guesses %d\n", totalGuesses);
            return guess;
        }
        else if(targetValue < array[guess]) {
            max = guess - 1;
        }
        else {
            min = guess + 1;
        }
    }
    return -1;
}

int main() {
    int length = 25;
    int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    if (assertEqual(binarySearch(primes, 73, length), 20)) {
        printf("Test 1 passed\n");
    }
    if (assertEqual(binarySearch(primes, 41, length), 12)) {
        printf("Test 2 passed\n");
    }
    if (assertEqual(binarySearch(primes, 97, length), 24)) {
        printf("Test 3 passed\n");
    }
}
