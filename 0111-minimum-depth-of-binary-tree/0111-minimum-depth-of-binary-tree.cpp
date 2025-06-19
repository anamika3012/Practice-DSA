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
    int minDepth(TreeNode* root) {
        if(root == NULL ) return 0;

        int leftAns = minDepth(root->left);
        int rightAns = minDepth(root->right);

        if(root->left==NULL && root->right !=NULL || root->right==NULL && root->left != NULL){
           int  ans = max(leftAns , rightAns) + 1;
            return ans;
        }
        int ans = min(leftAns , rightAns) + 1;
        return ans;
    }
};