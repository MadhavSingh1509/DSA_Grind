class Solution {
public:
    int longestSubsequence(vector<int>& nums) {int n=nums.size();
        int ans=0;
        bool flag=false;
        
        for(auto i:nums){if(i!=0)flag=true;
        ans^=i;}
        if(!flag)return 0;
        if(ans!=0)return n;
        return n-1;
    }
};