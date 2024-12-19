class Solution {
    public int maxChunksToSorted(int[] arr) {
        int maxi = -1;
        
        int ans = 0;
        
        for(int i=0;i<arr.length;i++)
        {
            maxi = Math.max(maxi, arr[i]);
            
            if(maxi == i)
                ans++;
        }
        
        return ans;
    }
}