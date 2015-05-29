
def reverse_string(input):
  length = len(input)
  output = [None]*length

  for i in range(0, length):
    output[length-1-i] = input[i]
  return output

input = "abcdef"
output = reverse_string(input)
output = ''.join(output)

print output
