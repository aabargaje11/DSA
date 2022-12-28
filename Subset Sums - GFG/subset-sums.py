#User function Template for python3
class Solution:
    def getans(self, arr, N, start, sum, ans):
        if start == N:
            ans.append(sum)
            return
        
        # take
        self.getans(arr,N,start+1,sum + arr[start], ans)
        
        # not take
        self.getans(arr,N,start+1,sum, ans)
        
        
        
	def subsetSums(self, arr, N):
		ans = []
		
		
		self.getans(arr,N,0,0, ans)
		
		sorted(ans)
		return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        N = int(input())
        arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.subsetSums(arr, N)
        ans.sort()
        for x in ans:
            print(x,end=" ")
        print("")

# } Driver Code Ends