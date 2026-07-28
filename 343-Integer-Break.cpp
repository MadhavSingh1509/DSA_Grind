class Solution {
public:
//bruteforce TC: {n* n^(n-1)}
//optimal TC :n*(n-1)=o of n sq
int dp[58];
int f(int x){
if(x==1)return 1;
if(dp[x]!=-1)return dp[x];
    int res=INT_MIN;
for(int j=1;j<x;j++){
    int prod=j*max(x-j,f(x-j));
    res=max(res,prod);
}
return dp[x]=res;
}
    int integerBreak(int n) {
       memset(dp,-1,sizeof(dp));
       return f(n); 
    }
};