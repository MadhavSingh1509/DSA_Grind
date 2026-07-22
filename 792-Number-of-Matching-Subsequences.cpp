class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=s.size();
        vector<vector<int>>v(n,vector<int>(26,-1));
        for(int i=n-1;i>=0;i--){
        char ch=s[i];
        if(i<n-1)v[i]=v[i+1];
        v[i][ch-'a']=i;
        }
        int ans=0;

        for(auto w:words){
            bool f=true;
            int idx=0;
            for(auto c:w){
          if(idx==n||v[idx][c-'a']==-1){f=false;break;}

          idx=v[idx][c-'a']+1;
          }
          if(f)ans++;
        }
        return ans;
    }
};