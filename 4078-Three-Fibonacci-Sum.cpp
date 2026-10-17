class Solution {
public:
    bool threeFibonacciSum(int n) {
        int x=0;
        int y=1;
        
        while(y<=n){
            if(1LL*2*(x+y)==n)return true;
            int temp=y;
            y=x+y;
            x=temp;

        }
return 0;
    }
};