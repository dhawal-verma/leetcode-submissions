class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minnum = INT_MAX;
        for(int i:prices){
            if(i < minnum) minnum = i;
            ans = max(ans, i-minnum);
            cout<<"min :"<<minnum<<"ans :"<<ans<<endl;
        }
        return ans;
    }
};
