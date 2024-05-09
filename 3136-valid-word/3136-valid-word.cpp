class Solution {
public:
    bool isValid(string word)
    {
        if(word.size() < 3)
            return false;
        
        bool vowel = false;
        bool consonant = false;
        
        for(char c: word)
        {
            if(!isalnum(c))
                return false;
            
            if(isvowel(c))
                vowel = true;
            
            if(isalpha(c) && !isvowel(c))
                consonant = true;
        }
        
        return vowel && consonant;
        
    }
    
    bool isvowel(char c)
    {
        if(c == 'a' || c =='e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        
        else return false;
    }
};