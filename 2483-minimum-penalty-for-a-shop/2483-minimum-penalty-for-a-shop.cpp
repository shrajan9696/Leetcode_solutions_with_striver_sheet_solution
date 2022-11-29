class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> yes;
        vector<int> no;
        int n= customers.length();
        for(int i=0;i<n;i++){
            if(customers[i]=='Y') yes.push_back(i);
            else no.push_back(i);
        }
        int p =INT_MAX;
        int h=0;
        for(int i=0;i<=n;i++){
            auto py = lower_bound(yes.begin(),yes.end(),i);
            auto pn = lower_bound(no.begin(),no.end(),i) ;
            int x=0;
            int y=0;
            if(py == yes.end())
            {
                x=0;
            }
            else{
                x= yes.size() - (py - yes.begin());
            }
            
            if(pn == no.end())
            {
                y = no.size();
            }
            else
            {
               
                    y = pn - no.begin();
                
                
            }
            
              
            int pen = x+y;
            cout<<pen<<" ";
            if(pen<p){
                p=pen;
                h = i;
            }
        }
        return h;
    }
};