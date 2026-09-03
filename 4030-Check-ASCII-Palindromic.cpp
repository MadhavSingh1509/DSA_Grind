class Solution {
public:
    bool isPalindromic(string s) {
        string temp = "";

        for (auto ch : s) {
            int val = int(ch);
            temp += bitset<8>(val).to_string();
        }

        int i = 0;
        int j = temp.size() - 1;

        while (i<j&&temp[i] == temp[j]) {
            
            i++;
            j--;
        }

        return j < i;
    }
};