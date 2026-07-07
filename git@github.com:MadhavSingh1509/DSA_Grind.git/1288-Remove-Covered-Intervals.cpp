class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });

        int maxTime = 0;
        int count = 0;

        for (auto interval : intervals) {
            if (interval[1] > maxTime) {
                maxTime = interval[1];
                count++;
            }
        }
        return count;
    }
};
