#count occurances of substring in string 

#string
s=input("Enter string: ")

#length of string
n=len(s)

#pattern
p=input("Enter the pattern: ")

#length of pattern
k=len(p)

count=0

for each in range(n-k+1):
    next_sub=s[each:each+k]
    if next_sub==p:
        count+=1

print(count)