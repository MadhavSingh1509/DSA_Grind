class Solution {
public:
    string smallestPalindrome(string s) {   //if(s.size()==1)return s;
                                        string temp="";
for(int i=0;i<s.size()/2;i++){temp.push_back(s[i]);}
                                         sort(temp.begin(),temp.end());
                  if(s.size()%2)temp.push_back(s[s.size()/2]);
                       if(s.size()%2)   { for(int j=temp.size()-2;j>=0;j--)temp.push_back(temp[j]); } 
                                         else { for(int j=temp.size()-1;j>=0;j--)temp.push_back(temp[j]);}
        return temp;
    }
};