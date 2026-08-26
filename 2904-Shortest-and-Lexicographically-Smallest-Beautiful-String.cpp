class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        //lengthwise shortest  beautiful substring khojo
        //unme v lexicographically smallest wale ko khojo
        //length +lexicographically shortest ko khojo jisme exactly k 1s ho
        map<int,set<string>>m;
        for(int i=0;i<n;i++){
                string temp="";
                int c=0;
            for(int j=i;j<n;j++){
temp.push_back(s[j]);
if(s[j]=='1')c++;
if(c==k)m[j-i+1].insert(temp);
if(c>k)break;
            }
        }
if(m.empty())return "";
auto &st=m.begin()->second;
return *st.begin();

    }
};