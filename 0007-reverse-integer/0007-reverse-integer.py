class Solution:
    def reverse(self, x: int) -> int:
        flag = 1
        
        if x < 0:
            flag = -1
            x = x * -1
            
        ans = 0
        
        while(x > 0):
            last = int(x % 10)
            ans = (ans * 10) + last
            x = int(x / 10)
            
            
        ans = ans * flag
        
        if ans < -2 ** 31 or ans > 2**31 - 1:
            return 0
        
        return ans