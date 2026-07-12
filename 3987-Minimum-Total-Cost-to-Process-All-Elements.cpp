class Solution {
public:
int mod=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        long ans=0;
        long res=k;
        long cost=0;
        for(auto i:nums){
            if(res<i){
                long need=i-res;
                long freq=(need+k-1)/k;
                //(cost*freq)+(freq*(freq+1))/2
                long long temp=cost*freq +(freq*(freq+1))/2;
                cost=cost+freq;
                res+=k*freq;
                
                ans=(ans+temp)%mod;
            }
            res-=i;
        }
return ans;
    }
};