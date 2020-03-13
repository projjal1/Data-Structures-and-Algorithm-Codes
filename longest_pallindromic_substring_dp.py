class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        l=len(s)
        
        if l==1 or l==0:
            return s
        
        max_word=""
        #Let's create a dp array
        dp=[]

        #Assign 0 value initially to the dp matrix
        for i in range(l):
            x=[]
            for j in range(l):
                x.append(0)
            dp.append(x)
    
        #Assigning all the elements 1  value till diagonals as single character is pallindrome
        for i in range(l):
            for j in range(i+1):
                dp[i][j]=1    

        for length_substring in range(1,l):
            #keeping track of rows
            for i in range(l-length_substring):
                j=i+length_substring
        
                val=dp[i+1][j-1]==1 and s[i]==s[j]
        
                # if true
                if val:
                    max_word=s[i:j+1]
                    dp[i][j]=1
                else:
                    continue
        
        #if no word found with length>=2
        if max_word=="":
            return s[0]
        
        return max_word

a=Solution()
print(a.longestPalindrome("Enter the string to check : "))
