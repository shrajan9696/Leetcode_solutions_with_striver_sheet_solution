class MedianFinder {
public:
    priority_queue<int> s;
      priority_queue<int, vector<int>,greater<int>> g;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(s.size()==0 and g.size()==0) s.push(num);
       else if(s.size()>g.size()){
            if(num>s.top()){
                g.push(num);
            }
            else{
                g.push(s.top());
                s.pop();
                s.push(num);
            }
        }
        else{
            if(num<g.top()){
                s.push(num);
            }
            else{
                g.push(num);
                s.push(g.top());
                g.pop();
            }
        }
    }
    
    double findMedian() {
      if(s.size()==g.size()){
          // cout<<s.top()<<" "<<g.top()<<" ";
      double ans = double( double(s.top())+double(g.top()))/2.0;
          return ans;
      }
        else{
            return double(s.top());
        }
      
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */