class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mp;

        for(int x : nums){
            if(mp[x]>0)return true;
            else mp[x] =1;
        }

        return false;
    }
};