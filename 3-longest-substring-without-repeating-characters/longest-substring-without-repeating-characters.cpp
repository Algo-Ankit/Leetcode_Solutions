class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxlen=0,start=0,end=0;
        while(end<s.size()){
            if(st.find(s[end])==st.end()){
                st.insert(s[end]);
                maxlen=max(maxlen,end-start+1);
                end++;
            }else{
                st.erase(s[start]);
                start++;
            }
        }
        return maxlen;
    }
};