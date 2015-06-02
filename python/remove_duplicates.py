def remove_dup(str):
  if str == None:
    return str
  length = len(str)
  if length < 2:
    return str

  tail = 1

  for i in range(1, length):
    for j in range(0, tail):
      if str[i] == str[j]:
        break
      j = j+1
    if j == tail:
      str[tail] = str[i]
      tail = tail+1
  str[tail] = 0
  return str

print(remove_dup([]))
print(remove_dup(['a']))
print(remove_dup(['a', 'b', 'a', 'b', 'c']))
print(remove_dup(['a', 'b', 'a', 'b', 'c', 'd']))
print(remove_dup(['a', 'a', 'a', 'b', 'b', 'c']))
print(remove_dup(['a', 'a', 'a', 'a', 'a', 'a']))
print(remove_dup(['a', 'a', 'a', 'b', 'b', 'c', 'a', 'b', 'd', 'd', 'e', 'a', 'e', 'f']))
