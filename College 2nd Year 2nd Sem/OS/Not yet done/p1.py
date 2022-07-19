from multiprocessing.sharedctypes import RawArray


def check(s):
    flag =0
    for i in range(1,len(s)):
        if(s[i]-s[i-1]>0):
            flag =1
            break
    return flag

def move1(ray,ben):
    for i in range(len(ray)):
        ben = ben + ray[i]
    return ray,ben

def move2(ben,kevin):
    for i in range(len(ben),-1,-1):
        kevin = kevin + ben[i]
        ben[i] = ""
    return ben,kevin

def drive():
    n = int(input())
    s = input()
    ray = s
    ben = ""
    kevin = ""
    ray,ben = move1(ray,ben)
    ben,kevin = move2(ben,kevin)
    print(kevin)
    
drive()