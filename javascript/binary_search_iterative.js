/* Returns either the index of the location in the array,
  or -1 if the array did not contain the targetValue */
var binarySearch = function(array, targetValue) {
	var min = 0;
	var max = array.length - 1;
    var guess = 0;
    var totalGuesses = 0;
    
    while(min <= max) {
        guess = Math.floor((min + max)/2);
        totalGuesses++;
        if(array[guess] === targetValue) {
            console.log('Total Guesses' + totalGuesses);
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
};

var primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 
		41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97];

var result = doSearch(primes, 73);
console.log("Found prime at index " + result);

Program.assertEqual(binarySearch(primes, 73), 20);
Program.assertEqual(binarySearch(primes, 41), 12);
Program.assertEqual(binarySearch(primes, 97), 24);