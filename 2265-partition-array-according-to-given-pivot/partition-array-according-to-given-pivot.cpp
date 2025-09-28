class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int less=0,equal=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) less++;
            else if(nums[i]==pivot) equal++;
        }

        vector<int> ans(n);
        int ii=0,j=less,k=less+equal;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[ii]=nums[i];
                ii++;
            }
            else if(nums[i]==pivot){
                ans[j]=nums[i];
                j++;
            }
            else{
                ans[k]=nums[i];
                k++;
            }
        }
        return ans;
    }
};