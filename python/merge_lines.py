# lines that do not start with a token, say "Begin" 
# need to be merged with previous line that begins with token
import sys

def parse(in_file, token):
    handle = open(in_file, 'r')
    output = open('parsed.out', 'w+')
    prev_line = ""
    lines = handle.readlines()

    i = 0
    while i < len(lines):
        curr_line = lines[i].strip()
        if i+1 < len(lines) and not lines[i+1].startswith(token):
            curr_line += lines[i+1].strip()
            output.write("\n")
            i = i+1
        else:
            output.write("\n")
        i = i+1
    output.truncate()
    output.close()
    handle.close()

arg_list = sys.argv
input_file = arg_list[1]
token = "Begin:" 
parse(input_file, token)