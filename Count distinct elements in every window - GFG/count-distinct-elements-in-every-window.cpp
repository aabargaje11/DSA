//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int, int> m;
        vector<int> ans(n-k+1,0);
        int count = 0;
        
        for(int i=0;i<k;i++){
            if(m[A[i]] == 0){
                count++;
            }
            m[A[i]]++;
        }
        
        int ii = 0;
        ans[ii] = count;
        ii++;
        
        for(int i=k;i<n;i++){
            m[A[i-k]]--;
            if(m[A[i-k]] == 0){
                count--;
            }
            
            if(m[A[i]]==0){
                count++;
            }
            m[A[i]]++;
            ans[ii] = count;
            ii++;
            
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends