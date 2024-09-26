class MyCalendar {
public:
    vector<pair<int,int>> c;
    MyCalendar()
    {
    }
    
    bool book(int s2, int e2)
    {
        for(auto [s1, e1]: c)
        {
            if(!(e1 <= s2 || e2 <= s1))
                return false;
        }
        
        c.push_back({s2, e2});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */