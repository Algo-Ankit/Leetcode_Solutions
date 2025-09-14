class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int numberofoperations=0;
        for(int i=0;i<n-1;i++){
           if(nums[i]>=nums[i+1]){
                int diff=abs(nums[i]-nums[i+1]);
                nums[i+1]=nums[i+1]+diff+1;
                numberofoperations += diff+1;
            }
        }
        return  numberofoperations;
    }
};