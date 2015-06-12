# Remove redundant swaps
# Swap after minimum found
#input = [3, 4, 2, 6, 1, 5] #Exe time 102
#input = [1, 2, 3, 4, 5, 6] #Exe time 81
input = [6, 5, 4, 3, 2, 1] #Exe time 99
 
i = 0
curr_index = i
next_index = curr_index+1
N = len(input)
  
while curr_index < N-1:
  minimum_index = curr_index
  while next_index < N:
    if input[next_index] < input[minimum_index]:
      minimum_index = next_index
      next_index += 1
    # Swap after minimum found
    temp = input[curr_index]
    input[curr_index] = input[minimum_index]
    input[minimum_index] = temp
    curr_index += 1
    next_index = curr_index+1

print input
