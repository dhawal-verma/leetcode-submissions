class Solution {
   public:
    string minWindow(string s, string t) {
        int size = t.size();
        int len = s.size();
        int count = 0;
        int minLength = INT_MAX;
        int startIndex = -1;
        int mp[256] = {0};
        int l = 0;
        
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }

        for (int r = 0; r < len; r++) {
            if (mp[s[r]] > 0) {
                count++;
            }
            mp[s[r]]--;
           
                while (count == size) {
                    if (r - l + 1 < minLength) {
                        minLength = r - l + 1;
                        startIndex = l;
                    }
                    mp[s[l]]++;
                    if(mp[s[l]]>0){
                        count--;
                    }
                    l++;
                }
            
        }
        return startIndex==-1?"":s.substr(startIndex,minLength);
    }
};
