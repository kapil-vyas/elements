import array
def is_unique(input):
        char_set = array.array('i', (0 for i in range(0, 256) ) )
        for i in input:
                char_set[ord(i)] += 1
                print i, ord(i), char_set[ord(i)]
                if char_set[ord(i)] == 2:
                        return False
        return True

print is_unique("hhello")
