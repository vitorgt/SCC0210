a = int(input())
s = 0
while(a):
    line = input()
    line = (" ".join(line.split())).split(' ')
    for i in range(0,len(line)):
        s += int(line[i])
    a -= 1
print(s)
