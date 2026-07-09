class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void Union(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);

        for (int i = 0; i < n - 1; i++) {
    if (nums[i + 1] - nums[i] <= maxDiff)
        dsu.Union(i, i + 1);
}

        vector<bool> ans;
        for (auto &q : queries)
            ans.push_back(dsu.findParent(q[0]) == dsu.findParent(q[1]));

        return ans;
    }
};