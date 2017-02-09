def solve():
    row = raw_input()
    row = row.split()
    memsize = int(row[0])
    codesize = int(row[1])
    inputsize = int(row[2])
    raw_program = raw_input()
    text = raw_input()
    teleports = [0 for x in range(codesize)]
    s = []
    program = []
    opt = False
    codepos = 0
    oldloops = dict()
    for i,x in enumerate(raw_program):
        if x=='+':
            teleports[codepos]+=1
            opt = True
            continue
        elif x=='-':
            teleports[codepos]-=1
            opt = True
            continue
        if opt==True:
            program.append('+')
            codepos+=1
            opt = False
        if x == '[':
            s.append(codepos)
            oldloops[codepos] = i
        elif x == ']':
            target = s.pop()
            teleports[target] = codepos
            teleports[codepos] = target
            oldloops[codepos] = i
        program.append(x)
        codepos += 1

    #print(teleports)
    codesize = len(program)
    codepos = 0
    mempos = 0
    depth = 0
    firstloop = 0
    inputpos = 0
    memory = [0 for x in range(memsize)]
    for x in range(50000000):
        if codepos >=codesize:
            print "Terminates"
            return
        elif program[codepos] == '+':
            memory[mempos]=(256000+memory[mempos]+teleports[codepos])%256
        elif program[codepos] == '<':
            mempos -=1
            if mempos < 0:
                mempos +=memsize
        elif program[codepos] == '>':
            mempos += 1
            if mempos >= memsize:
                mempos = 0
        elif program[codepos] == '[':
            if memory[mempos]==0:
                codepos = teleports[codepos]
            elif depth == 0:
                firstloop = codepos
                depth += 1
            else:
                depth += 1
        elif program[codepos] == ']':
            if memory[mempos] != 0:
                codepos = teleports[codepos]
            else:
                depth -=1
        elif program[codepos] == ',':
            if inputpos >= inputsize:
                memory[mempos] = 255
            else:
                memory[mempos] = int(ord(text[inputpos]))
                inputpos +=1
        #elif program[codepos] == '.':
        #   print chr(memory[mempos]),
        codepos +=1
    print "Loops", oldloops[firstloop], oldloops[teleports[firstloop]]


def main():
    n=int(raw_input())
    for i in range(n):
        solve()



main()
