class Solution {
public:

    bool flag = true;

    void f(int u, unordered_set<int>& st, vector<vector<int>>& adj) {
        st.insert(u);

        for(auto v : adj[u]) {
            if(!st.count(v))
                f(v, st, adj);
        }
    }

    void dfs(int u, vector<int>& vis, vector<vector<int>>& adj,
             unordered_set<int>& st) {

        if(st.count(u)) {
            flag = false;
            return;
        }

        vis[u] = true;

        for(auto v : adj[u]) {
            if(!vis[v])
                dfs(v, vis, adj, st);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for(auto x : invocations) {
            adj[x[0]].push_back(x[1]);
        }

        // Mark all suspicious methods reachable from k
        unordered_set<int> st;
        f(k, st, adj);

        // From every non-suspicious method,
        // check if we can reach a suspicious method
        vector<int> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(!st.count(i) && !vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> ans;

        // If some non-suspicious method invokes a suspicious method,
        // we cannot remove the suspicious methods alone.
        if(flag == false) {
            for(int i = 0; i < n; i++)
                ans.push_back(i);
        }
        else {
            for(int i = 0; i < n; i++) {
                if(!st.count(i))
                    ans.push_back(i);
            }
        }

        return ans;
    }
};