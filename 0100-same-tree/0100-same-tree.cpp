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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q || (p->val != q->val)) return false;

        // preorder traversal - NLR 
        bool nodeAns = (p->val == q->val) ;

        bool leftAns = isSameTree(p->left , q->left);

        bool rightAns = isSameTree(p->right , q->right);

        if(nodeAns && leftAns && rightAns) return true;
        return false;
    }
};