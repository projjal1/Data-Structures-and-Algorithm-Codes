'''A rotation on a string is defined as removing first element and concatenating it at the end
Given a number N and N strings .
Output the minimum no. of rotations on the strings so as to make all the strings equal.
If this is not possible print -1.

Input
4
11234
34112
41123
11234

Output 
3
'''

def compute(s,target_length,target):
    count=0
    for each in s:
        l=len(each)
        if l!=target_length:
            return -1
        else:
            #check if existing string is already equal
            if each==target:
                continue
            #perform rotations
            new_str=each
            for j in range(l-2):
                new_str=new_str[1:]+new_str[0]
                count+=1
                if new_str==target:
                    break
    return count

n=int(input())

target=input()
target_length=len(target)

count=0

s=[]

for each in range(n-1):
    s.append(input())

x=compute(s,target_length,target)
print(x)



