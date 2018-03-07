#reads each line and adds the entire document

s = 0
try:
    while(True):
        line = input()
        if line != "":
            line = (" ".join(line.split())).split(' ')
            for i in range(0,len(line)):
                s += int(line[i])
        else:
            break
except EOFError:
    pass
print(s)
