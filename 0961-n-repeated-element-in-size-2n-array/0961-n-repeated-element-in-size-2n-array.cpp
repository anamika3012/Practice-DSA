class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size();
        if (nums[0] == nums[1]) return nums[0];
        if (nums[0] == nums[2] || nums[1] == nums[2]) return nums[2];

        int ans = 0;
        int freq=0;
        for(int i=3; i<size; i++){
            if(freq == 0) ans = nums[i];
            if(nums[i] == ans)  freq++;
            else freq--;
        }
        return ans;
    }
};