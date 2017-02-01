f = open("increasing_elements.txt", 'w')

for i in range(1,1000):
    for j in range(1000):
        f.write(str(i))
        f.write(' ')

for j in range(1000):
        f.write(str(1000))
        f.write(' ')


f.close()