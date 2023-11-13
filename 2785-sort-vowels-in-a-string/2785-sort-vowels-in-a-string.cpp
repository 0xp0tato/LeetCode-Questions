class Solution {
public:
    string sortVowels(string s)
    {
        string ans;
        priority_queue<char, vector<char>, greater<char>> pq;
        
        for(auto x: s)
        {
            if(x == 'A' or x == 'E' or x == 'I' or x == 'O' or x == 'U' or x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u')
            {
                ans += '_';
                pq.push(x);
            }
            
            else
            {
                ans += x;
            }
        }
        
        for(auto &x: ans)
        {
            if(x == '_')
            {
                x = pq.top();
                pq.pop();
            }
        }
        
        return ans;
        
    }
};