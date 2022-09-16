class Twitter {
    int tweetCount = 0;
    //tweetNumber, userId, tweetId
    priority_queue<vector<int>> q;
    unordered_map<int, set<int>> foll;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        q.push({tweetCount, userId, tweetId});
        tweetCount++;
    }
    
    vector<int> getNewsFeed(int userId) {
        int count = 0;
        vector<int> ans;
        set<int> ss = foll[userId];
        priority_queue<vector<int>> temp = q;
        while(count != 10 and !temp.empty()){
            vector<int> v= temp.top();
            temp.pop();
            if(ss.find(v[1])!=ss.end() or v[1] == userId){
                ans.push_back(v[2]);
                count++;
            }
        }
        
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        foll[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        foll[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */