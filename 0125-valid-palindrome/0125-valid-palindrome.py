class Solution:
    def isPalindrome(self, s: str) -> bool:
        arr = []
        
        for ch in s:
            if(ch.isalnum()):
                arr.append(ch.lower())
        
        for i in range(len(arr)):
            if(arr[i] != arr[len(arr)-1-i]):
                return False
            
        return True