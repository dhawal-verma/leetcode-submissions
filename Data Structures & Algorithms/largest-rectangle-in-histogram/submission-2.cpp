class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        
        int size = heights.size();
        for(int i=0;i<size;i++){
            
            while(!st.empty() && heights[i]<heights[st.top()]){
               
                int height = heights[st.top()];
                st.pop();
                int left = st.empty()?-1:st.top();
                int right =i;

                maxArea = max(maxArea, (right-left-1) * height);
            }
            st.push(i);
        }
        while(!st.empty()){
               
                int height = heights[st.top()];
                st.pop();
                int left = st.empty()?-1:st.top();
                

                maxArea = max(maxArea, (size-left-1) * height);
            }

        return maxArea;
    }
};
