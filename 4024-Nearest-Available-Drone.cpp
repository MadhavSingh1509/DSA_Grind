class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int min=1e8;
        int ans=-1;
        int tx=target[0];
        int ty=target[1];
        int n=drones.size();
        for(int i=0;i<n;i++){
            vector<int>&v=drones[i];
            int x=v[0];
            int y=v[1];
            int range=v[2];
            if((abs(tx-x)+abs(ty-y))<=range){
                if((abs(tx-x)+abs(ty-y))<min){
                    min=abs(tx-x)+abs(ty-y);
                    ans=i;
                }
            }
        }
        return ans;
    }
};