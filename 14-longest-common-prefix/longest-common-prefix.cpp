struct trieNode{
        int string_below;
        int string_end;
        trieNode *children[26];
        trieNode(){
            string_below=0;
            string_end=0;
            for(int i=0;i<26;i++) children[i]=NULL;
        }
    };
    class Trie{
    public:
        // Initializing Trie
        trieNode *root;
        Trie(){
            root=new trieNode();
        }

        void insert(string s){
            trieNode *curr=root;
            for(auto ch:s){
                if(curr->children[ch-'a']==NULL)
                    curr->children[ch-'a']=new trieNode();
                curr=curr->children[ch-'a'];
                curr->string_below++;
            }
            curr->string_end++;
        }
        string lcp(){
            string s="";
            trieNode *curr=root;
            while(true){
                int count=0,index=-1;
                for(int i=0;i<26;i++){
                    if(curr->children[i]!=NULL){
                        count++;
                        index=i;
                    }
                }
                if(count==1 && curr->string_end==0){
                    s.push_back('a'+index);
                    curr=curr->children[index];
                }
                else break;
            }
            return s;
        }
    };

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t=new Trie();
        for(auto s:strs)
            t->insert(s);
        return t->lcp();

    }
};