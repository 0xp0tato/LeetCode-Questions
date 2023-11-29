class Solution:
    def isPalindrome(self, x: int) -> bool:
        
        if(x < 0):
            return False
        
        arr = []
        
        while(x):
            last = int(x%10)
            arr.append(last)
            x = int(x/10)
            
        for i in range(len(arr)):
            if(arr[i] != arr[len(arr)-1-i]):
                return False
            
            
        return True
        