class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> pref(m, vector<int>(n, 0));
        vector<bool> hasX(n, false);

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

            
                if(grid[i][j] == 'X')
                    pref[i][j] = 1;
                else if(grid[i][j] == 'Y')
                    pref[i][j] = -1;

                
                if(i > 0)
                    pref[i][j] += pref[i-1][j];

                if(j > 0)
                    pref[i][j] += pref[i][j-1];

                if(i > 0 && j > 0)
                    pref[i][j] -= pref[i-1][j-1];

                
                hasX[j] = hasX[j] || (j > 0 && hasX[j-1]) 
                                   || (grid[i][j] == 'X');

                
                if(pref[i][j] == 0 && hasX[j])
                    ans++;
            }
        }

        return ans;
    }
};