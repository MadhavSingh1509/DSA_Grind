class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> pref(m, vector<int>(n));
        vector<vector<int>> xcnt(m, vector<int>(n));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 'X') {
                    pref[i][j] = 1;
                    xcnt[i][j] = 1;
                }
                else if(grid[i][j] == 'Y') {
                    pref[i][j] = -1;
                }

                if(i > 0) {
                    pref[i][j] += pref[i-1][j];
                    xcnt[i][j] += xcnt[i-1][j];
                }

                if(j > 0) {
                    pref[i][j] += pref[i][j-1];
                    xcnt[i][j] += xcnt[i][j-1];
                }

                if(i > 0 && j > 0) {
                    pref[i][j] -= pref[i-1][j-1];
                    xcnt[i][j] -= xcnt[i-1][j-1];
                }

                if(pref[i][j] == 0 && xcnt[i][j] > 0)
                    ans++;
            }
        }
        
        return ans;
    }
};