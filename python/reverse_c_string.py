def swap(input, index_a, index_b):
        temp = input[index_a]
        input[index_a] = input[index_b]
        input[index_b] = temp

def reverse_C_string(input):
        print input
        L=len(input)
        for i in range( (L-1)/2 ):
                swap(input, i, L-2-i)
        return input

print reverse_C_string(['a','b','c','d','\0'])
print reverse_C_string(['a','b','c','d','e','\0'])

''' OUTPUT RESULTS
['a', 'b', 'c', 'd', '\x00']
['d', 'c', 'b', 'a', '\x00']
['a', 'b', 'c', 'd', 'e', '\x00']
['e', 'd', 'c', 'b', 'a', '\x00']
'''

