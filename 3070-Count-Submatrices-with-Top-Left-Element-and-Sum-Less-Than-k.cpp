class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int c=0;int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>pref(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pref[i][j]=grid[i][j];
                if(i>0)pref[i][j]+=pref[i-1][j];
                if(j>0)pref[i][j]+=pref[i][j-1];
                if(i>0  &&  j>0)pref[i][j]-=pref[i-1][j-1];


            }
        }
        for(int i2=0;i2<m;i2++){
    for(int j2=0;j2<n;j2++){
        int sum=pref[i2][j2];
        if(sum<=k)c++;
    }
}

return c;
    }
};