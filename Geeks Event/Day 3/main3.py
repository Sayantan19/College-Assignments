class Company:
    def __init__(self,n,a,i,d):
        self.name = n
        self.age = a
        self.id = i
        self.doj = d
    
    # self stores the address of the function (it can be any variable, but by convention it is self
    def modify(self):
        print(self.name+" is in Google")

emp1 = Company("Ramesh",20,256,3)
emp2 = Company("Suresh",21,356,5)

print(emp1.name)
print(emp2.name)
# print(emp1)
emp1.modify()