
tar = int(input())

for i in range(1, 100):
    num = pow(i, i) 
    if num > tar: break
    if num == tar:
        print(i)
        exit()
    

print(-1)