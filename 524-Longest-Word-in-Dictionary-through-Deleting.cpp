class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
       map<int,vector<string>>m;//len->group of words
       //yani ki s ke substrings hone chahiye dictionary ke words
       int n=s.size();
       vector<vector<int>>v(n,vector<int>(26,-1));
       for(int i=n-1;i>=0;i--){
        char ch=s[i];
        if(i<n-1)v[i]=v[i+1];
        v[i][ch-'a']=i;
       }
for(auto w:dictionary){
   bool f=true;
   int len=w.size();
   int pos=0;
   for(auto ch:w){
    if(pos==n|| v[pos][ch-'a']==-1){f=false;break;}
    pos=v[pos][ch-'a']+1;
   }
   if(f)m[len].push_back(w);
}
if(m.empty())return "";
vector<string>&vec=m.rbegin()->second;
sort(vec.begin(),vec.end());
return vec[0];
    }
};