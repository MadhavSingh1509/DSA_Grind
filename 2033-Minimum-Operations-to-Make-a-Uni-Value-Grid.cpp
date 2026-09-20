class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
    vector<int>v;

    for(auto i:grid){
        for(auto j:i)v.push_back(j);
    }
    if(v.size()==1)return 0;
    
    sort(v.begin(),v.end());
    int i=0;
    int j=v.size()-1;
    //0 1 2 3  
    int t1=j/2;
    int t2=j/2+1;
    bool f1=true;
    bool f2=true;
    int ans1=0,ans2=0;
    for(auto ele:v){
        if(abs(ele-v[t1])%x !=0)f1=false;
        if(abs(ele-v[t2])%x  !=0)f2=false;
        if(f1==false && f2==false)return -1;
        ans1+=abs(ele-v[t1])/x;
        ans2+=abs(ele-v[t2])/x;
      

    }
    return min(ans1,ans2);
    }
};