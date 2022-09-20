/*struct TrieNode{
    struct TrieNode *charr[26];
    bool isEnd;
    
  TrieNode(){
      for(int i = 0; i < 26; i ++){
          charr[i] = NULL;
      }
      isEnd = false;
  }
    
};
class WordDictionary {
public:
    TrieNode * root = new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode * temp = root;
        
        for(auto c:word){
            int index = c - 'a';
            if(!temp->charr[index]){
                temp->charr[index] = new TrieNode();
            }
            temp = temp->charr[index];
        }
        
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode * temp = root;
        return search(word, 0 ,temp);
    }
    bool search(string word, int index, TrieNode* root) {
        if(index == word.size()) return root->isEnd;
        
        char c = word[index];
        
        if(c!= '.'){
            if(root->charr[c- 'a'] == NULL) return false;
            return search(word, index+1, root->charr[c-'a']);
        }
        else{
            bool ans = false;
            
            for(int i=0;i<26;i++){
                if(!root->charr[i]) continue;
                if(search(word, index+1, root->charr[i])) return true;
            }
            
            return false;
        }
        return false;
    }
};
*/
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class WordDictionary {
public:
    
    WordDictionary *child[26] = {};
    bool isWord = false;
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        WordDictionary *root = this;
        for(char &x : word) {
            int ind = x-'a';
			// check if the child already exists, create if not
            if(!root->child[ind]) root->child[ind] =  new WordDictionary();
            root = root->child[ind];
        }
        root->isWord = true;
    }
    
    bool search(string word) {
        return search(word, 0, this);
    }
    
	/* Start with index 0 and recursively check if the string matches with our existing WordDictionary
	Conditional validations for each index include,
	- If the index contains a character which is not "." -> then check if the character exists as child of root & proceed to the next index
	- If the index contains "." -> recursively call the search function for all the available 26 childs and proceed with the next index
	- Termination Condition : When we complete all the characters of the given word (index == word.length()), check if the root is a valid word here (using root->isWord) and return accordingly. */
	
    bool search(string &word, int ind, WordDictionary *root) {
        if(ind==word.length()) return root->isWord;
        char x = word[ind];
        if(x!='.') {
            return root->child[x-'a'] && search(word, ind+1, root->child[x-'a']);
        }
        else {
            for(int i=0;i<26;i++) {
                if(root->child[i] && search(word, ind+1, root->child[i])) return true;
            }
            return false;
        }
        return root->isWord;
    }
};