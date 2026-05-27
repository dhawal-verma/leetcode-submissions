class Solution {
public:


    static bool cmp(pair<int,int>&a , pair<int,int> &b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp ;
        vector<int> ans;
        for(int i : nums){
            mp[i]++;
        }

        vector<pair<int,int>> temp;


        for(auto i : mp){
            temp.push_back(i);
        }
        sort(temp.begin(),temp.end(),cmp);

       vector<pair<int,int>> :: iterator itr = temp.begin();
       int i=0;

       while(itr!=temp.end() && i!=k){
        ans.push_back(itr->first);
        itr++;i++;
       }
       return ans;
    }
};
