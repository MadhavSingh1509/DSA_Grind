class Solution {
public:
    int m, n;

    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<int> temp;

        for (int i1 = 0; i1 < m; i1++) {
            for (int j1 = 0; j1 < n; j1++) {

                // sz = vertical distance from top to bottom
                for (int sz = 0; i1 + sz < m; sz += 2) {

                    int i2 = i1 + sz;
                    int j2 = j1;

                    int i3 = i1 + sz / 2;
                    int j3 = j1 - sz / 2;

                    int i4 = i1 + sz / 2;
                    int j4 = j1 + sz / 2;

                    if (!valid(i3, j3) || !valid(i4, j4))
                        continue;

                    // Single cell rhombus
                    if (sz == 0) {
                        temp.push_back(grid[i1][j1]);
                        continue;
                    }

                    int sum = 0;

                    // Top -> left
                    for (int k = 0; k <= sz / 2; k++)
                        sum += grid[i1 + k][j1 - k];

                    // Top -> right
                    for (int k = 0; k <= sz / 2; k++)
                        sum += grid[i1 + k][j1 + k];

                    // Left -> bottom
                    for (int k = 0; k <= sz / 2; k++)
                        sum += grid[i3 + k][j3 + k];

                    // Right -> bottom
                    for (int k = 0; k <= sz / 2; k++)
                        sum += grid[i4 + k][j4 - k];

                    // Four corners were counted twice
                    sum -= grid[i1][j1];
                    sum -= grid[i2][j2];
                    sum -= grid[i3][j3];
                    sum -= grid[i4][j4];

                    temp.push_back(sum);
                }
            }
        }

        sort(temp.rbegin(), temp.rend());

        vector<int> ans;

        for (int x : temp) {
            if (ans.empty() || ans.back() != x)
                ans.push_back(x);

            if (ans.size() == 3)
                break;
        }

        return ans;
    }
};