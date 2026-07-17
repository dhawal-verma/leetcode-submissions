class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        int size = position.size();
        vector <pair<int, int>> arr;

        for (int i = 0; i <size;i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end());
            double time = (double)(target - arr[arr.size()-1].first ) / arr[arr.size()-1].second ;
        st.push(time);
        for (int i = size - 2; i >= 0; i--) {
            double time = (double)(target - arr[i].first) / arr[i].second;
            if (!st.empty() && time > st.top()) {
                st.push(time);
                cout << st.top();
            }
        }
        return st.size();
    }
};
