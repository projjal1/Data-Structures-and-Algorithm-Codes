#Calculate the max sum from given array substring

n=int(input("Enter the size of array : "))
arr=list(map(int,input("Enter elements sep by space : ").split()))

max=0

#Iterate through array
for each in arr:
    s=max+each 
    #check if this element sum is more than max
    if s>max:
        #set max as 
        max=s 
    else:
        #discard the element summations
        continue 
    print(max)

#none element substring found
if max==0:
    #return the smallest element
    print(min(arr))
else:
    print(max)