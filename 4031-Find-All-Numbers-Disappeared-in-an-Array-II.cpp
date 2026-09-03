class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        set<int> st;
        for(auto i:nums) if(i>=lower && i<=upper) st.insert(i);
        vector<vector<int>> ans;

        // CHANGE 1: Guard against an empty set
        if (st.empty()) {
            ans.push_back({lower, upper});
            return ans;
        }

        auto it = st.begin();
        if(*it > lower) ans.push_back({lower, *it - 1});

        for(auto it = st.begin(); it != st.end(); it++){
            auto jt = it;
            jt++; 
 if(jt == st.end()) break; 

            int a = *it;
            int b = *jt;
            
            
            if(b>=a+2) {
                ans.push_back({a + 1, b - 1});
            }
        }

        // CHANGE 5: Use *st.rbegin() instead of dereferencing *st.end()
        if(*st.rbegin() < upper) {
            ans.push_back({*st.rbegin() + 1, upper});
        }
        
        return ans;
    }
};