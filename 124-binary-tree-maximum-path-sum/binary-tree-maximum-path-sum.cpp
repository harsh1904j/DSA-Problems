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
int findSum(TreeNode* root, int& maxi){
    if(root == NULL) return 0;
    int l_sum = max(0, findSum(root->left, maxi));
    int r_sum = max(0, findSum(root->right, maxi));
    maxi = max(maxi, l_sum + r_sum + root->val);
    return root->val + max(l_sum, r_sum);
}
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findSum(root, maxi);
        return maxi;
    }
};