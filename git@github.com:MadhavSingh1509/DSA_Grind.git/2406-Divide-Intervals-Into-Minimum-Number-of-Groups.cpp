class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        //i used hint 2:
        //the minimum number of intervals is same as maxm number of intervlas overlapping at a particular point say p;
        //how to find that poiint p where maxm number of intervals intersect?
        // this is restraunt customers of CSES
        //line sweep algorithm lgega
        //similiar problem  was also asked to me in infosys on site interview , and also a similiar problem is there in TLE eliminators sheet
        //
        vector<pair<int,int>>v;
        for(auto i:intervals){
            v.push_back({i[0],1});
            v.push_back({i[1],-1});
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            if(a.first==b.first)return a.second>b.second;
            return a.first<b.first;
        });
        int c=0,ans=1;
        for(auto i:v){
            if(i.second==1)c++;
            else c--;
            ans=max(ans,c);
        }

return ans;

    }
};