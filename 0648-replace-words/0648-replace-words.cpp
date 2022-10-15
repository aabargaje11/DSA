struct TriNode{
    struct TriNode* arr[26];
    bool isEnd;
    
};

class Solution {
public:
    void insert(TriNode *root, string str){
        TriNode * temp = root;
        for(auto c:str){
            int index = c - 'a';
            if(!temp->arr[index]){
                temp->arr[index] = new TriNode();
            }
            temp = temp->arr[index];
        }
        
        temp->isEnd = true;
    }
    string get_ans(string str, TriNode* root){
        
        string subans = "";
        // cout<<str<<" "<<str.size()<<endl;
        
        for(auto c:str){
            int index = c - 'a';
            subans = subans + c;
            if(root->isEnd){
                subans.erase(subans.end()-1);
                return subans;
            }
            else if(!root->arr[index]){
                return str;
            }
            else if(root->arr[index]){
                root = root->arr[index];
            }
            
        }
        
        
        return str;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        TriNode *root = new TriNode();
        for(auto s:dictionary){
            insert(root, s);
        }
        string ans = "";
        
        int i = sentence.size();
        vector<string>s;
        int j = 0;

        istringstream ss(sentence);
        string part;
        
        while(getline(ss, part, ' ')){
            ans = ans + get_ans(part, root);
            ans  = ans + " ";
            
        }
        ans.erase(ans.end()-1);
        
        return ans;
    }
};