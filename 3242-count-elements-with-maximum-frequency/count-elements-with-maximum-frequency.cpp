class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> arr(102);
        for(int i:nums){
            arr[i]++;
        }
        int maxfreq=*max_element(arr.begin(),arr.end());
        int total=0;
        for (int f : arr) {
            if (f == maxfreq) total += f;
        }
        return total;
    }
};