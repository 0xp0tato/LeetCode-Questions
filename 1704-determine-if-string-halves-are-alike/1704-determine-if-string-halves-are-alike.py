class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s)
        
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        
        a_count = 0
        b_count = 0
        
        for i in range (0, int(n/2)):
            if s[i] in vowels:
                a_count = a_count + 1
                
        for i in range(int(n/2), n):
            if s[i] in vowels:
                b_count = b_count + 1
                
        return a_count == b_count