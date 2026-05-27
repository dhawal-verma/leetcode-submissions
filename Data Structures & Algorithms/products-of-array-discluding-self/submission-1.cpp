class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> left;
        vector<int> right;
        int temp = 1;
        for(auto i : nums){
            temp *= i;
            left.push_back(temp);
        }
        temp = 1;
        int i = nums.size()-1;
        while(i>=0){
            temp *= nums[i];
            right.push_back(temp);
            i--;
        }
        reverse(right.begin(),right.end());
        vector<int> ans;

        ans.push_back(right[1]);
        for(int i=1;i<nums.size()-1;i++){
            ans.push_back(left[i-1] * right[i+1]);
        }
        ans.push_back(left[nums.size()-2]);

        return ans;
    }
};
