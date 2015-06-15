#input = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
input = [4, 6, 9, 10, 7, 3, 9, 33, 2, 0, -4]
 
i = 0
j = i+1
N = len(input)
while j < N:
  temp = input[j]
  k = i;
  while temp < input[k] and k > -1:
    input[k+1] = input[k]
    k -= 1
  input[k+1] = temp
  i += 1
  j = i+1
print input
