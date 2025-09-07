class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1 += nums1[i];
            sum2 += nums2[i];
        }
        int ans=max(sum1,sum2);

        vector<int> diff(n);
        for(int i=0;i<n;i++)
            diff[i] = nums2[i]-nums1[i];
        // Kadane's algorithm -> to find the max sum subarray in array of diff

        int kadaneSum=0;
        int c=0;

        for(int i=0;i<n;i++){
            kadaneSum+=diff[i];
            c=max(c,kadaneSum);
            if(kadaneSum>0) ans=max(ans,sum1+c);
            else kadaneSum=0;
        }

        for(int &d:diff) d *= -1; // Multiplying every value of diff with -1 , as we reverse the b-a to a-b

        kadaneSum=0,c=0;
        for(int i=0;i<n;i++){
            kadaneSum+=diff[i];
            c=max(c,kadaneSum);
            if(kadaneSum>0) ans=max(ans,sum2+c);
            else kadaneSum=0;
        }
        
        return ans;
    }
};