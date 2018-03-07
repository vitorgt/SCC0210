#reads an integer for the number of lines to read
#reads operator 'S' to add 'R' to add the first and subtract the others
#other operands print 'E' for error

a = int(input())
while(a):
    s = 0
    line = input()
    line = (" ".join(line.split())).split(' ')
    if "S" in line[0]:
        for i in range(1,len(line)):
            s += int(line[i])
        print("T " + str(s))
    elif "R" in line[0]:
        s += int(line[1])
        for i in range(2,len(line)):
            s -= int(line[i])
        print("T " + str(s))
    else:
        print("E")
    a -= 1
