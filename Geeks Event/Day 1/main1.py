# Day 1

# name = "Aniket"
# val = 2
# # conditional statements
# if(val>=8):
#     print("Pass with flying colors")
# elif(val>=7 and val<8):
#     print("Pass with maaer bokuni")
# else:
#     print("Ghor theke beriye jaao")

# # lists
# l = [10,9,"paul"]

# print(l[0])
# print(l[:3])
# l.append(65)
# print(l)

# for i in [65, 89, 45, 78, 65]:
#     print("Hello")

# Day 2

fname = "Sayantan"
lname = "Bose"
fullname = fname+" "+lname
print(fullname, "Good",end=' ')
l = [{"Kolkata": "city"}, [1,21,3], 56, "Hi"]
print(l)

x = 5
y = 5

print(x is y)

print('a' in [12,25])

#def is a keyword. cannot be used as a variable name

def scoop(*args):
    # pass
    print(type(args))
    print(args)
    print(args[0]+" "+args[1])

print(scoop("Hertiage","Academy","is good"))