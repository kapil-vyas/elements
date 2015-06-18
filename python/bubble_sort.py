input = [5, 4, 3, 2, 1]

N = len(input)
print input
i = 0
while i < N-1:
  j = i+1
  count_swap = 0
  while j < N:
    if input[i] > input[j]:
      #swap
      temp = input[i]
      input[i] = input[j]
      input[j] = temp
      count_swap += 1
    i += 1
    j += 1
  N -= 1
  i = 0
  if count_swap == 0:
    break
print input
