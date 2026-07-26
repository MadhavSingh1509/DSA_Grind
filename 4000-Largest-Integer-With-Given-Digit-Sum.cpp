class Solution {
public:
    int largestInteger(int n, int s) {
        
        if(s>9*n)return -1;
        if(s==0)return 0;
        int res=0;
        for(int i=0;i<n;i++){int d=min(9,s);
                            res=res*10+d;
                            s-=d;}
        return res;
        
        
    }
};