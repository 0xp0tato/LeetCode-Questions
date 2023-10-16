class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string encoded = longUrl;
        reverse(encoded.begin(), encoded.end());
        
        return encoded;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        string decoded = shortUrl;
        reverse(decoded.begin(), decoded.end());
        
        return decoded;
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));