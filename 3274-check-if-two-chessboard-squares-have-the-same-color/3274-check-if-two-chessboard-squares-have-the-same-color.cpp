class Solution {
public:
    bool checkTwoChessboards(string c1, string c2)
    {
        unordered_map<char,int> m;
        
        m['a'] = 1;
        m['b'] = 2;
        m['c'] = 3;
        m['d'] = 4;
        m['e'] = 5;
        m['f'] = 6;
        m['g'] = 7;
        m['h'] = 8;
        
        m['1'] = 1;
        m['2'] = 2;
        m['3'] = 3;
        m['4'] = 4;
        m['5'] = 5;
        m['6'] = 6;
        m['7'] = 7;
        m['8'] = 8;
        
        int c1x = m[c1[0]];
        int c1y = m[c1[1]];
        int c2x = m[c2[0]];
        int c2y = m[c2[1]];
        
        //0b 1w
        int a = 1;
        int b = 1;
        
        if(c1x % 2 == c1y % 2)
            a = 0;
        
        if(c2x % 2 == c2y % 2)
            b = 0;
        
        return (a == b);
    }
};