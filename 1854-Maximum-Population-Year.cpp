class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
       int ans=0;
       int maxii=0;
       int curr=0;
       vector<pair<int,int>>v;
       for(auto it:logs){
        v.push_back({it[0],1});
        v.push_back({it[1]-1,-1});
       } 
       sort(v.begin(),v.end(),[](auto &a,auto &b){
        if(a.first==b.first)return a.second>b.second;
        return a.first<b.first;
       });
       for(auto [y,c]:v)cout<<y<<"->"<<c<<endl;
for(auto [y,c]:v){
    curr+=c;
    if(curr>maxii){ans=y;maxii=curr;}
}
    return ans;   
    }
};