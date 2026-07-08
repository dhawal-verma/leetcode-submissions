class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> store;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            while(!store.empty() && nums[store.back()] <= nums[i]){
                store.pop_back();
            }
            if(!store.empty() && store.front()<= i-k){
                store.pop_front();
            }
            store.push_back(i);

            if(i+1>=k){
                ans.push_back(nums[store.front()]);
            }

        }
        return ans;
    }
};
