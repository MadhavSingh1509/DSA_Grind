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
//{rob,skip}

//{rob,skip}

pair<int,int>f(TreeNode* root){
    if(root==nullptr)return {0,0};
    auto  l=f(root->left);
    auto r=f(root->right);
    int rob=root->val+l.second+r.second;
    int skip=max(l.first,l.second)+max(r.first,r.second);
    return {rob,skip};
}
    int rob(TreeNode* root) {
        pair<int,int>p=f(root);
        return max(p.first,p.second);
    }
};
