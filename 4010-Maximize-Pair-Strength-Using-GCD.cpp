class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
      long long ans=0;
      int n=nums.size();
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){

            long long x=1LL*nums[i];
            long long y=1LL*nums[j];
            long long temp=(x*y)/(gcd(x,y)*gcd(x,y));
            ans=max(ans,temp);
        }
      }
      return ans;  
    }
};