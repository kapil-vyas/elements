a = [2, 4, 5, 6]
b = [1, 3, 7, 8, 9, 10, 11, 12, 13]
c = []

n1 = len(a)
n2 = len(b)
i = 0
j = 0
k = 0

while k < n1+n2:
  if i == n1 and j != n2:
    c.append(b[j])
    j += 1
  if j == n2 and i != n1:
    c.append(a[i])
    i += 1
  if i < n1 and j < n2:
    if a[i] < b[j]:
      c.append(a[i])
      i += 1
    else:
      c.append(b[j])
      j += 1
  k += 1
print c
