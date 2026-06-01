class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        vector<int> right(height.size()+1,0);
        int ans = 0;
        int maxn = 0;
        left.push_back(0);
        
        int minn = height[0];
        for(int i=0;i<height.size();i++){
            if(height[i]>minn)minn = height[i];
            left.push_back(minn);
        }

         for(int i=height.size()-1;i>=0;i--){
            if(height[i]>maxn)maxn = height[i];
            right[i] = maxn;
        }

        for(int i=0;i<height.size();i++){
            cout<<"Left "<<left[i]<<"Right"<<right[i]<<endl;
            cout<<"Left "<<min(left[i],right[i])<<endl;
            if(0<min(left[i],right[i]) - height[i])
            ans = ans + min(left[i],right[i]) - height[i];
        }
        return ans;
    }
};
