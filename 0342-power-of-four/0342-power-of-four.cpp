class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if(n <= 0)
            return false;
        
        long long int x = log2(n) / log2(4);
        
        return n == pow(4,x);
        
    }
};