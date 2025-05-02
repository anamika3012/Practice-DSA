class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m*n;
        int start_row = 0;
        int end_col = n-1;
        int end_row = m-1;
        int start_col = 0;

        int count=0;
        while(count < total){
           //print starting row
           for(int j=start_col; j<=end_col && count<total; j++ ){
            ans.push_back(matrix[start_row][j]);
            count++;
           }
           start_row++;
           //print ending column
           for(int i=start_row; i <=end_row && count<total; i++){
            ans.push_back(matrix[i][end_col]);
            count++;
           }
           end_col--;
           //print ending row
           for(int j= end_col; j>= start_col && count<total; j--){
            ans.push_back(matrix[end_row][j]);
            count++;
           }
           end_row--;
           //print starting column
           for(int i= end_row; i>=start_row && count<total; i--){
            ans.push_back(matrix[i][start_col]);
            count++;
           }
          start_col++; 
        }
        return ans;
    }
};