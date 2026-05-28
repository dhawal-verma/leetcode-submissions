class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> store(nums.begin(),nums.end());
        int ans = 0;
        for(int num : store){
            if(store.find(num-1) == store.end()){
                int length = 1;

                while(store.find(num+length)!= store.end()){
                    length ++;
                }
            ans = max(ans,length);
            }
        }
        return ans;
    }
};
