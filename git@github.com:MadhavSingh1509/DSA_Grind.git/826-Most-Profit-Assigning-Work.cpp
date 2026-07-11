class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {

        vector<pair<int,int>> jobs;

        for (int i = 0; i < difficulty.size(); i++)
            jobs.push_back({difficulty[i], profit[i]});

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int i = 0;
        int best = 0;
        int ans = 0;

        for (int ability : worker) {

            while (i < jobs.size() && jobs[i].first <= ability) {
                best = max(best, jobs[i].second);
                i++;
            }

            ans += best;
        }

        return ans;
    }
};