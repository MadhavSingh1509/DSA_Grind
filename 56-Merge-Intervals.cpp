class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());//nlogn
        int l=intervals[0][0];
        int r=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=r){r=max(intervals[i][1],r);
            continue;}
            ans.push_back({l,r});
            l=intervals[i][0];
            r=intervals[i][1];
        
        }
        ans.push_back({l,r});
        return ans;
    }
};