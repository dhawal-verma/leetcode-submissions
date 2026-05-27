class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26,0);

        for(int i : s){
            arr[i-'a']++;
        }
        for(int i : t){
            arr[i-'a']--;
        }

        
        for(int i : arr){
            if(i!=0)return false;
            // cout<<"i"<<i;
        }
        return true;
    }
};
