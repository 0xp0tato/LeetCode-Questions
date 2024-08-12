class KthLargest {
private:
    int k;
    // vector<int> nums;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums)
    {
        this->k = k;
        
        for(int n: nums)
        {
            this->pq.push(n);
            if(this->pq.size() > k)
                this->pq.pop();
        }
    }
    
    int add(int val)
    {
        pq.push(val);
        int k = this->k;
        
        if(this->pq.size() > k)
            this->pq.pop();
        
       return this->pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */