class StockSpanner {
public:
    stack<pair<int, int>> stk;
    int idx ;
    StockSpanner() {
        idx = -1;
        // stk.clear();
    }
    
    int next(int price) {
        idx = idx+1;
        while(!stk.empty() && stk.top().first <= price){
            stk.pop();
        }
        int ans = stk.empty() ? idx + 1 : idx - stk.top().second;
        stk.push({price, idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */