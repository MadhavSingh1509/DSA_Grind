class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(first[idx]==-1)first[idx]=i;
            last[idx]=i;
        }
        vector<pair<int,int>>intervals;
        for(int i=0;i<26;i++){
            if(first[i]==-1)continue;
            bool found=true;
int l=first[i];
int r=last[i];
for(int idx=l;idx<=r;idx++){
    int x=s[idx]-'a';
    if(first[x]<l){found=false;break;}
r=max(r,last[x]);

}
if(found)intervals.push_back({l,r});
        }
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a.second<b.second;
        });
        vector<string>ans;
        int prevend=-1;
        for(auto [l,r]:intervals){
            if(prevend<l){ans.push_back(s.substr(l,r-l+1));prevend=r;}
        }
        return ans;
    }
};