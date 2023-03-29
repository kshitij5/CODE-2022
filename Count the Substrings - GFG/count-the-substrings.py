#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
class Solution:
    def countSubstring(self, S): #User function Template for python3
        t=0
        for i in range(len(S)-1):
            c=d=0
            for j in range(i,len(S)):
                if S[j].islower():
                    c+=1
                else:
                    d+=1
                if c==d:
                    t+=1
        return t
        #code here

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        S = input()
        ob = Solution()
        ans = ob.countSubstring(S)
        print(ans)

# } Driver Code Ends