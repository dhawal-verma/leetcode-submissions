class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row  = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = col * row -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int rows = mid/col;
            int cols = mid%col;

            if(matrix[rows][cols]==target){
                return true;
            }else if(matrix[rows][cols]>target){
                high = mid-1;
            }else low = mid+1;
        }
        return false;
    }
};
