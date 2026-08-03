class Solution {
public:
    int n;
    
    int dp[50001][2];
    int f(vector<int>&piles,int i,int turn){
if(i==n)return 0;
        //alice turn:choose from 1 to 2m
        if(dp[i][turn]!=-1)return dp[i][turn];

       int ans=turn==1?INT_MIN:INT_MAX;
        int sum=0;
        for(int j=i;j<n&&j<i+3;j++){
            sum+=piles[j];
        
            int newturn=turn==1?0:1;
if(turn==1)ans=max(ans,sum+f(piles,j+1,newturn));
else ans=min(ans,-sum+f(piles,j+1,newturn));
        }
        return dp[i][turn]=ans;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        int x=f(stoneValue,0,1);
     if(f(stoneValue,0,1)>0)return "Alice";
     else if(x<0)return "Bob";
     else return "Tie";



    }
};