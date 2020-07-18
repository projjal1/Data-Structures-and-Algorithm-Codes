arr=[int(x) for x in input().split()]
l=len(arr)

s=sum(arr)
mid=s//2

flags=[]

for i in range(l):
    sep=[]
    for j in range(mid+1):
        sep.append(False)
    flags.append(sep)

for i in range(l):
    flags[i][0]=True 
    
for j in range(mid+1):
    if j==arr[0]:
        flags[0][j]=True 
     
     
for i in range(1,l):
    for j in range(1,mid+1):
        if flags[i-1][j]:
            flags[i][j]=True 
        else: 
            if j>=arr[i]:
                flags[i][j]=flags[i-1][j-arr[i]]
                
s1,s2=0,0
               
for j in range(mid,-1,-1):
    if flags[-1][j]:
        s1=j;
        break
    
s2=s-s1

print(max(s1,s2))
    
    