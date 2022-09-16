class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        // min heap
        // as we want have minimum sum
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<vector<int>> ans;
        map<pair<int, int>, int> mapp;
        
        q.push({nums1[0]+nums2[0],0,0});
        mapp[{0,0}] = 1;
        
        int len1 = nums1.size(), len2 = nums2.size();
        while(!q.empty()){
            vector<int> temp = q.top();
            int i = temp[1], j = temp[2];
            // cout<<i <<" "<<j<<endl;
            q.pop();
            
            ans.push_back({nums1[i], nums2[j]});
                                           
            if(ans.size() == k) break;
            if(i+1 < len1 and !mapp[{i+1,j}]){
                q.push({nums1[i+1] + nums2[j], i+1,j});
                mapp[{i+1,j}] = 1;
            }
            if(j+1 < len2 and !mapp[{i,j+1}]){
                q.push({nums1[i] + nums2[j+1], i,j+1});
                mapp[{i,j+1}] = 1;
            }
  
        }
        
                                           
         return ans;
        
    }
};