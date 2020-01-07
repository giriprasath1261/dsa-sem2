
from random import randint, sample ,shuffle

t = randint(1,5000)

print(str(t))

letters = ["a","b","c","d","e"]

for i in range(t):
    n = randint(1,13)
    samp = sample(letters*100,n)
    print("".join(samp))

k = randint(1,4000)

print(str(k))

for i in range(k):
    x = ""
    l = randint(1,3)
    ques = ["?"]
    r = randint(0,10)
    temp = sample(ques*3,l) + sample(letters*100,r)
    shuffle(temp)
    x += str("".join(temp))
    print(x)
