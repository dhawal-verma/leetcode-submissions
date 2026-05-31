class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low = 0;
        int high = heights.size()-1;

        int ans = 0;

        while(low<high){
            int sum = (high-low) * min(heights[high],heights[low]);
            ans  = max(ans,sum);
            if(heights[low]<heights[high])low++;
            else high--;
        }
        return ans;
    }
};
