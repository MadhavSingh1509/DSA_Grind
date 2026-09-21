class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,int>m;
        map<int,int>f;
        map<int,int>last;
        unordered_set<int>st;
        for(auto ele:nums)st.insert(ele);
        for(int i=0;i<nums.size();i++){
            if(!st.count(nums[i])){  continue;}
            if(f[nums[i]]==0){
                f[nums[i]]++;
              m[nums[i]]=i;
last[nums[i]]=i;
            }
            else  if(f[nums[i]]==1){
                f[nums[i]]=2;
                int diff=i-last[nums[i]];
                m[nums[i]]=diff;
                last[nums[i]]=i;
            }
            else {
                f[nums[i]]++;
                int diff=m[nums[i]];
                if(diff+last[nums[i]]==i){ last[nums[i]]=i;}
                else st.erase(nums[i]);
            }
        }

       int ans=0;
       for(auto ele:st)if(f[ele]==3)ans++;
       return ans;
    }
};