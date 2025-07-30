class Solution {
public:
    vector<int> dp;
    int rec(int level,vector<int>&nums){
        int n=nums.size();
        if(level>=n-1) return 0;
        if(dp[level]!=-1) return dp[level];
        int res = INT_MAX;
        for(int i=1;i<=nums[level];i++){
            if(i+level<n){
                int sol=rec(i+level,nums);
                if(sol!=INT_MAX){
                    res=min(1+sol,res);
                }
            }
        }
        return dp[level]=res;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n+1,-1);
        return rec(0,nums);
    }
};