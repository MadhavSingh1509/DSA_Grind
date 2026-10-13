class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> m;

        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        vector<bool> vis(n, false);

        q.push({0, 0});
        vis[0] = true;

        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();

            if (node == n - 1) return d;

            // Jump to the previous index
            if (node > 0 && !vis[node - 1]) {
                vis[node - 1] = true;
                q.push({node - 1, d + 1});
            }

            // Jump to the next index
            if (node + 1 < n && !vis[node + 1]) {
                vis[node + 1] = true;
                q.push({node + 1, d + 1});
            }

            // Jump to all indices having the same value
            
                for (int idx : m[arr[node]]) {
                    if (!vis[idx]) {
                        vis[idx] = true;
                        q.push({idx, d + 1});
                    }
                }

                // Process each value group only once
                m.erase(arr[node]);
            
        }

        return -1;
    }
};