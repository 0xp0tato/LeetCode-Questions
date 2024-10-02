class Solution {
public:
    char kthCharacter(int k)
    {
        string word = "a";
        
        while(word.size() < k)
        {
            string temp = word;
            
            for(int i=0;i<temp.size();i++)
                temp[i] = ((temp[i] - 'a' + 1) % 'z') + 'a';
            
            word += temp;
        }
        
        return word[k-1];
        
    }
};