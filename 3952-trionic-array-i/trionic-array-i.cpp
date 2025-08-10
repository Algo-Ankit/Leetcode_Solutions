class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        vector<int> changes;
        for(int i=1;i<nums.size();i++){
            int val=0;
            if(nums[i]>nums[i-1]) val=1;
            if(nums[i]<nums[i-1]) val=-1;
            
            if(changes.empty() || val!=changes.back()) changes.push_back(val);
        }
        vector<int> target={1,-1,1};
       return (changes==target);
    }
};