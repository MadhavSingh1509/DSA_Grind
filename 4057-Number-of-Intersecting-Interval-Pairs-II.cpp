class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>v;
        for(auto it:intervals){
            v.push_back({it[0],1});
            v.push_back({it[1],-1});
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
    if(a.first==b.first)return a.second>b.second;
return a.first<b.first;});
int curr=0;
long long ans=0;
for(auto [y,x]:v){
    if(x==1){ans+=curr;curr++;}
    else curr--;
}
return ans;
    }
};