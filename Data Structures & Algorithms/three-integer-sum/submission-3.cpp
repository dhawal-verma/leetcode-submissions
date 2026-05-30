class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int low = i+1;
            int high = nums.size()-1;
            while(low<high){
            // vector<int> triplet;
                if(nums[i]+nums[low]+nums[high]==0){
                    // triplet.insert(triplet.end(),{nums[i],nums[low],nums[high]});
                    ans.insert(ans.end(),{nums[i],nums[low],nums[high]});
                    high--;low++;
                //    break;
                }
                else if(nums[i]+nums[low]+nums[high]>0)high--;
                else low++;
            }
            
        }
         vector<vector<int>> my(ans.begin(),ans.end());
        return my;
    }
};
