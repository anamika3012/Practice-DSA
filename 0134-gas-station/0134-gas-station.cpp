// class Solution {
// public:
// ///// BRUTE-FORCE APPROACH
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();

//         for(int i=0; i<n; i++){
//             // if gas is less than the cost required then move on to next index .
//             if(gas[i] < cost[i]) continue;   

//             int j = (i + 1)%n;  
//             int currentGas = gas[i] - cost[i] + gas[j];

//             while(j !=i){
//                 if(currentGas < cost[j]) break;

//                 int costToMoveToNextj = cost[j];
//                 j = (j+1)%n;   //move on to next index
//                 int gasEarned = gas[j];
//                 currentGas = currentGas - costToMoveToNextj + gasEarned;
//             } 

//             if(j == i) return i;   // if index j is same as starting index i , then the answer is i
//         }
//     return -1;
//     }
// };



class Solution {
public:
///// BETTER  APPROACH   -> GREEDY  - O(N)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total =0;
        int station = 0;

        int totalgas = accumulate(begin(gas) , end(gas) ,0);
        int totalcost = accumulate(begin(cost) , end(cost) ,0);

        if(totalgas < totalcost) return -1;

        for(int i=0; i<gas.size(); i++){
            total = total +  gas[i] - cost[i];

            if(total <0){
                total = 0;
                station = i+1;
            }
        }
    return station;
    }
};