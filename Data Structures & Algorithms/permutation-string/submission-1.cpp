class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.length();
        int n2 = s2.length();
        if(n1>n2)return false;

        vector<int> count(26,0);
        vector<int> ans(26,0);
        
        for(int i=0;i<n1;i++){
            count[s1[i]-'a']++;
            ans[s2[i]-'a']++;
        }
        
        int l=0,r=n1-1;
        
       while(r < n2){

    if(count == ans)
        return true;

    ans[s2[l]-'a']--;
    l++;

    r++;
    if(r < n2)
        ans[s2[r]-'a']++;
}   
       return count==ans?true:false;

       
    }
};
