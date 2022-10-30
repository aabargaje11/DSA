class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        
        stack<string> s;
        int len = path.size();

        int i=0;
        while(i<len-1){
            string temp="";
            
            while(true and i<len-1){
                i++;
                if(path[i]=='/')
                    break;
                temp+=path[i];  
                
            }
            
            if(temp == "." or temp =="")
                continue;
            if(temp == ".."){                
                if(!s.empty())
                    s.pop();                
            }

            else{
                s.push(temp);
                cout<<temp<<endl;
            }
                

                
        }
        
        while(!s.empty()){
            ans =  "/" + s.top() + ans;
            s.pop();
        }
        if(ans == ""){
            ans = "/";
        }
        
        return ans;
        
    }
};