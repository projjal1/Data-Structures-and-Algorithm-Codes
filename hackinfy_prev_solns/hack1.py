#link to soln http://prochal.com/2019/06/the-jungle-book/

#final output array
output=[]

#static content
arr=[1,-1,3,-1]
n=len(arr)

#keep count of covered nodes
count=0

#first keep track of elems with -1
a=[]
for each in range(n):
    if arr[each]==-1:
        a.append(each)
        count+=1
output.append(a)

#now we have first set of matrices let's run our algo
while(True):
    if count==n:
        break
    check=output[-1]
    a=[]
    
    for i in check:
        #for each previous covered node check if its child exist
        for j in range(n):
            #if -1 then already covered
            if arr[j]==-1:
                continue
            #if node has just been covered in last iteration add it to local array
            elif arr[j]==i:
                arr[j]=-1
                a.append(j)
                count+=1
            else:
                continue

    #add current iteration result to output array
    output.append(a)

print(output)
