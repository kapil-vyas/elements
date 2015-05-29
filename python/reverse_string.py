
def reverse_string(input):
  length = len(input)
  output = [None]*length

  for i in range(0, length):
    output[length-1-i] = input[i]
  output = ''.join(str(i) for i in output)
  return output

input = "abcdef"
output = reverse_string(input)
print output

input = "123456"
output = reverse_string(input)
print output
