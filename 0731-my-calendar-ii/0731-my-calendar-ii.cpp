class MyCalendarTwo {
public:
    vector<pair<int,int>> c;
    vector<pair<int,int>> tb;
    MyCalendarTwo() {
        
    }
    
    bool book(int s2, int e2)
    {
        for(int i=0;i<tb.size();i++)
        {
            int s1 = tb[i].first;
            int e1 = tb[i].second;
            
            if(e1 > s2 && s1 < e2)
                return false;
        }
        
        for(int i=0;i<c.size();i++)
        {
            int s1 = c[i].first;
            int e1 = c[i].second;
            
            if(e1 > s2 && s1 < e2)
                tb.push_back({max(s1, s2), min(e1, e2)});
        }
        
        c.push_back({s2, e2});
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */