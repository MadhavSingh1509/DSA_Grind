class Solution {
public:
    vector<int> dp;

    int f(int x) {

        if(x == 0)
            return 0;

        if(dp[x] != -1)
            return dp[x];

        int ans = INT_MAX;

        int k = 1;
        int t = 1;

        while(t <= x) {

            int rem = x - t;

            int cost = f(rem) + k + (rem > 0 ? 1 : 0);

            ans = min(ans, cost);

            k++;
            t += k;
        }

        return dp[x] = ans;
    }

    int minDays(int n) {
        dp.assign(n + 1, -1);

        return f(n);
    }
};