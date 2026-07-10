class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<int,int>>v1;
int c=0;
for(int i=0;i<name.size();){
int curr=name[i]-'a';c=0;
while(i<name.size()&&curr==name[i]-'a'){i++;c++;}
v1.push_back({curr,c});

}
vector<pair<int,int>>v2;
for(int i=0;i<typed.size();){
int curr=typed[i]-'a';c=0;
while(i<typed.size()&&curr==typed[i]-'a'){i++;c++;}
v2.push_back({curr,c});

}

int i=0;
int j=0;

  if(v1.size()!=v2.size())return false;
int n=v1.size();
for(int i=0;i<n;i++){
if(v1[i].first!=v2[i].first  )return false;
if(v1[i].second>v2[i].second)return false;
}
return true;
    }
};