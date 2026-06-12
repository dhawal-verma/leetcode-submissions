class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans = 0;
        int l = 0,r = 0;
        while(r < s.size()){
            if(!st.contains(s[r])){
                st.insert(s[r]);
                r++;
            }else{
                ans = max(ans,r-l);
                while(st.contains(s[r])){
                    st.erase(s[l]);
                    l++;
                }
            }
        }
        return max(ans, (int)st.size());
    }
};
