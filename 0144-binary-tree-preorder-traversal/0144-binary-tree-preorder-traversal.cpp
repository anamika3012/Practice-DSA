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

    void traverse(TreeNode* root , vector<int>& output){
         if(root == NULL) return;

        //NLR
        output.push_back(root->val);
        traverse(root->left , output);
        traverse(root->right , output);
    }

    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> output;
        traverse(root , output);
       return output;
    }
};