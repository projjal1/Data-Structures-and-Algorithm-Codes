'''N<=1e50
Output the no. of pairs (x,y) such that
1. 0<=x<=n
2. 0<=y<=n
3. F(x) +F(y) =Prime no.
F(x) = sum of digits of x
(x,y) and (y,x) are to be treated as same pair
Input
3
ouput
5
Explaination
5 pairs (0,2) (1,1) (0,3) (2,3)(1,2) give prime no.s.'''

def isPrime(n):
    if n==0 or n==1:
        return False
    for k in range(2,int(n**0.5)+1):
        if n%k==0:
            return False 
    return True 

n=int(input())

count=0

for i in range(n+1):
    for j in range(i+1):
        if isPrime(i+j)==True:
            count+=1

print(count)

