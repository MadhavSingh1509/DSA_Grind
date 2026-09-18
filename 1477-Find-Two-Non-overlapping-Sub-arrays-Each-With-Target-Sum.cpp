class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i=0;
        int j=0;
        int n=arr.size();
        int bestmin=INT_MAX;
        vector<int>minlen(n,INT_MAX);
        int currsum=0;
        int ans=INT_MAX;

        while(j<n){
            currsum+=arr[j];
            while(currsum>target)currsum-=arr[i++];
            if(currsum==target){
                int len=j-i+1;
                if(i>0 && minlen[i-1]!=INT_MAX )ans=min(ans,len+minlen[i-1]);
                bestmin=min(bestmin,len);
            }
            minlen[j]=bestmin;
            j++;

        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};