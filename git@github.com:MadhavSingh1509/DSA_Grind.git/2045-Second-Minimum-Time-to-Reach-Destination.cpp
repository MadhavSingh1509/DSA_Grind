
//TODAY IS 07/07/2026
//This problem is going to be my 1000th problem on leetcode
//2024 june i did my first 100 problems
//2026 july my 1000th question
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> first(n + 1, INT_MAX);
        vector<int> second(n + 1, INT_MAX);

        queue<pair<int,int>> q;

        first[1] = 0;
        q.push({1,0});

        while (!q.empty()) {

            auto [u, curr] = q.front();
            q.pop();

            // wait if signal is red
            int depart = curr;
int intervalidx=depart/change;

            if ( intervalidx % 2 == 1) {
                int nxtintervalidx=intervalidx+1;
                depart=nxtintervalidx*change;
            }

            int arrival = depart + time;

            for (int v : adj[u]) {

                if (arrival < first[v]) {

                    second[v] = first[v];
                    first[v] = arrival;

                    q.push({v, arrival});
                }
                else if (arrival > first[v] && arrival < second[v]) {

                    second[v] = arrival;

                    q.push({v, arrival});
                }
            }
        }

        return second[n];
    }
};
