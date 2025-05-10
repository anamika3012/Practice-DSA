class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 =0 , sum2 =0;
        long long zerosInArr1 =0 , zerosInArr2 =0;

        // find sum of each arrays and also zerocount in each array
        for(int i=0;i<nums1.size(); i++){
            sum1 += nums1[i];
            if(nums1[i] == 0){
                zerosInArr1++;
                nums1[i] = 1;
                sum1+= 1;
            } 
        }

        for(int i=0;i<nums2.size(); i++){
            sum2 += nums2[i];
            if(nums2[i] == 0){
                zerosInArr2++;
                nums2[i] = 1;
                sum2+= 1;
            }
        }

        //compare the sums of both array
        if(sum1 > sum2 && zerosInArr2 ==0) return -1;
        if(sum1 < sum2 && zerosInArr1 ==0) return -1;

        return max(sum1 , sum2);
    }
};