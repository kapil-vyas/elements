def remove_duplicate(input):
        print input
        input = list(input)
        mark = len(input)
        i=0
        while i < mark:
                current = input[i]
                #print current
                j = i+1
                while j < mark:
                        #print "\t", input[j]
                        if input[j] == current:
                                temp = input[j]
                                m = j+1
                                while m < mark:
                                        #print input[m-1], input[m]     
                                        input[m-1] = input[m]
                                        m += 1
                                input[mark-1] = temp
                                mark -= 1
                                #print input
                        else:
                                j += 1
                i += 1
        input = ''.join(input)
        print input, mark

remove_duplicate("abbcadd")
remove_duplicate("aaaaaaa")
remove_duplicate("aaabbbb")
remove_duplicate("abcabcd")
remove_duplicate("1111111")
remove_duplicate("11223344")
remove_duplicate("abb4cadefkcghdf8mhhi8e")
remove_duplicate("11223344")
