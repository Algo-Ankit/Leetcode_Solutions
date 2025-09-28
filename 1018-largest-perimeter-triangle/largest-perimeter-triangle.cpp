class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
       int n=nums.size();
       if(n<3) return 0;
       sort(nums.begin(),nums.end());

       for (int i = n - 3; i >= 0; --i) {
            // use long long for the sum check to be safe against overflow
            if ((long long)nums[i] + nums[i+1] > nums[i+2]) {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
       return 0;
    }
};