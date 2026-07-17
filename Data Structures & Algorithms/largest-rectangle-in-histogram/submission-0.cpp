class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int size = heights.size();
        int maxArea = 0;
        for(int i=0;i<size;i++){

            int left = i;
            while(left>=0 && heights[left]>=heights[i]){
                left--;
            }
            int right = i;
            while(right <size && heights[right]>=heights[i]){
                right++;
            }
            int length = right - left -1;
            maxArea = max(maxArea , length * heights[i]);
        }

        return maxArea;
    }
};
