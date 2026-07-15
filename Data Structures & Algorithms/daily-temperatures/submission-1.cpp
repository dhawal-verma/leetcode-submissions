class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        vector<int> result(temp.size(),0);
        st.push(0);
        for(int i=1;i<temp.size();i++){
            if(!st.empty() && temp[i]>temp[st.top()]){

            while(!st.empty() && temp[i]>temp[st.top()]){
                result[st.top()] = i-st.top();
                st.pop();
            }
                st.push(i);
            }
            else{
                st.push(i);
            }
        }

       return result;
    }
};
