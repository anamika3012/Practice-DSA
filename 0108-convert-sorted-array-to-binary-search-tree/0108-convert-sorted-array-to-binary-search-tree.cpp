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

    //Approach : Find Mid of Array , this is root node . The elements on left will be left subtree , the elements on right will be rightsubtree.

    TreeNode* createTree(vector<int>& nums , int start , int end){
        int mid = (start + end)/2;
        //base case
        if(start > end ) return NULL;

        TreeNode* root = new TreeNode(nums[mid]);
        root ->left = createTree(nums , start , mid-1);
        root->right = createTree(nums , mid+1 , end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid = (start+end)/2;

        TreeNode* root = createTree(nums , start , end );
        
        return root;
    }
};