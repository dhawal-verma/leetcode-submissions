class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mp;

        for(int x : nums){
            if(mp.contains(x))return true;
            else mp.insert(x);
        }

        return false;
    }
};