class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int n=nums.size();
        // vector<int> ans(n);
        
        // for(int i=0;i<n;i++){
        //     int new_i=(i+k)% n;
        //     ans[new_i]=nums[i];
        // }
        // nums=ans;
      k=k%nums.size();
       reverse(nums.begin(),nums.end());
       reverse(nums.begin(),nums.begin()+k);
       reverse(nums.begin()+k,nums.end());

    }
};