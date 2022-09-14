struct Trie{
    struct Trie * ch[26] ;
    bool end;
    
};

class Solution {
public:
    void insert(Trie* root, string str){
        int len = str.size();
        for(int i=0;i<len;i++){
            int index = str[i] - 'a';
            if(!root->ch[index]){
                root->ch[index] = new Trie();
            }
            
            root = root->ch[index];
        }
        
        root->end = true;
    }
    void solve(Trie* root, vector<string> &temp, string str){
        if(temp.size() == 3) return;
        if(!root) return;
        if(root->end){
            temp.push_back(str);
        }
        // cout<<"In: "<<str<<endl;
        for(int i=0;i<26;i++){
            if(!root->ch[i]) continue;
            // cout<<"test"<<endl;
            solve(root->ch[i], temp, str+ char(i+97));
            
        }
        
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();
        vector<vector<string>> ans;
        
        for(auto s:products){
            insert(root, s);
        }
        Trie* curr = root;
        string tstr = "";
        for(auto c:searchWord){
            tstr+= c;
            vector<string> temp;
            if(curr != NULL){
                curr = curr->ch[c-'a'];
                solve(curr, temp, tstr);
                ans.push_back(temp);
            }
            else{
                ans.push_back({});
            }

        }
        
        return ans;
    }
};