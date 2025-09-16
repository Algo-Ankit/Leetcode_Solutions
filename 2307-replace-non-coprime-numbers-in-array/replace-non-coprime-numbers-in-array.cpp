class Solution {
public:
    int gcd(int a,int b){
        while(b!=0){
            int temp = b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    long long lcm(long long a,long long b){
        return (a / gcd(a,b)) * b; // divide first to avoid overflow
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        vector<long long> st;
        for(auto num:nums){
            long long curr=num;
            while(!st.empty() && gcd(st.back(),curr)>1){
                curr=lcm(st.back(),curr);
                st.pop_back();
            }
            st.push_back(curr);
        }
        vector<int> result;
        for(auto res:st){
            result.push_back((int)res);
        }
        return result;
    }
};