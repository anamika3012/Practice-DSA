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

    bool checkSymmetry(TreeNode* root1 , TreeNode* root2){
        //base case
        if(!root1 && !root2 ) return true;

        if(root1 && root2 && root1->val == root2->val){
            bool leftAns = checkSymmetry(root1->left , root2->right);
            bool rightAns = checkSymmetry(root1->right , root2->left);
            return leftAns && rightAns;
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode* root1 = root->left;
        TreeNode* root2 = root->right;

        bool ans = checkSymmetry(root1 , root2);

        return ans;
    }
};