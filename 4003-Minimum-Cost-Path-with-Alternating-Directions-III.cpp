#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long INF = 1e18;
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, INF)));

        using state = tuple<long long, int, int, int>;
        priority_queue<state, vector<state>, greater<state>> pq;

        dist[0][0][1] = 1;
        pq.push({1, 0, 0, 1});

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        while (!pq.empty()) {
            auto [cst, r, c, p] = pq.top();
            pq.pop();

            if (cst > dist[r][c][p]) continue;
            if (r == m - 1 && c == n - 1) return cst;

            int np = 1 - p;

            long long wc = cst + penalty[r][c];
            if (wc < dist[r][c][np]) {
                dist[r][c][np] = wc;
                pq.push({wc, r, c, np});
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    bool ok = ((p == 1 && (i == 0 || i == 1)) || (p == 0 && (i == 2 || i == 3)));
                    long long mc = cst + 1LL * (nr + 1) * (nc + 1) + (ok ? 0 : penalty[r][c]);

                    if (mc < dist[nr][nc][np]) {
                        dist[nr][nc][np] = mc;
                        pq.push({mc, nr, nc, np});
                    }
                }
            }
        }

        return min(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
    }
};