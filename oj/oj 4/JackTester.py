from random import randint

n = randint(1,50000)
t = randint(n-1,10000000)

print(str(n))
print((str(t)))

x = ""
for i in range(n-1):
    x+= str(randint(1,1000000)) + " "

print(x)

x = ""
for i in range(n-2):
    x+= str(randint(1,100000)) + " "

print(x)
