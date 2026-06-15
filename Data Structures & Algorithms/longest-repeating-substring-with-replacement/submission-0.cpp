class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0,maxF=0;
        unordered_map<int,int> mp;
        int ans = 0;

        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
            maxF = max(maxF,mp[s[right]]);
            while((right-left+1-maxF)>k){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);

        }
        return ans;

    }
};
