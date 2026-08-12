class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
int m,n;
m=matrix.size();
n=matrix[0].size();
int ans=0;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(i>0&&matrix[i][j]==1)matrix[i][j]=matrix[i-1][j]+1;
    
    }
    vector<int>heights=matrix[i];
        sort(heights.rbegin(),heights.rend());
        for(int j=0;j<n;j++){
            int width=j+1;
            int area=width*heights[j];
            ans=max(ans,area);
        }
}
return ans;
    }
};