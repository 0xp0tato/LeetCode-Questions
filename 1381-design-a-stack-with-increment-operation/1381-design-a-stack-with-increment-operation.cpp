class CustomStack {
public:
    vector<int> st;
    int i;
    CustomStack(int maxSize) 
    {
        st.resize(maxSize, -1);
        i = 0;
    }
    
    void push(int x) {
        if (i < st.size())
        {
            st[i] = x;
            i++;
        }
        // print();
    }
    
    int pop() {
        if(i-1 >= 0)
        {
            int num = st[i-1];
            st[i-1] = -1;
            i--;
            // print();
            return num;
        }
        
        else
        {
            // print();
            return -1;
        }
    }
    
    void increment(int k, int val)
    {
        for(int j=0;j<k && j<i;j++)
            st[j] += val;
        
        // print();
    }
    
    void print()
    {
        for(auto x: st)
            cout<<x<<" ";
        
        cout<<endl;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */