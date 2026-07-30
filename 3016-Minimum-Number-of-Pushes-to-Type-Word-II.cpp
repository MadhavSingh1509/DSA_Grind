class Solution {
public:
    int minimumPushes(string word) {
        // frequency se max to minimum order me save kro
        // uske baad grouping kro ,8 ke sets me sbko
        map<char, int> m;
        for (auto c : word)
            m[c]++;
        map<int, vector<char>> f;
        for (auto it : m) {
            char ch = it.first;
            int freq = it.second;
            f[freq].push_back(ch);
        }
        map<int, int> val;
        int count = 0;
        int value = 0;
        for (auto it = f.rbegin(); it != f.rend(); it++) {
            int freq = it->first;
            vector<char>& vec = it->second;
            for (auto c : vec) {
                if (count % 8 == 0)
                    value++;
                val[c] = value;
                count++;
            }
        }
        int ans = 0;
        for (auto ch : word)
           { ans += val[ch];}
            
        return ans;
    }
};