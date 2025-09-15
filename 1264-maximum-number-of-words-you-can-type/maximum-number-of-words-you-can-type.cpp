class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        vector<bool> letter(26,false);
        for(auto c:brokenLetters){
            letter[c-'a']=true;
        }

        istringstream iss(text);
        string word;
        int count=0;
        while(iss >> word){
            bool valid=true;
            for(auto a:word){
                if(letter[a-'a']==true){
                    valid=false;
                    break;
                }
            }
            if(valid) count++;
        }
        return count;  
    }
};