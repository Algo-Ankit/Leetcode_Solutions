class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int n=nums.size();

        vector<int> smal;
        vector<int> same;
        vector<int> large;

        for(int i=0;i<n;i++){
            if(nums[i]<pivot) smal.push_back(nums[i]);
            else if(nums[i]==pivot) same.push_back(nums[i]);
            else large.push_back(nums[i]);
        }

        smal.insert(smal.end(),same.begin(),same.end());
        smal.insert(smal.end(),large.begin(),large.end());

        return smal;
    }
};