class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int divisor_sum = 0;

        for(int n: nums){
            int count =0;
            int sum = 0;
            for(int i=1; i*i <=n; i++){
                if(n%i == 0){
                    int k = n/i;
                    if (i == k){
                        count ++;
                        sum += i;
                    }
                    else{
                        count += 2;
                        sum = sum + i+k;
                    }
                    if(count >4) break; 
                }
            }
            if (count == 4) divisor_sum += sum;
        } 
        return divisor_sum;
    }
};