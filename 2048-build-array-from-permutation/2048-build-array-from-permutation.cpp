class Solution {
public:

////// Space Complexity : O(n) , Time Complexity : O(n)
    // vector<int> buildArray(vector<int>& nums) {
    //     vector<int> ans(nums.size(), 0);

    //     for(int i=0; i<nums.size(); i++){
    //         ans[i] = nums[nums[i]];
    //     }
    // return ans;
    // }


////// Space Complexity : O(1) , Time Complexity : O(n)  
    vector<int> buildArray(vector<int>& nums){
        int n = nums.size();

        //modifying each element of array into new number x .
        for(int i=0; i<n; i++){
            nums[i] = nums[i]  + (nums[nums[i]] % n) * n;
        }

        // extract new numbers 
        for(int i=0; i<n; i++){
            nums[i] = nums[i] / n;
        }

        return nums;
    }
};