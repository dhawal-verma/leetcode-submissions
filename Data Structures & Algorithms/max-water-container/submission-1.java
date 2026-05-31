class Solution {
    public int maxArea(int[] heights) {
        int low =0;
        int high = heights.length-1;
        int ans = 0;
        while(low<high){
            int area = Math.min(heights[high],heights[low]) * (high-low);
            ans = Math.max(ans,area);

            if(heights[low]<heights[high])low++;
            else high--;
        }
        return ans;
    }
}
