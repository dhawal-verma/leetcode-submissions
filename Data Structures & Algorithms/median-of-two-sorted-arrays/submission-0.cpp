class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for(int x : nums1) ans.push_back(x);
        for(int x : nums2) ans.push_back(x);
        sort(ans.begin(),ans.end());

        int n = ans.size();
        double size = n;
        double median;

        int low = 0;int high = ans.size()-1;

        if(n%2 == 0){
            double first = size/2;
            double second = first +1;
            cout<<first<<" "<<second;
            median = (ans[first-1]+ans[second-1])/2.0;
        }else median = ans[(size)/2];

        return median;
    }
};
