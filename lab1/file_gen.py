import random 
f = open("random_elements_large.txt", 'w')

for i in range(1000000-1):
    f.write(str(random.randint(1000000, 1000000000-1)))
    f.write(' ')

f.write("1000000000")
f.close()
271608258