#print pairs (i,j) such that a[i]+a[j] is divisible by k

n,k=list(map(int,input().split()))

arr=list(map(int,input().split()))
arr.sort()

count=0

for i in range(n-1):
    no1=arr[i]
    for j in range(i+1,n):
        no2=arr[j]
        if (no1+no2)%k==0:
            count+=1

print(count)