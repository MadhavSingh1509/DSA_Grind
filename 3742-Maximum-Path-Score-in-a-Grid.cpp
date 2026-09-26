class Solution {
public:
//SOLVING AGAIN WITH TAKING STATIC ARRAY DP
int dp[201][201][400];
    int f(vector<vector<int>>&grid,int i,int j,int cost,int sum,int m,int n,int k){
        if(i==m||j==n)return INT_MIN;
        
        int addcost=0;
int addscore=0;
if(grid[i][j]==1){addcost=1;
addscore=1;
}
if(grid[i][j]==2){addcost=1;
addscore=2;
}
if(cost+addcost>k)return INT_MIN;//pruning and early exiting of the code
if(i==m-1&&j==n-1){
    sum+=addscore;
    cost+=addcost;
    if(cost>k)return INT_MIN;
    return addscore;
}

if(dp[i][j][cost]!=-1)return dp[i][j][cost];

int x=INT_MIN;
int y=INT_MIN;
x=f(grid,i+1,j,cost+addcost,sum,m,n,k);
y=f(grid,i,j+1,cost+addcost,sum,m,n,k);


        return dp[i][j][cost]=max(x,y)+addscore;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {memset(dp,-1,sizeof(dp));
    int sum=0;
    int m=grid.size();
    int n=grid[0].size();
        int ans=f(grid,0,0,0,sum,m,n,k);
        if(ans<0)return -1;
        return ans;
    }
};