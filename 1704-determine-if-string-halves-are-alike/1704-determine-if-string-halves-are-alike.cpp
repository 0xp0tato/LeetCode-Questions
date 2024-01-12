class Solution {
public:
    bool halvesAreAlike(string s)
    {
        int a_freq = 0;
        int b_freq = 0;
        
        int n = s.length();
        
        string a = s.substr(0, n/2);
        string b = s.substr(n/2, n);
        
        // vowels of a
        for(auto x: a)
            if(isVowel(x))
                a_freq++;
        
        // vowels of b
        for(auto x: b)
            if(isVowel(x))
                b_freq++;
        
        return a_freq == b_freq;
    }
    
    bool isVowel(char ch)
    {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        return find(vowels.begin(), vowels.end(), ch) != vowels.end();
    }
};