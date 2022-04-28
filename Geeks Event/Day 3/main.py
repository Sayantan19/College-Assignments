# functions with special meaning = constructors

class Company:
    pass

emp1 = Company()
emp2 = Company()

# This won't print the necessary output as the classs attributes have not been defined.

# print(emp1.name)
# print(emp2.name)

# Now we define the attibutes of the particular class
emp1.name = "Ramesh"
emp2.name = "Suresh"

#This will show us the required attributes. It defines in the class Declaration done in line 7 and 8

print(emp1.name)
print(emp2.name)

# we are creating an object and printing its class address
