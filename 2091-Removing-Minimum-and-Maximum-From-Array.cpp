class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i=-1,j=-1;
        int n=nums.size();
        int minii=*min_element(nums.begin(),nums.end());
        int maxii=*max_element(nums.begin(),nums.end());
        for(int x=0;x<n;x++){
            if(nums[x]==minii)i=x;
            if(nums[x]==maxii)j=x;
        }
        int ans=1e6;
     //   if(n==1)return 1;
        ans=min(ans,max(i,j)+1);
        ans=min(ans,n-min(i,j));
        ans=min(ans,min(i,j)+1+n-max(i,j));
        return ans;
        // 0 1 2 3 4 5 
    }
};