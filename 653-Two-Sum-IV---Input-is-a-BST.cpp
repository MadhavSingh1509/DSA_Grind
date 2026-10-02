/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool f(TreeNode* node,unordered_set<int>&st,int k){
    if(node==nullptr)return false;
    int target=k-node->val;
    if(st.count(target))return true;
    st.insert(node->val);
    return f(node->left,st,k)||f(node->right,st,k);
}
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>st;
        return f(root,st,k);
    }
};