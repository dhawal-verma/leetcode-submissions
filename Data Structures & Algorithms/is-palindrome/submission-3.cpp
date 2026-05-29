class Solution {
   public:
    bool isPalindrome(string s) {

        // if(s.size()==0)return true
        for (auto& x : s) {
        x = tolower(x);
    }
        int low = 0;
        int high = s.size() - 1;

        while (low < high) {
            while(low< high && (!(isalpha(s[low]) || isdigit(s[low])) )) low++;
            while (low<high && (!(isalpha(s[high]) || isdigit(s[high])))) high--;
            cout<<" low "<<s[low]<<" high "<<s[high];
            if ( s[low] != s[high]) {
                return false;
            } else {
                low++;
                high--;
            }
        }
        return true;
    }
};
