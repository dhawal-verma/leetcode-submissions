class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

      vector<int> ans;

      for(int i=0;i<=nums.size()-k;i++){
        int maxN =  INT_MIN;
        for(int j=i;j<i+k;j++){
            maxN = max(maxN,nums[j]);
        }
        ans.push_back(maxN);
      }
return ans;
        
    }
};
