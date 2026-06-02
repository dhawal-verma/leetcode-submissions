class Solution {
    public int maxProfit(int[] prices) {
        int minnum = Integer.MAX_VALUE;
        int ans = 0;

        for(int x : prices){
            ans = Math.max(ans,x-minnum);
            minnum = Math.min(minnum,x);
        }
        return ans;
    }
}
