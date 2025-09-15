class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        int i=0; // even pointer 
        int j=1; // odd pointer 
        while(i<n && j<n){
            if(nums[i]%2==0) i+=2;
            else if(nums[j]%2!=0) j+=2;
            else{
                swap(nums[i],nums[j]);
                i+=2;
                j+=2;
            }
        }
        return nums;
    }
};