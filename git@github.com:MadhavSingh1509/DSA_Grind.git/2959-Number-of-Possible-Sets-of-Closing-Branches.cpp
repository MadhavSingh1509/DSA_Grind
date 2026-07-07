class Solution {
public:
    int n, maxDistance;
    vector<vector<int>> roads;

    int solve(int i, int mask) {
        if (i == n) {
            const int INF = 1e9;
            vector<vector<int>> dist(n, vector<int>(n, INF));

            // distance to self
            for (int u = 0; u < n; u++) {
                if (mask & (1 << u))
                    dist[u][u] = 0;
            }

            // add only those roads whose both endpoints are selected
            for (auto &r : roads) {
                int u = r[0];
                int v = r[1];
                int wt = r[2];

                if ((mask & (1 << u)) && (mask & (1 << v))) {
                    dist[u][v] = min(dist[u][v], wt);
                    dist[v][u] = min(dist[v][u], wt);
                }
            }

            // Floyd-Warshall
            for (int k = 0; k < n; k++) {
                if (!(mask & (1 << k))) continue;

                for (int u = 0; u < n; u++) {
                    if (!(mask & (1 << u))) continue;

                    for (int v = 0; v < n; v++) {
                        if (!(mask & (1 << v))) continue;

                        if (dist[u][k] == INF || dist[k][v] == INF)
                            continue;

                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }

            // Check validity
            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u))) continue;

                for (int v = 0; v < n; v++) {
                    if (!(mask & (1 << v))) continue;

                    if (dist[u][v] > maxDistance)
                        return 0;
                }
            }

            return 1;
        }

        // Don't take node i
        int ans = solve(i + 1, mask);

        // Take node i
        ans += solve(i + 1, mask | (1 << i));

        return ans;
    }

    int numberOfSets(int N, int maxDist, vector<vector<int>>& r) {
        n = N;
        maxDistance = maxDist;
        roads = r;

        return solve(0, 0);
    }
};