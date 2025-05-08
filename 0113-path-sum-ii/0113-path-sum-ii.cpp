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

    void solve(TreeNode* root , int targetSum , int sum,vector<vector<int>>& ans,vector<int> v){
        //base case
        if(root ==  NULL){
            return;
        } 

        sum+= root->val;
        v.push_back(root->val);


        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(v);
                return;
            }
        }

        solve(root->left,targetSum, sum , ans,v);
        solve(root->right , targetSum , sum , ans,v);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        int sum =0;

        solve(root , targetSum , sum , ans,v);
        return ans;
    }
};