class Solution {
public:
    int countValidPrefixes(string s) {
        int c=0;
        int ans=0;
        for(auto ch:s){
            if(ch=='0')c++;
            else c--;
            if(c==1||c==-1||c==0)ans++;
        }
        return ans;
    }
};