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

    int solve(TreeNode* root , int& count){
        if(root == NULL) return 0 ;

        count++;
        int leftAns = solve(root->left , count);
        int rightAns = solve(root->right , count);
        return count;
     }

    int countNodes(TreeNode* root) {
        int count =0;
        int ans = solve(root , count);
        return ans;
    }
};