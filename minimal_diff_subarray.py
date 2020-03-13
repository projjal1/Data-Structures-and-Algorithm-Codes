arr=list(map(int,input("Input the String of integers : ").split()))
n=len(arr)

min=99999999

arr.sort()

temp=0

for x in range(1,n):
    sum1=sum(arr[:x])
    sum2=sum(arr[x:])

    diff=abs(sum1-sum2)

    if diff<min:
        min=diff

    else:
        print(arr[:x-1])
        print(arr[x-1:])
        break

