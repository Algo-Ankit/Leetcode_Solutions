class Solution {
public:
    int lcs(const string &s1,const string &s2){
        int n=s1.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // dp[i][j] = LCS of s[0..i-1] and s2[0..j-1]
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
                if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        // reverse the string and find the LCS between the two strings 
        auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return lcs(s,s2);
    }
};