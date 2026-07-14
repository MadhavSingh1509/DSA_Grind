class Solution {
public:
    const int MOD = 1e9 + 7;
    const int NEG = -1e9;

    int n;
    vector<string> board;
    vector<vector<int>> dp;

    // Returns maximum score from (i,j) to S.
    int dfs(int i, int j) {

        // Out of bounds or obstacle.
        if (i >= n || j >= n || board[i][j] == 'X')
            return NEG;

        // Reached destination.
        if (i == n - 1 && j == n - 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int best = max({dfs(i + 1, j),
                        dfs(i, j + 1),
                        dfs(i + 1, j + 1)});

        // Destination cannot be reached.
        if (best == NEG)
            return dp[i][j] = NEG;

        int val = 0;

        if (board[i][j] != 'E')
            val = board[i][j] - '0';

        return dp[i][j] = best + val;
    }

    vector<int> pathsWithMaxScore(vector<string>& b) {

        board = b;
        n = board.size();

        dp.assign(n, vector<int>(n, -1));

        // Phase 1:
        // Compute maximum score using memoization.
        int mx = dfs(0, 0);

        if (mx < 0)
            return {0, 0};

        // Phase 2:
        // Count number of maximum-score paths.
        vector<vector<int>> ways(n, vector<int>(n, 0));

        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X')
                    continue;

                if (i == n - 1 && j == n - 1)
                    continue;

                int best = NEG;

                if (i + 1 < n)
                    best = max(best, dp[i + 1][j]);

                if (j + 1 < n)
                    best = max(best, dp[i][j + 1]);

                if (i + 1 < n && j + 1 < n)
                    best = max(best, dp[i + 1][j + 1]);

                if (best == NEG)
                    continue;

                long long cnt = 0;

                if (i + 1 < n && dp[i + 1][j] == best)
                    cnt += ways[i + 1][j];

                if (j + 1 < n && dp[i][j + 1] == best)
                    cnt += ways[i][j + 1];

                if (i + 1 < n && j + 1 < n &&
                    dp[i + 1][j + 1] == best)
                    cnt += ways[i + 1][j + 1];

                ways[i][j] = cnt % MOD;
            }
        }

        return {mx, ways[0][0]};
    }
};