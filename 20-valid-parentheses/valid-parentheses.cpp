class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char curr=s[i];
            if(curr=='(' || curr=='{' || curr=='[') st.push(curr);
            else{
                if(st.empty()) return false;
                char c=st.top();
                if((c == '(' && curr == ')') || 
                   (c == '{' && curr == '}') || 
                   (c == '[' && curr == ']')) {
                    st.pop();
                } else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};